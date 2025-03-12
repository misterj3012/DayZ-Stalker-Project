class CfgPatches
{
	class X18Events_Sounds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Sounds_Effects" };
	};
};
class CfgSoundShaders
{
	class ExclusionZone_Environment_SoundShader
	{
		volume = 1;
		frequency = 1;
		limitation = 0;
		radius = 150;
		range = 150;
	};
	class ExclusionZone_Item_SoundShader
	{
		volume = 1;
		frequency = 1;
		range = 10;
		limitation = 0;
	};
};
class CfgSoundSets
{
	class ExclusionZone_Soundset
	{
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
		distanceFilter = "defaultDistanceFilter";
	};
};