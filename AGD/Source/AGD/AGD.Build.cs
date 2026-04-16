// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AGD : ModuleRules
{
	public AGD(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"AGD",
			"AGD/Variant_Platforming",
			"AGD/Variant_Platforming/Animation",
			"AGD/Variant_Combat",
			"AGD/Variant_Combat/AI",
			"AGD/Variant_Combat/Animation",
			"AGD/Variant_Combat/Gameplay",
			"AGD/Variant_Combat/Interfaces",
			"AGD/Variant_Combat/UI",
			"AGD/Variant_SideScrolling",
			"AGD/Variant_SideScrolling/AI",
			"AGD/Variant_SideScrolling/Gameplay",
			"AGD/Variant_SideScrolling/Interfaces",
			"AGD/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
