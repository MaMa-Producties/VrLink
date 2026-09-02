# VR Link, Unreal plugin (UE 5.6)

Connects an Unreal experience to the Neural Recorder tablet (the Muse EEG app).
The plugin handles the network link, the session lifecycle, scene and scenario
events, and gaze recording. You call it from Blueprint and nothing else changes.

Built against **Unreal Engine 5.6**. It only uses stock engine modules (`Core`,
`CoreUObject`, `Engine`, `InputCore`, `Networking`, `Sockets`, `Json`), so there
is nothing else to install.

## Install

**This is a packaged plugin. It ships precompiled, so your project does not need
to be a C++ project and you do not need a compiler.**

1. Copy the `VrLink` folder into your project's `Plugins/` folder, so you end up
   with `YourProject/Plugins/VrLink/VrLink.uplugin`. Create `Plugins/` if it is
   not there.
2. Open the project.

That is the whole install. Do **not** generate Visual Studio project files and
do not convert the project to C++. If Unreal offers to rebuild the module,
something is off, see the note below.

The plugin is enabled by default, so there is no checkbox to find.

### Getting updates

`git pull` in the `VrLink` folder, then restart the editor. Releases are tagged,
so `git tag` shows you what you are on.

### If Unreal asks to rebuild the module

That means the precompiled binary does not match your engine. Almost always it
is one of two things:

- You are not on **5.8**. The binary is tied to that version. Switch to the
  branch for your engine and the binary matches:

      git checkout ue5.6      # Unreal Engine 5.6
      git checkout ue5.7      # Unreal Engine 5.7
      git checkout master     # Unreal Engine 5.8

  Same source on every branch, only the compiled binary differs.
- You are on a **source build** of the engine rather than the launcher build.
  Binaries are tied to a specific engine build ID, and the two do not match.

In either case, tell us which engine you are on and we will build against it.
Rebuilding from source works too, but that is the thing this repo exists to
save you from.

## Use it from Blueprint

Every node lives on the **VrLink Subsystem**. In any Blueprint, drag off and
search for the node name. There is no actor to place and no reference to wire up.

| Node | When to call it | What it does |
|---|---|---|
| `Initialize Vr Link` | Once, on level start | Names the project and finds the tablet on the LAN |
| `Start Session` | When the ride begins | Tells the tablet to start recording |
| `Set Location` | On entering each area | Writes a `scene` row, meaning **where** they are |
| `Start Scenario` | When a design goes on display | Writes a `variable` row, meaning **which design** is showing |
| `End Scenario` | When a design stops being shown | Everything until the next design is ignored by the analysis |
| `Send Mark` | Anything worth flagging | A timestamped note in the log |
| `End Session` | When the ride finishes | Stops the recording cleanly |
| `Is Session Active` | Any time | True while recording |
| `Start Baseline` | **Required**, before the ride | Opens a calibration phase, see below |
| `End Baseline` | **Required**, closes each phase | Closes the phase of the same name |

### The one thing that matters most

**`Set Location` and `Start Scenario` are not interchangeable.**

- `Set Location` is *where the participant is*: "Location 1", "Spaklerweg north".
- `Start Scenario` is *which design they are being shown*: "Green facade", "Grey facade".

The analysis compares designs **within** a location, so it needs both, kept
separate. If the design variant is sent as a location, the report ends up
comparing two streets instead of two designs, and the study cannot answer its
own question.

### A whole run

```
Start Session
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

**Call `End Scenario` every time a design stops being shown**, even when another
one follows it straight away. Everything between it and the next `Start Scenario`
or `Set Location` is thrown away by the analysis: transitions, corridors, a fade
to black. That stretch has no design in it, and left unmarked it is credited to
the design that just ended.

This matters for gaze as much as for the EEG. Between two designs the head is
still pointing at something, and those rays would otherwise be counted as
somebody looking at the design that has already gone.

### One session per ride, not per trigger

Call `Start Session` once when the participant sets off and `End Session` once when
they finish, then use `Set Location` and `Start Scenario` on your existing trigger
volumes as they ride through.

Do not start and stop a session at each trigger. Every session needs its own
calibration baseline to be interpretable, and each one also prompts the
participant for a questionnaire, so ten sessions per participant means ten
questionnaires and ten uncalibrated fragments.

### The baseline is two phases, not one

Calibration records the participant **relaxed** and then **stressed**. Both are
needed, and they do different jobs:

- The **relaxed** window is the reference. Every later value is expressed as a
  difference from it, so without it a recording cannot be compared to anyone
  else's at all.
- The **stressed** window is the only thing that produces the
  `BaselineMin_/BaselineMax_` values in `session.csv`. Those are how the
  analysis tells a quiet person's genuine reaction from background noise.
  Without them, a naturally muted responder reads as "no reaction to anything",
  which is the wrong answer rather than a missing one.

**The VR side has to drive this, and for this study that means you.** The tablet
times how *long* calibration runs, but it has no stressed phase of its own. A
stressed window only ever exists because the VR experience declared it. Left to
the tablet alone, the range spans rest only and the stressed half never happens.

Each phase is opened and closed, so it is four calls rather than two, before
the ride begins:

```
Start Baseline (Relaxed)     <- calibration begins
End Baseline   (Relaxed)
Start Baseline (Stressed)
End Baseline   (Stressed)    <- ride can start
```

**Do `Relaxed` before `Stressed`.** The recorder closes the calibration window
at the first exit from a rest phase, so the order is not cosmetic. Reversed, the
window lands in the wrong place and every later number is referenced to the
wrong thing.

**If the stressed phase never runs, nothing will error.** The recording is still
written and looks perfectly normal. The min/max range is just narrow and close
to useless, and nobody finds out until the analysis. If you are driving the
phases yourself, this is the one to double-check.

## Gaze recording (optional)

Add the **Gaze Recorder** component to your VR pawn and it writes
`{SessionId}_gaze.csv` alongside the tablet's files: what the participant looked
at, where it was in the world, and which scene was active.

It follows the session on its own. It starts writing when a session starts and
stops when it ends, so there is nothing to call. It only records while a session
is active.

For the "what did they look at" column to be useful, **tag the actors that
matter** (`Trees`, `Green facade`, `Bike lane`). The recorder writes an actor's
first Tag if it has one, and falls back to the object name
(`StaticMeshActor_12`) if it does not. Untagged scenery still records, it is
just harder to read.

## Where the files land

The tablet writes `{SessionId}_eeg.csv`, `_events.csv` and `_session.csv`. The PC
writes `{SessionId}_gaze.csv`. They are separate machines, so the files are
paired later by the shared `SessionId` prefix. Nothing needs to be synced during
the session.

## If it does not connect

- The tablet and the PC must be on the same network. Discovery is UDP broadcast
  on port 47800, and the link itself is TCP on port 3030.
- `Is Session Active` returning false after `Start Session` means the handshake
  did not complete, usually a firewall prompt on the PC that was dismissed.
- With several stations in one room, set a matching pairing code on the tablet
  and its VR station so they do not cross-connect.

## What is in this repo

| Folder | Why it is here |
|---|---|
| `Source/` | The plugin source, for reference and for anyone who wants to rebuild |
| `Binaries/Win64/` | The precompiled editor DLL |
| `Intermediate/Build/` | Precompiled Game objects. **These are what let a Blueprint-only project package a build.** Do not delete them |

Questions to Waleed.
