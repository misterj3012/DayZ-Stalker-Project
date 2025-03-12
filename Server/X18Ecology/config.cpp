class CfgPatches
{
	class X18EcologyServer
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "X18Ecology", "X18MedicalServer" };
	};
};
class CfgMods
{
	class X18EcologyServer
	{
		author = "MisterJ";
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Ecology/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Ecology/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Ecology/Scripts/5_Mission" };
			};
		};
	};
};