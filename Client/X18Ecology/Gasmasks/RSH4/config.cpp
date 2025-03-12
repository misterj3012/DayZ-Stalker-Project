class CfgPatches
{
	class X18Ecology_GasMasks_RSH
	{
		units[] = { "X18_GasMask_RSH4","X18_GasMask_RSH4_Filter" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables", "DZ_AreaofDecay_Masks_RSH" };
	};
};
class CfgVehicles
{
	class RSH4_AoD_GasMask;
	class RSH4_AoD_GasMask_Filter_Base;
	class X18_GasMask_RSH4 : RSH4_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_RSH4";
		descriptionShort = "#GasMask_RSH4_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_rsh4_filter" };
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
	class X18_GasMask_RSH4_Filter_Base : RSH4_AoD_GasMask_Filter_Base
	{
		scope = 0;
		displayName = "#GasMask_RSH4_Filter";
		descriptionShort = "#GasMask_RSH4_Filter_DSC";
		inventorySlot[] = { "gasmask_rsh4_filter" };
		lootCategory = "Attachments";
		vehicleClass = "Clothing";
		weight = 210;
		itemSize[] = { 2,1 };
		repairableWithKits[] = { 5,2 };
		repairCosts[] = { 30,25 };
		heatIsolation = 0;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 20;
		varQuantityMin = 0.0;
		varQuantityMax = 20;
		varQuantityDestroyOnMin = 0;
		rotationFlags = 17;
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			energyStorageMax = 20;
			energyAtSpawn = 20;
			convertEnergyToQuantity = 1;
			reduceMaxEnergyByDamageCoef = 1;
			powerSocketsCount = 1;
			compatiblePlugTypes[] = { 1 };
		};
	};
	class X18_GasMask_RSH4_Filter : X18_GasMask_RSH4_Filter_Base
	{
		scope = 2;
	};
};
class CfgSlots
{
	class Slot_gasmask_rsh4_filter
	{
		name = "gasmask_rsh4_filter";
		displayName = "#GasMask_RSH4_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};