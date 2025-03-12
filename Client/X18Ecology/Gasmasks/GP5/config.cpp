class CfgPatches
{
	class X18Ecology_GasMasks_GP5
	{
		units[] = { "X18_GasMask_GP5","X18_GasMask_GP5_Black","X18_GasMask_GP5_Filter" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables","DZ_AreaofDecay_Masks_GP5" };
	};
};
class CfgVehicles
{
	class GP5_White_AoD_GasMask;
	class GP5_Black_AoD_GasMask;
	class GP5_AoD_GasMask_Filter_Base;
	class X18_GasMask_GP5 : GP5_White_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_GP5";
		descriptionShort = "#GasMask_GP5_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_gp5_filter" };
		rotationFlags = 2;
		weight = 900;
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
	class X18_GasMask_GP5_Black : GP5_Black_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_GP5";
		descriptionShort = "#GasMask_GP5_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_gp5_filter" };
		rotationFlags = 2;
		weight = 900;
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
	class X18_GasMask_GP5_Filter_Base : GP5_AoD_GasMask_Filter_Base
	{
		scope = 0;
		displayName = "#GasMask_GP5_Filter";
		descriptionShort = "#GasMask_GP5_Filter_DSC";
		inventorySlot[] = { "gasmask_gp5_filter" };
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
	class X18_GasMask_GP5_Filter : X18_GasMask_GP5_Filter_Base
	{
		scope = 2;
	};
};
class CfgSlots
{
	class Slot_GasMask_GP5Filter
	{
		name = "GasMask_GP5_Filter";
		displayName = "#GasMask_GP5_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};