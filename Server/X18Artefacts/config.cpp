class CfgPatches
{
	class X18ArtefactsServer
	{
		units[] = {};
		ammo[] = {};
		weapons[] = {};
		magazines[] = {};
		requiredVersion = 1.6;
		requiredAddons[] = { "X18CoreScripts", "X18Artefacts" };
	};
};
class CfgMods
{
	class X18ArtefactsServer
	{
		author = "MisterJ";
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Artefacts/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Artefacts/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Artefacts/Scripts/5_Mission" };
			};
		};
	};
};