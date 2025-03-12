class CfgPatches
{
	class X18Ecology_GasMasks_AVC
	{
		units[] = { "X18_GasMask_AVC","X18_AVC_GasMask_Filter" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables", "DZ_Armstalker_Masks_AVC" };
	};
};
class CfgVehicles
{
	class AVC_AoD_GasMask;
	class AVC_AoD_GasMask_Filter_Base;
	class X18_GasMask_AVC : AVC_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_AVC";
		descriptionShort = "#GasMask_AVC_DSC";
		inventorySlot[] = { "Mask" };
		attachments[] = { "gasmask_avc_filter_L" };
		itemInfo[] = { "Clothing","Mask" };
		simulation = "clothing";
		vehicleClass = "Clothing";
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
	class X18_GasMask_AVC_Filter_Base : AVC_AoD_GasMask_Filter_Base
	{

		scope = 0;
		displayName = "#GasMask_AVC_Filter";
		descriptionShort = "#GasMask_AVC_Filter_DSC";
		inventorySlot[] = { "gasmask_avc_filter_L" };
		lootCategory = "Attachments";
		vehicleClass = "Clothing";
		weight = 210;
		itemSize[] = { 2,1 };
		repairableWithKits[] = { 5,2 };
		repairCosts[] = { 30,25 };
		heatIsolation = 0;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 60;
		varQuantityMin = 0.0;
		varQuantityMax = 60;
		varQuantityDestroyOnMin = 0;
		rotationFlags = 17;
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			convertEnergyToQuantity = 1;
			reduceMaxEnergyByDamageCoef = 1;
			powerSocketsCount = 1;
			compatiblePlugTypes[] = { 1 };
		};
	};
	class X18_GasMask_AVC_Filter : X18_GasMask_AVC_Filter_Base
	{
		scope = 2;
	};
};
class CfgSlots
{
	class Slot_gasmask_avc_filter_L
	{
		name = "gasmask_avc_filter_L";
		displayName = "#GasMask_AVC_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};