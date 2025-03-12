class CfgPatches
{
	class X18Items
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Gear_Navigation", "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18Items
	{
		dir = "X18Items";
		name = "X18Items";
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Items/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Items/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Items/Scripts/5_Mission" };
			};
		};
	};
};