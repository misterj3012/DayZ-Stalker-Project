class CfgPatches
{
	class DZ_Gear_Medical
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Medical", "dz_aod_characters" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Edible_Base;
	class Bottle_Base;
	class BandageDressing : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BandageDressing0";
		descriptionShort = "$STR_CfgVehicles_BandageDressing1";
		model = "\FS_3_Items\bandage\bandage.p3d";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class TetracyclineAntibiotics : Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TetracyclineAntibiotics0";
		descriptionShort = "$STR_CfgVehicles_TetracyclineAntibiotics1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class DisinfectantSpray : Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_DisinfectantSpray0";
		descriptionShort = "$STR_CfgVehicles_DisinfectantSpray1";
		inventorySlot[] = { "Disinfectant","MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class DisinfectantAlcohol : Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_DisinfectantAlcohol0";
		descriptionShort = "$STR_CfgVehicles_DisinfectantAlcohol1";
		inventorySlot[] = { "Disinfectant","MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class PurificationTablets : Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PurificationTablets0";
		descriptionShort = "$STR_CfgVehicles_PurificationTablets1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class CharcoalTablets : Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CharcoalTablets0";
		descriptionShort = "$STR_CfgVehicles_CharcoalTablets1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class PainkillerTablets : Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PainkillerTablets0";
		descriptionShort = "$STR_CfgVehicles_PainkillerTablets1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class VitaminBottle : Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_VitaminBottle0";
		descriptionShort = "$STR_CfgVehicles_VitaminBottle1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class IodineTincture : Edible_Base
	{
		scope = 2;
		displayName = "$STR_IodineTincture0";
		descriptionShort = "$STR_IodineTincture1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class Epinephrine : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Epinephrine0";
		descriptionShort = "$STR_CfgVehicles_Epinephrine1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class Morphine : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Morphine0";
		descriptionShort = "$STR_CfgVehicles_Morphine1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class Syringe : Epinephrine
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Syringe0";
		descriptionShort = "$STR_CfgVehicles_Syringe1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class ClearSyringe : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Syringe0";
		descriptionShort = "$STR_CfgVehicles_Syringe1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class BloodSyringe : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Syringe0";
		descriptionShort = "$STR_CfgVehicles_Syringe1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class InjectionVial : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_InjectionVial0";
		descriptionShort = "$STR_CfgVehicles_InjectionVial1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class SalineBag : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SalineBag0";
		descriptionShort = "$STR_CfgVehicles_SalineBag1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class StartKitIV : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_StartKitIV0";
		descriptionShort = "$STR_CfgVehicles_StartKitIV1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class SalineBagIV : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SalineBagIV0";
		descriptionShort = "$STR_CfgVehicles_SalineBagIV1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class BloodBagEmpty : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BloodBagEmpty0";
		descriptionShort = "$STR_CfgVehicles_BloodBagEmpty1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class BloodBagFull : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BloodBagFull0";
		descriptionShort = "$STR_CfgVehicles_BloodBagFull1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class BloodBagIV : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BloodBagIV0";
		descriptionShort = "$STR_CfgVehicles_BloodBagIV1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class BloodTestKit : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BloodTestKit0";
		descriptionShort = "$STR_CfgVehicles_BloodTestKit1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
	class Thermometer : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Thermometer0";
		descriptionShort = "$STR_CfgVehicles_Thermometer1";
		inventorySlot[] = { "MedicalUniversal1","MedicalUniversal2","MedicalUniversal3","MedicalUniversal4","MedicalUniversal5","MedicalBandage","Gelik_MedicalBandage","Gelik_MedicalBandage2","Gelik_MedicalBandage3" };
	};
};
class CfgSlots
{
	class Slot_MedicalUniversal1
	{
		name = "MedicalUniversal1";
		displayName = "$STR_Medical";
		ghostIcon = "set:dayz_inventory image:medicalbandage";
	};
	class Slot_MedicalUniversal2
	{
		name = "MedicalUniversal2";
		displayName = "$STR_Medical";
		ghostIcon = "set:dayz_inventory image:medicalbandage";
	};
	class Slot_MedicalUniversal3
	{
		name = "MedicalUniversal3";
		displayName = "$STR_Medical";
		ghostIcon = "set:dayz_inventory image:medicalbandage";
	};
	class Slot_MedicalUniversal4
	{
		name = "MedicalUniversal4";
		displayName = "$STR_Medical";
		ghostIcon = "set:dayz_inventory image:medicalbandage";
	};
	class Slot_MedicalUniversal5
	{
		name = "MedicalUniversal5";
		displayName = "$STR_Medical";
		ghostIcon = "set:dayz_inventory image:medicalbandage";
	};
};