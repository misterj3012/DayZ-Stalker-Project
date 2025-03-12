class CfgPatches
{
	class X18Sounds
	{
		name = "X18Sounds";

		requiredVersion = 1.60;
		requiredAddons[] = { "X18CoreScripts" };
		units[] = {};
		weapons[] = {};
	};
};
class CfgMods
{
	class X18Sounds
	{
		extra = 0;
		type = "mod";
		name = "X18Sounds";
		dependencies[] =
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] =
				{
					"Noosphere/X18Sounds/Scripts/Common",
					"Noosphere/X18Sounds/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] =
				{
					"Noosphere/X18Sounds/Scripts/Common",
					"Noosphere/X18Sounds/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] =
				{
					"Noosphere/X18Sounds/Scripts/Common",
					"Noosphere/X18Sounds/Scripts/5_Mission"
				};
			};
		};
	};
};