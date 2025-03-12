class CfgPatches
{
	class X18Ecology_GasMasks_PPM88
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables","DZ_Characters_Masks" };
	};
};
class CfgVehicles
{
	class FS_GASMASK_PPM88;
	class FS_GasFilter;
	class X18_GasMask_PPM88 : FS_GASMASK_PPM88
	{
		scope = 2;
		displayName = "#GasMask_PPM88";
		descriptionShort = "#GasMask_PPM88_DSC";
		inventorySlot[] = { "Mask" };
		attachments[] = { "fil" };
		itemInfo[] = { "Clothing","Mask" };
		rotationFlags = 17;
		weight = 730;
		itemSize[] = { 3,4 };
		stackedUnit = "pc.";
		quantityBar = 0;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		varQuantityDestroyOnMin = 0;
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
	class X18_GasMask_PPM88_Filter : FS_GasFilter
	{
		scope = 1;
		displayName = "#GasMask_PPM88_Filter";
		descriptionShort = "#GasMask_PPM88_Filter_DSC";
		inventorySlot[] = { "fil" };
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
};
class CfgSlots
{
	class Slot_FIL
	{
		name = "FIL";
		displayName = "#GasMask_PPM88_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};