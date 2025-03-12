class CfgPatches
{
	class X18Editor
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts","Editor_Scripts" };
	};
};
class CfgMods
{
	class X18Editor
	{
		name = "X18Editor";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Editor/Scripts/Common","Noosphere/X18Editor/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Editor/Scripts/Common","Noosphere/X18Editor/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Editor/Scripts/Common","Noosphere/X18Editor/Scripts/5_Mission" };
			};
		};
	};
};