using UnrealBuildTool;

public class VrLink : ModuleRules
{
	public VrLink(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "Networking", "Sockets", "Json",
			// Engine-level eye tracking. Device-agnostic: whichever runtime the
			// headset ships (OpenXR, SRanipal, Vive) implements IEyeTracker, and
			// this asks the engine rather than any one vendor's SDK. Costs
			// nothing on a headset without eye tracking -- IsEyeTrackerConnected
			// simply returns false and the gaze ray stays the head ray.
			"EyeTracker"
		});
	}
}
