class CfgPatches
{
	class X18EventsServer
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "X18Events", };
	};
};
class CfgMods
{
	class X18EventsServer
	{
		name = "X18EventsServer";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Events/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Events/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Events/Scripts/5_Mission" };
			};
		};
	};
};