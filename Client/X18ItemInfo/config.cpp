class CfgPatches
{
	class X18ItemInfo
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18ItemInfo
	{
		name = "X18ItemInfo";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18ItemInfo/Scripts/Common", "Noosphere/X18ItemInfo/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18ItemInfo/Scripts/Common", "Noosphere/X18ItemInfo/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18ItemInfo/Scripts/Common", "Noosphere/X18ItemInfo/Scripts/5_Mission" };
			};
		};
	};
};