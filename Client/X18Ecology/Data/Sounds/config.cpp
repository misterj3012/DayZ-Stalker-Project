class CfgPatches
{
	class X18EcologySounds
	{
		units[] = {};
		ammo[] = {};
		weapons[] = {};
		magazines[] = {};
		requiredVersion = 1.6;
		requiredAddons[] = {
			"DZ_Data"
		};
	};
};
class CfgSoundShaders
{
	class Geiger_Detect_SoundShader
	{
		samples[] = {
			{"Noosphere\X18Ecology\Data\Sounds\Geiger_Detect_1",0.2},
			{"Noosphere\X18Ecology\Data\Sounds\Geiger_Detect_2",0.2},
			{"Noosphere\X18Ecology\Data\Sounds\Geiger_Detect_3",0.2},
			{"Noosphere\X18Ecology\Data\Sounds\Geiger_Detect_4",0.2},
			{"Noosphere\X18Ecology\Data\Sounds\Geiger_Detect_5",0.2},
			{"Noosphere\X18Ecology\Data\Sounds\Geiger_Detect_6",0.2}
		};
		volume = 0.05;
		range = 15;
	};
};
class CfgSoundSets
{
	class Geiger_Detect_SoundSet
	{
		soundShaders[] = { "Geiger_Detect_SoundShader" };
		sound3DProcessingType = "infected3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
};