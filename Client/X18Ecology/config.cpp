class CfgPatches
{
	class X18Ecology
	{
		units[] = {};
		ammo[] = {};
		weapons[] = {};
		magazines[] = {};
		requiredVersion = 1.6;
		requiredAddons[] = { "X18CoreScripts", "DZ_Characters_Masks", "DZ_AreaofDecay_Masks_GP7", "CP_Bagger" };
	};
};
class CfgMods
{
	class X18Ecology
	{
		dir = "X18Ecology";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "X18Ecology";
		author = "MisterJ";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Ecology/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Ecology/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Ecology/Scripts/5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class GeigerCounter_Base : Inventory_Base
	{
		scope = 0;
		weight = 2500;
		itemSize[] = { 3, 2 };
		SingleUseActions[] = { 509, 510 };
		animClass = "Pistol";
		rotationFlags = 2;
		isMeleeWeapon = 1;
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
		attachments[] = { "BatteryD" };
		repairableWithKits[] = { 5, 7 };
		repairCosts[] = { 30, 25 };
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.028;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 0.5;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLabels[] = { 1, 0.7, 0.5, 0.3, 0 };
					healthLevels[] = { {1, {"Noosphere\X18Ecology\Data\Textures\geiger_counter.rvmat"}}, {0.5, {"Noosphere\X18Ecology\Data\Textures\geiger_counter.rvmat"}}, {0, {"Noosphere\X18Ecology\Data\Textures\geiger_counter.rvmat"}} };
				};
			};
		};
	};
	class X18_Tools_GeigerCounter_High : GeigerCounter_Base
	{
		scope = 2;
		displayName = "#STR_GeigerCounter_High";
		descriptionShort = "#STR_DSC_GeigerCounter_High";
		model = "Noosphere\X18Ecology\Data\GeigerCounter_CD_VF-815.p3d";
		weight = 2500;
		itemSize[] = { 3, 2 };
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.0135;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 0.5;
		};
	};
	class X18_Tools_GeigerCounter_Mid : X18_Tools_GeigerCounter_High
	{
		scope = 2;
		displayName = "#STR_GeigerCounter_Middle";
		descriptionShort = "#STR_DSC_GeigerCounter_Middle";
		model = "Noosphere\X18Ecology\Data\GeigerCounter_BR-10A.p3d";
		weight = 750;
		itemSize[] = { 1, 3 };
		hiddenSelections[] = { "base", "screen" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Ecology\Data\Textures\GeigerCounter_co.paa", "Noosphere\X18Ecology\Data\Textures\GeigerCounter_Screen_co.paa" };
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.0095;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 0.5;
		};
	};
	class X18_Tools_GeigerCounter_Low : X18_Tools_GeigerCounter_High
	{
		scope = 2;
		displayName = "#STR_GeigerCounter_Low";
		descriptionShort = "#STR_DSC_GeigerCounter_Low";
		model = "Noosphere\X18Ecology\Data\GeigerCounter_RZ725.p3d";
		weight = 500;
		itemSize[] = { 1, 2 };
		hiddenSelections[] = { "base", "screen" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Ecology\Data\Textures\GeigerCounter_co.paa", "Noosphere\X18Ecology\Data\Textures\GeigerCounter_Screen_co.paa" };
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.0055;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 0.5;
		};
	};
};