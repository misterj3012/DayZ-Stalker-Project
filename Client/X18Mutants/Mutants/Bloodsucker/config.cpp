class CfgPatches
{
	class X18Mutants_Bloodsucker
	{
		units[] = { "Mutant_AoD_Krovosos1","Mutant_AoD_Krovosos2","Mutant_AoD_Krovosos3","Mutant_AoD_Krovosos4","Mutant_AoD_Krovosos5","Mutant_AoD_Krovosos6","Mutant_AoD_Krovosos1_Easy","Mutant_AoD_Krovosos2_Easy","Mutant_AoD_Krovosos3_Easy","Mutant_AoD_Krovosos4_Easy","Mutant_AoD_Krovosos5_Easy","Mutant_AoD_Krovosos6_Easy" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Characters","DZ_AoD_Mutant_Krovosos" };
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
	class Bloodsucker : InfectedMale
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert : NoiseMakeAlert
					{
						strength = 30.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 30.0;
				noiseToAlertMultiplier = 2.0;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 3;
				class Calm
				{
					DropSpeed = 1;
					DropDelay = 0;
					MaxAlertValue = 20;
				};
				class Alerted
				{
					DropSpeed = 1;
					DropDelay = 1;
					MaxAlertValue = 100;
				};
			};
			staminaDepletionSpeed = 3;
			staminaRechargeSpeed = 18;
		};
		class TargetSystemDZBase : TargetSystemDZBase
		{
			visionProximityRange = 3.0;
			visionProximityStrengthMult = 2.0;
			visionNightMinMult = 1.5;
			visionNightMaxMult = 1.0;
		};
		class NoiseSystemParams : NoiseSystemParams
		{
			rangeMin = 15;
			rangeMax = 40.0;
			rangeShotMin = 60;
			rangeShotMax = 200.0;
			radiusMin = 5.0;
			radiusMax = 25.0;
			radiusShotMin = 25.0;
			radiusShotMax = 50.0;
		};
	};
	class BloodsuckerNormal : Bloodsucker
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert : NoiseMakeAlert
					{
						strength = 40.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 40.0;
				noiseToAlertMultiplier = 3.0;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 3;
				class Calm
				{
					DropSpeed = 1;
					DropDelay = 0;
					MaxAlertValue = 20;
				};
				class Alerted
				{
					DropSpeed = 1;
					DropDelay = 1;
					MaxAlertValue = 100;
				};
			};
			staminaDepletionSpeed = 3;
			staminaRechargeSpeed = 18;
		};
		class TargetSystemDZBase : TargetSystemDZBase
		{
			visionProximityRange = 3.0;
			visionProximityStrengthMult = 2.0;
			visionNightMinMult = 1.5;
			visionNightMaxMult = 1.0;
		};
		class NoiseSystemParams : NoiseSystemParams
		{
			rangeMin = 15;
			rangeMax = 40.0;
			rangeShotMin = 60;
			rangeShotMax = 200.0;
			radiusMin = 5.0;
			radiusMax = 25.0;
			radiusShotMin = 25.0;
			radiusShotMax = 50.0;
		};
	};
	class BloodsuckerMarshCreature : Bloodsucker
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert : NoiseMakeAlert
					{
						strength = 50.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 50.0;
				noiseToAlertMultiplier = 4.0;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 4;
				class Calm
				{
					DropSpeed = 1;
					DropDelay = 0;
					MaxAlertValue = 20;
				};
				class Alerted
				{
					DropSpeed = 1;
					DropDelay = 1;
					MaxAlertValue = 100;
				};
			};
			staminaDepletionSpeed = 3;
			staminaRechargeSpeed = 18;
		};
		class TargetSystemDZBase : TargetSystemDZBase
		{
			visionProximityRange = 3.0;
			visionProximityStrengthMult = 2.0;
			visionNightMinMult = 1.5;
			visionNightMaxMult = 1.0;
		};
		class NoiseSystemParams : NoiseSystemParams
		{
			rangeMin = 15;
			rangeMax = 40.0;
			rangeShotMin = 60;
			rangeShotMax = 200.0;
			radiusMin = 5.0;
			radiusMax = 25.0;
			radiusShotMin = 25.0;
			radiusShotMax = 50.0;
		};
	};
	class BloodsuckerRed : Bloodsucker
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert : NoiseMakeAlert
					{
						strength = 30.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 60.0;
				noiseToAlertMultiplier = 5.0;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 5;
				class Calm
				{
					DropSpeed = 1;
					DropDelay = 0;
					MaxAlertValue = 20;
				};
				class Alerted
				{
					DropSpeed = 1;
					DropDelay = 1;
					MaxAlertValue = 100;
				};
			};
			staminaDepletionSpeed = 3;
			staminaRechargeSpeed = 18;
		};
		class TargetSystemDZBase : TargetSystemDZBase
		{
			visionProximityRange = 3.0;
			visionProximityStrengthMult = 2.0;
			visionNightMinMult = 1.5;
			visionNightMaxMult = 1.0;
		};
		class NoiseSystemParams : NoiseSystemParams
		{
			rangeMin = 15;
			rangeMax = 40.0;
			rangeShotMin = 60;
			rangeShotMax = 200.0;
			radiusMin = 5.0;
			radiusMax = 25.0;
			radiusShotMin = 25.0;
			radiusShotMax = 50.0;
		};
	};
	class BloodsuckerGreen : Bloodsucker
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert : NoiseMakeAlert
					{
						strength = 30.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 70.0;
				noiseToAlertMultiplier = 6.0;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 6;
				class Calm
				{
					DropSpeed = 1;
					DropDelay = 0;
					MaxAlertValue = 20;
				};
				class Alerted
				{
					DropSpeed = 1;
					DropDelay = 1;
					MaxAlertValue = 100;
				};
			};
			staminaDepletionSpeed = 3;
			staminaRechargeSpeed = 18;
		};
		class TargetSystemDZBase : TargetSystemDZBase
		{
			visionProximityRange = 3.0;
			visionProximityStrengthMult = 2.0;
			visionNightMinMult = 1.5;
			visionNightMaxMult = 1.0;
		};
		class NoiseSystemParams : NoiseSystemParams
		{
			rangeMin = 15;
			rangeMax = 40.0;
			rangeShotMin = 60;
			rangeShotMax = 200.0;
			radiusMin = 5.0;
			radiusMax = 25.0;
			radiusShotMin = 25.0;
			radiusShotMax = 50.0;
		};
	};
	class BloodsuckerDark : Bloodsucker
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert : NoiseMakeAlert
					{
						strength = 70.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 80.0;
				noiseToAlertMultiplier = 7.0;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 7;
				class Calm
				{
					DropSpeed = 1;
					DropDelay = 0;
					MaxAlertValue = 20;
				};
				class Alerted
				{
					DropSpeed = 1;
					DropDelay = 1;
					MaxAlertValue = 100;
				};
			};
			staminaDepletionSpeed = 3;
			staminaRechargeSpeed = 18;
		};
		class TargetSystemDZBase : TargetSystemDZBase
		{
			visionProximityRange = 3.0;
			visionProximityStrengthMult = 2.0;
			visionNightMinMult = 1.5;
			visionNightMaxMult = 1.0;
		};
		class NoiseSystemParams : NoiseSystemParams
		{
			rangeMin = 15;
			rangeMax = 40.0;
			rangeShotMin = 60;
			rangeShotMax = 200.0;
			radiusMin = 5.0;
			radiusMax = 25.0;
			radiusShotMin = 25.0;
			radiusShotMax = 50.0;
		};
	};
};
class CfgVehicles
{
	class Mutant_AoD_Krovosos1;
	class Mutant_AoD_Krovosos2;
	class Mutant_AoD_Krovosos3;
	class Mutant_AoD_Krovosos4;
	class Mutant_AoD_Krovosos5;
	class Mutant_AoD_Krovosos6;
	class X18_Mutant_Bloodsucker : Mutant_AoD_Krovosos1
	{
		scope = 2;
		displayName = "$STR_Bloodsucker";
		descriptionShort = "$STR_DSC_Bloodsucker";
		aiAgentTemplate = "Bloodsucker";
		meleeAmmo = "MeleeBloodSucker";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 900;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 350;
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
						hitpoints = 150;
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
						hitpoints = 150;
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
						hitpoints = 150;
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
			class ObtainedHead
			{
				item = "X18_Loot_Mutant_Bloodsucker_Head";
				count = 1;
			};
			class ObtainedJaw
			{
				item = "X18_Loot_Mutant_Bloodsucker_Tentacles";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Bloodsucker_SteakMeat";
				count = 3;
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
	class X18_Mutant_Bloodsucker_Normal : Mutant_AoD_Krovosos2
	{
		scope = 2;
		displayName = "$STR_Bloodsucker_Normal";
		descriptionShort = "$STR_DSC_Bloodsucker_Normal";
		aiAgentTemplate = "BloodsuckerNormal";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 900;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 350;
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
						hitpoints = 150;
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
						hitpoints = 150;
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
						hitpoints = 150;
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
			class ObtainedHead
			{
				item = "X18_Loot_Mutant_Bloodsucker_Head_Red";
				count = 1;
			};
			class ObtainedJaw
			{
				item = "X18_Loot_Mutant_Bloodsucker_Tentacles_Red";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Bloodsucker_SteakMeat";
				count = 3;
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
	class X18_Mutant_Bloodsucker_Dark : Mutant_AoD_Krovosos5
	{
		scope = 2;
		displayName = "$STR_Bloodsucker_Dark";
		descriptionShort = "$STR_DSC_Bloodsucker_Dark";
		aiAgentTemplate = "BloodsuckerDark";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 900;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 350;
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
						hitpoints = 150;
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
						hitpoints = 150;
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
						hitpoints = 150;
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
			class ObtainedHead
			{
				item = "X18_Loot_Mutant_Bloodsucker_Head_Dark";
				count = 1;
			};
			class ObtainedJaw
			{
				item = "X18_Loot_Mutant_Bloodsucker_Tentacles_Dark";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Bloodsucker_SteakMeat";
				count = 3;
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
	class X18_Mutant_Bloodsucker_Green : Mutant_AoD_Krovosos6
	{
		scope = 2;
		displayName = "$STR_Bloodsucker_Green";
		descriptionShort = "$STR_DSC_Bloodsucker_Green";
		aiAgentTemplate = "BloodsuckerGreen";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 900;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 350;
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
						hitpoints = 150;
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
						hitpoints = 150;
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
						hitpoints = 150;
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
				ammoType = "MeleeBloodSucker";
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
			class ObtainedHead
			{
				item = "X18_Loot_Mutant_Bloodsucker_Head";
				count = 1;
			};
			class ObtainedJaw
			{
				item = "X18_Loot_Mutant_Bloodsucker_Tentacles";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Bloodsucker_SteakMeat";
				count = 3;
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
	class ZombieMaleBase;
	class X18_Mutant_Bloodsucker_Base : ZombieMaleBase
	{
		scope = 0;
		displayName = "$STR_AoD_Mutant_Base";
		descriptionShort = "$STR_AoD_Mutant_Krovosos_Decr";
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Bloodsucker.p3d";
		hiddenSelections[] = { "vkComFidovPublic" };
		aiAgentTemplate = "Bloodsucker";
		htMin = 6000;
		htMax = 8800;
		afMax = 400;
		mfMax = 333;
		mFact = 333;
		tBody = 573;
		class InputController
		{
			movementSpeedMapping[] = { -7.7,-7.7,0.3,0.3 };
			lookAtFilterTimeout = 0.3;
			lookAtFilterSpeed = 1.17;
		};
		class Cargo
		{
			itemsCargoSize[] = { 10,15 };
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1350;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 400;
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
						hitpoints = 225;
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
						hitpoints = 225;
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
						hitpoints = 225;
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
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 8;
				};
				class Sprint1
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 9;
				};
				class Sprint2
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 10;
				};
				class Sprint3
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 11;
				};
				class Sprint4
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 12;
				};
				class Scuff1
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 17;
				};
				class Scuff2
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 18;
				};
				class Sccuff3
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 19;
				};
				class Scuff4
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 20;
				};
				class landFeetErc
				{
					soundLookupTable = "landFeetErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 21;
				};
				class landFootErc
				{
					soundLookupTable = "landFootErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 22;
				};
				class Bodyfall
				{
					soundLookupTable = "bodyfall_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 23;
				};
				class Bodyfall_Hand
				{
					soundLookupTable = "bodyfall_hand_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 24;
				};
				class Bodyfall_Slide
				{
					soundLookupTable = "bodyfall_slide_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 25;
				};
				class Prone_Walk_L
				{
					soundLookupTable = "walkProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 27;
				};
				class Prone_Walk_R
				{
					soundLookupTable = "walkProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 28;
				};
				class Prone_Run_L
				{
					soundLookupTable = "runProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 29;
				};
				class Prone_Run_R
				{
					soundLookupTable = "runProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 30;
				};
			};
			class Sounds
			{
				class Attack_Light1
				{
					soundSet = "BloodSuckerHitHand_SoundSet";
					id = 1;
				};
				class Attack_Light2
				{
					soundSet = "BloodSuckerHitHand_SoundSet";
					id = 2;
				};
				class Attack_Heavy1
				{
					soundSet = "BloodSuckerHitHand_SoundSet";
					id = 3;
				};
				class Attack_Heavy2
				{
					soundSet = "BloodSuckerHitHand_SoundSet";
					id = 4;
				};
				class TwoHands
				{
					soundSet = "BloodSuckerHitHand_SoundSet";
					id = 5;
				};
			};
			class SoundVoice
			{
				class LightHit
				{
					soundSet = "BloodSuckerHit_SoundSet";
					id = 1;
				};
				class HeavyHit
				{
					soundSet = "BloodSuckerHit_SoundSet";
					id = 2;
				};
				class Attack
				{
					soundSet = "BloodSuckerAttack_SoundSet";
					id = 5;
				};
				class Jump
				{
					soundSet = "ZmbF_Normal_Jump_Soundset";
					id = 10;
				};
				class Land
				{
					soundSet = "ZmbF_Normal_Land_Soundset";
					id = 11;
				};
				class CallToArmsShort
				{
					soundSet = "BloodSuckerGrowl_SoundSet";
					id = 20;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				attackName = "attackLong";
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
			class ObtainedHead
			{
				item = "X18_Loot_Mutant_Bloodsucker_Head_MarshCreature";
				count = 1;
			};
			class ObtainedJaw
			{
				item = "X18_Loot_Mutant_Bloodsucker_Tentacles_MarshCreature";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Bloodsucker_SteakMeat";
				count = 3;
				quantityMinMaxCoef[] = { 0.2,1 };
			};
		};
	};
	class X18_Mutant_Bloodsucker_MarshCreature : X18_Mutant_Bloodsucker_Base
	{
		scope = 2;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\MarshCreature.p3d";
		aiAgentTemplate = "Bloodsucker";
		hiddenSelections[] = { "vkcomfidovpublic","FUR" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Textures\MarshCreature\MarshCreature.paa","Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Textures\MarshCreature\MarshCreature_Fur.paa" };
	};
	class X18_Mutant_Bloodsucker_MarshCreature_2 : Mutant_AoD_Krovosos3
	{
		scope = 2;
		displayName = "$STR_Bloodsucker_MarshCreature";
		descriptionShort = "$STR_DSC_Bloodsucker_MarshCreature";
		aiAgentTemplate = "BloodsuckerMarshCreature";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1350;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 400;
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
						hitpoints = 225;
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
						hitpoints = 225;
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
						hitpoints = 225;
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
			class ObtainedHead
			{
				item = "X18_Loot_Mutant_Bloodsucker_Head_MarshCreature";
				count = 1;
			};
			class ObtainedJaw
			{
				item = "X18_Loot_Mutant_Bloodsucker_Tentacles_MarshCreature";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Bloodsucker_SteakMeat";
				count = 3;
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
	class X18_Mutant_Bloodsucker_Red : Mutant_AoD_Krovosos4
	{
		scope = 2;
		displayName = "$STR_Bloodsucker_Red";
		descriptionShort = "$STR_DSC_Bloodsucker_Red";
		aiAgentTemplate = "BloodsuckerRed";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1350;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 400;
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
						hitpoints = 225;
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
						hitpoints = 225;
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
						hitpoints = 225;
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
				ammoType = "MeleeBloodSuckerStrong";
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
			class ObtainedHead
			{
				item = "X18_Loot_Mutant_Bloodsucker_Head_Red";
				count = 1;
			};
			class ObtainedJaw
			{
				item = "X18_Loot_Mutant_Bloodsucker_Tentacles_Red";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Bloodsucker_SteakMeat";
				count = 3;
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
	class WolfSteakMeat;
	class Inventory_Base;
	class X18_Loot_Mutant_Bloodsucker_Head_Base : Inventory_Base
	{
		scope = 0;
		displayName = "$STR_Bloodsucker_Head";
		descriptionShort = "$STR_DSC_Bloodsucker_Head";
		weight = 6300;
		itemSize[] = { 3,3 };
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
	class X18_Loot_Mutant_Bloodsucker_Head : X18_Loot_Mutant_Bloodsucker_Head_Base
	{
		scope = 2;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Head.p3d";
	};
	class X18_Loot_Mutant_Bloodsucker_Head_Red : X18_Loot_Mutant_Bloodsucker_Head_Base
	{
		scope = 2;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Head_Red.p3d";
	};
	class X18_Loot_Mutant_Bloodsucker_Head_Dark : X18_Loot_Mutant_Bloodsucker_Head_Base
	{
		scope = 2;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Head_Dark.p3d";
	};
	class X18_Loot_Mutant_Bloodsucker_Head_MarshCreature : X18_Loot_Mutant_Bloodsucker_Head_Base
	{
		scope = 2;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Head_MarshCreature.p3d";
	};
	class X18_Loot_Mutant_Bloodsucker_Tentacles_Base : Inventory_Base
	{
		scope = 0;
		displayName = "$STR_Bloodsucker_Tentacles";
		descriptionShort = "$STR_DSC_Bloodsucker_Tentacles";
		weight = 1200;
		itemSize[] = { 1,3 };
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
	class X18_Loot_Mutant_Bloodsucker_Tentacles : X18_Loot_Mutant_Bloodsucker_Tentacles_Base
	{
		scope = 2;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Tentacle.p3d";
	};
	class X18_Loot_Mutant_Bloodsucker_Tentacles_Red : X18_Loot_Mutant_Bloodsucker_Tentacles_Base
	{
		scope = 2;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Tentacle_Red.p3d";
	};
	class X18_Loot_Mutant_Bloodsucker_Tentacles_Dark : X18_Loot_Mutant_Bloodsucker_Tentacles_Base
	{
		scope = 2;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Tentacle_Dark.p3d";
	};
	class X18_Loot_Mutant_Bloodsucker_Tentacles_MarshCreature : X18_Loot_Mutant_Bloodsucker_Tentacles_Base
	{
		scope = 2;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Tentacle_MarshCreature.p3d";
	};
};