class CfgPatches
{
	class X18Artefacts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts","JPC_Vest","quadlock" };
	};
};
class CfgMods
{
	class X18Artefacts
	{
		name = "X18Artefacts";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Artefacts/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Artefacts/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Artefacts/Scripts/5_Mission" };
			};
		};
	};
};
class CfgSlots
{
	class Slot_Artefact1
	{
		name = "ArtefactSlot1";
		displayName = "Artefact";
		ghostIcon = "set:nh_attachments image:Art";
	};
	class Slot_Artefact2
	{
		name = "ArtefactSlot2";
		displayName = "Artefact";
		ghostIcon = "set:nh_attachments image:Art";
	};
	class Slot_Artefact3
	{
		name = "ArtefactSlot3";
		displayName = "Artefact";
		ghostIcon = "set:nh_attachments image:Art";
	};
	class Slot_Artefact4
	{
		name = "ArtefactSlot4";
		displayName = "Artefact";
		ghostIcon = "set:nh_attachments image:Art";
	};
	class Slot_Artefact5
	{
		name = "ArtefactSlot5";
		displayName = "Artefact";
		ghostIcon = "set:nh_attachments image:Art";
	};
	class Slot_BatteryArtefact
	{
		name = "BatteryArtefact";
		displayName = "BatteryArtefact";
		selection = "BatteryArtefact";
		ghostIcon = "carbattery";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyArtefact1 : ProxyAttachment
	{
		scope = 2;
		model = "\Noosphere\X18Artefacts\Models\Container\Proxy\Artefact1.p3d";
		inventorySlot[] = { "ArtefactSlot1" };
	};
	class ProxyArtefact2 : ProxyAttachment
	{
		scope = 2;
		model = "\Noosphere\X18Artefacts\Models\Container\Proxy\Artefact2.p3d";
		inventorySlot[] = { "ArtefactSlot2" };
	};
	class ProxyArtefact3 : ProxyAttachment
	{
		scope = 2;
		model = "\Noosphere\X18Artefacts\Models\Container\Proxy\Artefact3.p3d";
		inventorySlot[] = { "ArtefactSlot3" };
	};
	class ProxyBattery : ProxyAttachment
	{
		scope = 2;
		model = "Noosphere\X18Artefacts\Models\ArtefactCharger\Proxies\Battery.p3d";
		inventorySlot[] = { "BatteryArtefact" };
	};
	class ProxyChargedArtefact : ProxyAttachment
	{
		scope = 2;
		model = "Noosphere\X18Artefacts\Models\ArtefactCharger\Proxies\ChargedArtefact.p3d";
		inventorySlot[] = { "ArtefactSlot1" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class HouseNoDestruct;
	class SmallProtectorCase;
	class ItemCompass;
	class Container_Base;
	class Detector_Base : Inventory_Base
	{
		scope = 0;
		displayName = "NONE";
		descriptionShort = "NONE";
		rotationFlags = 34;
		weight = 320;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1,{"DZ\gear\navigation\Data\compass.rvmat"}},{0.7,{"DZ\gear\navigation\Data\compass.rvmat"}},{0.5,{"DZ\gear\navigation\Data\compass_damage.rvmat"}},{0.3,{"DZ\gear\navigation\Data\compass_damage.rvmat"}},{0,{"DZ\gear\navigation\Data\compass_destruct.rvmat"}} };
				};
			};
		};
		class AnimationSources
		{
			class cover
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
		};
		attachments[] = { "BatteryD" };
		repairableWithKits[] = { 5,7 };
		repairCosts[] = { 30,25 };
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOffWhenInCargo = 1;
			energyUsagePerSecond = 0.027;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 1.0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class compass_open
				{
					soundSet = "compass_open_SoundSet";
					id = 204;
				};
				class compass_close
				{
					soundSet = "compass_close_SoundSet";
					id = 205;
				};
			};
		};
	};
	class X18_Artefact_Detector_Echo : Detector_Base
	{
		scope = 2;
		displayName = "$STR_Detector_Echo";
		descriptionShort = "$STR_DSC_Detector_Echo";
		model = "\Noosphere\X18Artefacts\Models\Detector\Detector_Echo.p3d";
		itemSize[] = { 1,3 };
		weight = 310;
		repairableWithKits[] = { 5,7 };
		repairCosts[] = { 30,25 };
		hiddenSelections[] = { "led","lamp" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Artefacts\Models\Detector\Test\green_ca.paa","Noosphere\X18Artefacts\Models\Detector\Test\blue_ca.paa" };
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOffWhenInCargo = 1;
			energyUsagePerSecond = 0.008;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 1.0;
		};
		class AnimationSources
		{
			class Open
			{
				source = "user";
				animPeriod = 0.25;
				initPhase = 0;
			};
		};
	};
	class X18_Artefact_Detector_Bear : Detector_Base
	{
		scope = 2;
		displayName = "$STR_Detector_Bear";
		descriptionShort = "$STR_DSC_Detector_Bear";
		model = "\Noosphere\X18Artefacts\Models\Detector\Detector_Bear.p3d";
		hiddenSelections[] = { "num1","num2","num3","num4","num5","num6","num7","num8","num9","num10","num11","num12","num13","num14","num15","num16","num17","num18","num19","num20","num21","num22","num23","num24","num25" };
		itemSize[] = { 1,3 };
		weight = 410;
		repairableWithKits[] = { 5,7 };
		repairCosts[] = { 50,90 };
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOffWhenInCargo = 1;
			energyUsagePerSecond = 0.011;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 1.0;
		};
		class AnimationSources
		{
			class cover
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
		};
	};
	class X18_Artefact_Detector_Veles : Detector_Base
	{
		scope = 2;
		displayName = "$STR_Detector_Veles";
		descriptionShort = "$STR_DSC_Detector_Veles";
		model = "\Noosphere\X18Artefacts\Models\Detector\Detector_Veles.p3d";
		hiddenSelections[] = { "num1","num2","num3","num4","num5","num6","num7","num8" };
		itemSize[] = { 1,3 };
		weight = 410;
		repairableWithKits[] = { 5,7 };
		repairCosts[] = { 50,90 };
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOffWhenInCargo = 1;
			energyUsagePerSecond = 0.027;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 1.0;
		};
	};
	class X18_Artefact_Container_Base : Container_Base
	{
		scope = 0;
		allowOwnedCargoManipulation = 1;
		destroyOnEmpty = 0;
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "smallprotectorcase_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "smallprotectorcase_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_Container_1_Base : X18_Artefact_Container_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Container_1";
		descriptionShort = "$STR_DSC_Artefact_Container";
		weight = 4000;
		itemSize[] = { 2,2 };
		attachments[] = { "ArtefactSlot1" };
		model = "\Noosphere\X18Artefacts\Models\Container\PKA1.p3d";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA1\pka1.rvmat" };
		class AnimationSources
		{
			class Open
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1.0,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0.0,{""}} };
				};
			};
		};
	};
	class X18_Artefact_Container_1_Brown : X18_Artefact_Container_1_Base
	{
		scope = 2;
		itemSize[] = { 1,3 };
	};
	class X18_Artefact_Container_1_Old : X18_Artefact_Container_1_Base
	{
		scope = 2;
		model = "items\p3d\Container.p3d";
	};
	class X18_Artefact_Container_2_Base : X18_Artefact_Container_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Container_2";
		descriptionShort = "$STR_DSC_Artefact_Container";
		model = "\Noosphere\X18Artefacts\Models\Container\PKA9.p3d";
		weight = 8000;
		itemSize[] = { 2,3 };
		attachments[] = { "ArtefactSlot1","ArtefactSlot2" };
		hiddenSelections[] = { "camoGround","ruchka" };
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class hands : AnimSourceShown {};
			class back : AnimSourceHidden {};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = { {1.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9.rvmat"}},{0.7,{"Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9.rvmat"}},{0.5,{"Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9_damage.rvmat"}},{0.3,{"Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9_damage.rvmat"}},{0.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Artefact_Container_2_Green : X18_Artefact_Container_2_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9_co.paa","Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9_ruchka_co.paa" };
		hiddenSelectionsMaterials[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9.rvmat","Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9_ruchka.rvmat" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = { {1.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9.rvmat"}},{0.7,{"Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9.rvmat"}},{0.5,{"Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9_damage.rvmat"}},{0.3,{"Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9_damage.rvmat"}},{0.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA9\pka9_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Artefact_Container_2_Eco : X18_Artefact_Container_2_Base
	{
		scope = 2;
		model = "\Noosphere\X18Artefacts\Models\Container\PKA3.p3d";
		descriptionShort = "Wissenschaftlicher Sicherheitsbehälter zum Transportieren von Gefahrgut. Durch seine qualitative Verarbeitung und abschirmenden Eigenschaften eignet er sich auch zum Transportieren von Artefakten oder anderen hochradioaktiven Materialien.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA3\pka3_co.paa" };
		hiddenSelectionsMaterials[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA3\pka3.rvmat" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = { {1.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA3\pka3.rvmat"}},{0.7,{"Noosphere\X18Artefacts\Models\Container\Data\PKA3\pka3.rvmat"}},{0.5,{"Noosphere\X18Artefacts\Models\Container\Data\PKA3\pka3_damage.rvmat"}},{0.3,{"Noosphere\X18Artefacts\Models\Container\Data\PKA3\pka3_damage.rvmat"}},{0.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA3\pka3_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Artefact_Container_3_Base : X18_Artefact_Container_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Container_3";
		descriptionShort = "$STR_DSC_Artefact_Container";
		model = "\Noosphere\X18Artefacts\Models\Container\PKA114.p3d";
		itemBehaviour = 1;
		weight = 16000;
		itemSize[] = { 2,4 };
		attachments[] = { "ArtefactSlot1","ArtefactSlot2","ArtefactSlot3" };
		hiddenSelections[] = { "camoGround","glass" };
	};
	class X18_Artefact_Container_3_YellowRust : X18_Artefact_Container_3_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_co.paa","Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_Glass_ca.paa" };
		hiddenSelectionsMaterials[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114.rvmat","Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_glass.rvmat" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = { {1.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114.rvmat"}},{0.7,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114.rvmat"}},{0.5,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_damage.rvmat"}},{0.3,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_damage.rvmat"}},{0.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Artefact_Container_3_Black : X18_Artefact_Container_3_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_black_co.paa","Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_Glass_ca.paa" };
		hiddenSelectionsMaterials[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_black.rvmat","Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_glass.rvmat" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = { {1.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_black.rvmat"}},{0.7,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_black.rvmat"}},{0.5,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_black_damage.rvmat"}},{0.3,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_black_damage.rvmat"}},{0.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_black_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Artefact_Container_3_Green : X18_Artefact_Container_3_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_green_co.paa","Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_Glass_ca.paa" };
		hiddenSelectionsMaterials[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_green.rvmat","Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_glass.rvmat" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = { {1.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_green.rvmat"}},{0.7,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_green.rvmat"}},{0.5,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_green_damage.rvmat"}},{0.3,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_green_damage.rvmat"}},{0.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_green_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Artefact_Container_3_Orange : X18_Artefact_Container_3_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_Orange_co.paa","Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_Glass_ca.paa" };
		hiddenSelectionsMaterials[] = { "Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_Orange.rvmat","Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_glass.rvmat" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = { {1.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_Orange.rvmat"}},{0.7,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_Orange.rvmat"}},{0.5,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_Orange_damage.rvmat"}},{0.3,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_Orange_damage.rvmat"}},{0.0,{"Noosphere\X18Artefacts\Models\Container\Data\PKA114\pka114_Orange_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Artefact_Base : Inventory_Base
	{
		scope = 0;
		displayName = "ArtefactBase";
		isMeleeWeapon = 1;
		weight = 500;
		itemSize[] = { 2,2 };
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 60;
		varQuantityMin = 0;
		varQuantityMax = 60;
		varQuantityDestroyOnMin = 1;
		varTemperatureMax = 1000;
		inventorySlot[] = { "ArtefactSlot1","ArtefactSlot2","ArtefactSlot3","ArtefactSlot4","ArtefactSlot5" };
		rotationFlags = 17;
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeBlunt";
				range = 1;
			};
			class Heavy
			{
				ammo = "MeleeBlunt_Heavy";
				range = 1;
			};
			class Sprint
			{
				ammo = "MeleeBlunt_Heavy";
				range = 2.8;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
		};
	};
	class X18_Artefact_Spawn_Base : HouseNoDestruct
	{
		scope = 0;
		displayName = "ArtefactSpawnBase";
		model = "Noosphere\X18Artefacts\Models\EmptySphere.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
		};
	};
	class X18_Artefact_AlteredInsulator_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_AlteredInsulator";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\AlteredInsulator\AlteredInsulator.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 45;
			energyAtSpawn = 45;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_AlteredInsulator : X18_Artefact_AlteredInsulator_Base
	{
		scope = 2;
	};
	class X18_Artefact_AlteredInsulator_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_AlteredWheel_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_AlteredWheel";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\AlteredWheel\AlteredWheel.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_AlteredWheel : X18_Artefact_AlteredWheel_Base
	{
		scope = 2;
	};
	class X18_Artefact_AlteredWheel_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_BallOfTwine_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_BallOfTwine";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\BallOfTwine\BallOfTwine.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 45;
			energyAtSpawn = 45;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_BallOfTwine : X18_Artefact_BallOfTwine_Base
	{
		scope = 2;
	};
	class X18_Artefact_BallOfTwine_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Battery_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Battery";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Battery\Battery.p3d";
		inventorySlot[] += { "BatteryArtefact" };
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Battery : X18_Artefact_Battery_Base
	{
		scope = 2;
	};
	class X18_Artefact_Battery_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Bubble_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Bubble";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Bubble\Bubble.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 45;
			energyAtSpawn = 45;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Bubble : X18_Artefact_Bubble_Base
	{
		scope = 2;
	};
	class X18_Artefact_Bubble_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Compass_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Compass";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Compass\Compass.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 15;
			energyAtSpawn = 15;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Compass : X18_Artefact_Compass_Base
	{
		scope = 2;
	};
	class X18_Artefact_Compass_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Crystal_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Crystal";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Crystal\Crystal.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 15;
			energyAtSpawn = 15;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Crystal : X18_Artefact_Crystal_Base
	{
		scope = 2;
	};
	class X18_Artefact_Crystal_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Eye_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Eye";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Eye\Eye.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 45;
			energyAtSpawn = 45;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Eye : X18_Artefact_Eye_Base
	{
		scope = 2;
	};
	class X18_Artefact_Eye_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Fireball_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Fireball";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Fireball\Fireball.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Fireball : X18_Artefact_Fireball_Base
	{
		scope = 2;
	};
	class X18_Artefact_Fireball_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Flame_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Flame";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Flame\Flame.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Flame : X18_Artefact_Flame_Base
	{
		scope = 2;
	};
	class X18_Artefact_Flame_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Flash_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Flash";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Flash\Flash.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Flash : X18_Artefact_Flash_Base
	{
		scope = 2;
	};
	class X18_Artefact_Flash_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Goldfish_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Goldfish";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Goldfish\Goldfish.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Goldfish : X18_Artefact_Goldfish_Base
	{
		scope = 2;
	};
	class X18_Artefact_Goldfish_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Gravi_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Gravi";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Gravi\Gravi.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Gravi : X18_Artefact_Gravi_Base
	{
		scope = 2;
	};
	class X18_Artefact_Gravi_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_HeartOfTheOasis_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_HeartOfTheOasis";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\HeartOfTheOasis\HeartOfTheOasis.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_HeartOfTheOasis : X18_Artefact_HeartOfTheOasis_Base
	{
		scope = 2;
	};
	class X18_Artefact_HeartOfTheOasis_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Kolobok_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Kolobok";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Kolobok\Kolobok.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 30;
			energyAtSpawn = 30;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Kolobok : X18_Artefact_Kolobok_Base
	{
		scope = 2;
	};
	class X18_Artefact_Kolobok_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_MamasBeads_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_MamasBeads";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\MamasBeads\MamasBeads.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_MamasBeads : X18_Artefact_MamasBeads_Base
	{
		scope = 2;
	};
	class X18_Artefact_MamasBeads_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_MeatChunk_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_MeatChunk";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\MeatChunk\MeatChunk.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_MeatChunk : X18_Artefact_MeatChunk_Base
	{
		scope = 2;
	};
	class X18_Artefact_MeatChunk_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Moonlight_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Moonlight";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Moonlight\Moonlight.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 15;
			energyAtSpawn = 15;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Moonlight : X18_Artefact_Moonlight_Base
	{
		scope = 2;
	};
	class X18_Artefact_Moonlight_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_NightStar_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_NightStar";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\NightStar\NightStar.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 30;
			energyAtSpawn = 30;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Nightstar : X18_Artefact_NightStar_Base
	{
		scope = 2;
	};
	class X18_Artefact_Nightstar_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Shell_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Shell";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Shell\Shell.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Shell : X18_Artefact_Shell_Base
	{
		scope = 2;
	};
	class X18_Artefact_Shell_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Snowflake_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Snowflake";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Snowflake\Snowflake.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 30;
			energyAtSpawn = 30;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Snowflake : X18_Artefact_Snowflake_Base
	{
		scope = 2;
	};
	class X18_Artefact_Snowflake_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_Soul_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_Soul";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\Soul\Soul.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 45;
			energyAtSpawn = 45;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_Soul : X18_Artefact_Soul_Base
	{
		scope = 2;
	};
	class X18_Artefact_Soul_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_StoneBlood_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_StoneBlood";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\StoneBlood\StoneBlood.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 60;
			energyAtSpawn = 60;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_StoneBlood : X18_Artefact_StoneBlood_Base
	{
		scope = 2;
	};
	class X18_Artefact_StoneBlood_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class X18_Artefact_StoneFlower_Base : X18_Artefact_Base
	{
		scope = 0;
		displayName = "$STR_Artefact_StoneFlower";
		descriptionShort = "$STR_DSC_Artefact";
		model = "Noosphere\X18Artefacts\Models\StoneFlower\StoneFlower.p3d";
		class EnergyManager
		{
			convertEnergyToQuantity = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyStorageMax = 45;
			energyAtSpawn = 45;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			updateInterval = 1;
		};
	};
	class X18_Artefact_StoneFlower : X18_Artefact_StoneFlower_Base
	{
		scope = 2;
	};
	class X18_Artefact_StoneFlower_Spawn : X18_Artefact_Spawn_Base
	{
		scope = 2;
	};
	class tactical_pouch_base : Container_Base
	{
		itemsCargoSize[] = { 4,3 };
	};
	class PlateCarrierPouches : Container_Base
	{
		itemsCargoSize[] = { 4,3 };
	};
	class Pouches_Base : PlateCarrierPouches
	{
		itemsCargoSize[] = { 4,3 };
	};
	class MMG_falcon_b1_belt_black;
	class X18_Artefact_Belt_ClearSky_Black_Base : MMG_falcon_b1_belt_black
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_Belt_ClearSky_Black_1 : X18_Artefact_Belt_ClearSky_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_Belt_ClearSky_Black_2 : X18_Artefact_Belt_ClearSky_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_Belt_ClearSky_Black_3 : X18_Artefact_Belt_ClearSky_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class MMG_falcon_b1_belt_tan;
	class X18_Artefact_Belt_ClearSky_Tan_Base : MMG_falcon_b1_belt_tan
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_Belt_ClearSky_Tan_1 : X18_Artefact_Belt_ClearSky_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_Belt_ClearSky_Tan_2 : X18_Artefact_Belt_ClearSky_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_Belt_ClearSky_Tan_3 : X18_Artefact_Belt_ClearSky_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class tacticalbelt_quad_black;
	class X18_Artefact_TacticalBelt_ClearSky_Black_Base : tacticalbelt_quad_black
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_TacticalBelt_ClearSky_Black_1 : X18_Artefact_TacticalBelt_ClearSky_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_TacticalBelt_ClearSky_Black_2 : X18_Artefact_TacticalBelt_ClearSky_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_TacticalBelt_ClearSky_Black_3 : X18_Artefact_TacticalBelt_ClearSky_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class tacticalbelt_quad_tan;
	class X18_Artefact_TacticalBelt_ClearSky_Tan_Base : tacticalbelt_quad_tan
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_TacticalBelt_ClearSky_Tan_1 : X18_Artefact_TacticalBelt_ClearSky_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_TacticalBelt_ClearSky_Tan_2 : X18_Artefact_TacticalBelt_ClearSky_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_TacticalBelt_ClearSky_Tan_3 : X18_Artefact_TacticalBelt_ClearSky_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class MMG_falcon_b1_belt_olive;
	class X18_Artefact_Belt_Freedom_Olive_Base : MMG_falcon_b1_belt_olive
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_Belt_Freedom_Olive_1 : X18_Artefact_Belt_Freedom_Olive_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_Belt_Freedom_Olive_2 : X18_Artefact_Belt_Freedom_Olive_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_Belt_Freedom_Olive_3 : X18_Artefact_Belt_Freedom_Olive_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class MMG_falcon_b1_belt_erdl;
	class X18_Artefact_Belt_Freedom_ERDL_Base : MMG_falcon_b1_belt_erdl
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_Belt_Freedom_ERDL_1 : X18_Artefact_Belt_Freedom_ERDL_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_Belt_Freedom_ERDL_2 : X18_Artefact_Belt_Freedom_ERDL_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_Belt_Freedom_ERDL_3 : X18_Artefact_Belt_Freedom_ERDL_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class tacticalbelt_quad_green;
	class X18_Artefact_TacticalBelt_Freedom_Green_Base : tacticalbelt_quad_green
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_TacticalBelt_Freedom_Green_1 : X18_Artefact_TacticalBelt_Freedom_Green_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_TacticalBelt_Freedom_Green_2 : X18_Artefact_TacticalBelt_Freedom_Green_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_TacticalBelt_Freedom_Green_3 : X18_Artefact_TacticalBelt_Freedom_Green_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class X18_Artefact_TacticalBelt_Guards_Green_Base : tacticalbelt_quad_green
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_TacticalBelt_Guards_Green_1 : X18_Artefact_TacticalBelt_Guards_Green_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_TacticalBelt_Guards_Green_2 : X18_Artefact_TacticalBelt_Guards_Green_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_TacticalBelt_Guards_Green_3 : X18_Artefact_TacticalBelt_Guards_Green_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class X18_Artefact_TacticalBelt_Guards_Black_Base : tacticalbelt_quad_black
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_TacticalBelt_Guards_Black_1 : X18_Artefact_TacticalBelt_Guards_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_TacticalBelt_Guards_Black_2 : X18_Artefact_TacticalBelt_Guards_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_TacticalBelt_Guards_Black_3 : X18_Artefact_TacticalBelt_Guards_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class X18_Artefact_TacticalBelt_Guards_Tan_Base : tacticalbelt_quad_tan
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_TacticalBelt_Guards_Tan_1 : X18_Artefact_TacticalBelt_Guards_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_TacticalBelt_Guards_Tan_2 : X18_Artefact_TacticalBelt_Guards_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_TacticalBelt_Guards_Tan_3 : X18_Artefact_TacticalBelt_Guards_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class X18_Artefact_Belt_ISG_Black_Base : MMG_falcon_b1_belt_black
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_Belt_ISG_Black_1 : X18_Artefact_Belt_ISG_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_Belt_ISG_Black_2 : X18_Artefact_Belt_ISG_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_Belt_ISG_Black_3 : X18_Artefact_Belt_ISG_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class X18_Artefact_Belt_ISG_Tan_Base : MMG_falcon_b1_belt_tan
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_Belt_ISG_Tan_1 : X18_Artefact_Belt_ISG_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_Belt_ISG_Tan_2 : X18_Artefact_Belt_ISG_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_Belt_ISG_Tan_3 : X18_Artefact_Belt_ISG_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class X18_Artefact_TacticalBelt_ISG_Black_Base : tacticalbelt_quad_black
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_TacticalBelt_ISG_Black_1 : X18_Artefact_TacticalBelt_ISG_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_TacticalBelt_ISG_Black_2 : X18_Artefact_TacticalBelt_ISG_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_TacticalBelt_ISG_Black_3 : X18_Artefact_TacticalBelt_ISG_Black_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class X18_Artefact_TacticalBelt_ISG_Tan_Base : tacticalbelt_quad_tan
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_TacticalBelt_ISG_Tan_1 : X18_Artefact_TacticalBelt_ISG_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_TacticalBelt_ISG_Tan_2 : X18_Artefact_TacticalBelt_ISG_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_TacticalBelt_ISG_Tan_3 : X18_Artefact_TacticalBelt_ISG_Tan_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class X18_Artefact_Belt_SoZ_ERDL_Base : MMG_falcon_b1_belt_erdl
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_Belt_SoZ_ERDL_1 : X18_Artefact_Belt_SoZ_ERDL_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_Belt_SoZ_ERDL_2 : X18_Artefact_Belt_SoZ_ERDL_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_Belt_SoZ_ERDL_3 : X18_Artefact_Belt_SoZ_ERDL_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class X18_Artefact_TacticalBelt_SoZ_Green_Base : tacticalbelt_quad_green
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_TacticalBelt_SoZ_Green_1 : X18_Artefact_TacticalBelt_SoZ_Green_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_TacticalBelt_SoZ_Green_2 : X18_Artefact_TacticalBelt_SoZ_Green_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_TacticalBelt_SoZ_Green_3 : X18_Artefact_TacticalBelt_SoZ_Green_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"Belt_Back",
			"Belt_Left",
			"VestPouch",
			"Magazine",
			"Magazine2",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class X18_Artefact_Belt_SoZ_Olive_Base : MMG_falcon_b1_belt_olive
	{
		scope = 0;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Artefact_Belt_SoZ_Olive_1 : X18_Artefact_Belt_SoZ_Olive_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 0;
	};
	class X18_Artefact_Belt_SoZ_Olive_2 : X18_Artefact_Belt_SoZ_Olive_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 1;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2"
		};
	};
	class X18_Artefact_Belt_SoZ_Olive_3 : X18_Artefact_Belt_SoZ_Olive_Base
	{
		scope = 2;
		displayName = "$STR_Artefact_Belt";
		descriptionShort = "$STR_DSC_Artefact_Belt";
		quickBarBonus = 2;
		attachments[] =
		{
			"Belt_Right",
			"tactical_pouch3",
			"Belt_Back",
			"Belt_Left",
			"carbine",
			"ArtefactSlot1",
			"ArtefactSlot2",
			"ArtefactSlot3"
		};
	};
	class WorldContainer_Base;
	class X18_ArtefactCharger : WorldContainer_Base
	{
		scope = 2;
		storageCategory = 1;
		displayName = "Artefakt Energieabsorber";
		descriptionShort = "MK II of Sakharov's invention allowing to recharge a few specific artefacts that lost their properties. Requires discharge from Battery artifact.";
		model = "Noosphere\X18Artefacts\Models\ArtefactCharger\ArtefactCharger.p3d";
		attachments[] = { "BatteryArtefact","ArtefactSlot1" };
		weight = 1000;
		itemSize[] = { 3,3 };
		heavyItem = 1;
		physLayer = "item_large";
		simulation = "inventoryItem";
		canBeDigged = 0;
		itemBehaviour = 0;
		rotationFlags = 2;
		carveNavmesh = 1;
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		visibilityModifier = 0.95;
		hiddenSelections[] = { "all" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Artefacts\Models\ArtefactCharger\glas.paa" };
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyUsagePerSecond = 0.1;
			updateInterval = 10;
			plugType = 1;
			attachmentAction = 1;
		};
		class Cargo
		{
			itemsCargoSize[] = { 0,0 };
			openable = 0;
			allowOwnedCargoManipulation = 0;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10000;
				};
			};
		};
		class AnimationSources
		{
			class upperglass
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class lowerglass
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class lowerleftarm
			{
				source = "user";
				animPeriod = 1;
				initPhase = 1;
			};
			class lowerrightarm
			{
				source = "user";
				animPeriod = 1;
				initPhase = 1;
			};
			class upperarm
			{
				source = "user";
				animPeriod = 1;
				initPhase = 3;
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class BatteryArtefact
			{
				name = "Battery Artefakt";
				description = "";
				attachmentSlots[] = { "BatteryArtefact" };
				icon = "cat_common_cargo";
			};
			class ChargableArtefacts
			{
				name = "Artefakte";
				description = "";
				attachmentSlots[] = { "ArtefactSlot1" };
				icon = "cat_common_cargo";
			};
		};
	};
	class X18_ArtefactStorage : WorldContainer_Base
	{
		scope = 0;
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		storageCategory = 1;
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		visibilityModifier = 0.95;
		displayName = "Artefakt Analyseeinheit";
		descriptionShort = "Pressurised armoured cabinet designed to hold heavily radioactive materials. Contains 3 display units for safe specimen visual inspection and basic parameter readings.";
		weight = 10;
		itemSize[] = { 3,3 };
		heavyItem = 1;
		physLayer = "item_large";
		simulation = "inventoryItem";
		canBeDigged = 0;
		itemBehaviour = 1;
		rotationFlags = 2;
		carveNavmesh = 1;
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOffWhenInCargo = 0;
			switchOnAtSpawn = 0;
			energyUsagePerSecond = 0.1;
			updateInterval = 10;
			plugType = 1;
			attachmentAction = 1;
		};
		class Cargo
		{
			itemsCargoSize[] = { 10,8 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10000;
				};
			};
		};
	};
	class X18_ArtefactStorage_Invis : X18_ArtefactStorage
	{
		scope = 2;
		model = "Noosphere\X18Artefacts\Models\ArtefactStorage\ArtefactStorage.p3d";
		attachments[] = { "ArtefactSlot1","ArtefactSlot2","ArtefactSlot3" };
		class GUIInventoryAttachmentsProps
		{
			class ArtefactSlot1
			{
				name = "Artefakt Einheit 1";
				description = "";
				attachmentSlots[] = { "ArtefactSlot1" };
				icon = "cat_common_cargo";
			};
			class ArtefactSlot2
			{
				name = "Artefakt Einheit 2";
				description = "";
				attachmentSlots[] = { "ArtefactSlot2" };
				icon = "cat_common_cargo";
			};
			class ArtefactSlot3
			{
				name = "Artefakt Einheit 3";
				description = "";
				attachmentSlots[] = { "ArtefactSlot3" };
				icon = "cat_common_cargo";
			};
		};
	};

	class X18_ArtefactTank : X18_ArtefactStorage
	{
		scope = 2;
		displayName = "Artefakt Tank";
		descriptionShort = "Pressurised armoured cabinet designed to hold heavily radioactive materials.";
		model = "\Noosphere\X18Artefacts\Models\Container\ArtefactTank.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		visibilityModifier = 0.95;
		weight = 10;
		itemSize[] = { 3,3 };
		heavyItem = 1;
		physLayer = "item_large";
		simulation = "inventoryItem";
		canBeDigged = 0;
		itemBehaviour = 1;
		rotationFlags = 2;
		carveNavmesh = 1;
		hiddenSelections[] = { "camo" };
		class Cargo
		{
			itemsCargoSize[] = { 4,8 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "seachest_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "seachest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};