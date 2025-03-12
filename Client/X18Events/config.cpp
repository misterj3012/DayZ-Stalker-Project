class CfgPatches
{
	class X18Events
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "X18SoundManager", "DF_Scripts" };
	};
};
class CfgMods
{
	class X18Events
	{
		name = "X18Events";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Events/Scripts/Common", "Noosphere/X18Events/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Events/Scripts/Common", "Noosphere/X18Events/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Events/Scripts/Common", "Noosphere/X18Events/Scripts/5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class ThunderBolt : HouseNoDestruct
	{
		model = "\dz\data\data\blesk1.p3d";
	};
	class ThunderBoltHeavy : HouseNoDestruct
	{
		model = "\dz\data\data\blesk2.p3d";
	};
};