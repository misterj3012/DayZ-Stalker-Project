class CfgPatches
{
	class X18Mutants_Zombie
	{
		units[] = { "Mutant_AoD_Snork1","Mutant_AoD_Snork2","Mutant_AoD_Snork1_Easy","Mutant_AoD_Snork2_Easy" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Characters", "DZ_AoD_Mutant_Tushkano", "DZ_AoD_Mutant_Zombi_Hand" };
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
	class Zombie1 : InfectedMale
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert : NoiseMakeAlert
					{
						strength = 25.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 25.0;
				noiseToAlertMultiplier = 1.0;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 2;
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
			staminaDepletionSpeed = 2;
			staminaRechargeSpeed = 15;
		};
		class TargetSystemDZBase : TargetSystemDZBase
		{
			visionProximityRange = 2.0;
			visionProximityStrengthMult = 1.5;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.5;
		};
		class NoiseSystemParams : NoiseSystemParams
		{
			rangeMin = 10;
			rangeMax = 35.0;
			rangeShotMin = 50;
			rangeShotMax = 180.0;
			radiusMin = 5.0;
			radiusMax = 20.0;
			radiusShotMin = 25.0;
			radiusShotMax = 40.0;
		};
	};
	class Zombie2 : Zombie1
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class MovementSprint : MovementSprint
			{
				maxSpeed = 3.0;
				minSpeed = 0.0;
				acceleration = 15.0;
				maxAngleSpeed = 120.0;
				slowRadius = 0.0;
				goalRadius = 1.5;
				stopRadius = 1.7;
				useStartAnimation = "false";
				startAnimationMaxSpeed = 0.0;
				slowToTurn = "false";
				smoothAcceleration = "true";
				pathFilter = "ZombieAlerted";
			};
		};
	};
	class Zombie3 : Zombie2
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					noiseMakeAlertPeriod = 4.0;
					class NoiseMakeAlert : NoiseMakeAlert
					{
						strength = 25.0;
						type = "shot";
					};
				};
			};
		};
	};
	class Zombie4 : InfectedMale
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert
					{
						strength = 40.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 20.0;
				noiseToAlertMultiplier = 1.2;
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
			rangeShotMax = 175.0;
			radiusMin = 5.0;
			radiusMax = 22.0;
			radiusShotMin = 35.0;
			radiusShotMax = 70.0;
		};
	};
	class Zombie5 : InfectedMale
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert
					{
						strength = 10.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 20.0;
				noiseToAlertMultiplier = 1.0;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 1.8;
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
			visionNightMaxMult = 0.4;
		};
		class NoiseSystemParams : NoiseSystemParams
		{
			rangeMin = 5;
			rangeMax = 35.0;
			rangeShotMin = 15;
			rangeShotMax = 180.0;
			radiusMin = 5.0;
			radiusMax = 20.0;
			radiusShotMin = 35.0;
			radiusShotMax = 70.0;
		};
	};
	class Zombie6 : InfectedMale
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
	class Zombie7 : InfectedMale
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class MovementWalk : MovementWalk
			{
				maxSpeed = 3.0;
				minSpeed = 0.0;
				acceleration = 15.0;
				maxAngleSpeed = 120.0;
				slowRadius = 0.0;
				stopRadius = 1.7;
				pathFilter = "ZombieCalm";
			};
			class MovementRun : MovementRun
			{
				maxSpeed = 9.0;
				minSpeed = 0.0;
				acceleration = 27.0;
				maxAngleSpeed = 120.0;
				maxSpeedRange = 9.0;
				slowRadius = 0.0;
				goalRadius = 1.5;
				goalSpeed = 7.2;
				stopRadius = 1.7;
				waypointRadius = 1.5;
				useStartAnimation = "false";
				smoothAcceleration = "true";
				pathFilter = "ZombieAlerted";
			};
			class SlotCalm : SlotCalm
			{
				class BehaviourZombieCalm : BehaviourZombieCalm
				{
					StandingDurationMin = 0.5;
					StandingDurationMax = 3;
					WalkingDurationMin = 4;
					WalkingDurationMax = 8;
					MinLookTime = 1;
					MaxLookTime = 2;
					IsAttractMode = "false";
				};
			};
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					noiseMakeAlertPeriod = 10.0;
					class NoiseMakeAlert
					{
						strength = 0.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 25.0;
				noiseToAlertMultiplier = 1.5;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 2.0;
			};
		};
	};
	class Zombie8 : InfectedMale
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert
					{
						strength = 75.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 25.0;
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
			rangeMax = 45.0;
			rangeShotMin = 0;
			rangeShotMax = 150.0;
			radiusMin = 5.0;
			radiusMax = 35.0;
			radiusShotMin = 35.0;
			radiusShotMax = 80.0;
		};
	};
	class Zombie9 : InfectedMale
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class MovementWalk : MovementWalk
			{
				maxSpeed = 3.0;
				minSpeed = 0.0;
				acceleration = 15.0;
				maxAngleSpeed = 120.0;
				slowRadius = 0.0;
				stopRadius = 1.7;
				pathFilter = "ZombieCalm";
			};
			class MovementRun : MovementRun
			{
				maxSpeed = 10.0;
				minSpeed = 0.0;
				acceleration = 28.0;
				maxAngleSpeed = 120.0;
				maxSpeedRange = 10.0;
				slowRadius = 0.0;
				goalRadius = 1.5;
				goalSpeed = 7.2;
				stopRadius = 1.7;
				waypointRadius = 1.5;
				useStartAnimation = "false";
				smoothAcceleration = "true";
				pathFilter = "ZombieAlerted";
			};
			class SlotCalm : SlotCalm
			{
				class BehaviourZombieCalm : BehaviourZombieCalm
				{
					StandingDurationMin = 0.5;
					StandingDurationMax = 6;
					WalkingDurationMin = 2;
					WalkingDurationMax = 3;
					MinLookTime = 1;
					MaxLookTime = 2;
					IsAttractMode = "false";
				};
			};
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					noiseMakeAlertPeriod = 20.0;
					class NoiseMakeAlert
					{
						strength = 0.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 25.0;
				noiseToAlertMultiplier = 1.5;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 2.0;
			};
		};
	};
	class Zombie10 : InfectedMale
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert
					{
						strength = 40.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 15.0;
				noiseToAlertMultiplier = 1.2;
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
			staminaDepletionSpeed = 10;
			staminaRechargeSpeed = 15;
		};
		class TargetSystemDZBase : TargetSystemDZBase
		{
			visionNightMinMult = 2.0;
			visionNightMaxMult = 0.6;
		};
		class NoiseSystemParams : NoiseSystemParams
		{
			rangeMin = 0;
			rangeMax = 30.0;
			rangeShotMin = 0;
			rangeShotMax = 150.0;
			radiusMin = 5.0;
			radiusMax = 20.0;
			radiusShotMin = 35.0;
			radiusShotMax = 50.0;
		};
	};
	class Zombie11 : InfectedMale
	{
		class BehaviourHLZombie : BehaviourHLZombie
		{
			class SlotAlerted : SlotAlerted
			{
				class BehaviourZombieAlerted : BehaviourZombieAlerted
				{
					class NoiseMakeAlert
					{
						strength = 120.0;
						type = "sound";
					};
				};
			};
			class AlertSystem : AlertSystem
			{
				visionToAlertMultiplier = 15.0;
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
			visionNightMinMult = 2.0;
			visionNightMaxMult = 0.6;
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
	class Zombi_AoD_Novice1;
	class Zombi_AoD_Novice2;
	class Zombi_AoD_Novice3;
	class Zombi_AoD_Novice4;
	class Zombi_AoD_Novice5;
	class Zombi_AoD_Novice6;
	class Zombi_AoD_Novice7;
	class Zombi_AoD_Novice8;
	class Zombi_AoD_Loner_Zorya;
	class Zombi_AoD_Duty_Zorya;
	class Zombi_AoD_Freedom_Zorya;
	class Zombi_AoD_Monolith_Zorya;
	class X18_Mutant_Zombie : Zombi_AoD_Novice1
	{
		scope = 2;
		displayName = "$STR_AoD_Zombi_Stalk_Name";
		aiAgentTemplate = "Zombie1";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 140;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Zombie_Hand";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Zombie_SteakMeat";
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
	class X18_Mutant_Zombie_2 : Zombi_AoD_Novice2
	{
		scope = 2;
		displayName = "$STR_AoD_Zombi_Stalk_Name";
		aiAgentTemplate = "Zombie2";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 140;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Zombie_Hand";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Zombie_SteakMeat";
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
	class X18_Mutant_Zombie_3 : Zombi_AoD_Novice3
	{
		scope = 2;
		displayName = "$STR_AoD_Zombi_Stalk_Name";
		aiAgentTemplate = "Zombie3";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 140;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Zombie_Hand";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Zombie_SteakMeat";
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
	class X18_Mutant_Zombie_4 : Zombi_AoD_Novice4
	{
		scope = 2;
		displayName = "$STR_AoD_Zombi_Stalk_Name";
		aiAgentTemplate = "Zombie4";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 140;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Zombie_Hand";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Zombie_SteakMeat";
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
	class X18_Mutant_Zombie_5 : Zombi_AoD_Novice5
	{
		scope = 2;
		displayName = "$STR_AoD_Zombi_Stalk_Name";
		aiAgentTemplate = "Zombie5";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 140;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Zombie_Hand";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Zombie_SteakMeat";
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
	class X18_Mutant_Zombie_6 : Zombi_AoD_Novice6
	{
		scope = 2;
		displayName = "$STR_AoD_Zombi_Stalk_Name";
		aiAgentTemplate = "Zombie6";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 140;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Zombie_Hand";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Zombie_SteakMeat";
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
	class X18_Mutant_Zombie_7 : Zombi_AoD_Novice7
	{
		scope = 2;
		displayName = "$STR_AoD_Zombi_Stalk_Name";
		aiAgentTemplate = "Zombie7";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 140;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Zombie_Hand";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Zombie_SteakMeat";
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
	class X18_Mutant_Zombie_8 : Zombi_AoD_Loner_Zorya
	{
		scope = 2;
		displayName = "$STR_AoD_Zombi_Stalk_Name";
		aiAgentTemplate = "Zombie8";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 140;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Zombie_Hand";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Zombie_SteakMeat";
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
	class X18_Mutant_Zombie_9 : Zombi_AoD_Duty_Zorya
	{
		scope = 2;
		displayName = "$STR_AoD_Zombi_Stalk_Name";
		aiAgentTemplate = "Zombie9";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 140;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Zombie_Hand";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Zombie_SteakMeat";
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
	class X18_Mutant_Zombie_10 : Zombi_AoD_Freedom_Zorya
	{
		scope = 2;
		displayName = "$STR_AoD_Zombi_Stalk_Name";
		aiAgentTemplate = "Zombie10";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 140;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Zombie_Hand";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Zombie_SteakMeat";
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
	class X18_Mutant_Zombie_11 : Zombi_AoD_Monolith_Zorya
	{
		scope = 2;
		displayName = "$STR_AoD_Zombi_Stalk_Name";
		aiAgentTemplate = "Zombie11";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 140;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
						hitpoints = 100;
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
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_Zombie_Hand";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Zombie_SteakMeat";
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
	class Mutant_AoD_Zombi_Hand : Inventory_Base {};
	class X18_Loot_Mutant_Zombie_Hand : Mutant_AoD_Zombi_Hand
	{
		scope = 2;
		displayName = "$STR_AoD_Mutant_Zombi_Hand_Name";
		descriptionShort = "$STR_AoD_Mutant_Zombi_Hand_Decr";
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