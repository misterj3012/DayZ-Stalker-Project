class CfgPatches
{
	class X18Psi
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18Psi
	{
		name = "X18Psi";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Psi/Scripts/Common", "Noosphere/X18Psi/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Psi/Scripts/Common", "Noosphere/X18Psi/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Psi/Scripts/Common", "Noosphere/X18Psi/Scripts/5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class House;
	class Barrel_ColorBase;
	class Inventory_Base;
	class X18_PsiField_Base : House
	{
		scope = 0;
		psiRadius = 0.0;
		//model = "\Noosphere\X18Psi\Data\PsiTower.p3d";
	};
	class X18_PsiField_50 : X18_PsiField_Base
	{
		scope = 2;
		psiRadius = 50.0;
	};
	class X18_PsiField_100 : X18_PsiField_Base
	{
		scope = 2;
		psiRadius = 100.0;
	};
	class X18_PsiField_150 : X18_PsiField_Base
	{
		scope = 2;
		psiRadius = 150.0;
	};
	class X18_PsiField_200 : X18_PsiField_Base
	{
		scope = 2;
		psiRadius = 200.0;
	};
	class X18_PsiField_250 : X18_PsiField_Base
	{
		scope = 2;
		psiRadius = 250.0;
	};
	class X18_PsiField_275 : X18_PsiField_Base
	{
		scope = 2;
		psiRadius = 275.0;
	};
	class X18_PsiField_300 : X18_PsiField_Base
	{
		scope = 2;
		psiRadius = 300.0;
	};
	class X18_PsiField_500 : X18_PsiField_Base
	{
		scope = 2;
		psiRadius = 500.0;
	};
	class X18_PsiTower_Base : Barrel_ColorBase
	{
		scope = 0;
		displayName = "Psi Emitter";
		model = "\Noosphere\X18Psi\Data\PsiTower.p3d";
		psiRadius = 0.0;
		descriptionShort = "";
		class Cargo
		{
			itemsCargoSize[] = { 0,0 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15000;
					//healthLevels[] = { {1, {"Noosphere\X18Psi\Data\PsiTower\psi_tower.rvmat"}}, {0.7, {"Noosphere\X18Psi\Data\PsiTower\psi_tower.rvmat"}}, {0.5, {"Noosphere\X18Psi\Data\PsiTower\psi_tower_damage.rvmat"}}, {0.3, {"Noosphere\X18Psi\Data\PsiTower\psi_tower_damage.rvmat"}}, {0, {"Noosphere\X18Psi\Data\PsiTower\psi_tower_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_PsiTower_50 : X18_PsiTower_Base
	{
		scope = 2;
		psiRadius = 50.0;
	};
	class X18_PsiTower_100 : X18_PsiTower_Base
	{
		scope = 2;
		psiRadius = 100.0;
	};
	class X18_PsiTower_150 : X18_PsiTower_Base
	{
		scope = 2;
		psiRadius = 150.0;
	};
	class X18_PsiTower_200 : X18_PsiTower_Base
	{
		scope = 2;
		psiRadius = 200.0;
	};
	class X18_PsiTower_250 : X18_PsiTower_Base
	{
		scope = 2;
		psiRadius = 250.0;
	};
	class X18_PsiTower_300 : X18_PsiTower_Base
	{
		scope = 2;
		psiRadius = 300.0;
	};
	class X18_PsiTower_500 : X18_PsiTower_Base
	{
		scope = 2;
		psiRadius = 500.0;
	};
	class Mich2001Helmet;
	class X18_PsiHelmet : Mich2001Helmet
	{
		scope = 2;
		displayName = "#STR_CfgVehicles_PSIhelmet_BC0";
		descriptionShort = "";
		model = "\Noosphere\X18Psi\Data\PsiHelmet_g.p3d";
		inventorySlot[] = { "Headgear" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		attachments[] = { "PsiHelmetClip","PsiHelmetClip2" };
		rotationFlags = 2;
		weight = 800;
		itemSize[] = { 4,3 };
		noMask = 0;
		varWetMax = 0.72;
		absorbency = 0.35;
		heatIsolation = 0.8;
		visibilityModifier = 0.95;
		headSelectionsToHide[] = { "Clipping_Mich2001" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = { {1,{"DZ\characters\headgear\data\mich2001.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.7,{"DZ\characters\headgear\data\mich2001.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.5,{"DZ\characters\headgear\data\mich2001_damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\mich2001_damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0,{"DZ\characters\headgear\data\mich2001_destruct.rvmat","DZ\characters\headgear\data\mich2001_rail_destruct.rvmat"}} };
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 1;
					};
					class Blood
					{
						damage = 1;
					};
					class Shock
					{
						damage = 1;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 1;
					};
					class Blood
					{
						damage = 1;
					};
					class Shock
					{
						damage = 1;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 1;
					};
					class Blood
					{
						damage = 1;
					};
					class Shock
					{
						damage = 1;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\Noosphere\X18Psi\Data\PsiHelmet.p3d";
			female = "\Noosphere\X18Psi\Data\PsiHelmet.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpPot_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "BallisticHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_PsiHelmetClip_Base : Inventory_Base
	{
		scope = 0;
		itemSize[] = { 2,1 };
		repairableWithKits[] = { 5,2 };
		repairCosts[] = { 30,25 };
		heatIsolation = 0;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 30;
		varQuantityMin = 0.0;
		varQuantityMax = 30;
		varQuantityDestroyOnMin = 0;
		rotationFlags = 17;
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			energyStorageMax = 30;
			energyAtSpawn = 30;
			convertEnergyToQuantity = 1;
			reduceMaxEnergyByDamageCoef = 1;
			powerSocketsCount = 1;
			compatiblePlugTypes[] = { 1 };
		};
	};
	class X18_PsiHelmetClip : X18_PsiHelmetClip_Base
	{
		scope = 2;
		displayName = "#PsiHelmetClip";
		descriptionShort = "#PsiHelmetClip_DSC";
		model = "\Noosphere\X18Psi\Data\PsiHelmetClip.p3d";
		absorbency = 1;
		itemSize[] = { 1,2 };
		weight = 100;
		inventorySlot[] = { "PsiHelmetClip","PsiHelmetClip2" };
		class DamageSystem
		{
			class GlobalHealthq
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1,{"DZ\gear\tools\data\Lockpick.rvmat"}},{0.7,{"DZ\gear\tools\data\Lockpick.rvmat"}},{0.5,{"DZ\gear\tools\data\Lockpick_damage.rvmat"}},{0.3,{"DZ\gear\tools\data\Lockpick_damage.rvmat"}},{0,{"DZ\gear\tools\data\Lockpick_destruct.rvmat"}} };
				};
			};
		};
	};class X18_PsiHelmetNotAdjusted : Mich2001Helmet
	{
		scope = 2;
		displayName = "#STR_CfgVehicles_PSIhelmet_BC0";
		descriptionShort = "";
		model = "\Noosphere\X18Psi\Data\PsiHelmet_g.p3d";
		inventorySlot[] = { "Headgear" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		rotationFlags = 2;
		weight = 800;
		itemSize[] = { 4,3 };
		noMask = 0;
		varWetMax = 0.72;
		absorbency = 0.35;
		heatIsolation = 0.8;
		visibilityModifier = 0.95;
		headSelectionsToHide[] = { "Clipping_Mich2001" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = { {1,{"DZ\characters\headgear\data\mich2001.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.7,{"DZ\characters\headgear\data\mich2001.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.5,{"DZ\characters\headgear\data\mich2001_damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\mich2001_damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0,{"DZ\characters\headgear\data\mich2001_destruct.rvmat","DZ\characters\headgear\data\mich2001_rail_destruct.rvmat"}} };
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 1;
					};
					class Blood
					{
						damage = 1;
					};
					class Shock
					{
						damage = 1;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 1;
					};
					class Blood
					{
						damage = 1;
					};
					class Shock
					{
						damage = 1;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 1;
					};
					class Blood
					{
						damage = 1;
					};
					class Shock
					{
						damage = 1;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\Noosphere\X18Psi\Data\PsiHelmet.p3d";
			female = "\Noosphere\X18Psi\Data\PsiHelmet.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpPot_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "BallisticHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BaseBuildingBase;
	class X18_PsiTowerBB : BaseBuildingBase
	{
		scope = 2;
		displayName = "#STR_X18_PsiTower0";
		descriptionShort = "#STR_X18_PsiTower1";
		model = "\Noosphere\X18Psi\Data\PsiTower.p3d";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 60000;
		itemSize[] = { 6,6 };
		physLayer = "item_large";
		createProxyPhysicsOnInit = "false";
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 999999;
					healthLevels[] = { {1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}} };
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
			class DamageZones
			{
				class Body
				{
					class Health
					{
						hitpoints = 999999;
						transferToGlobalCoef = 0;
						healthLevels[] = { {1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}} };
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = { "lvl1" };
					fatalInjuryCoef = -1;
				};
			};
		};
		attachments[] = { "PsiTowerPart","PsiTowerPart2","ArtefactSlot1" };
		class GUIInventoryAttachmentsProps
		{
			class level_2
			{
				name = "#STR_CfgVehicles_X18_PsiTower_Att_Category_Level_2";
				description = "";
				attachmentSlots[] = { "PsiTowerPart" };
				icon = "set:dayz_inventory image:electricity";
				selection = "lvl2";
			};
			class level_3
			{
				name = "#STR_CfgVehicles_X18_PsiTower_Att_Category_Level_3";
				description = "";
				attachmentSlots[] = { "PsiTowerPart2" };
				icon = "set:dayz_inventory image:electricity";
				selection = "lvl3";
			};
			class artefact
			{
				name = "#STR_CfgVehicles_X18_PsiTower_Att_Category_Artefact";
				description = "";
				attachmentSlots[] = { "ArtefactSlot1" };
				icon = "set:dayz_inventory image:electricity";
				selection = "lvl3";
			};
		};
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
			class lvl1 : AnimSourceShown {};
			class lvl2 : AnimSourceHidden {};
			class lvl3 : AnimSourceHidden {};
			class lvl3_static : AnimSourceHidden {};
			class lvl3_spin_visible : AnimSourceHidden {};
		};
		class Construction
		{
			class tower
			{
				class lvl2
				{
					name = "#STR_CfgVehicles_X18_PsiTower_Att_Category_Level_2";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 1024;
					dismantle_action_type = 1024;
					material_type = 5;
					class Materials
					{
						class Material1
						{
							type = "MetalWire";
							slot_name = "PsiTowerPart";
							quantity = -1;
							lockable = 1;
						};
					};
				};
				class lvl3
				{
					name = "#STR_CfgVehicles_X18_PsiTower_Att_Category_Level_3";
					id = 3;
					required_parts[] = { "lvl2" };
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 1024;
					dismantle_action_type = 1024;
					material_type = 5;
					class Materials
					{
						class Material1
						{
							type = "MetalWire";
							slot_name = "PsiTowerPart2";
							quantity = -1;
							lockable = 1;
						};
					};
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyPsiHelmetClip : ProxyAttachment
	{
		scope = 0;
		inventorySlot = "PsiHelmetClip";
		model = "\Noosphere\X18Psi\Data\PsiHelmet\Proxy\PsiHelmetClip.p3d";
	};
	class ProxyPsiHelmetClip2 : ProxyAttachment
	{
		scope = 0;
		inventorySlot = "PsiHelmetClip2";
		model = "\Noosphere\X18Psi\Data\PsiHelmet\Proxy\PsiHelmetClip2.p3d";
	};
};
class CfgSlots
{
	class Slot_PsiHelmetClip
	{
		name = "PsiHelmetClip";
		displayName = "#STR_CfgBatteryD0";
		ghostIcon = "set:dayz_inventory image:batteryd";
	};
	class Slot_PsiHelmetClip2
	{
		name = "PsiHelmetClip2";
		displayName = "#STR_CfgBatteryD0";
		ghostIcon = "set:dayz_inventory image:batteryd";
	};
};

class CfgSoundShaders
{
	class X18Psi_50_SoundShader
	{
		range = 75;
		samples[] = { {"\Noosphere\X18Psi\Data\Sounds\psi",1} };
		volume = 2;
	};
	class X18Psi_100_SoundShader
	{
		range = 125;
		samples[] = { {"\Noosphere\X18Psi\Data\Sounds\psi",1} };
		volume = 2;
	};
	class X18Psi_150_SoundShader
	{
		range = 175;
		samples[] = { {"\Noosphere\X18Psi\Data\Sounds\psi",1} };
		volume = 2;
	};
	class X18Psi_200_SoundShader
	{
		range = 225;
		samples[] = { {"\Noosphere\X18Psi\Data\Sounds\psi",1} };
		volume = 2;
	};
	class X18Psi_250_SoundShader
	{
		range = 275;
		samples[] = { {"\Noosphere\X18Psi\Data\Sounds\psi",1} };
		volume = 2;
	};
	class X18Psi_275_SoundShader
	{
		range = 300;
		samples[] = { {"\Noosphere\X18Psi\Data\Sounds\psi",1} };
		volume = 2;
	};
	class X18Psi_300_SoundShader
	{
		range = 325;
		samples[] = { {"\Noosphere\X18Psi\Data\Sounds\psi",1} };
		volume = 2;
	};
	class X18Psi_500_SoundShader
	{
		range = 525;
		samples[] = { {"\Noosphere\X18Psi\Data\Sounds\psi",1} };
		volume = 2;
	};
	class X18Psi_Voices_SoundShader
	{
		samples[] = { {"Noosphere\X18Psi\Data\Sounds\Psi_voices_01",1},{"Noosphere\X18Psi\Data\Sounds\Psi_voices_02",1},{"Noosphere\X18Psi\Data\Sounds\Psi_voices_03",1},{"Noosphere\X18Psi\Data\Sounds\Psi_voices_04",1},{"Noosphere\X18Psi\Data\Sounds\Psi_voices_05",1},{"Noosphere\X18Psi\Data\Sounds\Psi_voices_06",1},{"Noosphere\X18Psi\Data\Sounds\Psi_voices_07",1},{"Noosphere\X18Psi\Data\Sounds\Psi_voices_08",1},{"Noosphere\X18Psi\Data\Sounds\Psi_voices_09",1} };
		volume = 0.25;
		radius = 25;
	};
};
class CfgSoundSets
{
	class X18Psi_base_SoundSet
	{
		sound3DProcessingType = "Vehicle_Ext_3DProcessingType";
		distanceFilter = "softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve = "vehicleEngineAttenuationCurve";
		volumeFactor = 1;
		spatial = 1;
		loop = 0;
	};
	class X18Psi_50_SoundSet : X18Psi_base_SoundSet
	{
		soundShaders[] = { "X18Psi_50_SoundShader" };
		volumeFactor = 1;
	};
	class X18Psi_100_SoundSet : X18Psi_base_SoundSet
	{
		soundShaders[] = { "X18Psi_100_SoundShader" };
		volumeFactor = 1;
	};
	class X18Psi_150_SoundSet : X18Psi_base_SoundSet
	{
		soundShaders[] = { "X18Psi_150_SoundShader" };
		volumeFactor = 1;
	};
	class X18Psi_200_SoundSet : X18Psi_base_SoundSet
	{
		soundShaders[] = { "X18Psi_200_SoundShader" };
		volumeFactor = 1;
	};
	class X18Psi_250_SoundSet : X18Psi_base_SoundSet
	{
		soundShaders[] = { "X18Psi_250_SoundShader" };
		volumeFactor = 1;
	};
	class X18Psi_275_SoundSet : X18Psi_base_SoundSet
	{
		soundShaders[] = { "X18Psi_275_SoundShader" };
		volumeFactor = 1;
	};
	class X18Psi_300_SoundSet : X18Psi_base_SoundSet
	{
		soundShaders[] = { "X18Psi_300_SoundShader" };
		volumeFactor = 1;
	};
	class X18Psi_500_SoundSet : X18Psi_base_SoundSet
	{
		soundShaders[] = { "X18Psi_500_SoundShader" };
		volumeFactor = 1;
	};
	class X18Psi_Voices_SoundSet : X18Psi_base_SoundSet
	{
		soundShaders[] = { "X18Psi_Voices_SoundShader" };
		volumeFactor = 1;
	};
};