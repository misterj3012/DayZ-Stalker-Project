class CfgPatches
{
	class X18Clothing
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"X18CoreScripts"};
	};
};
class CfgMods
{
	class X18Clothing
	{
		name = "X18Clothing";
		author = "MisterJ";
		version = "1.0";
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Clothing/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Clothing/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Clothing/Scripts/5_Mission" };
			};
		};
	};
};