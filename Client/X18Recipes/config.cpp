class CfgPatches
{
	class X18Recipes
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "IMPGMOD", /*"mmg_storage",*/ "ModularVestSystem", "quadlock", "script_a" };
	};
};
class CfgMods
{
	class X18Recipes
	{
		name = "X18Recipes";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Recipes/Scripts/Common", "Noosphere/X18Recipes/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Recipes/Scripts/Common", "Noosphere/X18Recipes/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Recipes/Scripts/Common", "Noosphere/X18Recipes/Scripts/5_Mission" };
			};
		};
	};
};