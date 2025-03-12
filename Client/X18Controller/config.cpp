class CfgPatches
{
	class X18Controller
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "X18Mutants", "X18Psi" };
	};
};
class CfgMods
{
	class X18Controller
	{
		name = "X18Controller";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Controller/Scripts/Common", "Noosphere/X18Controller/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Controller/Scripts/Common", "Noosphere/X18Controller/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Controller/Scripts/Common", "Noosphere/X18Controller/Scripts/5_Mission" };
			};
		};
	};
};