class CfgPatches
{
	class X18Ambient
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18Ambient
	{
		name = "X18Ambient";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Ambient/Scripts/Common", "Noosphere/X18Ambient/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Ambient/Scripts/Common", "Noosphere/X18Ambient/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Ambient/Scripts/Common", "Noosphere/X18Ambient/Scripts/5_Mission" };
			};
		};
	};
};