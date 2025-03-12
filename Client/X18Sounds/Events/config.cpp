class CfgPatches
{
	class X18Sounds_Events
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
	class Events_Siren_SoundShader_Settings
	{
		range = 400;
		volume = 1;
	};
	class Events_RadioCode_Siren_SoundShader : Events_Siren_SoundShader_Settings
	{
		samples[] = { {"Noosphere\X18Sounds\Events\Sounds\radiocode",1} };
	};
	class Events_Transmitter_SoundShader_Settings
	{
		range = 7.5;
	};
	class Events_RadioCode_Transmitter_SoundShader : Events_Transmitter_SoundShader_Settings
	{
		samples[] = { {"Noosphere\X18Sounds\Events\Sounds\radiocode",1} };
	};
	class Events_Radio_SoundShader_Settings
	{
		range = 10;
	};
	class Events_RadioCode_Radio_SoundShader : Events_Radio_SoundShader_Settings
	{
		samples[] = { {"Noosphere\X18Sounds\Events\Sounds\radiocode",1} };
	};
	class Events_Vehicle_RadioCode_SoundShader_Settings
	{
		range = 15;
	};
	class Events_Vehicle_RadioCode_SoundShader : Events_Vehicle_RadioCode_SoundShader_Settings
	{
		samples[] = { {"Noosphere\X18Sounds\Events\Sounds\radiocode",1} };
	};
	class Events_Vehicle_CarAlarm_SoundShader_Settings
	{
		range = 100;
		volume = 1;
	};
	class Events_Vehicle_CarAlarm_SoundShader : Events_Vehicle_CarAlarm_SoundShader_Settings
	{
		samples[] = { {"Noosphere\X18Sounds\Events\Sounds\caralarm",1} };
	};
};
class CfgSoundSets
{
	class Event_RadioCode_SoundSet
	{
		sound3DProcessingType = "character3DProcessingType";
		distanceFilter = "defaultDistanceFreqAttenuationFilter";
		volumeCurve = "defaultAmpAttenuationCurve";
		volumeFactor = 1;
		spatial = 1;
		loop = 0;
	};
	class Events_RadioCode_Siren_SoundSet : Event_RadioCode_SoundSet
	{
		soundShaders[] = { "Events_RadioCode_Siren_SoundShader" };
	};
	class Events_RadioCode_Transmitter_SoundSet : Event_RadioCode_SoundSet
	{
		soundShaders[] = { "Events_RadioCode_Transmitter_SoundShader" };
	};
	class Events_RadioCode_Radio_SoundSet : Event_RadioCode_SoundSet
	{
		soundShaders[] = { "Events_RadioCode_Radio_SoundShader" };
	};
	class Events_RadioCode_Vehicle_SoundSet : Event_RadioCode_SoundSet
	{
		soundShaders[] = { "Events_Vehicle_RadioCode_SoundShader" };
	};
	class Event_CarAlarm_SoundSet
	{
		sound3DProcessingType = "Vehicle_Ext_3DProcessingType";
		distanceFilter = "softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve = "defaultAmpAttenuationCurve";
		volumeFactor = 1;
		spatial = 1;
		loop = 0;
	};
	class Events_CarAlarm_Vehicle_SoundSet : Event_CarAlarm_SoundSet
	{
		soundShaders[] = { "Events_Vehicle_CarAlarm_SoundShader" };
	};
};