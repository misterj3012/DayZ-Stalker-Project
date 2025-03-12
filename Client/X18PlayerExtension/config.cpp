class CfgPatches
{
	class X18PlayerExtension
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18PlayerExtension
	{
		name = "X18PlayerExtension";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18PlayerExtension/Scripts/Common", "Noosphere/X18PlayerExtension/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18PlayerExtension/Scripts/Common", "Noosphere/X18PlayerExtension/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18PlayerExtension/Scripts/Common", "Noosphere/X18PlayerExtension/Scripts/5_Mission" };
			};
		};
	};
};