class CfgPatches
{
	class X18Ecology_GasMasks_Stalker
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables","DZ_Weapons_Firearms","DZ_Scripts","SGE_Loner" };
	};
};
class CfgVehicles
{
	class SGE_Stalker_GasMask;
	class SGE_Stalker_FullGasMask;
	class SGE_Stalker_GasMask_Filter;
	class X18_GasMask_Stalker : SGE_Stalker_GasMask
	{
		scope = 2;
		displayName = "#GasMask_Stalker";
		descriptionShort = "#GasMask_Stalker_DSC";
		inventorySlot[] = { "Mask" };
		attachments[] = { "Gas_Filtr_L" };
		itemInfo[] = { "Clothing","Mask" };
		rotationFlags = 17;
		weight = 730;
		itemSize[] = { 2,3 };
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
	class X18_GasMask_Stalker_Filter : SGE_Stalker_GasMask_Filter
	{
		scope = 1;
		displayName = "#GasMask_Stalker_Filter";
		descriptionShort = "#GasMask_Stalker_Filter_DSC";
		inventorySlot[] = { "Gas_Filtr_L" };
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
	class X18_GasMask_Stalker_FullFace : SGE_Stalker_FullGasMask
	{
		scope = 2;
		displayName = "#GasMask_Stalker_FullFace";
		descriptionShort = "#GasMask_Stalker_FullFace_DSC";
		inventorySlot[] = { "Mask" };
		attachments[] = { "Gas_Filtr_L" };
		itemInfo[] = { "Clothing","Mask" };
		rotationFlags = 17;
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
	class X18_GasMask_Stalker_FullFace_Filter : SGE_Stalker_GasMask_Filter
	{
		scope = 1;
		displayName = "#GasMask_Stalker_FullFace_Filter";
		descriptionShort = "#GasMask_Stalker_FullFace_Filter_DSC";
		inventorySlot[] = { "Gas_Filtr_L" };
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
	class ProxyGas_l : ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Gas_Filtr_L";
	};
	class ProxyGas_R : ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Gas_Filtr_R";
	};
};
class CfgSlots
{
	class Slot_Gas_Filtr_L
	{
		name = "Gas_Filtr_L";
		displayName = "#GasMask_Stalker_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
	class Slot_Gas_Filtr_R
	{
		name = "Gas_Filtr_R";
		displayName = "#GasMask_Stalker_Filter";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};