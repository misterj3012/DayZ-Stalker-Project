class CfgPatches
{
	class X18ArtefactsSounds
	{
		units[] = {};
		ammo[] = {};
		weapons[] = {};
		magazines[] = {};
		requiredVersion = 1.6;
		requiredAddons[] =
		{
			"DZ_Data"
		};
	};
};
class CfgSoundShaders
{
	class Detector_SoundShader
	{
		samples[] = { {"Noosphere\X18Artefacts\Data\Sounds\Detector_Sound",1} };
		volume = 0.01;
		range = 15;
	};
};
class CfgSoundSets
{
	class Detector_SoundSet
	{
		soundShaders[] = { "Detector_SoundShader" };
		sound3DProcessingType = "infected3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
};