class CfgPatches
{
	class X18Mutants_Controller
	{
		units[] = { "Mutant_AoD_Controller1" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Characters", "DZ_AoD_Mutant_Controller", "DZ_AoD_Mutant_Controller_Hand", "DZ_Gear_Food" };
	};
};
class CfgAIBehaviours
{
	class Infected
	{
		class BehaviourHLZombie
		{
			class MovementWalk;
			class MovementRun;
			class MovementSprint;
			class SlotCalm
			{
				class BehaviourZombieCalm;
			};
			class SlotAlerted
			{
				class BehaviourZombieAlerted;
			};
			class AlertSystem
			{
				class Calm;
				class Alerted;
			};
		};
		class TargetSystemDZBase;
		class NoiseSystemParams;
	};
	class Controller : Infected
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class MovementWalk : MovementWalk
			{
				maxSpeed = 1.5;
				minSpeed = 0;
			};
			class MovementRun : MovementRun
			{
				maxSpeed = 1.5;
				minSpeed = 0;
				pathFilter = "ZombieCalm";
			};
			class MovementSprint : MovementSprint
			{
				maxSpeed = 1.5;
				minSpeed = 0;
				pathFilter = "ZombieCalm";
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 30;
				noiseToAlertMultiplier = 3.0;
				damageToAlertMultiplier = 10000;
				noiseShotToAlertMultiplier = 2.0;
			};
		};
	};
};
class CfgVehicles
{
	class Mutant_AoD_Controller1;
	class X18_Mutant_Controller : Mutant_AoD_Controller1
	{
		scope = 2;
		displayName = "$STR_Controller";
		descriptionShort = "$STR_DSC_Controller";
		aiAgentTemplate = "Controller";
		psiRadius = 20.0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1800;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1.5;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.7;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 3;
							};
						};
					};
					componentNames[] = { "Head","Neck" };
					fatalInjuryCoef = 0.1;
					inventorySlots[] = { "Headgear","Mask" };
				};
				class Torso
				{
					class Health
					{
						hitpoints = 300;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 1.2;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
						};
					};
					componentNames[] = { "Spine1","Spine3" };
					fatalInjuryCoef = -1;
					inventorySlots[] = { "Vest","Body","Back" };
					inventorySlotsCoefs[] = { 1.0,1.0,1.0 };
				};
				class LeftArm : Torso
				{
					componentNames[] = { "LeftArm","LeftForeArm" };
					inventorySlots[] = { "Vest","Body","Back" };
					inventorySlotsCoefs[] = { 1.0,1.0,1.0 };
					fatalInjuryCoef = -1;
				};
				class RightArm : LeftArm
				{
					componentNames[] = { "RightArm","RightForeArm" };
					inventorySlots[] = { "Vest","Body","Back" };
					inventorySlotsCoefs[] = { 1.0,1.0,1.0 };
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 300;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
						};
					};
					componentNames[] = { "LeftLeg","LeftUpLeg" };
					fatalInjuryCoef = -1;
					inventorySlots[] = { "Legs" };
				};
				class RightLeg : LeftLeg
				{
					componentNames[] = { "RightLeg","RightUpLeg" };
					fatalInjuryCoef = -1;
					inventorySlots[] = { "Legs" };
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 300;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
						};
					};
					transferToZonesNames[] = { "LeftLeg" };
					transferToZonesCoefs[] = { 0.1 };
					componentNames[] = { "LeftFoot" };
					fatalInjuryCoef = -1;
					inventorySlots[] = { "Feet" };
				};
				class RightFoot : LeftFoot
				{
					transferToZonesNames[] = { "RightLeg" };
					transferToZonesCoefs[] = { 0.1 };
					componentNames[] = { "RightFoot" };
					fatalInjuryCoef = -1;
					inventorySlots[] = { "Feet" };
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				attackName = "attackLong";
				ammoType = "MeleeController";
				stanceName = "erect";
				moveAnimNames[] = { "run","sprint" };
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				attackName = "attackRun";
				ammoType = "MeleeController";
				stanceName = "erect";
				moveAnimNames[] = { "run","sprint" };
				minDistance = 0.5;
				distance = 1.3;
				time = 1.0;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				attackName = "attackShort";
				ammoType = "MeleeController";
				stanceName = "erect";
				moveAnimNames[] = { "idle","walk" };
				minDistance = 0.5;
				distance = 1.3;
				time = 1.0;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				attackName = "attackShortLow";
				ammoType = "MeleeController";
				stanceName = "erect";
				moveAnimNames[] = { "idle","walk","run" };
				minDistance = 0;
				distance = 2;
				time = 1.0;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				attackName = "crawlAttackMove";
				ammoType = "MeleeController";
				stanceName = "crawl";
				moveAnimNames[] = { "walk" };
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				attackName = "crawlAttackStill";
				ammoType = "MeleeController";
				stanceName = "crawl";
				moveAnimNames[] = { "idle" };
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
		class Skinning
		{
			class ObtainedBrain
			{
				item = "X18_Loot_Mutant_Controller_Brain";
				count = 1;
			};
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Controller_Hand";
				count = 2;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Controller_SteakMeat";
				count = 4;
				quantityMinMaxCoef[] = { 0.2,1 };
			};
		};
		class InputController
		{
			movementSpeedMapping[] = { 0.0,1.5,2.9,8.9 };
			lookAtFilterTimeout = 0.5;
			lookAtFilterSpeed = 1.57;
		};
	};
	class Inventory_Base;
	class Mutant_AoD_Controller_Hand : Inventory_Base {};
	class X18_Loot_Mutant_Controller_Hand : Mutant_AoD_Controller_Hand
	{
		scope = 2;
		displayName = "$STR_AoD_Mutant_Controller_Hand_Name";
		descriptionShort = "$STR_AoD_Mutant_Controller_Hand_Decr";
		weight = 1200;
		itemSize[] = { 2,2 };
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		stackedUnit = "";
		quantityBar = 0;
		quantityShow = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = { {1.0,{"DZ\gear\tools\data\cassette.rvmat"}},{0.7,{"DZ\gear\tools\data\cassette.rvmat"}},{0.5,{"DZ\gear\tools\data\cassette_damage.rvmat"}},{0.3,{"DZ\gear\tools\data\cassette_damage.rvmat"}},{0.0,{"DZ\gear\tools\data\cassette_destruct.rvmat"}} };
				};
			};
		};
	};
	class FS_Kontroler_Brain : Inventory_Base {};
	class X18_Loot_Mutant_Controller_Brain : FS_Kontroler_Brain
	{
		scope = 2;
		displayName = "Gehirn eines Controllers";
		descriptionShort = "Das Gehrin eines seltenen Mutanten, der in der Nähe des Zentrums der Zone gesehen wurde. Ähnelt entfernt einem Humanoiden mit übergroßem Kopf. Hat eine hohe Wahrnehmungsfähigkeit und kann das Verhalten von weniger hoch entwickelten Wesen beeinflussen. Erwachsene Exemplare können Menschen kontrollieren.";
		weight = 1200;
		itemSize[] = { 2,2 };
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		stackedUnit = "";
		quantityBar = 0;
		quantityShow = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = { {1.0,{"DZ\gear\tools\data\cassette.rvmat"}},{0.7,{"DZ\gear\tools\data\cassette.rvmat"}},{0.5,{"DZ\gear\tools\data\cassette_damage.rvmat"}},{0.3,{"DZ\gear\tools\data\cassette_damage.rvmat"}},{0.0,{"DZ\gear\tools\data\cassette_destruct.rvmat"}} };
				};
			};
		};
	};
};