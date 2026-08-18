using UnrealBuildTool;

public class VrLink : ModuleRules
{
	public VrLink(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "Networking", "Sockets", "Json"
		});
	}
}
