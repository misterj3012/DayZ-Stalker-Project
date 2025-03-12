class CfgPatches
{
	class X18Ecology_GasMasks_GMS
	{
		units[] = { "X18_GasMask_GMS","X18_GasMask_GMS_Valve","X18_GasMask_GMS_Filter" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables", "DZ_AreaofDecay_Masks_GMS" };
	};
};
class CfgVehicles
{
	class GMS_AoD_GasMask;
	class GMS_AoD_GasMask_Clapan;
	class GMS_AoD_GasMask_Filter_Base;
	class X18_GasMask_GMS : GMS_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_GMS";
		descriptionShort = "#GasMask_GMS_DSC";
		inventorySlot[] = { "Mask" };
		itemInfo[] = { "Clothing","Mask" };
		attachments[] = { "gasmask_gms_clapan","gasmask_gms_filter" };
		rotationFlags = 2;
		weight = 1230;
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
	class X18_GasMask_GMS_Valve : GMS_AoD_GasMask_Clapan
	{
		scope = 2;
		displayName = "#GasMask_GMS_Valve";
		descriptionShort = "#GasMask_GMS_Valve_DSC";
		inventorySlot[] = { "gasmask_gms_clapan" };
		lootCategory = "Attachments";
		vehicleClass = "Clothing";
		rotationFlags = 17;
		weight = 210;
		itemSize[] = { 2,1 };
		repairableWithKits[] = { 5,2 };
		repairCosts[] = { 30,25 };
	};
	class X18_GasMask_GMS_Filter_Base : GMS_AoD_GasMask_Filter_Base
	{
		scope = 0;
		displayName = "#GasMask_GMS_Filter";
		descriptionShort = "#GasMask_GMS_Filter_DSC";
		inventorySlot[] = { "gasmask_gms_filter" };
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
	class X18_GasMask_GMS_Filter : X18_GasMask_GMS_Filter_Base
	{
		scope = 2;
	};
};
class CfgSlots
{
	class Slot_gasmask_gms_clapan
	{
		name = "gasmask_gms_clapan";
		displayName = "#GasMask_GMS_Valve";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
	class Slot_gasmask_gms_filter
	{
		name = "gasmask_gms_filter";
		displayName = "#GasMask_GMS_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};