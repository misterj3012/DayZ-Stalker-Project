class CfgPatches
{
	class X18Ecology_GasMasks_CM7
	{
		units[] = { "X18_GasMask_CM7","X18_GasMask_CM7_Filter" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables", "DZ_AreaofDecay_Masks_CM7" };
	};
};
class CfgVehicles
{
	class CM7_AoD_GasMask;
	class CM7_AoD_GasMask_Filter_Base;
	class X18_GasMask_CM7 : CM7_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_CM7";
		descriptionShort = "#GasMask_CM7_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_cm7_filter_L" };
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
	class X18_GasMask_CM7_Filter_Base : CM7_AoD_GasMask_Filter_Base
	{
		scope = 0;
		displayName = "#GasMask_CM7_Filter";
		descriptionShort = "#GasMask_CM7_Filter_DSC";
		inventorySlot[] = { "gasmask_cm7_filter_L" };
		lootCategory = "Attachments";
		vehicleClass = "Clothing";
		weight = 210;
		itemSize[] = { 2,1 };
		repairableWithKits[] = { 5,2 };
		repairCosts[] = { 30,25 };
		heatIsolation = 0;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 30;
		varQuantityMin = 0.0;
		varQuantityMax = 30;
		varQuantityDestroyOnMin = 0;
		rotationFlags = 17;
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			energyStorageMax = 30;
			energyAtSpawn = 30;
			convertEnergyToQuantity = 1;
			reduceMaxEnergyByDamageCoef = 1;
			powerSocketsCount = 1;
			compatiblePlugTypes[] = { 1 };
		};
	};
	class X18_GasMask_CM7_Filter : X18_GasMask_CM7_Filter_Base
	{
		scope = 2;
		inventorySlot[] = { "gasmask_cm7_filter_L" };
	};
};
class CfgSlots
{
	class Slot_gasmask_cm7_filter_L
	{
		name = "gasmask_cm7_filter_L";
		displayName = "#GasMask_CM7_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};