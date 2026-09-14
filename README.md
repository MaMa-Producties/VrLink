# VR Link

An Unreal plugin that connects a VR experience to the Neural Recorder tablet, the
Muse EEG app used in the UrbanSense study.

It handles the network link, the session lifecycle, scene and scenario events,
the bike pedal state, and gaze recording. You call it from Blueprint. Nothing
else in your project changes.

## Requirements

- **Unreal Engine 5.8** (branches for 5.6 and 5.7, see [Updates](#updates))
- A Windows PC on the same network as the tablet
- No compiler and no C++ project. The plugin ships precompiled.

Stock engine modules only: `Core`, `CoreUObject`, `Engine`, `InputCore`,
`Networking`, `Sockets`, `Json`.

## Install

1. Copy the `VrLink` folder into your project's `Plugins/` folder, so you have
   `YourProject/Plugins/VrLink/VrLink.uplugin`. Create `Plugins/` if it is not
   there.
2. Open the project.

That is the whole install. The plugin is enabled by default. Do **not** generate
Visual Studio project files or convert the project to C++.

### Updates

`git pull` in the `VrLink` folder, then restart the editor. Releases are tagged.

### If Unreal offers to rebuild the module

The precompiled binary does not match your engine. Either:

- **Wrong engine version.** Check out the matching branch:

      git checkout ue5.6      # Unreal Engine 5.6
      git checkout ue5.7      # Unreal Engine 5.7
      git checkout master     # Unreal Engine 5.8

  Same source on every branch, only the binary differs.
- **A source build of the engine** rather than the launcher build. Binaries are
  tied to an engine build ID. Tell us which engine you are on and we will build
  against it.

## Usage

Every node is on the **VrLink Subsystem**. Drag off in any Blueprint and search
the node name. No actor to place, no reference to wire.

| Node | When to call it | What it does |
|---|---|---|
| `Initialize Vr Link` | Once, on level start | Names the project, finds the tablet |
| `Start Session` | The ride begins | Tells the tablet to start recording |
| `Start Baseline` / `End Baseline` | **Required**, before the ride | Opens and closes a calibration phase |
| `Set Location` | Entering an area | **Where** the participant is |
| `Start Scenario` / `End Scenario` | A design goes on and off display | **Which design** is showing |
| `Set Pedalling` | Whenever the bike sensor changes | Whether the pedals are turning |
| `Can Start Baseline` | Before `Start Baseline` | False while no headband is on a head |
| `Get Headband Message` | While showing the message | The line to display, empty when ready |
| `On Headband State Changed` | Bind once, on level start | Fires whenever the headband state changes |
| `Send Mark` | Anything worth flagging | A timestamped note |
| `End Session` | The ride finishes | Stops the recording cleanly |
| `Is Session Active` | Any time | True while recording |

### A whole run

```
Start Session
Set Pedalling   (whatever the pedals are doing right now)

wait until      Can Start Baseline

Start Baseline  (Relaxed)    ...   End Baseline (Relaxed)
Start Baseline  (Stressed)   ...   End Baseline (Stressed)

Set Location    "Spaklerweg north"
Start Scenario  "Green facade"    ...   End Scenario
Start Scenario  "Grey facade"     ...   End Scenario

Set Location    "Menadostraat"
Start Scenario  "Blue lights"     ...   End Scenario
Start Scenario  "Grey facade"     ...   End Scenario

End Session
```

## The six rules

These are the ones that cost a session if they are missed. None of them raise an
error: the recording is written, looks normal, and is wrong at analysis time.

### 1. Do not start the baseline until the headband is on

The tablet records EEG from a headband the participant wears. If it is not on, or
not connected, the ride still runs perfectly and records no brain data at all.

That happened on 11 September: a 507 second ride, a full gaze stream, a complete
questionnaire, and an EEG file containing only its header. Nobody knew for two
days.

Gate your baseline on **Can Start Baseline**, and show **Get Headband Message**
while it is not empty:

```
On level start
    -> bind On Headband State Changed
    -> show Get Headband Message, hide it when empty

Before Start Baseline
    -> Branch on Can Start Baseline
       true  -> Start Baseline
       false -> wait, keep the message on screen
```

`Start Baseline` refuses on its own if you forget, and says so in the log, in the
headset and on the tablet. Do not rely on that: a refused baseline means the
participant is sitting in a VR experience that is not going anywhere, and only
your own screen can tell them why.

**If it drops out mid-ride, show it and carry on.** Do not end the session.
Stopping would lose the gaze and the questionnaire as well, and whether to
restart is the operator's call, not the experience's.

### 2. `Set Location` and `Start Scenario` are not interchangeable

- `Set Location` is *where they are*: "Spaklerweg north".
- `Start Scenario` is *which design they see*: "Green facade".

The analysis compares designs **within** a location. Send a design as a location
and the report compares two streets instead of two designs.

### 3. Call `End Scenario` every time a design stops showing

Even when the next one follows immediately. Everything between `End Scenario` and
the next `Start Scenario` or `Set Location` is discarded: transitions, corridors,
fades. Left unmarked, that stretch is credited to the design that just ended,
for gaze as well as EEG.

### 4. Run the baseline as two phases, relaxed first

```
Start Baseline (Relaxed)     <- calibration begins
End Baseline   (Relaxed)
Start Baseline (Stressed)
End Baseline   (Stressed)    <- ride can start
```

- **Relaxed** is the reference. Every later value is a difference from it.
- **Stressed** is the only source of `BaselineMin_/BaselineMax_`, which is how a
  quiet participant's real reaction is told from background noise. Skip it and a
  muted responder reads as "no reaction to anything".

**Order matters.** The recorder closes the calibration window at the first exit
from a rest phase.

**The VR side has to drive this.** The tablet times how long calibration runs but
has no stressed phase of its own. If the experience does not declare it, it never
happens.

### 5. Call `Set Pedalling` once right after `Start Session`

Whatever the pedals are doing, even standing still.

Wire the bike sensor's boolean straight in and call it every tick if that is
easiest. The plugin drops repeats, so only the changes reach the file, as a
start and a stop row. From those the analysis gets every stretch of movement,
and the tablet gets a running total of seconds spent pedalling.

Without an opening call there are no pedal marks at all, and a file with none
could be a build that never reported or a participant who never moved. The
analysis will not guess between those, so it reports "unknown" for the whole
ride. The calibration has to be at rest to be a rest reference, and this is the
only thing that can say whether it was.

### 6. One session per ride, not per trigger

`Start Session` once when they set off, `End Session` once when they finish. Use
`Set Location` and `Start Scenario` on your trigger volumes in between.

Each session needs its own calibration and prompts its own questionnaire, so ten
sessions per participant means ten questionnaires and ten fragments that cannot
be compared.

## Gaze recording (optional)

Add the **Gaze Recorder** component to your VR pawn. It writes
`{SessionId}_gaze.csv` and follows the session on its own, so there is nothing to
call.

**No tagging needed.** The heat map is built from the world position the gaze ray
lands on. When the ray hits nothing, sky or an open street, the `HitX/HitY/HitZ`
columns are blank. The row is still real, it just has no position.

## Where the files land

The tablet writes `{SessionId}_eeg.csv`, `_events.csv` and `_session.csv`. The PC
writes `{SessionId}_gaze.csv`, into `Documents/MuseEEG/{sessionFolder}/`.

Two machines, so the files are paired afterwards by the shared `SessionId`
prefix. Nothing needs syncing during the session.

## Troubleshooting

| Symptom | Cause |
|---|---|
| No connection | Tablet and PC must share a network. Discovery is UDP broadcast on port 47800, the link is TCP on 3030 |
| `Is Session Active` false after `Start Session` | The handshake did not complete, usually a dismissed firewall prompt on the PC |
| Stations cross-connecting | Set a matching pairing code on each tablet and its VR station |
| `Start Baseline` does nothing | No headband is connected or it is not being worn. Check the log, the headset and the tablet: all three say so |
| Headset says the baseline started without a check | The tablet app is older than 14 September 2026 and cannot report its headband. Update it |
| Unreal wants to rebuild | See [If Unreal offers to rebuild the module](#if-unreal-offers-to-rebuild-the-module) |

## What is in this repo

| Folder | Why it is here |
|---|---|
| `Source/` | Plugin source, for reference and for rebuilding |
| `Binaries/Win64/` | The precompiled editor DLL |
| `Intermediate/Build/` | Precompiled Game objects. **These are what let a Blueprint-only project package a build.** Do not delete them |

## Credits

Built by MaMa Producties for the UrbanSense study.

Questions to Waleed.

## License

No licence file is attached, so default copyright applies: all rights reserved.
Ask MaMa Producties before using this outside the UrbanSense project.
