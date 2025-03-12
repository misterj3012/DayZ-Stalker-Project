class CfgPatches
{
	class X18Ecology_GasMasks_M50
	{
		units[] = { "X18_GasMask_M50","M50_AoD_Camo_GasMask","X18_GasMask_M50_Filter_Left","X18_GasMask_M50_Filter_Right","X18_GasMask_M50M2","X18_GasMask_M50M2_Filter_Left","X18_GasMask_M50M2_Filter_Right","X18_GasMask_M50CBRN","M50cbrn_AoD_SMG_GasMask","X18_GasMask_M50CBRN_Filter_Left","X18_GasMask_M50CBRN_Filter_Right" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables", "DZ_AreafDecay_Masks_M50" };
	};
};
class CfgVehicles
{
	class M50_AoD_GasMask;
	class M50_AoD_Camo_GasMask;
	class M50_AoD_GasMask_Filter_Left;
	class M50m2_AoD_GasMask;
	class M50m2_AoD_GasMask_Filter_Left;
	class M50cbrn_AoD_GasMask;
	class M50cbrn_AoD_SMG_GasMask;
	class M50cbrn_AoD_GasMask_Filter_Left;
	class X18_GasMask_M50 : M50_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_M50";
		descriptionShort = "#GasMask_M50_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_m50_filter_L" };
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
	class X18_GasMask_M50_Camo : M50_AoD_Camo_GasMask
	{
		scope = 2;
		displayName = "#GasMask_M50";
		descriptionShort = "#GasMask_M50_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_m50_filter_L" };
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
	class X18_GasMask_M50_Filter : M50_AoD_GasMask_Filter_Left
	{
		scope = 2;
		displayName = "#GasMask_M50_Filter";
		descriptionShort = "#GasMask_M50_Filter_DSC";
		inventorySlot[] = { "gasmask_m50_filter_L" };
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
	class X18_GasMask_M50M2 : M50m2_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_M50M2";
		descriptionShort = "#GasMask_M50M2_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_m50m2_filter_L" };
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
	class X18_GasMask_M50M2_Filter : M50m2_AoD_GasMask_Filter_Left
	{
		scope = 2;
		displayName = "#GasMask_M50M2_Filter";
		descriptionShort = "#GasMask_M50M2_Filter_DSC";
		inventorySlot[] = { "gasmask_m50m2_filter_L" };
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
	class X18_GasMask_M50CBRN : M50cbrn_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_M50CBRN";
		descriptionShort = "#GasMask_M50CBRN_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_m50cbrn_filter_L" };
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
	class X18_GasMask_M50CBRN_SMG : M50cbrn_AoD_SMG_GasMask
	{
		scope = 2;
		displayName = "#GasMask_M50CBRN";
		descriptionShort = "#GasMask_M50CBRN_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_m50cbrn_filter_L" };
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
	class X18_GasMask_M50CBRN_Filter : M50cbrn_AoD_GasMask_Filter_Left
	{
		scope = 2;
		displayName = "#GasMask_M50CBRN_Filter";
		descriptionShort = "#GasMask_M50CBRN_Filter_DSC";
		inventorySlot[] = { "gasmask_m50cbrn_filter_L" };
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
};
class CfgSlots
{
	class Slot_gasmask_m50_filter_L
	{
		name = "gasmask_m50_filter_L";
		displayName = "#GasMask_M50_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
	class Slot_gasmask_m50m2_filter_L
	{
		name = "gasmask_m50m2_filter_L";
		displayName = "#GasMask_M50M2_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
	class Slot_gasmask_m50cbrn_filter_L
	{
		name = "gasmask_m50cbrn_filter_L";
		displayName = "#GasMask_M50CBRN_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};