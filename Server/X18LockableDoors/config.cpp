class CfgPatches
{
	class X18LockableDoorsServer
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "X18LockableDoors" };
	};
};
class CfgMods
{
	class X18LockableDoorsServer
	{
		author = "MisterJ";
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18LockableDoors/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18LockableDoors/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18LockableDoors/Scripts/5_Mission" };
			};
		};
	};
};