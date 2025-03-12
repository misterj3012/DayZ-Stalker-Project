class CfgPatches
{
	class X18PlayerExtensionServer
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "X18PlayerExtension" };
	};
};
class CfgMods
{
	class X18PlayerExtensionServer
	{
		name = "X18PlayerExtensionServer";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18PlayerExtension/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18PlayerExtension/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18PlayerExtension/Scripts/5_Mission" };
			};
		};
	};
};