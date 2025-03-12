class CfgPatches
{
	class DZ_Gear_Camping
	{
		units[] = { "TentMedium_Packed","TentMedium_Pitched" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Camping" };
	};
};
class CfgVehicles
{
	class Flag_Base;
	class Inventory_Base;
	class X18_Flagpole : Inventory_Base
	{
		scope = 2;
		model = "\DZ\gear\camping\territory_flag.p3d";
		carveNavmesh = 1;
		displayName = "Flagpole";
		rotationFlags = 2;
		descriptionShort = "Territory Flagpole.";
		attachments[] = { "Material_FPole_Flag" };
		weight = 9999999;
		itemSize[] = { 1,3 };
	};
	class Flag_Bandits : Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Items\Gear\Camping\Flags\Data\flag_bandits_co.paa" };
	};
	class Flag_ClearSky : Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Items\Gear\Camping\Flags\Data\flag_clearsky_co.paa" };
	};
	class Flag_Duty : Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Items\Gear\Camping\Flags\Data\flag_duty_co.paa" };
	};
	class Flag_Ecologists : Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Items\Gear\Camping\Flags\Data\flag_ecologists_co.paa" };
	};
	class Flag_Freedom : Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Items\Gear\Camping\Flags\Data\flag_freedom_co.paa" };
	};
	class Flag_ISG : Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Items\Gear\Camping\Flags\Data\flag_isg_co.paa" };
	};
	class Flag_Mercenary : Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Items\Gear\Camping\Flags\Data\flag_mercenary_co.paa" };
	};
	class Flag_Military : Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Items\Gear\Camping\Flags\Data\flag_military_co.paa" };
	};
	class Flag_Monolith : Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Items\Gear\Camping\Flags\Data\flag_monolith_co.paa" };
	};
};