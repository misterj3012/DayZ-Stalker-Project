class CfgPatches
{
	class X18Sounds_Factions
	{
		units[] = {};
		ammo[] = {};
		weapons[] = {};
		magazines[] = {};
		requiredVersion = 1.6;
		requiredAddons[] = { "DZ_Data" };
	};
};
class CfgSoundShaders
{
	class Factions_SoundShader_Settings
	{
		range = 2000;
		volume = 1;
	};
	class Factions_SinnerSound_Short_SoundShader : Factions_SoundShader_Settings
	{
		samples[] = { {"Noosphere\X18Sounds\Factions\Sounds\SinnerSound_Short",1} };
	};
};
class CfgSoundSets
{
	class Event_SinnerSound_Short_SoundSet
	{
		sound3DProcessingType = "character3DProcessingType";
		distanceFilter = "defaultDistanceFreqAttenuationFilter";
		volumeCurve = "defaultAmpAttenuationCurve";
		volumeFactor = 1;
		spatial = 1;
		loop = 0;
	};
	class Factions_SinnerSound_Short_SoundSet : Event_SinnerSound_Short_SoundSet
	{
		soundShaders[] = { "Factions_SinnerSound_Short_SoundShader" };
	};
};