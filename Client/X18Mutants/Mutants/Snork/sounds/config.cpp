class CfgPatches
{
	class DZ_Sounds_Effects
	{
		units[] = { "Sound_Owl","Sound_Stream","Sound_Frog","Sound_Frogs","Sound_Alarm","Sound_Alarm2","Sound_Fire","Sound_BirdSinging","Sound_Crickets1","Sound_Crickets2","Sound_Crickets3","Sound_Crickets4","Sound_Chicken","Sound_Cock","Sound_Cow","Sound_Crow","Sound_Wolf","Sound_Dog","Sound_BadDog","Sound_SorrowDog","Sound_LittleDog","Sound_Music","Sound_Factory01","Sound_Factory02","Sound_Factory03","Sound_Factory04","Sound_Factory05","Sound_Factory06","Sound_Factory07","Sound_Factory08","Sound_Factory09","Sound_Factory10","Sound_Factory11","Sound_Factory12","Sound_Factory13","Sound_Factory14","Sound_Factory15","Sound_Factory16","Sound_Factory17","Sound_Factory18","Sound_Flies" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Vehicles_Wheeled" };
	};
};
class CfgSoundSets
{
	class FV_ST_PACK_Snork_Attack_Soundset
	{
		soundShaders[] = { "FV_ST_PACK_SnorkAttack" };
		sound3DProcessingType = "infected3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class FV_ST_PACK_Snork_Popal_Soundset
	{
		soundShaders[] = { "FV_ST_PACK_Snork_Popal" };
		sound3DProcessingType = "infected3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class FV_ST_PACK_Snork_AGGR_Soundset
	{
		soundShaders[] = { "FV_ST_PACK_snork_AGGR" };
		sound3DProcessingType = "infected3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
};
class CfgSoundShaders
{
	class FV_ST_PACK_SnorkAttack
	{
		samples[] = { {"Noosphere\X18Mutants\Mutants\Snork\Sounds\udar",0.125},{"Noosphere\X18Mutants\Mutants\Snork\Sounds\udar2",0.125},{"Noosphere\X18Mutants\Mutants\Snork\Sounds\udar3",0.125},{"Noosphere\X18Mutants\Mutants\Snork\Sounds\udar4",0.125},{"Noosphere\X18Mutants\Mutants\Snork\Sounds\udar5",0.125} };
		volume = 0.9;
		range = 90;
	};
	class FV_ST_PACK_Snork_Popal
	{
		samples[] = { {"Noosphere\X18Mutants\Mutants\Snork\Sounds\popal",0.125},{"Noosphere\X18Mutants\Mutants\Snork\Sounds\popal2",0.125} };
		volume = 0.1;
		range = 20;
	};
	class FV_ST_PACK_snork_AGGR
	{
		samples[] = { {"Noosphere\X18Mutants\Mutants\Snork\Sounds\agr",0.125},{"Noosphere\X18Mutants\Mutants\Snork\Sounds\agr2",0.125},{"Noosphere\X18Mutants\Mutants\Snork\Sounds\agr3",0.125},{"Noosphere\X18Mutants\Mutants\Snork\Sounds\agr4",0.125},{"Noosphere\X18Mutants\Mutants\Snork\Sounds\agr5",0.125},{"Noosphere\X18Mutants\Mutants\Snork\Sounds\agr6",0.125} };
		volume = 1;
		range = 215;
	};
};