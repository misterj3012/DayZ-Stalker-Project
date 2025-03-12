class CfgPatches
{
	class X18Sounds_MoveSounds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters_Backpacks",
			"DZ_Characters_Belts",
			"DZ_Characters_Glasses",
			"DZ_Characters_Gloves",
			"DZ_Characters_Headgear",
			"DZ_Characters_Masks",
			"DZ_Characters_Pants",
			"DZ_Characters_Shoes",
			"DZ_Characters_Tops",
			"DZ_Characters_Vests",
			"DZ_Gear_Books",
			"DZ_Gear_Camping",
			"DZ_Gear_Consumables",
			"DZ_Gear_Containers",
			"DZ_Gear_Cooking",
			"DZ_Gear_Crafting",
			"DZ_Gear_Cultivation",
			"DZ_Gear_Drinks",
			"DZ_Gear_Food",
			"DZ_Gear_Medical",
			"DZ_Gear_Navigation",
			"DZ_Gear_Optics",
			"DZ_Radio",
			"DZ_Gear_Tools",
			"DZ_Gear_Traps",
			"DZ_Vehicles_Parts",
			"DZ_Vehicles_Wheeled",
			"DZ_Weapons_Ammunition",
			"DZ_Weapons_Lights",
			"DZ_Weapons_Magazines",
			"DZ_Weapons_Muzzles",
			"DZ_Weapons_Optics",
			"DZ_Weapons_Supports",
			"DZ_Weapons_Firearms",
			"DZ_Weapons_Melee_Blade",
			"DZ_Weapons_Melee_Blunt",
			"DZ_Weapons_Melee_Powered"
		};
		magazines[] = {};
	};
};
class CfgVehicles
{
	class Static;
	class Inventory_Base : Static
	{
		MoveSounds[] = { "MoveSound_Item_Move_Small","MoveSound_Item_Move_Regular" };
		MoveSoundVolume = 1.0;
	};
	class ItemOptics : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class Clothing_Base;
	class Edible_Base;
	class Book_Base;
	class Clothing : Clothing_Base {};
	class Switchable_Base;
	class Container_Base;
	class HouseNoDestruct;
	class TentBase;
	class Box_Base;
	class WorldContainer_Base;
	class Bottle_Base;
	class Transmitter_Base;
	class FishingRod_Base;
	class Powered_Base;
	class Trap_Base;
	class ItemBarrel;
	class ItemSuppressor;
	class FishingRod_Base_New : FishingRod_Base {};
	class BaseBuildingBase : Inventory_Base {};
	class TaloonBag_ColorBase : Clothing
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet","pickUpCourierBag_SoundSet" };
	};
	class TortillaBag : Clothing
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet","pickUpCourierBag_SoundSet" };
	};
	class CourierBag : Clothing
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet","pickUpCourierBag_SoundSet" };
	};
	class FurCourierBag : Clothing
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet","pickUpCourierBag_SoundSet" };
	};
	class ImprovisedBag : Clothing
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet","pickUpCourierBag_SoundSet" };
	};
	class FurImprovisedBag : Clothing
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet","pickUpCourierBag_SoundSet" };
	};
	class DryBag_ColorBase : Clothing
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet","pickUpCourierBag_SoundSet" };
	};
	class HuntingBag : Clothing
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet","pickUpCourierBag_SoundSet" };
	};
	class MountainBag_ColorBase : Clothing
	{
		MoveSounds[] = { "taloonbag_drop_SoundSet" };
	};
	class SmershBag : Clothing
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet","pickUpCourierBag_SoundSet" };
	};
	class ChildBag_ColorBase : Clothing
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet","pickUpCourierBag_SoundSet" };
	};
	class GhillieBushrag_ColorBase : Clothing
	{
		MoveSounds[] = { "Cloth_Back_walkCro_ghillie_Soundset","Cloth_Back_runCro_ghillie_Soundset","Cloth_Back_walkErc_ghillie_Soundset","Cloth_Back_walkRasErc_ghillie_Soundset","Cloth_Back_runErc_ghillie_Soundset","Cloth_Back_runRasErc_ghillie_Soundset","Cloth_Back_sprintErc_ghillie_Soundset","Cloth_Back_shortmove_ghillie_Soundset" };
	};
	class GhillieTop_ColorBase : Clothing
	{
		MoveSounds[] = { "Cloth_Back_walkCro_ghillie_Soundset","Cloth_Back_runCro_ghillie_Soundset","Cloth_Back_walkErc_ghillie_Soundset","Cloth_Back_walkRasErc_ghillie_Soundset","Cloth_Back_runErc_ghillie_Soundset","Cloth_Back_runRasErc_ghillie_Soundset","Cloth_Back_sprintErc_ghillie_Soundset","Cloth_Back_shortmove_ghillie_Soundset" };
	};
	class GhillieSuit_ColorBase : Clothing
	{
		MoveSounds[] = { "Cloth_Back_walkCro_ghillie_Soundset","Cloth_Back_runCro_ghillie_Soundset","Cloth_Back_walkErc_ghillie_Soundset","Cloth_Back_walkRasErc_ghillie_Soundset","Cloth_Back_runErc_ghillie_Soundset","Cloth_Back_runRasErc_ghillie_Soundset","Cloth_Back_sprintErc_ghillie_Soundset","Cloth_Back_shortmove_ghillie_Soundset" };
	};
	class LeatherSack_ColorBase : Clothing
	{
		MoveSounds[] = { "taloonbag_drop_SoundSet" };
	};
	class AssaultBag_ColorBase : Clothing
	{
		MoveSounds[] = { "taloonbag_drop_SoundSet" };
	};
	class CoyoteBag_ColorBase : Clothing
	{
		MoveSounds[] = { "taloonbag_drop_SoundSet" };
	};
	class AliceBag_ColorBase : Clothing
	{
		MoveSounds[] = { "taloonbag_drop_SoundSet" };
	};
	class LargeTentBackPack : Clothing
	{
		MoveSounds[] = { "mediumtent_drop_SoundSet" };
	};
	class CivilianBelt : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class MilitaryBelt : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class LeatherKnifeSheath : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class NylonKnifeSheath : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class LeatherBelt_ColorBase : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class SportGlasses_ColorBase : Clothing
	{
		MoveSounds[] = { "SportGlasses_pickup_SoundSet","SportGlasses_drop_SoundSet" };
	};
	class AviatorGlasses : Clothing
	{
		MoveSounds[] = { "SportGlasses_pickup_SoundSet","SportGlasses_drop_SoundSet" };
	};
	class DesignerGlasses : Clothing
	{
		MoveSounds[] = { "SportGlasses_pickup_SoundSet","SportGlasses_drop_SoundSet" };
	};
	class ThickFramesGlasses : Clothing
	{
		MoveSounds[] = { "SportGlasses_pickup_SoundSet","SportGlasses_drop_SoundSet" };
	};
	class ThinFramesGlasses : Clothing
	{
		MoveSounds[] = { "SportGlasses_pickup_SoundSet","SportGlasses_drop_SoundSet" };
	};
	class TacticalGoggles : Clothing
	{
		MoveSounds[] = { "SportGlasses_pickup_SoundSet","SportGlasses_drop_SoundSet" };
	};
	class NVGHeadstrap : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class NVGoggles : ItemOptics
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class WorkingGloves_ColorBase : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class TacticalGloves_ColorBase : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class NBCGloves_ColorBase : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class SurgicalGloves_ColorBase : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class LeatherGloves_ColorBase : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class OMNOGloves_ColorBase : Clothing
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class BallisticHelmet_ColorBase : Clothing
	{
		MoveSounds[] = { "BallisticHelmet_drop_SoundSet" };
	};
	class BaseballCap_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class ZSh3PilotHelmet : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_drop_SoundSet" };
	};
	class ConstructionHelmet_ColorBase : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_drop_SoundSet" };
	};
	class BurlapSackCover : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class BeanieHat_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class Ushanka_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class PumpkinHelmet : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class MotoHelmet_ColorBase : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_drop_SoundSet" };
	};
	class DarkMotoHelmet_ColorBase : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_drop_SoundSet" };
	};
	class Headtorch_ColorBase : Switchable_Base
	{
		MoveSounds[] = { "WorkingGloves_pickup_SoundSet","WorkingGloves_drop_SoundSet" };
	};
	class Bandana_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class BandanaHead_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class RadarCap_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class MilitaryBeret_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class FlatCap_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class ZmijovkaCap_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class CowboyHat_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class BoonieHat_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class OfficerHat : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class PoliceCap : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class PilotkaCap : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class TankerHelmet : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class GorkaHelmet : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_drop_SoundSet" };
	};
	class FirefightersHelmet_ColorBase : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_drop_SoundSet" };
	};
	class SkateHelmet_ColorBase : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_drop_SoundSet" };
	};
	class WeldingMask : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_drop_SoundSet" };
	};
	class PrisonerCap : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class GhillieHood_ColorBase : Clothing
	{
		MoveSounds[] = { "Cloth_Back_walkCro_ghillie_Soundset","Cloth_Back_runCro_ghillie_Soundset","Cloth_Back_walkErc_ghillie_Soundset","Cloth_Back_walkRasErc_ghillie_Soundset","Cloth_Back_runErc_ghillie_Soundset","Cloth_Back_runRasErc_ghillie_Soundset","Cloth_Back_sprintErc_ghillie_Soundset","Cloth_Back_shortmove_ghillie_Soundset" };
	};
	class LeatherHat_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class MedicalScrubsHat_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class GreatHelm : Clothing
	{
		MoveSounds[] = { "GreatHelm_drop_SoundSet" };
	};
	class Ssh68Helmet : Clothing
	{
		MoveSounds[] = { "BallisticHelmet_drop_SoundSet" };
	};
	class DirtBikeHelmet_ColorBase : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_drop_SoundSet" };
	};
	class DirtBikeHelmet_Visor : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_pickup_SoundSet" };
	};
	class DirtBikeHelmet_Mouthguard : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_pickup_SoundSet" };
	};
	class NBCHoodBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class HockeyHelmet_ColorBase : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_drop_SoundSet" };
	};
	class SantasHat : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class Mich2001Helmet : Clothing
	{
		MoveSounds[] = { "BallisticHelmet_drop_SoundSet" };
	};
	class GasMask : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_pickup_SoundSet" };
	};
	class BandanaMask_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class NioshFaceMask : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class GP5GasMask : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_pickup_SoundSet" };
	};
	class AirborneMask : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_pickup_SoundSet" };
	};
	class GP5GasMask_Filter : Inventory_Base
	{
		MoveSounds[] = { "DarkMotoHelmet_pickup_SoundSet" };
	};
	class Balaclava3Holes_ColorBase : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_pickup_SoundSet" };
	};
	class SantasBeard : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class MouthRag : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class SurgicalMask : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class HockeyMask : Clothing
	{
		MoveSounds[] = { "DarkMotoHelmet_pickup_SoundSet" };
	};
	class Jeans_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class CargoPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class TTSKOPants : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class HunterPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class CanvasPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class CanvasPantsMidi_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class TrackSuitPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class GorkaPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class PolicePants : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class PolicePantsOrel : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class ParamedicPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class FirefightersPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class PrisonUniformPants : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class LeatherPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class MedicalScrubsPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class USMCPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class SlacksPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class BDUPants : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class NBCPantsBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class Breeches_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class ShortJeans_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class Skirt_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class JumpsuitPants_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class AthleticShoes_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_pickup_SoundSet" };
	};
	class HikingBoots_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_drop_SoundSet" };
	};
	class HikingBootsLow_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_pickup_SoundSet" };
	};
	class Wellies_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_drop_SoundSet" };
	};
	class WorkingBoots_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_pickup_SoundSet" };
	};
	class JungleBoots_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_pickup_SoundSet" };
	};
	class DressShoes_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_pickup_SoundSet" };
	};
	class MilitaryBoots_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_drop_SoundSet" };
	};
	class CombatBoots_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_drop_SoundSet" };
	};
	class JoggingShoes_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_pickup_SoundSet" };
	};
	class LeatherShoes_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_pickup_SoundSet" };
	};
	class Sneakers_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_pickup_SoundSet" };
	};
	class NBCBootsBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_pickup_SoundSet" };
	};
	class Ballerinas_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_pickup_SoundSet" };
	};
	class TTSKOBoots : Clothing
	{
		MoveSounds[] = { "AthleticShoes_drop_SoundSet" };
	};
	class Armband_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_drop_SoundSet" };
	};
	class Sweater_ColorBase : Clothing
	{
		MoveSounds[] = { "AthleticShoes_drop_SoundSet" };
	};
	class Shirt_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class TShirt_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class Hoodie_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class TacticalShirt_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class HikingJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class Raincoat_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class M65Jacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class TTsKOJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class GorkaEJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class RidersJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class WoolCoat_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class TrackSuitJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class PoliceJacket : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class PoliceJacketOrel : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class ParamedicJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class FirefighterJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class PrisonUniformJacket : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class MiniDress_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class QuiltedJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class BomberJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class LeatherJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class HuntingJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class MedicalScrubsShirt_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class LabCoat : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class NurseDress_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class USMCJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class Blouse_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class NBCJacketBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class DenimJacket : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class TelnyashkaShirt : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class ChernarusSportShirt : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class JumpsuitJacket_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class BDUJacket : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class ManSuit_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class WomanSuit_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class LeatherShirt_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class PlateCarrierVest : Clothing
	{
		MoveSounds[] = { "SmershVest_pickup_SoundSet","SmershVest_drop_SoundSet" };
	};
	class SmershVest : Clothing
	{
		MoveSounds[] = { "SmershVest_pickup_SoundSet","SmershVest_drop_SoundSet" };
	};
	class PressVest_ColorBase : Clothing
	{
		MoveSounds[] = { "SmershVest_pickup_SoundSet","SmershVest_drop_SoundSet" };
	};
	class UKAssVest_ColorBase : Clothing
	{
		MoveSounds[] = { "SmershVest_pickup_SoundSet","SmershVest_drop_SoundSet" };
	};
	class PoliceVest : Clothing
	{
		MoveSounds[] = { "SmershVest_pickup_SoundSet","SmershVest_drop_SoundSet" };
	};
	class PlateCarrierHolster : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class ChestHolster : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class HighCapacityVest_ColorBase : Clothing
	{
		MoveSounds[] = { "SmershVest_pickup_SoundSet","SmershVest_drop_SoundSet" };
	};
	class LeatherStorageVest_ColorBase : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class HuntingVest : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class ReflexVest : Clothing
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class ItemBook : Book_Base
	{
		MoveSounds[] = { "taloonbag_drop_SoundSet" };
	};
	class MediumTent : TentBase
	{
		MoveSounds[] = { "pickUpTent_SoundSet","pickUpTentLight_SoundSet","mediumtent_drop_SoundSet" };
	};
	class LargeTent : TentBase
	{
		MoveSounds[] = { "mediumtent_movement_sprint_SoundSet","mediumtent_drop_SoundSet" };
	};
	class CarTent : TentBase
	{
		MoveSounds[] = { "mediumtent_movement_sprint_SoundSet","mediumtent_drop_SoundSet" };
	};
	class PartyTent : TentBase
	{
		MoveSounds[] = { "pickUpTent_SoundSet","pickUpTentLight_SoundSet","mediumtent_drop_SoundSet" };
	};
	class CamoNetShelter : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class FenceKit : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class WatchtowerKit : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class BarbedWire : Inventory_Base
	{
		MoveSounds[] = { "FenceKit_crafting_1_SoundSet" };
	};
	class CombinationLock : Inventory_Base
	{
		MoveSounds[] = { "pickUpShovelLight_SoundSet" };
	};
	class CombinationLock4 : CombinationLock
	{
		MoveSounds[] = { "pickUpShovelLight_SoundSet" };
	};
	class CamoNet : Inventory_Base
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet","pickUpCourierBag_SoundSet" };
	};
	class SeaChest : Container_Base
	{
		MoveSounds[] = { "pickUpSeaChest_SoundSet","seachest_movement_SoundSet" };
	};
	class WoodenCrate : Container_Base
	{
		MoveSounds[] = { "pickUpSeaChest_SoundSet","seachest_movement_SoundSet" };
	};
	class Spotlight : Inventory_Base
	{
		MoveSounds[] = { "powergenerator_movement_walk_SoundSet" };
	};
	class XmasLights : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class Refridgerator : Inventory_Base
	{
		MoveSounds[] = { "powergenerator_movement_walk_SoundSet","pickUpPowerGenerator_SoundSet","powergenerator_drop_SoundSet" };
	};
	class PowerGenerator : Inventory_Base
	{
		MoveSounds[] = { "powergenerator_movement_walk_SoundSet","pickUpPowerGenerator_SoundSet","powergenerator_drop_SoundSet" };
	};
	class CableReel : Inventory_Base
	{
		MoveSounds[] = { "cablereel_drop_SoundSet" };
	};
	class BatteryCharger : Inventory_Base
	{
		MoveSounds[] = { "batterycharger_drop_SoundSet" };
	};
	class HescoBox : Inventory_Base
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class Fabric : Inventory_Base
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class ShelterBase : TentBase
	{
		MoveSounds[] = { "mediumtent_movement_walk_SoundSet" };
	};
	class TerritoryFlagKit : Inventory_Base
	{
		MoveSounds[] = { "FenceKit_crafting_1_SoundSet" };
	};
	class Flag_Base : Inventory_Base
	{
		MoveSounds[] = { "Shirt_pickup_SoundSet","Shirt_drop_SoundSet" };
	};
	class Paper : Inventory_Base
	{
		MoveSounds[] = { "pickUpPaper_SoundSet" };
	};
	class DuctTape : Inventory_Base
	{
		MoveSounds[] = { "rope_tieup_back_SoundSet" };
	};
	class Rag : Inventory_Base
	{
		MoveSounds[] = { "Bandage_loop_SoundSet" };
	};
	class BurlapStrip : Inventory_Base
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet" };
	};
	class Stone : Inventory_Base {};
	class SmallStone : Inventory_Base {};
	class Firewood : Inventory_Base
	{
		MoveSounds[] = { "woodenlog_drop_SoundSet" };
	};
	class Battery9V : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class LargeGasCanister : Inventory_Base
	{
		MoveSounds[] = { "pickUpShovelLight_SoundSet" };
	};
	class MediumGasCanister : Inventory_Base
	{
		MoveSounds[] = { "pickUpShovelLight_SoundSet" };
	};
	class SmallGasCanister : Inventory_Base
	{
		MoveSounds[] = { "pickUpShovelLight_SoundSet" };
	};
	class ButaneCanister : Inventory_Base
	{
		MoveSounds[] = { "pickUpShovelLight_SoundSet" };
	};
	class Spraycan_ColorBase : Inventory_Base
	{
		MoveSounds[] = { "pickUpShovelLight_SoundSet" };
	};
	class Matchbox : Inventory_Base
	{
		MoveSounds[] = { "MatchOut_SoundSet" };
	};
	class NailBox : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class Roadflare : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet" };
	};
	class Chemlight_ColorBase : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet" };
	};
	class Pelt_Base : Inventory_Base
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet" };
	};
	class TannedLeather : Inventory_Base
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet" };
	};
	class Hook : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet" };
	};
	class BoneHook : Inventory_Base {};
	class Bark_ColorBase : Inventory_Base
	{
		MoveSounds[] = { "bark_pickup_SoundSet","bark_drop_SoundSet" };
	};
	class Nail : Inventory_Base
	{
		MoveSounds[] = { "MoveSound_Bullet_Move_Smoll" };
	};
	class Bone : Inventory_Base
	{
		MoveSounds[] = { "baseballbat_drop_SoundSet" };
	};
	class Bait : Inventory_Base {};
	class BoneBait : Inventory_Base {};
	class GardenLime : Inventory_Base
	{
		MoveSounds[] = { "pickUpGardenLimeLight_SoundSet","pickUpGardenLime_SoundSet" };
	};
	class Netting : Inventory_Base
	{
		MoveSounds[] = { "pickUpPlantMaterial_SoundSet" };
	};
	class WoodenPlank : Inventory_Base
	{
		MoveSounds[] = { "woodenlog_pickup_SoundSet" };
	};
	class MetalPlate : Inventory_Base
	{
		MoveSounds[] = { "crowbar_drop_SoundSet" };
	};
	class WoodenLog : Inventory_Base
	{
		MoveSounds[] = { "woodenlog_pickup_SoundSet" };
	};
	class Barrel_ColorBase : Container_Base
	{
		MoveSounds[] = { "barrel_drop_SoundSet" };
	};
	class Refrigerator : WorldContainer_Base
	{
		MoveSounds[] = { "pickUpBarrelLight_SoundSet" };
	};
	class RefrigeratorMinsk : WorldContainer_Base
	{
		MoveSounds[] = { "barrel_drop_SoundSet" };
	};
	class TrashCan : WorldContainer_Base
	{
		MoveSounds[] = { "pickUpBarrelLight_SoundSet" };
	};
	class FirstAidKit : Container_Base
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet" };
	};
	class SmallProtectorCase : Container_Base
	{
		MoveSounds[] = { "smallprotectorcase_pickup_SoundSet" };
	};
	class PlateCarrierPouches : Container_Base
	{
		MoveSounds[] = { "pickUpCourierBag_SoundSet" };
	};
	class AmmoBox : Container_Base
	{
		MoveSounds[] = { "ammobox_drop_SoundSet" };
	};
	class Bear_ColorBase : Container_Base
	{
		MoveSounds[] = { "pickUpCourierBag_SoundSet" };
	};
	class WaterproofBag_ColorBase : Container_Base
	{
		MoveSounds[] = { "pickUpGardenLimeLight_SoundSet" };
	};
	class GiftBox_Base : Container_Base
	{
		MoveSounds[] = { "pickUpCourierBag_SoundSet" };
	};
	class FireplaceBase : Inventory_Base
	{
		MoveSounds[] = { "pickUpFireplaceLight_SoundSet","pickUpFireplace_SoundSet" };
	};
	class BarrelHoles_ColorBase : FireplaceBase
	{
		MoveSounds[] = { "barrel_drop_SoundSet" };
	};
	class Pot : Bottle_Base
	{
		MoveSounds[] = { "pickUpPot_SoundSet","pickUpPotLight_SoundSet" };
	};
	class FryingPan : Inventory_Base
	{
		MoveSounds[] = { "pickUpPot_SoundSet","pickUpPotLight_SoundSet" };
	};
	class PortableGasStove : Inventory_Base
	{
		MoveSounds[] = { "pickUpShovelLight_SoundSet" };
	};
	class PortableGasLamp : Inventory_Base
	{
		MoveSounds[] = { "pickUpShovelLight_SoundSet" };
	};
	class Candle : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class PetrolLighter : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class Tripod : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class BurlapSack : Inventory_Base
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet" };
	};
	class Rope : Inventory_Base
	{
		MoveSounds[] = { "rope_struggle_SoundSet" };
	};
	class MetalWire : Inventory_Base
	{
		MoveSounds[] = { "FenceKit_crafting_1_SoundSet" };
	};
	class WoodenStick : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class Torch : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class ChickenFeather : Inventory_Base
	{
		MoveSounds[] = { "pickUpPlantMaterial_SoundSet" };
	};
	class LongWoodenStick : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class SharpWoodenStick : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class GorkaHelmetVisor : Inventory_Base
	{
		MoveSounds[] = { "DarkMotoHelmet_pickup_SoundSet" };
	};
	class HandDrillKit : Inventory_Base
	{
		MoveSounds[] = { "bark_drop_SoundSet" };
	};
	class Spear : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class SeedBase : Inventory_Base
	{
		MoveSounds[] = { "seeds_pickup_SoundSet" };
	};
	class TomatoSeedsPack : Inventory_Base
	{
		MoveSounds[] = { "seedpack_pickup_SoundSet" };
	};
	class PepperSeedsPack : Inventory_Base
	{
		MoveSounds[] = { "seedpack_pickup_SoundSet" };
	};
	class PumpkinSeedsPack : Inventory_Base
	{
		MoveSounds[] = { "seedpack_pickup_SoundSet" };
	};
	class ZucchiniSeedsPack : Inventory_Base
	{
		MoveSounds[] = { "seedpack_pickup_SoundSet" };
	};
	class CannabisSeedsPack : Inventory_Base
	{
		MoveSounds[] = { "seedpack_pickup_SoundSet" };
	};
	class PlantMaterial : Inventory_Base
	{
		MoveSounds[] = { "pickUpPlantMaterial_SoundSet" };
	};
	class AntiPestsSpray : Inventory_Base
	{
		MoveSounds[] = { "pickUpBackPack_Plastic_Light_SoundSet" };
	};
	class Canteen : Bottle_Base
	{
		MoveSounds[] = { "WaterBottle_pickup_SoundSet" };
	};
	class WaterBottle : Bottle_Base
	{
		MoveSounds[] = { "WaterBottle_pickup_SoundSet" };
	};
	class Vodka : Bottle_Base
	{
		MoveSounds[] = { "SodaCan_drop_SoundSet" };
	};
	class WaterPouch_ColorBase : Bottle_Base
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet" };
	};
	class SodaCan_ColorBase : Edible_Base
	{
		MoveSounds[] = { "SodaCan_pickup_SoundSet" };
	};
	class SodaCan_Empty : Inventory_Base
	{
		MoveSounds[] = { "SodaCan_pickup_SoundSet" };
	};
	class BoxCerealCrunchin : Edible_Base
	{
		MoveSounds[] = { "Eating_BoxShake_Soundset" };
	};
	class PowderedMilk : Edible_Base
	{
		MoveSounds[] = { "pickUpBloodBag_SoundSet" };
	};
	class SmallGuts : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class Guts : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class Rice : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class Marmalade : Edible_Base
	{
		MoveSounds[] = { "Marmalade_pickup_SoundSet" };
	};
	class BakedBeansCan : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class BakedBeansCan_Opened : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class PeachesCan : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class PeachesCan_Opened : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class TacticalBaconCan : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class TacticalBaconCan_Opened : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class SpaghettiCan : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class SpaghettiCan_Opened : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class SardinesCan : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class SardinesCan_Opened : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class TunaCan : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class TunaCan_Opened : Edible_Base
	{
		MoveSounds[] = { "BakedBeansCan_pickup_SoundSet" };
	};
	class Apple : Edible_Base
	{
		MoveSounds[] = { "Apple_pickup_SoundSet" };
	};
	class Plum : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class Pear : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class Banana : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class Orange : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class Tomato : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class GreenBellPepper : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class Zucchini : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class Pumpkin : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class SlicedPumpkin : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class Potato : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class Kiwi : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class SambucusBerry : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class CaninaBerry : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class Cannabis : Edible_Base
	{
		MoveSounds[] = { "Zucchini_pickup_SoundSet" };
	};
	class HumanSteakMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class GoatSteakMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class MouflonSteakMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class BoarSteakMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class PigSteakMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class DeerSteakMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class WolfSteakMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class BearSteakMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class CowSteakMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class SheepSteakMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class FoxSteakMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class ChickenBreastMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class RabbitLegMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class CarpFilletMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class MackerelFilletMeat : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class Lard : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class Carp : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class Sardines : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class Mackerel : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class Worm : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class MushroomBase : Edible_Base
	{
		MoveSounds[] = { "Eating_TakeFood_Soundset" };
	};
	class BandageDressing : Inventory_Base
	{
		MoveSounds[] = { "Bandage_loop_SoundSet" };
	};
	class DisinfectantSpray : Edible_Base
	{
		MoveSounds[] = { "pickUpBackPack_Plastic_Light_SoundSet" };
	};
	class DisinfectantAlcohol : Edible_Base
	{
		MoveSounds[] = { "SodaCan_drop_SoundSet" };
	};
	class PurificationTablets : Edible_Base
	{
		MoveSounds[] = { "purificationtablets_pickup_SoundSet" };
	};
	class CharcoalTablets : Edible_Base
	{
		MoveSounds[] = { "purificationtablets_pickup_SoundSet" };
	};
	class PainkillerTablets : Edible_Base
	{
		MoveSounds[] = { "purificationtablets_pickup_SoundSet" };
	};
	class VitaminBottle : Edible_Base
	{
		MoveSounds[] = { "vitaminbottle_pickup_SoundSet" };
	};
	class TetracyclineAntibiotics : Edible_Base
	{
		MoveSounds[] = { "purificationtablets_pickup_SoundSet" };
	};
	class Epinephrine : Inventory_Base
	{
		MoveSounds[] = { "pickUpBackPack_Plastic_Light_SoundSet" };
	};
	class Morphine : Inventory_Base
	{
		MoveSounds[] = { "pickUpBackPack_Plastic_Light_SoundSet" };
	};
	class Syringe : Epinephrine
	{
		MoveSounds[] = { "Syringe_splash_SoundSet" };
	};
	class ClearSyringe : Inventory_Base
	{
		MoveSounds[] = { "Syringe_splash_SoundSet" };
	};
	class BloodSyringe : Inventory_Base
	{
		MoveSounds[] = { "Syringe_splash_SoundSet" };
	};
	class InjectionVial : Inventory_Base
	{
		MoveSounds[] = { "injectionvial_pickup_SoundSet" };
	};
	class SalineBag : Inventory_Base
	{
		MoveSounds[] = { "pickUpBloodBag_SoundSet" };
	};
	class StartKitIV : Inventory_Base
	{
		MoveSounds[] = { "pickUpBloodBag_SoundSet" };
	};
	class SalineBagIV : Inventory_Base
	{
		MoveSounds[] = { "pickUpBloodBag_SoundSet" };
	};
	class BloodBagEmpty : Inventory_Base
	{
		MoveSounds[] = { "pickUpBloodBag_SoundSet" };
	};
	class BloodBagFull : Inventory_Base
	{
		MoveSounds[] = { "pickUpBloodBag_SoundSet" };
	};
	class BloodBagIV : Inventory_Base
	{
		MoveSounds[] = { "pickUpBloodBag_SoundSet" };
	};
	class BloodTestKit : Inventory_Base
	{
		MoveSounds[] = { "pickUpBloodBag_SoundSet" };
	};
	class Splint : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class Thermometer : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class Defibrillator : Inventory_Base
	{
		MoveSounds[] = { "sewingkit_pickup_SoundSet" };
	};
	class CigarettePack_ColorBase : Inventory_Base
	{
		MoveSounds[] = { "sewingkit_pickup_SoundSet" };
	};
	class ItemMap : Inventory_Base {};
	class ItemCompass : Inventory_Base {};
	class ChernarusMap : ItemMap
	{
		MoveSounds[] = { "pickUpPaper_SoundSet" };
	};
	class Compass : ItemCompass
	{
		MoveSounds[] = { "compass_open_SoundSet","compass_close_SoundSet" };
	};
	class Rangefinder : ItemOptics
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class Binoculars : ItemOptics
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class PersonalRadio : Transmitter_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class BaseRadio : Transmitter_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class Megaphone : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_drop_SoundSet" };
	};
	class Radio : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_drop_SoundSet" };
	};
	class Flashlight : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class Pen_ColorBase : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class CanOpener : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class Heatpack : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class MessTin : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_drop_SoundSet" };
	};
	class Pliers : Inventory_Base
	{
		MoveSounds[] = { "pickUpPliers_SoundSet" };
	};
	class Lockpick : Inventory_Base
	{
		MoveSounds[] = { "lockpicker_move_in_SoundSet","lockpicker_move_out_SoundSet" };
	};
	class WeaponCleaningKit : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_drop_SoundSet" };
	};
	class SewingKit : Inventory_Base
	{
		MoveSounds[] = { "sewingkit_pickup_SoundSet" };
	};
	class LeatherSewingKit : Inventory_Base
	{
		MoveSounds[] = { "sewingkit_pickup_SoundSet" };
	};
	class Handcuffs : Inventory_Base
	{
		MoveSounds[] = { "sewingkit_pickup_SoundSet" };
	};
	class HandcuffKeys : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class Cassette : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class Shovel : Inventory_Base
	{
		MoveSounds[] = { "shovel_drop_SoundSet" };
	};
	class FieldShovel : Inventory_Base
	{
		MoveSounds[] = { "shovel_drop_SoundSet" };
	};
	class Crowbar : Inventory_Base
	{
		MoveSounds[] = { "crowbar_drop_SoundSet" };
	};
	class FireExtinguisher : Inventory_Base
	{
		MoveSounds[] = { "crowbar_drop_SoundSet" };
	};
	class Hammer : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet" };
	};
	class MeatTenderizer : Inventory_Base
	{
		MoveSounds[] = { "crowbar_drop_SoundSet" };
	};
	class Wrench : Inventory_Base
	{
		MoveSounds[] = { "wrench_drop_SoundSet" };
	};
	class LugWrench : Inventory_Base
	{
		MoveSounds[] = { "wrench_drop_SoundSet" };
	};
	class Pipe : Inventory_Base
	{
		MoveSounds[] = { "crowbar_drop_SoundSet" };
	};
	class Screwdriver : Inventory_Base
	{
		MoveSounds[] = { "wrench_drop_SoundSet" };
	};
	class Sickle : Inventory_Base
	{
		MoveSounds[] = { "wrench_drop_SoundSet" };
	};
	class Hacksaw : Inventory_Base
	{
		MoveSounds[] = { "crowbar_drop_SoundSet" };
	};
	class KitchenKnife : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class SteakKnife : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class HayHook : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class StoneKnife : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class Mace : Inventory_Base
	{
		MoveSounds[] = { "crowbar_drop_SoundSet" };
	};
	class FarmingHoe : Inventory_Base
	{
		MoveSounds[] = { "pickUpShovel_SoundSet" };
	};
	class ImprovisedFishingRod : FishingRod_Base_New
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class ObsoleteFishingRod : FishingRod_Base_New
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class FishingRod : FishingRod_Base_New
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class SledgeHammer : Inventory_Base
	{
		MoveSounds[] = { "woodaxe_drop_SoundSet" };
	};
	class Iceaxe : Inventory_Base
	{
		MoveSounds[] = { "woodaxe_drop_SoundSet" };
	};
	class Broom : Inventory_Base
	{
		MoveSounds[] = { "woodaxe_drop_SoundSet" };
	};
	class Paddle : Inventory_Base
	{
		MoveSounds[] = { "woodaxe_drop_SoundSet" };
	};
	class ElectronicRepairKit : Inventory_Base
	{
		MoveSounds[] = { "sewingkit_drop_SoundSet" };
	};
	class EpoxyPutty : Inventory_Base
	{
		MoveSounds[] = { "pickUpBackPack_Plastic_Light_SoundSet" };
	};
	class Whetstone : Inventory_Base
	{
		MoveSounds[] = { "" };
	};
	class HandSaw : Inventory_Base
	{
		MoveSounds[] = { "pickUpBackPack_Plastic_Light_SoundSet" };
	};
	class BearTrap : Trap_Base
	{
		MoveSounds[] = { "beartrap_movement_walk_SoundSet" };
	};
	class LandMineTrap : Trap_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class SmallFishTrap : Trap_Base
	{
		MoveSounds[] = { "WaterBottle_pickup_SoundSet" };
	};
	class FishNetTrap : Trap_Base
	{
		MoveSounds[] = { "pickUpCourierBag_Light_SoundSet" };
	};
	class TripwireTrap : Trap_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class RabbitSnareTrap : Trap_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","baseballbat_drop_SoundSet" };
	};
	class TruckBattery : Inventory_Base
	{
		MoveSounds[] = { "carbattery_drop_SoundSet" };
	};
	class CarBattery : Inventory_Base
	{
		MoveSounds[] = { "carbattery_drop_SoundSet" };
	};
	class BrakeFluid : Inventory_Base
	{
		MoveSounds[] = { "engineoil_pickup_SoundSet" };
	};
	class EngineOil : Inventory_Base
	{
		MoveSounds[] = { "engineoil_pickup_SoundSet" };
	};
	class CarRadiator : Inventory_Base
	{
		MoveSounds[] = { "pickUpCanisterGasolineLight_SoundSet" };
	};
	class HeadlightH7 : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class HeadlightH7_Box : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class SparkPlug : Inventory_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class TireRepairKit : Inventory_Base
	{
		MoveSounds[] = { "smallprotectorcase_pickup_SoundSet" };
	};
	class CanisterGasoline : Bottle_Base
	{
		MoveSounds[] = { "pickUpCanisterGasolineLight_SoundSet","pickUpCanisterGasoline_SoundSet" };
	};
	class CarWheel : Inventory_Base
	{
		MoveSounds[] = { "hatchbackwheel_drop_SoundSet" };
	};
	class CarDoor : Inventory_Base
	{
		MoveSounds[] = { "hatchbackdoors_driver_pickup_SoundSet" };
	};
	class AmmoBox_556x45_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_556x45Tracer_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_308Win_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_308WinTracer_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_762x54_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_762x54Tracer_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_762x39_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_762x39Tracer_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_22_50Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_357_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_45ACP_25rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_9x19_25rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_380_35rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_00buck_10rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_12gaSlug_10Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_12gaRubberSlug_10Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_12gaBeanbag_10Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_545x39_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_545x39Tracer_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_9x39AP_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class AmmoBox_9x39_20Rnd : Box_Base
	{
		MoveSounds[] = { "ammoboxUnpack_SoundSet" };
	};
	class UniversalLight : Switchable_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class TLRLight : Switchable_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class AK_Bayonet : Inventory_Base
	{
		MoveSounds[] = { "CombatKnife_drop_SoundSet" };
	};
	class M9A1_Bayonet : Inventory_Base
	{
		MoveSounds[] = { "CombatKnife_drop_SoundSet" };
	};
	class Mosin_Bayonet : Inventory_Base
	{
		MoveSounds[] = { "CombatKnife_drop_SoundSet" };
	};
	class SKS_Bayonet : Inventory_Base
	{
		MoveSounds[] = { "CombatKnife_drop_SoundSet" };
	};
	class Mosin_Compensator : ItemSuppressor
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class MP5_Compensator : ItemSuppressor
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class ImprovisedSuppressor : ItemSuppressor
	{
		MoveSounds[] = { "WaterBottle_pickup_SoundSet" };
	};
	class M4_Suppressor : ItemSuppressor
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class AK_Suppressor : ItemSuppressor
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class PistolSuppressor : ItemSuppressor
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class MakarovPBSuppressor : ItemSuppressor
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class M4_OEBttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class M4_MPBttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class M4_CQBBttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class AK_WoodBttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class AK74_WoodBttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class AK_FoldingBttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class AK_PlasticBttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class AKS74U_Bttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class MP5k_StockBttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class Red9Bttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class Fal_OeBttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class Fal_FoldingBttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class Saiga_Bttstck : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class M4_PlasticHndgrd : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class M4_RISHndgrd : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class M4_MPHndgrd : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class AK_WoodHndgrd : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class AK74_Hndgrd : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class AK_RailHndgrd : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class AK_PlasticHndgrd : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class MP5_PlasticHndgrd : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class MP5_RailHndgrd : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class M249_Hndgrd : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class M249_RisHndgrd : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class AtlasBipod : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class M249_Bipod : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class GhillieAtt_ColorBase : Inventory_Base
	{
		MoveSounds[] = { "Cloth_Back_walkCro_ghillie_Soundset","Cloth_Back_runCro_ghillie_Soundset","Cloth_Back_walkErc_ghillie_Soundset","Cloth_Back_walkRasErc_ghillie_Soundset","Cloth_Back_runErc_ghillie_Soundset","Cloth_Back_runRasErc_ghillie_Soundset","Cloth_Back_sprintErc_ghillie_Soundset","Cloth_Back_shortmove_ghillie_Soundset" };
	};
	class Grenade_Base : Inventory_Base
	{
		MoveSounds[] = { "MagRifle_empty_in_SoundSet" };
	};
	class WoodAxe : Inventory_Base
	{
		MoveSounds[] = { "woodaxe_drop_SoundSet" };
	};
	class Hatchet : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_light_SoundSet" };
	};
	class FirefighterAxe : Inventory_Base
	{
		MoveSounds[] = { "woodaxe_drop_SoundSet" };
	};
	class Cleaver : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet" };
	};
	class CombatKnife : Inventory_Base
	{
		MoveSounds[] = { "combatknife_drop_SoundSet" };
	};
	class HuntingKnife : Inventory_Base
	{
		MoveSounds[] = { "combatknife_drop_SoundSet" };
	};
	class Machete : Inventory_Base
	{
		MoveSounds[] = { "combatknife_drop_SoundSet" };
	};
	class Pitchfork : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet" };
	};
	class Pickaxe : Inventory_Base
	{
		MoveSounds[] = { "pickUpShovel_SoundSet" };
	};
	class Sword : Inventory_Base
	{
		MoveSounds[] = { "pickUpShovel_SoundSet" };
	};
	class BaseballBat : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","hatchet_pickup_light_SoundSet" };
	};
	class NailedBaseballBat : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","hatchet_pickup_light_SoundSet" };
	};
	class PipeWrench : Inventory_Base
	{
		MoveSounds[] = { "crowbar_drop_SoundSet" };
	};
	class BrassKnuckles_ColorBase : Inventory_Base
	{
		MoveSounds[] = { "pickUpCableReelLight_SoundSet" };
	};
	class TelescopicBaton : Inventory_Base
	{
		MoveSounds[] = { "Baton_deploy_SoundSet" };
	};
	class HockeyStick : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","hatchet_pickup_light_SoundSet" };
	};
	class NewHockeyStick : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","hatchet_pickup_light_SoundSet" };
	};
	class PoliceBaton : Inventory_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","hatchet_pickup_light_SoundSet" };
	};
	class Chainsaw : Switchable_Base
	{
		MoveSounds[] = { "pickUpPowerGenerator_SoundSet" };
	};
	class CattleProd : Powered_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","hatchet_pickup_light_SoundSet" };
	};
	class StunBaton : Powered_Base
	{
		MoveSounds[] = { "hatchet_pickup_SoundSet","hatchet_pickup_light_SoundSet" };
	};
};
class CfgMagazines
{
	class DefaultMagazine;
	class Magazine_Base : DefaultMagazine
	{
		MoveSounds[] = { "MagRifle_empty_in_SoundSet" };
	};
	class Ammunition_Base : Magazine_Base
	{
		MoveSounds[] = { "MoveSound_Bullet_Move_Smoll" };
	};
	class Ammo_12gaPellets : Ammunition_Base
	{
		MoveSounds[] = { "MoveSound_ShotgunShell_Move_Smoll" };
	};
	class Ammo_12gaSlug : Ammunition_Base
	{
		MoveSounds[] = { "MoveSound_ShotgunShell_Move_Smoll" };
	};
	class Ammo_12gaRubberSlug : Ammunition_Base
	{
		MoveSounds[] = { "MoveSound_ShotgunShell_Move_Smoll" };
	};
	class Ammo_12gaBeanbag : Ammunition_Base
	{
		MoveSounds[] = { "MoveSound_ShotgunShell_Move_Smoll" };
	};
	class Ammo_Flare : Ammunition_Base
	{
		MoveSounds[] = { "MoveSound_ShotgunShell_Move_Smoll" };
	};
	class Ammo_ArrowComposite : Ammunition_Base
	{
		MoveSounds[] = { "MoveSound_Item_Move_Small" };
	};
	class Ammo_SharpStick : Ammunition_Base
	{
		MoveSounds[] = { "MoveSound_Item_Move_Small" };
	};
	class Ammo_ArrowPrimitive : Ammunition_Base
	{
		MoveSounds[] = { "MoveSound_Item_Move_Small" };
	};
	class Ammo_ArrowBoned : Ammunition_Base
	{
		MoveSounds[] = { "MoveSound_Item_Move_Small" };
	};
	class Ammo_ArrowBolt : Ammunition_Base
	{
		MoveSounds[] = { "MoveSound_Item_Move_Small" };
	};
	class Ammo_DartSyringe : Ammunition_Base
	{
		MoveSounds[] = { "MoveSound_Item_Move_Small" };
	};
	class Mag_357Speedloader_6Rnd : Magazine_Base
	{
		MoveSounds[] = { "PSO11Optic_pickup_SoundSet" };
	};
	class Mag_CLIP762x54_5Rnd : Magazine_Base
	{
		MoveSounds[] = { "MoveSound_Bullet_Move_Smoll" };
	};
	class Mag_762x54Snaploader_2Rnd : Magazine_Base
	{
		MoveSounds[] = { "MoveSound_Bullet_Move_Smoll" };
	};
	class Mag_308WinSnaploader_2Rnd : Magazine_Base
	{
		MoveSounds[] = { "MoveSound_Bullet_Move_Smoll" };
	};
	class Mag_CLIP762x39_10Rnd : Magazine_Base
	{
		MoveSounds[] = { "MoveSound_Bullet_Move_Smoll" };
	};
	class Mag_CLIP9x19_10Rnd : Magazine_Base
	{
		MoveSounds[] = { "MoveSound_Bullet_Move_Smoll" };
	};
	class Mag_12gaSnaploader_2Rnd : Magazine_Base
	{
		MoveSounds[] = { "MoveSound_ShotgunShell_Move_Smoll" };
	};
};
class cfgWeapons
{
	class RifleCore;
	class PistolCore;
	class Rifle_Base : RifleCore
	{
		MoveSounds[] = { "pickUpRifle_SoundSet" };
	};
	class BoltActionRifle_Base : Rifle_Base
	{
		MoveSounds[] = { "pickUpRifleLight_SoundSet" };
	};
	class BoltActionRifle_InnerMagazine_Base : BoltActionRifle_Base
	{
		MoveSounds[] = { "pickUpRifleLight_SoundSet" };
	};
	class Shotgun_Base : Rifle_Base
	{
		MoveSounds[] = { "pickUpRifle_SoundSet" };
	};
	class Pistol_Base : PistolCore
	{
		MoveSounds[] = { "pickUpPistol_SoundSet" };
	};
};
class CfgSoundShaders
{
	class MoveSound_GrenadeBop_Base
	{
		volume = 3;
		range = 25;
		radius = 0.01;
	};
	class MoveSound_GrenadeBop_Concrete_SoundShader : MoveSound_GrenadeBop_Base
	{
		samples[] = { {"DZ\Sounds\Characters\movement\footstep\asphalt_ext\shared\sprinterc_7",1},{"DZ\Sounds\Characters\movement\footstep\asphalt_ext\shared\sprinterc_5",1},{"DZ\Sounds\Characters\movement\footstep\asphalt_ext\shared\walkerc_5",1},{"DZ\Sounds\Characters\movement\footstep\asphalt_ext\shared\sprinterc_2",1},{"DZ\Sounds\Characters\movement\footstep\asphalt_ext\shared\sprinterc_6",1} };
	};
	class MoveSound_GrenadeBop_Metal_SoundShader : MoveSound_GrenadeBop_Base
	{
		samples[] = { {"DZ\Sounds\Characters\movement\footstep\metal_thick_int\shared\sprinterc_3",1},{"DZ\Sounds\Characters\movement\footstep\metal_thick_int\shared\sprinterc_4",1},{"DZ\Sounds\Characters\movement\footstep\metal_thick_int\shared\sprinterc_6",1},{"DZ\Sounds\Characters\movement\footstep\metal_thick_int\shared\sprinterc_7",1},{"DZ\Sounds\Characters\movement\footstep\metal_thick_int\shared\sprinterc_5",1} };
	};
	class MoveSound_Grebadenop_Dirt_SoundShader : MoveSound_GrenadeBop_Base
	{
		volume = 50;
		samples[] = { {"DZ\Sounds\Characters\movement\footstep\dirt_int\shared\runerc_8",1},{"DZ\Sounds\Characters\movement\footstep\dirt_int\shared\sprinterc_1",1},{"DZ\Sounds\Characters\movement\footstep\dirt_int\shared\walkerc_3",1},{"DZ\Sounds\Characters\movement\footstep\dirt_int\shared\runerc_3",1},{"DZ\Sounds\Characters\movement\footstep\dirt_int\shared\sprinterc_4",1} };
	};
	class MoveSound_Grebadenop_Gravel_SoundShader : MoveSound_GrenadeBop_Base
	{
		samples[] = { {"DZ\Sounds\Characters\movement\footstep\gravel_small_ext\shared\runerc_1",1},{"DZ\Sounds\Characters\movement\footstep\gravel_small_ext\shared\runerc_2",1},{"DZ\Sounds\Characters\movement\footstep\gravel_small_ext\shared\sprinterc_3",1},{"DZ\Sounds\Characters\movement\footstep\gravel_small_ext\shared\sprinterc_3",1},{"DZ\Sounds\Characters\movement\footstep\gravel_small_ext\shared\sprinterc_2",1} };
	};
	class MoveSound_Grebadenop_Grass_SoundShader : MoveSound_GrenadeBop_Base
	{
		samples[] = { {"DZ\Sounds\Characters\movement\footstep\cp_grass_tall\boots\scufferc_1",1},{"DZ\Sounds\Characters\movement\footstep\cp_grass_tall\boots\scufferc_3",1},{"DZ\Sounds\Characters\movement\footstep\cp_grass_tall\boots\scufferc_5",1},{"DZ\Sounds\Characters\movement\footstep\cp_grass_tall\boots\scufferc_7",1},{"DZ\Sounds\Characters\movement\footstep\cp_grass_tall\boots\scufferc_8",1} };
	};

	class MoveSound_SoundShader_Base
	{
		volume = 3;
		range = 7.5;
		radius = 1.5;
	};
	class MoveSound_ShotgunShell_Move_SoundShader : MoveSound_SoundShader_Base
	{
		volume = 1;
		samples[] = { {"DZ\Sounds\weapons\shells\shell_12ga_default_1",1},{"DZ\Sounds\weapons\shells\shell_12ga_default_2",1},{"DZ\Sounds\weapons\shells\shell_12ga_default_3",1},{"DZ\Sounds\weapons\shells\shell_12ga_default_4",1},{"DZ\Sounds\weapons\shells\shell_12ga_default_5",1} };
	};
	class MoveSound_Bullet_Move_SoundShader : MoveSound_SoundShader_Base
	{
		samples[] = { {"DZ\Sounds\weapons\firearms\magnum\handling\magnum_bullet_in_01",1},{"DZ\Sounds\weapons\firearms\magnum\handling\magnum_bullet_in_02",1},{"DZ\Sounds\weapons\firearms\magnum\handling\magnum_bullet_in_03",1},{"DZ\Sounds\weapons\firearms\magnum\handling\magnum_bullet_in_04",1},{"DZ\Sounds\weapons\firearms\magnum\handling\magnum_bullet_in_05",1} };
	};
	class MoveSound_Item_Move_Small_SoundShader : MoveSound_SoundShader_Base
	{
		samples[] = { {"DZ\Sounds\Characters\movement\attachment\Backpack\small\runErc_1",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\runErc_2",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\runErc_3",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\runErc_4",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\runErc_5",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\runErc_6",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\runErc_7",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\runErc_8",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\sprintErc_1",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\sprintErc_2",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\sprintErc_3",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\sprintErc_4",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\sprintErc_5",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\sprintErc_6",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\sprintErc_7",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\small\sprintErc_8",1} };
	};
	class MoveSound_Item_Move_Regular_SoundShader : MoveSound_SoundShader_Base
	{
		range = 13.5;
		samples[] = { {"DZ\Sounds\Characters\movement\attachment\Backpack\military\runErc_1",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\runErc_2",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\runErc_3",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\runErc_4",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\runErc_5",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\runErc_6",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\runErc_7",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\runErc_8",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\sprintErc_1",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\sprintErc_2",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\sprintErc_3",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\sprintErc_4",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\sprintErc_5",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\sprintErc_6",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\sprintErc_7",1},{"DZ\Sounds\Characters\movement\attachment\Backpack\military\sprintErc_8",1} };
	};
};
class CfgSoundSets
{
	class MoveSound_GrenadeBop_Base
	{
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
		distanceFilter = "defaultDistanceFilter";
	};
	class MoveSound_GrenadeBop_Metal : MoveSound_GrenadeBop_Base
	{
		soundShaders[] = { "MoveSound_GrenadeBop_Metal_SoundShader" };
	};
	class MoveSound_GrenadeBop_Concrete : MoveSound_GrenadeBop_Base
	{
		soundShaders[] = { "MoveSound_GrenadeBop_Concrete_SoundShader" };
	};
	class MoveSound_GrenadeBop_Dirt : MoveSound_GrenadeBop_Base
	{
		soundShaders[] = { "MoveSound_Grebadenop_Dirt_SoundShader" };
	};
	class MoveSound_GrenadeBop_Gravel : MoveSound_GrenadeBop_Base
	{
		soundShaders[] = { "MoveSound_Grebadenop_Gravel_SoundShader" };
	};
	class MoveSound_GrenadeBop_Grass : MoveSound_GrenadeBop_Base
	{
		soundShaders[] = { "MoveSound_Grebadenop_Grass_SoundShader" };
	};


	class MoveSound_SoundSet_Base
	{
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
		distanceFilter = "defaultDistanceFilter";
	};
	class MoveSound_ShotgunShell_Move_Smoll : MoveSound_SoundSet_Base
	{
		soundShaders[] = { "MoveSound_ShotgunShell_Move_SoundShader" };
	};
	class MoveSound_Bullet_Move_Smoll : MoveSound_SoundSet_Base
	{
		soundShaders[] = { "MoveSound_Bullet_Move_SoundShader" };
	};
	class MoveSound_Item_Move_Small : MoveSound_SoundSet_Base
	{
		soundShaders[] = { "MoveSound_Item_Move_Small_SoundShader" };
	};
	class MoveSound_Item_Move_Regular : MoveSound_SoundSet_Base
	{
		soundShaders[] = { "MoveSound_Item_Move_Regular_SoundShader" };
	};
};