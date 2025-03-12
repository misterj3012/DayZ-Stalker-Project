class CfgPatches
{
	class X18Items_SinnerSound
	{
		units[] = { "X18_Sin_BeastMaster_SS_Short" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Characters" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class X18_Sin_BeastMaster_SS_Short : Inventory_Base
	{
		scope = 2;
		displayName = "Azteken-Todespfeife";
		descriptionShort = "Plays the short SinnerSound! (Only Sin!)";
		model = "NH_ChernobylZoneObjects\other\corpses\skeleton\corp_skeleton_part1.p3d";
		itemSize[] = { 1,1 };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class turnOnRadio
				{
					soundSet = "turnOnRadio_SoundSet";
					id = 1006;
				};
				class turnOffRadio
				{
					soundSet = "turnOffRadioNoise_SoundSet";
					id = 1007;
				};
			};
		};
	};
};