# VR Link

VR Link connects your Unreal VR experience to the **Neural Recorder**, the tablet
app that records the participant's brain activity (EEG) during the UrbanSense
study.

Your experience tells the tablet what is happening: the ride starts, the
participant enters a location, a design appears. The tablet records the brain
data with those moments marked, so the analysis knows which design caused which
reaction.

You use it from Blueprint. You do not need C++ or a compiler.

## What you need

- **Unreal Engine 5.8 or newer**, the normal launcher version.
- A Windows PC on the **same network** (Wi-Fi or cable) as the tablet.

## Install

1. Copy the `VrLink` folder into the `Plugins` folder of your project, so this
   file exists: `YourProject/Plugins/VrLink/VrLink.uplugin`.
   No `Plugins` folder yet? Create it.
2. Open the project. The plugin is switched on automatically.

That is all. Do **not** convert the project to C++ and do **not** generate Visual
Studio files.

**To update:** close Unreal, replace the `VrLink` folder with the newest version
from the `master` branch, and open the project again.

**Unreal asks to rebuild the plugin?** Your engine does not match the plugin.
Use Unreal 5.8 from the Epic launcher. On a newer version or a source build, ask
us for a matching plugin.

## The nodes

All nodes are on the **VrLink Subsystem**. In any Blueprint, right-click and
type the node name. There is nothing to place in the level.

| Node | Call it when | What it tells the tablet |
|---|---|---|
| `Initialize Vr Link` | Once, when the level starts | The project name. The PC then waits for the tablet to connect. |
| `Start Session` | The participant is ready to begin | Start recording. |
| `Set Pedalling` | The bike sensor changes (or every tick) | Whether the pedals are turning. |
| `Can Start Baseline` | Before the baseline | True only when the headband is worn and working. |
| `Get Headband Message` | While waiting for the headband | A line of text to show the participant. Empty when all is fine. |
| `On Headband State Changed` | Bind once, when the level starts | Fires when the headband connects, drops out or comes back. |
| `Start Baseline` / `End Baseline` | The calibration forest | Start and end of a calibration phase (Relaxed or Stressed). |
| `Set Location` | The participant enters a place | **Where** they are. |
| `Start Scenario` | A design becomes visible | **Which design** they see. |
| `End Scenario` | That design is no longer visible | Ignore everything until the next design. |
| `Send Mark` | Something worth noting happens | A note with a time stamp, for example `oncoming:start`. |
| `End Session` | The ride is over | Stop recording, and why (see below). |
| `Is Session Active` | Any time | True while the tablet is recording. |

## A whole ride, step by step

```
Initialize Vr Link   "Olifantenpad"
Start Session
Set Pedalling        (what the pedals are doing right now)

wait until Can Start Baseline is true

Start Baseline (Relaxed)   ... calm forest ...    End Baseline (Relaxed)
Start Baseline (Stressed)  ... scary forest ...   End Baseline (Stressed)

Set Location    "Fietspad S111 - Holterbergweg/Arena"
Start Scenario  "Groen impact"        ... ride ...   End Scenario
Start Scenario  "Huidige situatie"    ... ride ...   End Scenario
   (all five designs, in a random order)

Set Location    "Onderdoorgang A10 - Spaklerweg"
Start Scenario  "Visueel comfort"     ... ride ...   End Scenario
   (all five designs, in a random order)

End Session     "complete"
```

## Rules

Breaking one of these gives **no error message**. The recording looks fine, but
the results are wrong. That is why they matter.

### 1. Wait for the headband before the baseline

If the headband is not on the head, the ride still works but **no brain data is
recorded**. Only start the baseline when `Can Start Baseline` is true. Until
then, show `Get Headband Message` in the headset so the participant knows why
nothing happens.

If the headband drops out during the ride: show the message and **keep going**.
Do not end the session. The operator on the tablet decides whether to stop.

### 2. Always do both baseline phases, Relaxed first

```
Start Baseline (Relaxed)
End Baseline   (Relaxed)
Start Baseline (Stressed)
End Baseline   (Stressed)
```

The Relaxed phase is the participant's calm starting point. The Stressed phase
shows how strongly this person can react. Without both, every result is measured
against nothing. The tablet cannot do this for you: if the experience does not
call these nodes, there is no baseline.

### 3. A location is a place, a scenario is a design

- `Set Location` = **where**: "Onderdoorgang A10 - Spaklerweg".
- `Start Scenario` = **which design**: "Groen impact".

The analysis compares designs **within one place**. Send a design as a location
and it compares the wrong things.

### 4. Call `End Scenario` every time a design disappears

Also when the next design follows straight away. Everything between
`End Scenario` and the next `Start Scenario` (fades, loading, corridors) is
ignored by the analysis. If you forget it, those seconds count as reactions to
the design that just ended.

### 5. Use exactly the same names every time

`"Groen impact"`, `"Groen Impact"` and `"Groen impact "` (with a space at the end)
are **three different designs** to the analysis. Copy the names from one agreed
list and never type them by hand in more than one place.

### 6. Shuffle the designs yourself

The study needs the five designs of a location in a **different random order for
each participant**. VR Link does not do this for you. Keep the locations in the
same order; shuffle only the designs inside each location. The tablet reads the
order from your `Start Scenario` calls, so it needs nothing else.

### 7. Call `Set Pedalling` right after `Start Session`

Even if the participant is standing still. After that, call it whenever the bike
sensor changes (every tick is fine, repeats are ignored). Without that first call
the analysis cannot tell "not pedalling" from "sensor not connected".

### 8. One session per participant

Call `Start Session` once at the beginning and `End Session` once at the end.
Never start a new session per location or per design: each session asks the
participant a full questionnaire.

## Ending a session: which reason

| Reason | Use it when |
|---|---|
| `complete` | The ride ran to the end. This is the default. |
| `interrupted` | The ride stopped early, for example the participant felt sick. |
| `emergency-stop` | The ride had to stop immediately. |

The tablet saves the reason. Anything other than `complete` tells the analysis
the ride is not a full measurement.

If the VR app is simply closed, **no reason is sent** and the tablet only sees
the connection drop. Always end with `End Session` when you can.

## Gaze recording (where people look)

Add the **Gaze Recorder** component to your VR pawn. That is all: it starts and
stops with the session by itself and writes `{SessionId}_gaze.csv`.

There is no need to tag objects. The heat map uses the point in the world where
the participant's view lands. When they look at the sky or an open street, that
row has no position, which is normal.

## Where the files are saved

- The **tablet** saves the brain data, events, session details and answers.
- The **VR PC** saves the gaze file in `Documents/MuseEEG/{Study}/Sessions/{date}/`,
  the same folder name as on the tablet.

Afterwards, copy the PC's files next to the tablet's. Files of one session start
with the same `SessionId`, so they find each other.

## Two bikes in one building

With two setups on the same network, a tablet can connect to the **wrong** VR PC.
To prevent it:

1. Give each VR PC a fixed IP address on the router.
2. On each tablet, in Settings, **turn off automatic discovery** and enter the IP
   address of its own VR PC.

## Troubleshooting

| Problem | What to check |
|---|---|
| The tablet does not connect | Same network? Windows firewall: allow Unreal when it asks. The connection uses TCP port 3030. |
| `Is Session Active` stays false after `Start Session` | The tablet is not connected yet. See the line above. |
| A tablet connects to the wrong bike | See "Two bikes in one building". |
| `Start Baseline` does nothing | The headband is not worn or not connected. The log, the headset and the tablet all say which. |
| Unreal asks to rebuild the plugin | Wrong engine version. See Install. |

## What is in this folder

| Folder | What it is |
|---|---|
| `Source/` | The plugin's source code, for reference. |
| `Binaries/Win64/` | The ready-built plugin for the editor. |
| `Intermediate/Build/` | Ready-built parts needed to **package** your game. Do not delete. |

## Credits and licence

Built by MaMa Producties for the UrbanSense study. All rights reserved: ask
MaMa Producties before using it outside the UrbanSense project.
