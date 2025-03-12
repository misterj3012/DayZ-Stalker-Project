
#define _ARMA_

class CfgPatches
{
	class X18PersonalChestServer
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts","X18PersonalChest","DF_Scripts" };
	};
};
class CfgMods
{
	class X18PersonalChestServer
	{
		name = "X18PersonalChestServer";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18PersonalChest/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18PersonalChest/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18PersonalChest/Scripts/5_Mission" };
			};
		};
	};
};
