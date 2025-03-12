class CfgPatches
{
	class DZ_Sounds_Effects
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Vehicles_Wheeled" };
	};
};
class CfgSoundSets
{
	class psi_supersonic_SoundSet
	{
		soundShaders[] = { "psi_supersonic_SoundShader" };
		sound3DProcessingType = "infected3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class psi_hit_SoundSet
	{
		soundShaders[] = { "psi_hit_SoundShader" };
		sound3DProcessingType = "infected3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
};
class CfgSoundShaders
{
	class psi_supersonic_SoundShader
	{
		samples[] = { {"\Noosphere\X18Controller\Data\Sounds\psi_supersonic",1} };
		volume = 1;
		range = 200;
	};
	class psi_hit_SoundShader
	{
		samples[] = { {"\Noosphere\X18Controller\Data\Sounds\psi_hit",1} };
		volume = 1.5;
		range = 200;
	};
};