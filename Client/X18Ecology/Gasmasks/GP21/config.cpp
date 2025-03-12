class CfgPatches
{
	class X18Ecology_GasMasks_GP21
	{
		units[] = { "X18_GasMask_GP21","X18_GasMask_GP21_Filter" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables", "DZ_AreaofDecay_Masks_GP21" };
	};
};
class CfgVehicles
{
	class GP21_AoD_GasMask;
	class GP21_AoD_GasMask_Filter_Base;
	class X18_GasMask_GP21 : GP21_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_GP21";
		descriptionShort = "#GasMask_GP21_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_gp21_filter_L" };
		rotationFlags = 2;
		weight = 730;
		itemSize[] = { 3,4 };
		heatIsolation = 0.5;
		noHelmet = 0;
		class EnergyManager
		{
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			plugType = 1;
			attachmentAction = 1;
			wetnessExposure = 0.1;
			updateInterval = 1;
		};
		class Protection
		{
			biological = 1;
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class X18_GasMask_GP21_Filter_Base : GP21_AoD_GasMask_Filter_Base
	{
		scope = 0;
		displayName = "#GasMask_GP21_Filter";
		descriptionShort = "#GasMask_GP21_Filter_DSC";
		inventorySlot[] = { "gasmask_gp21_filter_L" };
		lootCategory = "Attachments";
		vehicleClass = "Clothing";
		weight = 210;
		itemSize[] = { 2,1 };
		repairableWithKits[] = { 5,2 };
		repairCosts[] = { 30,25 };
		heatIsolation = 0;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 40;
		varQuantityMin = 0.0;
		varQuantityMax = 40;
		varQuantityDestroyOnMin = 0;
		rotationFlags = 17;
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			energyStorageMax = 40;
			energyAtSpawn = 40;
			convertEnergyToQuantity = 1;
			reduceMaxEnergyByDamageCoef = 1;
			powerSocketsCount = 1;
			compatiblePlugTypes[] = { 1 };
		};
	};
	class X18_GasMask_GP21_Filter : X18_GasMask_GP21_Filter_Base
	{
		scope = 2;
	};
};
class CfgSlots
{
	class Slot_Left_GasMask_GP21_Filter
	{
		name = "Left_GasMask_GP21_Filter";
		displayName = "#GasMask_GP21_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};