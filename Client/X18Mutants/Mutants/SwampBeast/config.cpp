class CfgPatches
{
	class X18Mutants_Poltergeist
	{
		units[] = { "Mutant_AoD_Poltergeist" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Characters", "DZ_AoD_Mutant_Poltergeist", "DZ_AoD_Mutant_Poltergeist_Eye" };
	};
};
class CfgAIBehaviours
{
	class Infected
	{
		name = "zombie";
		HeadLookBoneName = "lookat";
		teamName = "Zombies";
		class BehaviourHLZombie
		{
			class MovementWalk
			{
				maxSpeed = 1.5;
				minSpeed = 0.0;
				acceleration = 5.0;
				maxAngleSpeed = 180.0;
				slowRadius = 0.0;
				stopRadius = 0.5;
				pathFilter = "ZombieCalm";
			};
			class MovementRun
			{
				maxSpeed = 3.0;
				minSpeed = 0.0;
				acceleration = 15.0;
				maxAngleSpeed = 120.0;
				slowRadius = 0.0;
				goalRadius = 1.5;
				stopRadius = 1.7;
				useStartAnimation = "false";
				pathFilter = "ZombieAlerted";
			};
			class MovementSprint
			{
				maxSpeed = 9.0;
				minSpeed = 0.0;
				acceleration = 27.0;
				maxAngleSpeed = 180.0;
				maxSpeedRange = 9.0;
				slowRadius = 3.2;
				goalRadius = 1.5;
				goalSpeed = 7.2;
				stopRadius = 1.7;
				waypointRadius = 1.5;
				useStartAnimation = "false";
				startAnimationMaxSpeed = 0.0;
				slowToTurn = "false";
				smoothAcceleration = "true";
				pathFilter = "ZombieAlerted";
			};
			class SlotCalm
			{
				class BehaviourZombieCalm
				{
					StandingDurationMin = 6;
					StandingDurationMax = 8;
					WalkingDurationMin = 4;
					WalkingDurationMax = 8;
					MinLookTime = 1;
					MaxLookTime = 2;
					IsAttractMode = "false";
					class SoundsDuring
					{
						class Sound1
						{
							moveWithEntity = "true";
						};
						probability = 0.8;
						RepeatTimeMin = 9.0;
						RepeatTimeMax = 15.0;
						RepeatEnabled = "true";
					};
				};
			};
			class SlotAlerted
			{
				class BehaviourZombieAlerted
				{
					maxTimeInDisturbedState = 5.0;
					alertToAttract = 0.8;
					fightStateEnterDistance = 2.0;
					fightStateExitDistance = 3.0;
					fightStateEnterOrientAngleDiff = 160.0;
					fightStateExitOrientAngleDiff = 160.0;
					disturbedTargetHistoryLength = 10.0;
					disturbedVisionUtilityWeight = 1.0;
					disturbedNoiseUtilityWeight = 1.0;
					disturbedDamageUtilityWeight = 1.0;
					attractedTargetHistoryLength = 10.0;
					attractedVisionUtilityWeight = 1.0;
					attractedNoiseUtilityWeight = 1.0;
					attractedDamageUtilityWeight = 1.0;
					attractedSearchDistance = 15;
					chaseTargetHistoryLength = 10.0;
					chaseVisionUtilityWeight = 1.0;
					chaseNoiseUtilityWeight = 1.0;
					chaseDamageUtilityWeight = 1.0;
					class SoundsEntering
					{
						class Sound1 {};
						probability = 1.0;
					};
					class SoundsDuring
					{
						class Sound1 {};
						probability = 1.0;
						RepeatTimeMin = 3.9;
						RepeatTimeMax = 4.1;
						RepeatEnabled = "true";
					};
					noiseMakeAlertPeriod = 6.0;
					class NoiseMakeAlert
					{
						strength = 40.0;
						type = "sound";
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 20.0;
				noiseToAlertMultiplier = 1.0;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 1.7;
				class Calm
				{
					DropSpeed = 1;
					DropDelay = 0;
					MaxAlertValue = 20;
				};
				class Alerted
				{
					DropSpeed = 3;
					DropDelay = 1;
					MaxAlertValue = 100;
				};
			};
			staminaDepletionSpeed = 5;
			staminaRechargeSpeed = 10;
		};
		class TargetSystemDZBase
		{
			visionProximityRange = 2.5;
			visionProximityStrengthMult = 2.0;
			visionCloseRange = 10.0;
			visionCloseHeight = 1.8;
			visionCloseStrengthMult = 1.5;
			visionRangeMin = 20;
			visionRangeMax = 40;
			visionFov = 1.0;
			visionPeripheralRangeMin = 2.5;
			visionPeripheralRangeMax = 20;
			visionPeripheralFov = 2.3;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.0;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.3;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 0.6;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 0.5;
		};
		class NoiseSystemParams
		{
			rangeMin = 0;
			rangeMax = 35.0;
			rangeShotMin = 0;
			rangeShotMax = 180.0;
			radiusMin = 10.0;
			radiusMax = 25.0;
			radiusShotMin = 35.0;
			radiusShotMax = 70.0;
			class NoiseStrengthTeamMultipliers
			{
				BigGame = 1.0;
				Zombies = 1.0;
				Player = 1.0;
			};
		};
	};
	class InfectedMale : Infected
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotCalm : SlotCalm
			{
				class BehaviourZombieCalm : BehaviourZombieCalm
				{
					class SoundsDuring : SoundsDuring
					{
						class Sound1 : Sound1
						{
							moveWithEntity = "true";
						};
					};
				};
			};
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class SoundsEntering : SoundsEntering
					{
						class Sound1 : Sound1 {};
					};
					class SoundsDuring : SoundsDuring
					{
						class Sound1 : Sound1 {};
					};
				};
			};
		};
	};
	class SwampBeast : InfectedMale
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert
					{
						strength = 60.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 20.0;
				noiseToAlertMultiplier = 1.0;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 1.7;
				class Calm
				{
					DropSpeed = 1;
					DropDelay = 0;
					MaxAlertValue = 20;
				};
				class Alerted
				{
					DropSpeed = 3;
					DropDelay = 1;
					MaxAlertValue = 100;
				};
			};
			staminaDepletionSpeed = 5;
			staminaRechargeSpeed = 10;
		};
		class TargetSystemDZBase : TargetSystemDZBase
		{
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.3;
		};
		class NoiseSystemParams : NoiseSystemParams
		{
			rangeMin = 0;
			rangeMax = 35.0;
			rangeShotMin = 0;
			rangeShotMax = 150.0;
			radiusMin = 5.0;
			radiusMax = 25.0;
			radiusShotMin = 35.0;
			radiusShotMax = 70.0;
		};
	};
};
class CfgVehicles
{
	class Mutant_AoD_Poltergeist;
	class X18_Mutant_SwampBeast : Mutant_AoD_Poltergeist
	{
		scope = 2;
		displayName = "$STR_SwampBeast";
		descriptionShort = "$STR_DSC_SwampBeast";
		aiAgentTemplate = "SwampBeast";
		meleeAmmo = "MeleeSwampBeast";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 500;
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
						transferToGlobalCoef = 0.75;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.6;
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
				attackName = "crawlAttackMove";
				ammoType = "MeleeSwampBeast";
				stanceName = "crawl";
				moveAnimNames[] = { "idle" };
				distance = 0.6;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 0.6;
				cooldown = 0.65;
			};
			class AttackRun
			{
				attackName = "crawlAttackMove";
				ammoType = "MeleeSwampBeast";
				stanceName = "crawl";
				moveAnimNames[] = { "walk" };
				distance = 0.6;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 0.6;
				cooldown = 0.65;
			};
			class AttackShort
			{
				attackName = "crawlAttackMove";
				ammoType = "MeleeSwampBeast";
				stanceName = "crawl";
				moveAnimNames[] = { "idle" };
				distance = 0.6;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 0.6;
				cooldown = 1.75;
			};
			class AttackShortLow
			{
				attackName = "crawlAttackMove";
				ammoType = "MeleeSwampBeast";
				stanceName = "crawl";
				moveAnimNames[] = { "idle" };
				distance = 0.6;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 0.6;
				cooldown = 1.75;
			};
			class CrawlAttackMove
			{
				attackName = "crawlAttackMove";
				ammoType = "MeleeSwampBeast";
				stanceName = "crawl";
				moveAnimNames[] = { "walk" };
				distance = 0.6;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 0.6;
				cooldown = 1.75;
			};
			class CrawlAttackStill
			{
				attackName = "crawlAttackStill";
				ammoType = "MeleeSwampBeast";
				stanceName = "crawl";
				moveAnimNames[] = { "idle" };
				distance = 0.6;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 0.6;
				cooldown = 0.65;
			};
		};
		class Skinning
		{
			class ObtainedEye
			{
				item = "X18_Loot_Mutant_SwampBeast_Eye";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_SwampBeast_SteakMeat";
				count = 2;
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
	class Mutant_AoD_Poltergeist_Eye : Inventory_Base {};
	class X18_Loot_Mutant_SwampBeast_Eye : Mutant_AoD_Poltergeist_Eye
	{
		scope = 2;
		displayName = "$STR_SwampBeast_Eye";
		descriptionShort = "$STR_DSC_SwampBeast_Eye";
		weight = 1200;
		itemSize[] = { 1,1 };
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
class CfgSoundShaders
{
	class baseCharacter_SoundShader
	{
		range = 50;
	};
	class PolterAttack_SoundShader
	{
		samples[] = { {"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_attack_0",1},{"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_attack_1",1},{"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_attack_2",1} };
		volume = 1.78;
		range = 80;
		rangeCurve = "defaultAnimalAttenuationCurve";
	};
	class PolterDamage_SoundShader
	{
		samples[] = { {"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_damage_0",1},{"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_damage_1",1},{"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_damage_2",1} };
		volume = 1.78;
		range = 80;
		rangeCurve = "defaultAnimalAttenuationCurve";
	};
	class PolterDie_SoundShader
	{
		samples[] = { {"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_die_0",1},{"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_die_1",1} };
		volume = 3.78;
		range = 80;
		rangeCurve = "defaultAnimalAttenuationCurve";
	};
	class PolterHandHit_SoundShader
	{
		samples[] = { {"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_hit_0",1},{"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_hit_1",1},{"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_hit_2",1} };
		volume = 1.78;
		range = 100;
		rangeCurve = "defaultAnimalAttenuationCurve";
	};
	class PolterIdle_SoundShader
	{
		samples[] = { {"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_idle_0",1},{"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_idle_1",1},{"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_idle_2",1} };
		volume = 6.78;
		range = 150;
		rangeCurve = "defaultAnimalAttenuationCurve";
	};
	class PolterRun_SoundShader
	{
		samples[] = { {"Noosphere\X18Mutants\Mutants\SwampBeast\Sounds\swampbeast_calltoarms_0",1} };
		volume = 3.78;
		range = 80;
		rangeCurve = "defaultAnimalAttenuationCurve";
	};
};