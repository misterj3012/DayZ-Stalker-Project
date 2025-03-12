class CfgPatches
{
	class X18Sounds_Mutants
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Vehicles_Wheeled" };
	};
};
class CfgSoundSets
{
	class Mutant_Base_VoiceFX_Base_SoundSet
	{
		sound3DProcessingType = "infected3DProcessingType";
		distanceFilter = "infectedDistanceFreqAttenuationFilter";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
		occlusionFactor = 1;
		obstructionFactor = 1;
		frequencyFactor = 1;
		volumeFactor = 0.75;
	};
	//---Bloodsucker
	class Mutant_AoD_Krovosos1_Base_LightAttack_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Krovosos1_Base_LightAttack_Shader" };
	};
	class Mutant_AoD_Krovosos1_Base_HeavyAttack_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Krovosos1_Base_HeavyAttack_Shader" };
	};
	class Mutant_AoD_Krovosos1_Base_Die_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Krovosos1_Base_Die_Shader" };
	};
	class Mutant_AoD_Krovosos1_Base_Hit_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Krovosos1_Base_Hit_Shader" };
	};
	class Mutant_AoD_Krovosos1_Base_Invisible_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Krovosos1_Base_Invisible_Shader" };
	};
	class Mutant_AoD_Krovosos1_Base_CallToArms_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Krovosos1_Base_CallToArms_Shader" };
	};
	class Mutant_AoD_Krovosos1_Base_CalmMove_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Krovosos1_Base_CalmMove_Shader" };
		delay = 2;
		delayRandomizer = 1;
		startDelay = 2;
		startDelayRandomizer = 1;
		frequencyFactor = 0.92;
	};
	class Mutant_AoD_Krovosos1_Base_AlertedMove_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Krovosos1_Base_AlertedMove_Shader" };
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.92;
	};
	class Mutant_AoD_Krovosos1_Base_ChaseMove_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Krovosos1_Base_ChaseMove_Shader" };
		delay = 1.5;
		delayRandomizer = 1;
		startDelay = 1;
		startDelayRandomizer = 1;
		frequencyFactor = 0.92;
	};
	class Mutant_AoD_Krovosos1_Base_DisturbedIdle_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Krovosos1_Base_DisturbedIdle_Shader" };
		frequencyFactor = 0.92;
	};
	//---Snork
	class Mutant_AoD_Snork_Base_LightAttack_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Snork_Base_LightAttack_Shader" };
	};
	class Mutant_AoD_Snork_Base_HeavyAttack_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Snork_Base_HeavyAttack_Shader" };
	};
	class Mutant_AoD_Snork_Base_Die_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Snork_Base_Die_Shader" };
	};
	class Mutant_AoD_Snork_Base_Hit_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Snork_Base_Hit_Shader" };
	};
	class Mutant_AoD_Snork_Base_CallToArms_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Snork_Base_CallToArms_Shader" };
	};
	class Mutant_AoD_Snork_Base_CalmMove_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Snork_Base_CalmMove_Shader" };
		delay = 2;
		delayRandomizer = 1;
		startDelay = 2;
		startDelayRandomizer = 1;
		frequencyFactor = 0.92;
	};
	class Mutant_AoD_Snork_Base_AlertedMove_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Snork_Base_AlertedMove_Shader" };
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.92;
	};
	class Mutant_AoD_Snork_Base_ChaseMove_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Snork_Base_ChaseMove_Shader" };
		delay = 1.5;
		delayRandomizer = 1;
		startDelay = 1;
		startDelayRandomizer = 1;
		frequencyFactor = 0.92;
	};
	class Mutant_AoD_Snork_Base_DisturbedIdle_Soundset : Mutant_Base_VoiceFX_Base_SoundSet
	{
		soundShaders[] = { "Mutant_AoD_Snork_Base_DisturbedIdle_Shader" };
		frequencyFactor = 0.92;
	};
};
class CfgSoundShaders
{
	//---Bloodsucker
	class Mutant_AoD_Krovosos1_Base_CallToArms_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Bloodsucker\CallToArms_0",1},{"Noosphere\X18Sounds\Mutants\Bloodsucker\CallToArms_1",1},{"Noosphere\X18Sounds\Mutants\Bloodsucker\CallToArms_2",1},{"Noosphere\X18Sounds\Mutants\Bloodsucker\CallToArms_3",1} };
		volume = 6;
		range = 600;
	};
	class Mutant_AoD_Krovosos1_Base_LightAttack_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Bloodsucker\LightAttack_0",0.25},{"Noosphere\X18Sounds\Mutants\Bloodsucker\LightAttack_1",0.25},{"Noosphere\X18Sounds\Mutants\Bloodsucker\LightAttack_2",0.25} };
		volume = 1;
		range = 60;
	};
	class Mutant_AoD_Krovosos1_Base_HeavyAttack_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Bloodsucker\HeavyAttack_0",0.25},{"Noosphere\X18Sounds\Mutants\Bloodsucker\HeavyAttack_1",0.25} };
		volume = 1;
		range = 60;
	};
	class Mutant_AoD_Krovosos1_Base_Hit_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Bloodsucker\Hit_0",0.5},{"Noosphere\X18Sounds\Mutants\Bloodsucker\Hit_1",0.5},{"Noosphere\X18Sounds\Mutants\Bloodsucker\Hit_2",0.5},{"Noosphere\X18Sounds\Mutants\Bloodsucker\Hit_3",0.5},{"Noosphere\X18Sounds\Mutants\Bloodsucker\Hit_4",0.5},{"Noosphere\X18Sounds\Mutants\Bloodsucker\Hit_5",0.5},{"Noosphere\X18Sounds\Mutants\Bloodsucker\Hit_6",0.5},{"Noosphere\X18Sounds\Mutants\Bloodsucker\Hit_7",0.5} };
		volume = 1;
		range = 60;
	};
	class Mutant_AoD_Krovosos1_Base_Die_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Bloodsucker\Die_0",0.33},{"Noosphere\X18Sounds\Mutants\Bloodsucker\Die_1",0.33},{"Noosphere\X18Sounds\Mutants\Bloodsucker\Die_2",0.33},{"Noosphere\X18Sounds\Mutants\Bloodsucker\Die_3",0.34},{"Noosphere\X18Sounds\Mutants\Bloodsucker\Die_4",0.34} };
		volume = 1;
		range = 60;
	};
	class Mutant_AoD_Krovosos1_Base_CalmMove_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Bloodsucker\CalmMove_0",0.125},{"Noosphere\X18Sounds\Mutants\Bloodsucker\CalmMove_1",0.125},{"Noosphere\X18Sounds\Mutants\Bloodsucker\CalmMove_2",0.125},{"Noosphere\X18Sounds\Mutants\Bloodsucker\CalmMove_3",0.125},{"Noosphere\X18Sounds\Mutants\Bloodsucker\CalmMove_4",0.125},{"Noosphere\X18Sounds\Mutants\Bloodsucker\CalmMove_5",0.125} };
		volume = 0.8;
		range = 60;
	};
	class Mutant_AoD_Krovosos1_Base_ChaseMove_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Bloodsucker\ChaseMove_0",0.125},{"Noosphere\X18Sounds\Mutants\Bloodsucker\ChaseMove_1",0.125} };
		volume = 2;
		range = 60;
	};
	class Mutant_AoD_Krovosos1_Base_DisturbedIdle_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Bloodsucker\DisturbedIdle_0",0.125},{"Noosphere\X18Sounds\Mutants\Bloodsucker\DisturbedIdle_1",0.125} };
		volume = 1.2;
		range = 60;
	};
	class Mutant_AoD_Krovosos1_Base_AlertedMove_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Bloodsucker\AlertedMove_0",0.125},{"Noosphere\X18Sounds\Mutants\Bloodsucker\AlertedMove_1",0.125} };
		volume = 1.2;
		range = 60;
	};
	///---Snork
	class Mutant_AoD_Snork_Base_CallToArms_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Snork\CallToArms_0",1} };
		volume = 3;
		range = 150;
	};
	class Mutant_AoD_Snork_Base_LightAttack_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Snork\LightAttack_0",0.25},{"Noosphere\X18Sounds\Mutants\Snork\LightAttack_1",0.25},{"Noosphere\X18Sounds\Mutants\Snork\LightAttack_2",0.25},{"Noosphere\X18Sounds\Mutants\Snork\LightAttack_3",0.25},{"Noosphere\X18Sounds\Mutants\Snork\LightAttack_4",0.25} };
		volume = 1;
		range = 60;
	};
	class Mutant_AoD_Snork_Base_HeavyAttack_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Snork\HeavyAttack_0",0.25},{"Noosphere\X18Sounds\Mutants\Snork\HeavyAttack_1",0.25},{"Noosphere\X18Sounds\Mutants\Snork\HeavyAttack_2",0.25} };
		volume = 1;
		range = 60;
	};
	class Mutant_AoD_Snork_Base_Hit_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Snork\Hit_0",0.5},{"Noosphere\X18Sounds\Mutants\Snork\Hit_1",0.5},{"Noosphere\X18Sounds\Mutants\Snork\Hit_2",0.5} };
		volume = 1;
		range = 60;
	};
	class Mutant_AoD_Snork_Base_Die_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Snork\Die_0",0.33},{"Noosphere\X18Sounds\Mutants\Snork\Die_1",0.33},{"Noosphere\X18Sounds\Mutants\Snork\Die_2",0.33} };
		volume = 1;
		range = 60;
	};
	class Mutant_AoD_Snork_Base_CalmMove_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Snork\CalmMove_0",0.125},{"Noosphere\X18Sounds\Mutants\Snork\CalmMove_1",0.125},{"Noosphere\X18Sounds\Mutants\Snork\CalmMove_2",0.125},{"Noosphere\X18Sounds\Mutants\Snork\CalmMove_3",0.125},{"Noosphere\X18Sounds\Mutants\Snork\CalmMove_4",0.125},{"Noosphere\X18Sounds\Mutants\Snork\CalmMove_5",0.125} };
		volume = 0.8;
		range = 60;
	};
	class Mutant_AoD_Snork_Base_ChaseMove_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Snork\ChaseMove_0",0.125},{"Noosphere\X18Sounds\Mutants\Snork\ChaseMove_1",0.125} };
		volume = 2;
		range = 60;
	};
	class Mutant_AoD_Snork_Base_DisturbedIdle_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Snork\DisturbedIdle_0",0.125},{"Noosphere\X18Sounds\Mutants\Snork\DisturbedIdle_1",0.125},{"Noosphere\X18Sounds\Mutants\Snork\DisturbedIdle_2",0.125},{"Noosphere\X18Sounds\Mutants\Snork\DisturbedIdle_3",0.125} };
		volume = 1.2;
		range = 60;
	};
	class Mutant_AoD_Snork_Base_AlertedMove_Shader
	{
		samples[] = { {"Noosphere\X18Sounds\Mutants\Snork\AlertedMove_0",0.125},{"Noosphere\X18Sounds\Mutants\Snork\AlertedMove_1",0.125} };
		volume = 1.2;
		range = 60;
	};
};
class CfgSounds
{
	class default
	{
		name = "";
		titles[] = {};
	};
	class Mutant_AoD_Krovosos1_Base_CloakedEngaged : default
	{
		sound[] = { "Noosphere\X18Sounds\Mutants\Bloodsucker\Invisible_0",2.0,1,30 };
	};
	class Mutant_AoD_Krovosos1_Base_CloakedDisengaged : default
	{
		sound[] = { "Noosphere\X18Sounds\Mutants\Bloodsucker\Invisible_1",2.0,1,30 };
	};
};