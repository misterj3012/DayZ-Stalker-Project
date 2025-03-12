class CfgPatches
{
	class X18Events_EmissionSounds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Sounds_Effects", "X18Events_Sounds" };
	};
};
class CfgSoundShaders
{
	class ExclusionZone_Environment_SoundShader;
	class Emission_Warning_1_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Warning_01",1} };
	};
	class Emission_Alarm_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Alarm",1} };
		volume = 0.75;
		radius = 75;
		range = 3500;
	};
	class Emission_Warning_2_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Warning_02",1} };
	};
	class Emission_Relief_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Relief",1} };
	};
	class Emission_Hit_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Hit_01",1} };
		volume = 0.2;
	};
	class Emission_Lightning_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Lightning_01",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Lightning_02",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Lightning_03",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Lightning_04",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Lightning_05",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Lightning_06",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Lightning_07",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Lightning_08",1} };
		radius = 50;
		range = 20000;
	};
	class Emission_Wave_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_wave_1",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_wave_2",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_wave_3",1} };
		radius = 100;
		range = 20000;
	};
	class Emission_Drone_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_drone1",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_drone2",1} };
		radius = 100;
		range = 20000;
	};
	class Emission_Begin_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_begin_01",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_begin_02",1} };
		radius = 100;
		range = 20000;
	};
	class Emission_End_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_End_01",1} };
		radius = 100;
		range = 20000;
	};
	class Emission_Bass_Soundshader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Bass_01",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Bass_02",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Bass_03",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Bass_04",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Bass_05",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Bass_06",1} };
		volume = 0;
		radius = 12000;
		range = 25000;
	};
	class Emission_Contact_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Contact_01",1}, {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Contact_02",1}, {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Contact_03",1}, {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Contact_04",1} };
	};
	class Emission_Impact_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\Emission\Emission_Impact_01",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Impact_02",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Impact_03",1},{"Noosphere\X18Events\Data\Sounds\Emission\Emission_Impact_04",1} };
		radius = 1600;
		range = 2000;
	};
};
class CfgSoundSets
{
	class ExclusionZone_Soundset;
	class Emission_Warning_1 : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Warning_1_SoundShader" };
	};
	class Emission_Alarm : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Alarm_SoundShader" };
	};
	class Emission_Warning_2 : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Warning_2_SoundShader" };
	};
	class Emission_Begin : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Begin_SoundShader" };
	};
	class Emission_Relief : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Relief_SoundShader" };
	};
	class Emission_Hit : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Hit_SoundShader" };
	};
	class Emission_Lightning : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Lightning_SoundShader" };
	};
	class Emission_Wave : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Wave_SoundShader" };
	};
	class Emission_Drone : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Drone_SoundShader" };
	};
	class Emission_Impact : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Impact_SoundShader" };
	};
	class Emission_Contact : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Contact_SoundShader" };
	};
	class Emission_Bass : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Bass_Soundshader","Emission_Bass2_Soundshader" };
	};
	class Emission_Wind : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Wind_SoundShader" };
	};
	class Emission_Ambient : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Ambient_SoundShader" };
	};
	class Emission_GraviIdle : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_GraviIdle_SoundShader" };
	};
};