class CfgPatches
{
	class X18SoundManager
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "X18Sounds" };
	};
};
class CfgMods
{
	class X18SoundManager
	{
		name = "X18SoundManager";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18SoundManager/Scripts/Common", "Noosphere/X18SoundManager/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18SoundManager/Scripts/Common", "Noosphere/X18SoundManager/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18SoundManager/Scripts/Common", "Noosphere/X18SoundManager/Scripts/5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class ItemBase;
	class HouseNoDestruct;
	class RadioObject : HouseNoDestruct
	{
		scope = 0;
	};
	class X18_Sound_Radio : RadioObject
	{
		scope = 2;
		displayName = "Radio";
		overrideDrawArea = "20.0";
		forceFarBubble = "true";
		model = "DZ\structures\furniture\eletrical_appliances\radio_b\radio_b.p3d";
	};
	class X18_Sound_Radio_Speaker : RadioObject
	{
		scope = 2;
		displayName = "SpeakerMusic";
		model = "DZ\structures\furniture\School_equipment\intercom_speaker.p3d";
		weight = 36;
		rotationFlags = 16;
		overrideDrawArea = "20.0";
		forceFarBubble = "true";
	};
};