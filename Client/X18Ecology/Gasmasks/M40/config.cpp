class CfgPatches
{
	class X18Ecology_GasMasks_M40
	{
		units[] = { "X18_GasMask_M40","M40m2_AoD_GasMask","X18_GasMask_M40_Filter","M40_AoD_Balon_GasMask" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables", "DZ_ArmStalker_Masks_M40" };
	};
};
class CfgVehicles
{
	class M40_AoD_GasMask;
	class M40m2_AoD_GasMask;
	class M40_AoD_GasMask_Filter_Base;
	class M40_AoD_Balon_GasMask;
	class X18_GasMask_M40 : M40_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_M40";
		descriptionShort = "#GasMask_M40_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_m40_filter" };
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
	class X18_GasMask_M40M2 : M40m2_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_M40M2";
		descriptionShort = "#GasMask_M40M2_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_m40_filter" };
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
	class X18_GasMask_M40_Filter_Base : M40_AoD_GasMask_Filter_Base
	{
		scope = 0;
		displayName = "#GasMask_M40_Filter";
		descriptionShort = "#GasMask_M40_Filter_DSC";
		inventorySlot[] = { "gasmask_m40_filter" };
		lootCategory = "Attachments";
		vehicleClass = "Clothing";
		weight = 210;
		itemSize[] = { 2,1 };
		repairableWithKits[] = { 5,2 };
		repairCosts[] = { 30,25 };
		heatIsolation = 0;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 45;
		varQuantityMin = 0.0;
		varQuantityMax = 45;
		varQuantityDestroyOnMin = 0;
		rotationFlags = 17;
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			energyStorageMax = 45;
			energyAtSpawn = 45;
			convertEnergyToQuantity = 1;
			reduceMaxEnergyByDamageCoef = 1;
			powerSocketsCount = 1;
			compatiblePlugTypes[] = { 1 };
		};
	};
	class X18_GasMask_M40_Filter : X18_GasMask_M40_Filter_Base
	{
		scope = 2;
	};
	class X18_GasMask_M40_Balon : M40_AoD_Balon_GasMask
	{
		scope = 2;
		displayName = "#GasMask_M40_Balon";
		descriptionShort = "#GasMask_M40_Balon_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		rotationFlags = 2;
		weight = 730;
		itemSize[] = { 3,4 };
		heatIsolation = 0.5;
		noHelmet = 0;
		class Protection
		{
			biological = 1;
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
};
class CfgSlots
{
	class Slot_gasmask_m40_filter
	{
		name = "gasmask_m40_filter";
		displayName = "#GasMask_M40_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};