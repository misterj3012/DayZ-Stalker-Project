class CfgPatches
{
	class X18DayZ
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18DayZ
	{
		name = "X18DayZ";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18DayZ/Scripts/Common", "Noosphere/X18DayZ/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18DayZ/Scripts/Common", "Noosphere/X18DayZ/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18DayZ/Scripts/Common", "Noosphere/X18DayZ/Scripts/5_Mission" };
			};
		};
	};
};