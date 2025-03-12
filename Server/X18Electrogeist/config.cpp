class CfgPatches
{
	class X18ElectrogeistServer
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "X18Electrogeist" };
	};
};
class CfgMods
{
	class X18ElectrogeistServer
	{
		name = "X18ElectrogeistServer";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Electrogeist/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Electrogeist/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "CConsciousness/X18Electrogeist/Scripts/5_Mission" };
			};
		};
	};
};
class CfgAmmo
{
	class Electrogeist_Damage
	{
		hit = 2;
		indirectHit = 0;
		indirectHitRange = 0;
		model = "shotShell";
		affectSkeleton = 1;
		caliber = 0.1;
		deflecting = 0;
		class DamageApplied
		{
			type = "FP";
			class Health
			{
				damage = 15;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 0;
			};
		};
		class NoiseHit
		{
			strength = 10;
			type = "sound";
		};
	};
};