class CfgPatches
{
	class X18AnomaliesServer
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "X18Anomalies", "X18Events" };
	};
};
class CfgMods
{
	class X18AnomaliesServer
	{
		author = "MisterJ";
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Anomalies/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Anomalies/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Anomalies/Scripts/5_Mission" };
			};
		};
	};
};