# VR Link (Primed Relay)

VR Link connects your Unreal VR experience to **Primed Record**, the tablet app
that records the participant's brain activity (EEG). Both are part of **Primed**,
the suite used in the UrbanSense study. In the suite this plugin is called
**Primed Relay**.

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
| `Start Session` | The participant is ready to begin | Start recording. If the tablet already started the recording, nothing changes: the session and its clock carry on. |
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
| `Is Session Paused` | Any time | True while the operator has paused the recording on the tablet. The recording's clock stands still and no gaze is written meanwhile. |
| `On Recording Ended` | Bind once, when the level starts | Fires when the tablet ends the recording (Stop on the tablet). The experience does not stop by itself: bind this if it should. |
| `Release Tablet` | A tablet crashed or lost Wi-Fi and the VR PC still holds it | Nothing: it frees the VR PC for the next tablet. See "Several tablets, two bikes". |

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

The plugin smooths the sensor for you: a start is only passed on after 0.3 s of
pedalling, a stop after 0.6 s without. So a flickering sensor no longer fills the
tablet's log, and each pedal event reaches the tablet that much after the change.

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

VR Link records gaze **by itself**. There is nothing to add: it starts and stops
with the session and writes `{SessionId}_gaze.csv`.

**Do not add a Gaze Recorder component to your pawn.** Earlier versions of this
README said to, and then two recorders wrote every row twice into the same file. If
your pawn has one, remove it. Until you do, the extra one stays idle and says so in
the headset: "A second Gaze Recorder ... stays idle".

There is no need to tag objects. The heat map uses the point in the world where
the participant's view lands. When they look at the sky or an open street, that
row has no position, which is normal.

Without eye tracking, the recorder follows the direction of the **head**. With a
headset that tracks the **eyes**, it follows the eyes instead, which is much more
precise. It switches by itself: every row says which one it used, `head` or `eye`,
in the `Source` column.

### What is in the gaze file

One row per frame (up to 60 a second). The columns that matter:

| Column | What it says |
|---|---|
| `Source` | `eye` when the eye tracker gave the direction, `head` when the head did. |
| `Valid` | `0` when the eye tracker was tracking but lost this sample, for example during a blink. The row then has the head direction. Otherwise `1`. |
| `HeadX/Y/Z` | Where the head was, in centimetres. |
| `DirX/Y/Z` | The direction of the look: the eyes on `eye` rows, the head on `head` rows. |
| `HitX/Y/Z` | Where the look landed. Empty when it landed on nothing (sky, open street). |
| `Scene` | The location at that moment. |
| `HeadQuatX/Y/Z/W` | Which way the head faced, on `eye` rows only, so a head turn can be told from an eye movement. Empty on `head` rows. |

The tablet's event log also gets two marks from the gaze side:

- `gazeformat:2` at the start, which says the file has the columns above.
- `route:reset` whenever the participant is moved more than 10 m at once (a new
  level, a respawn, a route restart). You do not need to send it yourself.

### Eye tracking setup (HTC VIVE Focus Vision)

Nothing changes in VR Link. The eye data only has to reach Unreal:

1. **Headset:** Settings > Eye tracking. Turn it on and run the calibration.
   Calibration is personal, so repeat it for each participant if there is time.
2. **PC:** stream the headset with **VIVE Streaming** in **VIVE Hub**. Make VIVE
   the active OpenXR runtime on the PC (not SteamVR), and switch on eye tracking
   in VIVE Hub's streaming settings if it offers the option.
3. **Unreal:** Edit > Plugins, enable **OpenXR** and **OpenXR Eye Tracker**, then
   restart the editor.
4. **Gaze Recorder:** leave **Prefer Eye Tracking** ticked (it is by default).

### Check that it really works

Do one test ride and check all four:

| Check | Working | Not working |
|---|---|---|
| Message in the headset at the start | Green: *Eye tracking active* | Yellow: *No eye tracking* |
| Tablet's `_events.csv` | `eyetracker:present` | `eyetracker:absent` |
| `Source` column in `_gaze.csv` | Mostly `eye` (a few `head` rows during blinks are normal) | Only `head` |
| Head still, look from a lamp post on the left to one on the right | `HitX/HitY/HitZ` jump between the two | They only change when you turn your head |

The last check is the one that proves it. In Blueprint, **Is Using Eye Tracking**
on the Gaze Recorder tells you the same thing live, for example to show a warning.

## Where the files are saved

- The **tablet** saves the brain data, events, session details and answers.
- The **VR PC** saves the gaze file in `Documents/MuseEEG/{Study}/Sessions/{date}/`,
  the same folder name as on the tablet.

Afterwards, copy the PC's files next to the tablet's. Files of one session start
with the same `SessionId`, so they find each other.

## Several tablets, two bikes

On test day there are more tablets than bikes. Each tablet uses a VR PC only for
the ride, then lets go of it, so the next participant can ride while the previous
one does the questionnaire and interview. You do not need to do anything for this
in your Blueprint: the plugin and the tablet handle it.

### How a day runs

1. The operator presses **Start a new session** on a tablet. The tablet finds a
   VR PC that is free and connects to it.
2. The participant rides. That VR PC now belongs to this tablet.
3. The ride ends. The tablet **lets go** of the VR PC and moves on to the
   questionnaire and interview, without VR.
4. Another tablet can now take that VR PC for the next participant.

### What a VR PC does when a tablet knocks

| Situation | What happens |
|---|---|
| No tablet connected | The tablet connects. |
| Another tablet is connected | The new tablet is told **"busy"** and turned away. It tries the other VR PC, or waits and tries again. The connected tablet is **never** knocked off. |
| A tablet is connected, another is being checked, and a third knocks; or a tablet answers slowly | The late one is told **"try again"** and dials again a moment later. |
| The same tablet connects again (its Wi-Fi dropped, the app restarted) | Its new connection replaces its old one, straight away. |
| The recording tablet lost Wi-Fi for a moment | It reconnects and gets its VR PC back. The ride carries on during the gap; what was sent meanwhile is not repeated. The VR PC also tells it which location and design are on (newer tablet versions show this). |
| A tablet with the wrong pairing code | It is refused and disconnected, so the VR PC stays free for its own tablet. |
| A tablet lets go after its ride | The VR PC is free immediately. |
| `Start Session` was called with no tablet connected | The ride starts anyway. The next tablet to connect joins it. |

Testing two tablets on one PC: they must be two real devices. Two copies of the
tablet app on the same computer share one network address, and the VR PC treats
them as one tablet reconnecting.

### Set up once

- **Any tablet on any free bike** (most rides per day): leave the pairing code
  **empty** in `Study Config` on both VR PCs, and turn the pairing code **off** on
  every tablet.
- **Fixed pairs** (a tablet always uses the same bike): give each VR PC its own
  pairing code in `Study Config`, and enter that code on its tablets.
- Give each VR PC a key for **`Release Tablet`** (see below). One line of Blueprint:
  a key press event calling `Release Tablet` on the VrLink Subsystem.

### When a VR PC stays "busy"

A tablet that crashes, runs out of battery or drops off Wi-Fi between rides may
not say goodbye, so the VR PC still thinks it is connected. Every other tablet
then gets "busy". (A tablet that closes the app or lets go normally frees the PC
at once.)

- A tablet with a current version of Primed Record checks in every few seconds.
  If it goes quiet for 20 seconds, the VR PC frees itself.
- Otherwise, press the **`Release Tablet`** key on that VR PC. A ride in progress
  is not stopped by this, and its own tablet can reconnect into it.

## Troubleshooting

| Problem | What to check |
|---|---|
| The tablet does not connect | Same network? Windows firewall: allow Unreal when it asks. The connection uses TCP port 3030. |
| A tablet says "VR PC in use" | Another tablet is using that VR PC. It is free again once that tablet's ride ends. If no tablet should be connected, press `Release Tablet`. See "Several tablets, two bikes". |
| `Start Session` with no tablet connected | Not a problem: the ride starts, and the next tablet to connect joins it. |
| A tablet connects to the wrong bike | Use fixed pairs. See "Several tablets, two bikes". |
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
