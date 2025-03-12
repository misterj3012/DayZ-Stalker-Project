class CfgPatches
{
	class X18Ecology_GasMasks_CBRN
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables","DZ_AreaofDecay_Masks_CBRN" };
	};
};
class CfgVehicles
{
	class CBRN_AoD_Himza_GasMask;
	class X18_GasMask_CBRN : CBRN_AoD_Himza_GasMask
	{
		scope = 2;
		displayName = "#GasMask_CBRN";
		descriptionShort = "#GasMask_CBRN_DSC";
		attachments[] = { "gasmask_cbrn_filter_L", "gasmask_cbrn_filter_R" };
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
	class CBRN_AoD_Himza_Filter_R;
	class X18_GasMask_CBRN_Filter_Right : CBRN_AoD_Himza_Filter_R
	{
		scope = 2;
		displayName = "#GasMask_CBRN_Left_Filter";
		descriptionShort = "#GasMask_CBRN_Left_Filter_DSC";
		inventorySlot[] = { "gasmask_cbrn_filter_R" };
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
	class CBRN_AoD_Himza_Filter_L;
	class X18_GasMask_CBRN_Filter_Left : CBRN_AoD_Himza_Filter_L
	{
		scope = 2;
		displayName = "#GasMask_CBRN_Right_Filter";
		descriptionShort = "#GasMask_CBRN_Right_Filter_DSC";
		inventorySlot[] = { "gasmask_cbrn_filter_L" };
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
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxygasmask_cbrn_filter_L : ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = { "gasmask_cbrn_filter_L" };
	};
	class Proxygasmask_cbrn_filter_R : ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = { "gasmask_cbrn_filter_R" };
	};
};
class CfgSlots
{
	class Slot_gasmask_cbrn_filter_L
	{
		name = "gasmask_cbrn_filter_L";
		displayName = "#GasMask_CBRN_Right_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
	class Slot_gasmask_cbrn_filter_R
	{
		name = "gasmask_cbrn_filter_R";
		displayName = "#GasMask_CBRN_Left_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};