class CfgPatches
{
	class X18RadioToggle
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18RadioToggle
	{
		name = "X18RadioToggle";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		inputs = "Noosphere\X18RadioToggle\Data\modded_inputs.xml";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18RadioToggle/Scripts/Common", "Noosphere/X18RadioToggle/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18RadioToggle/Scripts/Common", "Noosphere/X18RadioToggle/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18RadioToggle/Scripts/Common", "Noosphere/X18RadioToggle/Scripts/5_Mission" };
			};
		};
	};
};
class CfgSoundShaders
{
	class RadioPTT_Self_Down_SoundShader
	{
		samples[] = { {"\Noosphere\X18RadioToggle\Data\Sounds\down", 1} };
		volume = 1.0;
	};
	class RadioPTT_Self_Up_SoundShader
	{
		samples[] = { {"\Noosphere\X18RadioToggle\Data\Sounds\up", 1} };
		volume = 1.0;
	};
};
class CfgSoundSets
{
	class RadioPTT_Self_Down_SoundSet
	{
		soundShaders[] = { "RadioPTT_Self_Down_SoundShader" };
		volumeFactor = 0.33;
		frequencyFactor = 1;
	};
	class RadioPTT_Self_Up_SoundSet
	{
		soundShaders[] = { "RadioPTT_Self_Up_SoundShader" };
		volumeFactor = 0.33;
		frequencyFactor = 1;
	};
};