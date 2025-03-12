class CfgPatches
{
	class X18Ecology_GasMasks_Container
	{
		units[] = { "X18_GasMask_Container" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Characters","DZ_Characters_Masks","DZ_Gear_Consumables" };
	};
};
class CfgVehicles
{
	class Box_AoD_GasMask;
	class X18_GasMask_Container : Box_AoD_GasMask
	{
		scope = 2;
		displayName = "#GasMask_Container";
		descriptionShort = "#GasMask_Container_DSC";
		inventorySlot[] = {
			"Belt_Left",
			"WalkieTalkie",
			"VestGrenadeA",
			"VestGrenadeB",
			"VestGrenadeC",
			"VestGrenadeD",
			"GasMaskContainer"
		};
		attachments[] = { "Mask" };
		lootCategory = "Attachments";
		vehicleClass = "Clothing";
		rotationFlags = 17;
		weight = 500;
		itemSize[] = { 2,3 };
		repairableWithKits[] = { 5,2 };
		repairCosts[] = { 30,25 };
		heatIsolation = 0;
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyMask : ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = { "Mask" };
	};
};
class CfgSlots
{
	class Slot_GasMaskContainer
	{
		name = "GasMaskContainer";
		displayName = "#GasMask";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};