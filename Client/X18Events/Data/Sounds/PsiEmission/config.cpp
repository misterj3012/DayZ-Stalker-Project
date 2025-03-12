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
	class PsiEmission_Warning_1_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Warning_01",1} };
	};
	class PsiEmission_Alarm_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Alarm",1} };
		volume = 0.75;
		radius = 75;
		range = 3500;
	};
	class PsiEmission_Warning_2_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Warning_02",1} };
	};
	class PsiEmission_Relief_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Relief",1} };
	};
	class PsiEmission_Hit_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Hit_01",1} };
		volume = 0.2;
	};
	class PsiEmission_Voices_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_voices_01",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_voices_02",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_voices_03",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_voices_04",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_voices_05",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_voices_06",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_voices_07",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_voices_08",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_voices_09",1} };
		volume = 0.1;
		radius = 150;
	};
	class PsiEmission_Voices_Loop_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_voices_loop",1} };
		volume = 1;
		radius = 7.5;
		range = 20;
	};
	class PsiEmission_Voices_Static_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_voices_static_02",1} };
		radius = 0.15;
		range = 5;
	};
	class PsiEmission_Lightning_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Lightning_01",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Lightning_02",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Lightning_03",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Lightning_04",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Lightning_05",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Lightning_06",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Lightning_07",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Lightning_08",1} };
		radius = 50;
		range = 20000;
	};
	class PsiEmission_Wave_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_wave_1",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_wave_2",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_wave_3",1} };
		radius = 100;
		range = 20000;
	};
	class PsiEmission_Drone_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_drone1",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_drone2",1} };
		radius = 100;
		range = 20000;
	};
	class PsiEmission_Begin_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_begin_01",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_begin_02",1} };
		radius = 100;
		range = 20000;
	};
	class PsiEmission_End_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_End_01",1} };
		radius = 100;
		range = 20000;
	};
	class PsiEmission_Bass_Soundshader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Bass_01",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Bass_02",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Bass_03",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Bass_04",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Bass_05",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Bass_06",1} };
		volume = 0;
		radius = 12000;
		range = 25000;
	};
	class PsiEmission_Contact_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Contact_01",1}, {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Contact_02",1}, {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Contact_03",1}, {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Contact_04",1} };
	};
	class PsiEmission_Impact_SoundShader : ExclusionZone_Environment_SoundShader
	{
		samples[] = { {"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Impact_01",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Impact_02",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Impact_03",1},{"Noosphere\X18Events\Data\Sounds\PsiEmission\PsiEmission_Impact_04",1} };
		radius = 1600;
		range = 2000;
	};
};
class CfgSoundSets
{
	class ExclusionZone_Soundset;
	class PsiEmission_Warning_1 : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Warning_1_SoundShader" };
	};
	class PsiEmission_Alarm : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Alarm_SoundShader" };
	};
	class PsiEmission_Warning_2 : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Warning_2_SoundShader" };
	};
	class PsiEmission_Begin : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Begin_SoundShader" };
	};
	class PsiEmission_Relief : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Relief_SoundShader" };
	};
	class PsiEmission_Hit : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Hit_SoundShader" };
	};
	class PsiEmission_Lightning : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Lightning_SoundShader" };
	};
	class PsiEmission_Wave : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Wave_SoundShader" };
	};
	class PsiEmission_Drone : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Drone_SoundShader" };
	};
	class PsiEmission_Impact : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Impact_SoundShader" };
	};
	class PsiEmission_Contact : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Contact_SoundShader" };
	};
	class PsiEmission_Bass : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Bass_Soundshader","Emission_Bass2_Soundshader" };
	};
	class PsiEmission_Wind : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Wind_SoundShader" };
	};
	class PsiEmission_Ambient : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Ambient_SoundShader" };
	};
	class PsiEmission_GraviIdle : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_GraviIdle_SoundShader" };
	};
	class PsiEmission_Voices : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Voices_SoundShader" };
	};
	class PsiEmission_Voices_Loop : ExclusionZone_Soundset
	{
		soundShaders[] = { "Emission_Voices_Loop_SoundShader" };
	};
};