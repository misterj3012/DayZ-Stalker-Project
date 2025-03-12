class CfgPatches
{
	class DZ_Gear_Consumables
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Battery9V : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Battery9V0";
		descriptionShort = "$STR_CfgVehicles_Battery9V1";
		model = "\dz\gear\consumables\9v_battery.p3d";
		isMeleeWeapon = 1;
		weight = 10;
		absorbency = 0.8;
		itemSize[] = { 1,1 };
		stackedUnit = "w";
		quantityBar = 1;
		varQuantityInit = 50;
		varQuantityMin = 0.0;
		varQuantityMax = 50;
		varQuantityDestroyOnMin = 0;
		inventorySlot[] = { "BatteryD" };
		rotationFlags = 17;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Electronics\Data\9v_co.paa" };
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			energyStorageMax = 50;
			energyAtSpawn = 50;
			convertEnergyToQuantity = 1;
			reduceMaxEnergyByDamageCoef = 1;
			powerSocketsCount = 1;
			compatiblePlugTypes[] = { 1 };
		};
		class AnimationSources
		{
			class cover
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = { {1.0,{"DZ\gear\consumables\data\9v.rvmat"}},{0.7,{"DZ\gear\consumables\data\9v.rvmat"}},{0.5,{"DZ\gear\consumables\data\9v_damage.rvmat"}},{0.3,{"DZ\gear\consumables\data\9v_damage.rvmat"}},{0.0,{"DZ\gear\consumables\data\9v_destruct.rvmat"}} };
				};
			};
		};
	};
	class Battery12V : Battery9V
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Battery12V0";
		descriptionShort = "$STR_CfgVehicles_Battery12V1";
		isMeleeWeapon = 1;
		weight = 10;
		absorbency = 0.8;
		itemSize[] = { 1,1 };
		stackedUnit = "w";
		quantityBar = 1;
		varQuantityInit = 100;
		varQuantityMin = 0.0;
		varQuantityMax = 100;
		varQuantityDestroyOnMin = 0;
		inventorySlot[] = { "BatteryD" };
		rotationFlags = 17;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Electronics\Data\12v_co.paa" };
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			energyStorageMax = 100;
			energyAtSpawn = 100;
			convertEnergyToQuantity = 1;
			reduceMaxEnergyByDamageCoef = 1;
			powerSocketsCount = 1;
			compatiblePlugTypes[] = { 1 };
		};
		class AnimationSources
		{
			class cover
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = { {1.0,{"DZ\gear\consumables\data\9v.rvmat"}},{0.7,{"DZ\gear\consumables\data\9v.rvmat"}},{0.5,{"DZ\gear\consumables\data\9v_damage.rvmat"}},{0.3,{"DZ\gear\consumables\data\9v_damage.rvmat"}},{0.0,{"DZ\gear\consumables\data\9v_destruct.rvmat"}} };
				};
			};
		};
	};
	class Battery15V : Battery9V
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Battery15V0";
		descriptionShort = "$STR_CfgVehicles_Battery15V1";
		isMeleeWeapon = 1;
		weight = 10;
		absorbency = 0.8;
		itemSize[] = { 1,1 };
		stackedUnit = "w";
		quantityBar = 1;
		varQuantityInit = 150;
		varQuantityMin = 0.0;
		varQuantityMax = 150;
		varQuantityDestroyOnMin = 0;
		inventorySlot[] = { "BatteryD" };
		rotationFlags = 17;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Electronics\Data\15v_co.paa" };
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			energyStorageMax = 150;
			energyAtSpawn = 150;
			convertEnergyToQuantity = 1;
			reduceMaxEnergyByDamageCoef = 1;
			powerSocketsCount = 1;
			compatiblePlugTypes[] = { 1 };
		};
		class AnimationSources
		{
			class cover
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = { {1.0,{"DZ\gear\consumables\data\9v.rvmat"}},{0.7,{"DZ\gear\consumables\data\9v.rvmat"}},{0.5,{"DZ\gear\consumables\data\9v_damage.rvmat"}},{0.3,{"DZ\gear\consumables\data\9v_damage.rvmat"}},{0.0,{"DZ\gear\consumables\data\9v_destruct.rvmat"}} };
				};
			};
		};
	};
};