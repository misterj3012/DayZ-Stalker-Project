class CfgPatches
{
	class X18PDAServer
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18ScriptsServer", "X18PDA", "X18DiscordServer", "X18PlayerExtensionServer", "JM_COT_Scripts" };
	};
};
class CfgMods
{
	class X18PDAServer
	{
		name = "X18PDAServer";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18PDA/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18PDA/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18PDA/Scripts/5_Mission" };
			};
		};
	};
};