# VR Link — Unreal plugin

Connects an Unreal experience to the Neural Recorder tablet (the Muse EEG app).
The plugin handles the network link, the session lifecycle, scene and scenario
events, and gaze recording. You call it from Blueprint; nothing else changes.

Built against **Unreal Engine 5.8**. It depends only on stock engine modules
(`Core`, `CoreUObject`, `Engine`, `InputCore`, `Networking`, `Sockets`, `Json`),
so there is nothing else to install.

## Install

1. Copy the `VrLink` folder into your project's `Plugins/` folder, so you end up
   with `YourProject/Plugins/VrLink/VrLink.uplugin`. Create `Plugins/` if it is
   not there.
2. Right-click your `.uproject` → **Generate Visual Studio project files**.
3. Open the project. Unreal will offer to rebuild the missing module — say yes.
   That takes a minute or two the first time.

The plugin is enabled by default, so there is no checkbox to find.

There are deliberately no `Binaries/` or `Intermediate/` folders in this zip.
Those are compiled output from one machine and one engine build; shipping them
causes version mismatches that look like plugin bugs. Unreal regenerates both.

## Use it from Blueprint

Every node lives on the **VrLink Subsystem**. In any Blueprint, drag off and
search for the node name — no actor to place, no reference to wire up.

| Node | When to call it | What it does |
|---|---|---|
| `Initialize Vr Link` | Once, on level start | Names the project and finds the tablet on the LAN |
| `Start Session` | When the ride begins | Tells the tablet to start recording |
| `Set Location` | On entering each area | Writes a `scene` row — **where** they are |
| `Set Scenario` | When the design variant changes | Writes a `variable` row — **which design** is showing |
| `Send Mark` | Anything worth flagging | A timestamped note in the log |
| `End Session` | When the ride finishes | Stops the recording cleanly |
| `Is Session Active` | Any time | True while recording |
| `Send Baseline Phase` | **Required** — four calls before the ride | Marks the relaxed and stressed windows — see below |

### The one thing that matters most

**`Set Location` and `Set Scenario` are not interchangeable.**

- `Set Location` = *where the rider is*: "Location 1", "Spaklerweg north".
- `Set Scenario` = *which design they are being shown*: "Green facade", "Grey facade".

The analysis compares designs **within** a location, so it needs both, kept
separate. If the design variant is sent as a location, the report ends up
comparing two streets instead of two designs and the study cannot answer its
own question.

### One session per ride, not per trigger

Call `Start Session` once when the rider sets off and `End Session` once when
they finish, then use `Set Location` / `Set Scenario` on your existing trigger
volumes as they ride through.

Do not start and stop a session at each trigger. Every session needs its own
calibration baseline to be interpretable, and each one also prompts the
participant for a questionnaire — so ten sessions per rider means ten
questionnaires and ten uncalibrated fragments.

### The baseline is two phases, not one

Calibration records the participant **relaxed** and then **stressed**. Both are
needed, and they do different jobs:

- The **relaxed** window is the reference. Every later value is expressed as a
  difference from it, so without it a recording cannot be compared to anyone
  else's at all.
- The **stressed** window is the only thing that produces the
  `BaselineMin_/BaselineMax_` values in `session.csv`. Those are how the
  analysis tells a quiet person's genuine reaction from background noise —
  without them, a naturally muted responder reads as "no reaction to anything",
  which is the wrong answer, not a missing one.

**The VR side has to drive this, and for this study that means you.** The tablet
times how *long* calibration runs, but it has no stressed phase of its own — a
stressed window only ever exists because the VR experience declared it. Left to
the tablet alone, the range spans rest only and the stressed half never happens.

The node takes a phase name **and a start/end boolean**, so it is four calls, not
two, before the ride begins:

```
Send Baseline Phase ("relaxed",  bStart = true)    <- calibration begins
Send Baseline Phase ("relaxed",  bStart = false)
Send Baseline Phase ("stressed", bStart = true)
Send Baseline Phase ("stressed", bStart = false)   <- ride can start
```

**Send `relaxed` before `stressed`.** The recorder closes the calibration window
at the first exit from a rest phase, so the order is not cosmetic — reversed, the
window lands in the wrong place and every later number is referenced to the
wrong thing.

**If the stressed phase never runs, nothing will error.** The recording is still
written and looks perfectly normal; the min/max range is just narrow and close to
useless, and nobody finds out until the analysis. If you are driving the phases
yourself, this is the one to double-check.

## Gaze recording (optional)

Add the **Gaze Recorder** component to your VR pawn and it writes
`{SessionId}_gaze.csv` alongside the tablet's files: what the participant looked
at, where it was in the world, and which scene was active.

It follows the session on its own — it starts writing when a session starts and
stops when it ends, so there is nothing to call. It only records while a session
is active.

For the "what did they look at" column to be useful, **tag the actors that
matter** (`Trees`, `Green facade`, `Bike lane`). The recorder writes an actor's
first Tag if it has one, and falls back to the object name (`StaticMeshActor_12`)
if it does not. Untagged scenery still records, it is just harder to read.

## Where the files land

The tablet writes `{SessionId}_eeg.csv`, `_events.csv` and `_session.csv`. The PC
writes `{SessionId}_gaze.csv`. They are separate machines, so the files are
paired later by the shared `SessionId` prefix — nothing needs to be synced
during the session.

## If it does not connect

- The tablet and the PC must be on the same network. Discovery is UDP broadcast
  on port 47800; the link itself is TCP on port 3030.
- `Is Session Active` returning false after `Start Session` means the handshake
  did not complete — usually a firewall prompt on the PC that was dismissed.
- With several stations in one room, set a matching pairing code on the tablet
  and its VR station so they do not cross-connect.

Questions to Waleed.
