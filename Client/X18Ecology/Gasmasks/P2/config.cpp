class CfgPatches
{
	class X18Ecology_GasMasks_P2
	{
		units[] = { "X18_GasMask_P2","X18_GasMask_P2_Black","X18_GasMask_P2_Duty","X18_GasMask_P2_Filter" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables", "DZ_AreaofDecay_Masks_Stalker" };
	};
};
class CfgVehicles
{
	class P2_AoD_Loner_GasMask;
	class P2_AoD_Loner_Black_GasMask;
	class P1_AoD_GasMask_Filter;
	class X18_GasMask_P2 : P2_AoD_Loner_GasMask
	{
		scope = 2;
		displayName = "#GasMask_P2";
		descriptionShort = "#GasMask_P2_DSC";
		inventorySlot = "Mask";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		attachments[] = { "gasmask_loner_filter_L" };
		weight = 850;
		itemSize[] = { 3,4 };
		absorbency = 0.9;
		heatIsolation = 0.6;
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
	class X18_GasMask_P2_Black : P2_AoD_Loner_Black_GasMask
	{
		scope = 2;
		displayName = "#GasMask_P2_Black";
		descriptionShort = "#GasMask_P2_Black_DSC";
		inventorySlot = "Mask";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		attachments[] = { "gasmask_loner_filter_L" };
		weight = 850;
		itemSize[] = { 3,4 };
		absorbency = 0.9;
		heatIsolation = 0.6;
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
	class X18_GasMask_P2_Duty : X18_GasMask_P2
	{
		scope = 2;
		displayName = "#GasMask_P2_Duty";
		descriptionShort = "#GasMask_P2_Duty_DSC";
		hiddenSelections[] = { "camo_mask" };
		hiddenSelectionsTextures[] = { "\Noosphere\X18Ecology\Gasmasks\P2\Data\gasmask_stalker_duty_co.paa" };
	};
	class X18_GasMask_P2_Filter_Base : P1_AoD_GasMask_Filter
	{
		scope = 0;
		displayName = "#GasMask_P2_Filter";
		descriptionShort = "#GasMask_P2_Filter_DSC";
		inventorySlot[] = { "gasmask_loner_filter_L" };
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
	class X18_GasMask_P2_Filter : X18_GasMask_P2_Filter_Base
	{
		scope = 2;
		displayName = "#GasMask_P2_Filter";
		descriptionShort = "#GasMask_P2_Filter_DSC";
		varQuantityInit = 30;
		varQuantityMax = 30;
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
	class X18_GasMask_P2_Filter_Duty : X18_GasMask_P2_Filter_Base
	{
		scope = 2;
		displayName = "#GasMask_P2_Filter_Duty";
		descriptionShort = "#GasMask_P2_Filter_Duty_DSC";
		hiddenSelections[] = { "camo_filter" };
		hiddenSelectionsTextures[] = { "\Noosphere\X18Ecology\Gasmasks\P2\Data\gasmask_duty_filter_co.paa" };
		varQuantityInit = 45;
		varQuantityMax = 45;
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
	class Slot_gasmask_loner_filter_L
	{
		name = "gasmask_loner_filter_L";
		displayName = "#GasMask_P2_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};