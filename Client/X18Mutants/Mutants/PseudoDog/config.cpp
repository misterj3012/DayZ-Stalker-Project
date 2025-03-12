class CfgPatches
{
	class X18Mutants_Animals_PseudoDog
	{
		units[] = { "Mutant_AoD_Pse_Dog1","Mutant_AoD_Pse_Dog2" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Animals", "DZ_Weapons_Melee","DZ_AoD_Mutant_Pse_Dog", "DZ_Gear_Food","DZ_AoD_Mutant_Pdog_Tail" };
		ammo[] = { "MeleePseudoDog","MeleePseudoDog_Hight" };
	};
};
class GroupBehaviourTemplates
{
	class DZPseudoDogGroupBeh
	{
		type = "Predators";
		alertDistributionSpeed = 20;
		catchUpTestDelay = 4;
		catchUpStartRadius = 40;
		catchUpTargetRadius = 5;
		groupRadius = 5;
		spawnMinDistanceBetweenAgents = 1;
		agentPathLength = 50;
		atNeedMinDuration = 60;
		atNeedMaxDuration = 120;
		singleAgentSafeKeeperDelayMin = 100;
		singleAgentSafeKeeperDelayMax = 100;
		preyAttractionRange = 60;
		innerOuterCircleRatio = 0.6;
		endAttractionRange = 10;
		attractionCooldown = 60;
		endAttractionTime = 300;
		targetEscapingSpeed = 1.5;
		killAddFear = 34;
		eatingTime = 600;
		huntingCooldown = 10;
		maxHuntingTime = 60;
		safeKeeperIntervalMin = 20;
		safeKeeperIntervalMax = 40;
		siegeAttackCountdownMin = 1;
		siegeAttackCountdownMax = 4;
		huntAttackCountdownMin = 1;
		huntAttackCountdownMax = 2;
		changeTargetCooldown = 1;
		changeTargetAlertRatio = 1.3;
		changeTargetEffectRadius = 6;
		subgroupSpacingMax = 25;
		class LifeCycleDayTime
		{
			class Activity1
			{
				endTimeMin = 7.5;
				endTimeMax = 8.5;
				zoneType = "Rest";
			};
			class Activity2
			{
				endTimeMin = 16;
				endTimeMax = 17;
				zoneType = "Rest";
			};
			class Activity3
			{
				endTimeMin = 18.5;
				endTimeMax = 19.5;
				zoneType = "Rest";
			};
			class Activity4
			{
				endTimeMin = 22.5;
				endTimeMax = 23.5;
				zoneType = "Graze";
			};
			class Activity5
			{
				endTimeMin = 25.5;
				endTimeMax = 28.5;
				zoneType = "Graze";
			};
		};
	};
};
class CfgAIBehaviours
{
	class Predators_PseudoDog
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "Predator";
		defaultGroupTemplateName = "DZPseudoDogGroupBeh";
		class PathAgent
		{
			radius = 0.3;
			height = 1;
			lengthRadius = 0.7;
		};
		class BehaviourHLPredator
		{
			instantAlertRangeMin = 0;
			instantAlertRangeMax = 0;
			instantAlertStrength = 0;
			proximityAttackRange = 2.5;
			attackCooldown = 3;
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					travelingMode = "true";
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 0;
					grazeOnSpotDurationMin = 5;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 15;
					grazeWalkingDurationMax = 25;
					restingDurationMin = 5;
					restingDurationMax = 10;
					travelingDurationMin = 15;
					travelingDurationMax = 30;
					grazeWalkingSpeed = 0.3;
					travelingWalkingSpeed = 1.36;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						pathFilter = "WolfOnHunt";
					};
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.38;
						minSpeed = 0.78;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
				};
			};
			class SlotSiege
			{
				class BehaviourSiege
				{
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = { "" };
						};
						class Sound2
						{
							sounds[] = { "" };
						};
						class Sound3
						{
							sounds[] = { "" };
						};
						probability = 1;
					};
					class SoundsDuring
					{
						class Sound1
						{
							sounds[] = { "" };
						};
						class Sound2
						{
							sounds[] = { "" };
						};
						class Sound3
						{
							sounds[] = { "" };
						};
						class Sound4
						{
							sounds[] = { "" };
						};
						class Sound5
						{
							sounds[] = { "" };
						};
						class Sound6
						{
							sounds[] = { "" };
						};
						class Sound7
						{
							sounds[] = { "" };
						};
						class Sound8
						{
							sounds[] = { "" };
						};
						probability = 0.4;
						RepeatTimeMin = 5;
						RepeatTimeMax = 15;
						RepeatEnabled = "true";
					};
					innerRadius = 7;
					innerRadiusMin = 4.5;
					innerRadiusMax = 10;
					outerRadius = 16;
					directionChangeTimeMin = 7;
					directionChangeTimeMax = 25;
					PlayerFOV = 1.4;
					preferPlayerFOVCooldown = 1;
					attackDistance = 3.5;
					class InnerCircleMovement
					{
						maxSpeed = 6.3;
						optimalSpeed = 6.3;
						optimalSpeedRange = 1;
						minSpeed = 1;
						acceleration = 7;
						maxAngleSpeed = 90;
						slowRadius = 0;
						stopRadius = 2;
						maxSpeedRange = 2;
						pathFilter = "WolfOnHunt";
						startAnimationMaxSpeed = 0.54;
					};
					class Movement
					{
						maxSpeed = 9;
						optimalSpeed = 6.3;
						optimalSpeedRange = 15;
						minSpeed = 1;
						acceleration = 10;
						maxAngleSpeed = 180;
						slowRadius = 0;
						stopRadius = 2;
						maxSpeedRange = 20;
						pathFilter = "WolfOnOuterCircle";
						startAnimationMaxSpeed = 0.54;
					};
					class AttackMovement
					{
						maxSpeed = 12.175;
						optimalSpeed = 12;
						optimalSpeedRange = 6;
						minSpeed = 0.8;
						acceleration = 10;
						maxAngleSpeed = 180;
						slowRadius = 2;
						stopRadius = 3;
						maxSpeedRange = 30;
						pathFilter = "WolfOnHunt";
					};
				};
			};
			class SlotEating
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 20;
					eatingWeight = 20;
					grazeOnSpotDurationMin = 5;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 10;
					grazeWalkingDurationMax = 15;
					restingDurationMin = 15;
					restingDurationMax = 25;
					travelingDurationMin = 15;
					travelingDurationMax = 30;
					eatingDurationMin = 15;
					eatingDurationMax = 25;
					safetyDurationMin = 10;
					safetyDurationMax = 20;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						pathFilter = "WolfOnHunt";
					};
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.38;
						minSpeed = 0.78;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
				};
			};
			class SlotHunting
			{
				class BehaviourHunt
				{
					attackRange = 3.5;
					followingRadius = 15;
					followingRadiusReqroupCooldownMin = 5;
					followingRadiusReqroupCooldownMax = 15;
					followingRadiusRegroupMinSpeed = 1.5;
					predictFollowingMinDistance = 10;
					minDistanceToTargetRatio = 0.3;
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = { "WolfBark3_0_SoundSet" };
						};
						probability = 0.3;
					};
					class SoundsDuring
					{
						class Sound1
						{
							sounds[] = { "X18_Dog_Bark2_SoundSet" };
						};
						probability = 1;
						RepeatTimeMin = 10;
						RepeatTimeMax = 30;
						RepeatEnabled = "true";
					};
					class Movement
					{
						maxSpeed = 10;
						optimalSpeed = 9.5;
						minSpeed = 1;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						maxSpeedRange = 15;
						optimalSpeedRange = 5;
						pathFilter = "WolfOnHunt";
					};
					class MovementAttack
					{
						maxSpeed = 12.175;
						optimalSpeed = 12.175;
						minSpeed = 6;
						acceleration = 20;
						maxAngleSpeed = 360;
						slowRadius = 0;
						stopRadius = 0;
						maxSpeedRange = 3;
						optimalSpeedRange = 1;
						pathFilter = "WolfOnHunt";
					};
				};
			};
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					travelingMode = "true";
					grazeOnSpotWeight = 50;
					grazeWalkingWeight = 50;
					restWeight = 50;
					travelWeight = 0;
					grazeOnSpotDurationMin = 5;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 15;
					grazeWalkingDurationMax = 25;
					restingDurationMin = 25;
					restingDurationMax = 35;
					travelingDurationMin = 15;
					travelingDurationMax = 30;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						pathFilter = "WolfOnHunt";
					};
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.38;
						minSpeed = 0.78;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
				};
			};
			class SlotCalmTravelling
			{
				class BehaviourCalm
				{
					travelingMode = "true";
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 50;
					grazeOnSpotDurationMin = 10;
					grazeOnSpotDurationMax = 20;
					grazeWalkingDurationMin = 25;
					grazeWalkingDurationMax = 35;
					restingDurationMin = 5;
					restingDurationMax = 10;
					travelingDurationMin = 10;
					travelingDurationMax = 50;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 4;
						stopRadius = 2;
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.38;
						minSpeed = 0.78;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 2;
						stopRadius = 1;
						pathFilter = "WolfOnHunt";
					};
				};
			};
			class SlotAttracted
			{
				class BehaviourCalm
				{
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = { "X18_Dog_Howl_SoundSet","X18_Dog_HowlDistant_SoundSet" };
						};
						class Sound2
						{
							sounds[] = { "" };
						};
						class Sound3
						{
							sounds[] = { "" };
						};
						class Sound4
						{
							sounds[] = { "" };
						};
						class Sound5
						{
							sounds[] = { "" };
						};
						class Sound6
						{
							sounds[] = { "" };
						};
						class Sound7
						{
							sounds[] = { "" };
						};
						class Sound8
						{
							sounds[] = { "" };
						};
						probability = 0.9;
					};
					class SoundsDuring
					{
						class Sound1
						{
							sounds[] = { "X18_Dog_Howl_SoundSet","X18_Dog_HowlDistant_SoundSet" };
						};
						class Sound2
						{
							sounds[] = { "" };
						};
						class Sound3
						{
							sounds[] = { "" };
						};
						class Sound4
						{
							sounds[] = { "" };
						};
						class Sound5
						{
							sounds[] = { "" };
						};
						class Sound6
						{
							sounds[] = { "" };
						};
						class Sound7
						{
							sounds[] = { "" };
						};
						class Sound8
						{
							sounds[] = { "" };
						};
						probability = 0.5;
						RepeatTimeMin = 5;
						RepeatTimeMax = 25;
						RepeatEnabled = "true";
					};
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 50;
					grazeOnSpotDurationMin = 5;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 5;
					grazeWalkingDurationMax = 10;
					restingDurationMin = 5;
					restingDurationMax = 10;
					travelingDurationMin = 50;
					travelingDurationMax = 100;
					grazeWalkingSpeed = 0.544;
					travelingWalkingSpeed = 0.782;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 5;
						stopRadius = 3;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "WolfOnHunt";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.38;
						minSpeed = 0.78;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "WolfOnHunt";
					};
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 0;
						stopRadius = 0.5;
					};
				};
			};
			class SlotFireplace
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 20;
					travelWeight = 0;
					grazeOnSpotDurationMin = 50;
					grazeOnSpotDurationMax = 100;
					grazeWalkingDurationMin = 50;
					grazeWalkingDurationMax = 100;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					grazeWalkingSpeed = 0.2;
					travelingWalkingSpeed = 1.36;
					safetyIntervalMin = 30;
					safetyIntervalMax = 40;
					safetyDurationMin = 5;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5;
						maxAngleSpeed = 90;
						slowRadius = 0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
				};
			};
			class SlotScared
			{
				class BehaviourFleeFromTargets
				{
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = { "" };
						};
						class Sound2
						{
							sounds[] = { "" };
						};
						class Sound3
						{
							sounds[] = { "" };
						};
						probability = 1;
					};
					class SoundsDuring
					{
						class Sound1
						{
							sounds[] = { "" };
						};
						class Sound2
						{
							sounds[] = { "" };
						};
						class Sound3
						{
							sounds[] = { "" };
						};
						probability = 0.3;
						RepeatTimeMin = 5;
						RepeatTimeMax = 25;
						RepeatEnabled = "true";
					};
					class RunMovement
					{
						maxSpeed = 12.175;
						optimalSpeed = 6.39;
						minSpeed = 1;
						acceleration = 2;
						maxAngleSpeed = 360;
						slowRadius = 4;
						stopRadius = 0;
						maxSpeedRange = 15;
						optimalSpeedRange = 10;
						pathFilter = "DeerOnRun";
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 10;
				noiseToAlertMultiplier = 1;
				damageToAlertMultiplier = 200;
				class Calm
				{
					dropSpeed = 3;
					dropDelay = 2;
					maxAlertValue = 30;
				};
				class Alerted
				{
					dropSpeed = 11;
					dropDelay = 0;
					maxAlertValue = 100;
				};
				class AlertedExtra
				{
					dropSpeed = 25;
					dropDelay = 10;
					maxAlertValue = 500;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 25;
			rangeMax = 60;
			rangeShotMin = 0;
			rangeShotMax = 50;
			class NoiseStrengthTeamMultipliers
			{
				BigGame = 0.4;
				Zombies = 0.6;
				Player = 1;
			};
		};
		class TargetSystemDZBase
		{
			class VisionTeamMultipliers
			{
				BigGame = 0.6;
				Zombies = 1;
				Player = 1;
			};
			visionManSizeStand = 1;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.6;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.5;
			visionRangeMin = 50;
			visionRangeMax = 70;
			visionFov = 1.8;
			visionPeripheralRangeMin = 1;
			visionPeripheralRangeMax = 16;
			visionPeripheralFov = 6.2;
			visionNightMinMult = 1;
			visionNightMaxMult = 0.75;
			visionRainMinMult = 1;
			visionRainMaxMult = 0.9;
			visionFogMinMult = 1;
			visionFogMaxMult = 0.7;
		};
	};
};
class CfgVehicles
{
	class Mutant_AoD_Pse_Dog1;
	class Mutant_AoD_Pse_Dog2;
	class X18_Mutant_Animal_PseudoDog : Mutant_AoD_Pse_Dog1
	{
		scope = 2;
		displayName = "$STR_PseudoDog";
		descriptionShort = "$STR_DSC_PseudoDog";
		aiAgentTemplate = "Predators_PseudoDog";
		DamageSphereAmmos[] = { "MeleePseudoDog" };
		injuryLevels[] = { 1.0,0.5,0.2,0.0 };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
				class Blood
				{
					hitpoints = 5000;
				};
				class Shock
				{
					hitpoints = 100;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[] = { "Zone_Head" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.15;
					canBleed = 0;
					class Health
					{
						hitpoints = 180;
						transferToGlobalCoef = 1;
					};
					class Blood : Health
					{
						hitpoints = 0;
					};
					class Shock : Health
					{
						hitpoints = 0;
					};
				};
				class Zone_Neck : Zone_Head
				{
					componentNames[] = { "Zone_Neck" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 100;
					};
				};
				class Zone_Chest : Zone_Head
				{
					componentNames[] = { "Zone_Chest" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 150;
					};
				};
				class Zone_Belly : Zone_Head
				{
					componentNames[] = { "Zone_Belly" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 150;
					};
				};
				class Zone_Spine : Zone_Head
				{
					componentNames[] = { "Zone_Spine_Front","Zone_Spine_Back" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 150;
					};
				};
				class Zone_Pelvis : Zone_Head
				{
					componentNames[] = { "Zone_Pelvis" };
					transferToZonesNames[] = { "Zone_Spine" };
					transferToZonesCoefs[] = { 0.5 };
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 180;
					};
				};
				class Zone_Legs : Zone_Head
				{
					componentNames[] = { "Zone_Legs_Front","Zone_Legs_Back" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.0;
					class Health : Health
					{
						hitpoints = 100;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedTail
			{
				item = "X18_Loot_Mutant_Animal_PseudoDog_Tail";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Animal_PseudoDog_SteakMeat";
				count = 2;
				quantityMinMaxCoef[] = { 0.2,1 };
			};
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "PawMediumWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "PawMediumWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "PawMediumWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "PawMediumWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "PawMediumRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "PawMediumRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "PawMediumRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "PawMediumRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 8;
				};
				class Bodyfall
				{
					soundLookupTable = "PawMediumBodyfall_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 11;
				};
				class Settle
				{
					soundLookupTable = "PawMediumSettle_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 12;
				};
				class Rest2standA
				{
					soundLookupTable = "PawMediumRest2standA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 13;
				};
				class Rest2standB
				{
					soundLookupTable = "PawMediumRest2standB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 14;
				};
				class Stand2restA
				{
					soundLookupTable = "PawMediumStand2restA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 15;
				};
				class Stand2restB
				{
					soundLookupTable = "PawMediumStand2restB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 16;
				};
				class Stand2restC
				{
					soundLookupTable = "PawMediumStand2restC_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 17;
				};
				class Jump
				{
					soundLookupTable = "PawMediumJump_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 18;
				};
				class Impact
				{
					soundLookupTable = "PawMediumImpact_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 19;
				};
			};
			class Sounds
			{
				class WolfBark
				{
					soundSet = "PseDogAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 1;
				};
				class WolfBark_1
				{
					soundSet = "PseDogAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 61;
				};
				class WolfBark_2
				{
					soundSet = "PseDogAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 71;
				};
				class WolfBark2
				{
					soundSet = "PseDogAttack2_SoundSet";
					noise = "WolfRoarNoise";
					id = 2;
				};
				class WolfBark3
				{
					soundSet = "PseDogAttack2_SoundSet";
					noise = "WolfRoarNoise";
					id = 3;
				};
				class WolfBreath
				{
					soundSet = "WolfBreath_SoundSet";
					noise = "WolfRoarNoise";
					id = 4;
				};
				class WolfGroans
				{
					soundSet = "PseDogGroan_SoundSet";
					noise = "WolfRoarNoise";
					id = 5;
				};
				class WolfGrowl_A
				{
					soundSet = "PseDogGrowl_SoundSet";
					noise = "WolfRoarNoise";
					id = 6;
				};
				class WolfGrowl_B
				{
					soundSet = "PseDogGrowl_SoundSet";
					noise = "WolfRoarNoise";
					id = 7;
				};
				class WolfGrowl
				{
					soundSet = "PseDogGrowl_SoundSet";
					noise = "WolfRoarNoise";
					id = 8;
				};
				class WolfPant
				{
					soundSet = "PseDogIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 9;
				};
				class WolfPantShort
				{
					soundSet = "PseDogIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 10;
				};
				class WolfPantLong
				{
					soundSet = "PseDogIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 18;
				};
				class WolfSnarl
				{
					soundSet = "WolfSnarl_SoundSet";
					noise = "WolfRoarNoise";
					id = 11;
				};
				class WolfSnarlShort
				{
					soundSet = "WolfSnarlShort_SoundSet";
					noise = "WolfRoarNoise";
					id = 12;
				};
				class WolfWhimper
				{
					soundSet = "WolfWhimper_SoundSet";
					noise = "WolfRoarNoise";
					id = 13;
				};
				class WolfYelp
				{
					soundSet = "PseDogDie_SoundSet";
					noise = "WolfRoarNoise";
					id = 14;
				};
				class WolfYawn
				{
					soundSet = "PseDogDie_SoundSet";
					noise = "WolfRoarNoise";
					id = 15;
				};
				class WolfDeath
				{
					soundSet = "PseDogHurt_SoundSet";
					noise = "WolfRoarNoise";
					id = 20;
				};
				class WolfHowl
				{
					soundSet = "PseDogHowl_SoundSet";
					noise = "WolfRoarNoise";
					id = 16;
				};
				class WolfHowls
				{
					soundSet = "PseDogDistant_SoundSet";
					noise = "WolfRoarNoise";
					id = 17;
				};
			};
			class Damages
			{
				class Bite
				{
					damage = "PseudoDogBiteDamage";
					id = 1;
				};
				class BiteLow
				{
					damage = "PseudoDogLowBiteDamage";
					id = 2;
				};
			};
		};
		class CommandMoveSettings
		{
			useSpeedMapping = 1;
			movementSpeedMapping[] = { 0,0.25,0.5,1.2,4.5,12.2 };
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout = 0.5;
			lookAtFilterSpeed = 1.57;
		};
	};
	class X18_Mutant_Animal_PseudoDog_White : Mutant_AoD_Pse_Dog2
	{
		scope = 2;
		displayName = "$STR_PseudoDog";
		descriptionShort = "$STR_DSC_PseudoDog";
		aiAgentTemplate = "Predators_PseudoDog";
		DamageSphereAmmos[] = { "MeleePseudoDog" };
		injuryLevels[] = { 1.0,0.5,0.2,0.0 };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
				class Blood
				{
					hitpoints = 5000;
				};
				class Shock
				{
					hitpoints = 100;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[] = { "Zone_Head" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.15;
					canBleed = 0;
					class Health
					{
						hitpoints = 180;
						transferToGlobalCoef = 1;
					};
					class Blood : Health
					{
						hitpoints = 0;
					};
					class Shock : Health
					{
						hitpoints = 0;
					};
				};
				class Zone_Neck : Zone_Head
				{
					componentNames[] = { "Zone_Neck" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 100;
					};
				};
				class Zone_Chest : Zone_Head
				{
					componentNames[] = { "Zone_Chest" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 150;
					};
				};
				class Zone_Belly : Zone_Head
				{
					componentNames[] = { "Zone_Belly" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 150;
					};
				};
				class Zone_Spine : Zone_Head
				{
					componentNames[] = { "Zone_Spine_Front","Zone_Spine_Back" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 150;
					};
				};
				class Zone_Pelvis : Zone_Head
				{
					componentNames[] = { "Zone_Pelvis" };
					transferToZonesNames[] = { "Zone_Spine" };
					transferToZonesCoefs[] = { 0.5 };
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 180;
					};
				};
				class Zone_Legs : Zone_Head
				{
					componentNames[] = { "Zone_Legs_Front","Zone_Legs_Back" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.0;
					class Health : Health
					{
						hitpoints = 100;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedHead
			{
				item = "X18_Loot_Mutant_Animal_PseudoDog_Head";
				count = 1;
			};
			class ObtainedTail
			{
				item = "X18_Loot_Mutant_Animal_PseudoDog_Tail";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Animal_PseudoDog_SteakMeat";
				count = 2;
				quantityMinMaxCoef[] = { 0.2,1 };
			};
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "PawMediumWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "PawMediumWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "PawMediumWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "PawMediumWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "PawMediumRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "PawMediumRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "PawMediumRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "PawMediumRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 8;
				};
				class Bodyfall
				{
					soundLookupTable = "PawMediumBodyfall_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 11;
				};
				class Settle
				{
					soundLookupTable = "PawMediumSettle_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 12;
				};
				class Rest2standA
				{
					soundLookupTable = "PawMediumRest2standA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 13;
				};
				class Rest2standB
				{
					soundLookupTable = "PawMediumRest2standB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 14;
				};
				class Stand2restA
				{
					soundLookupTable = "PawMediumStand2restA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 15;
				};
				class Stand2restB
				{
					soundLookupTable = "PawMediumStand2restB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 16;
				};
				class Stand2restC
				{
					soundLookupTable = "PawMediumStand2restC_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 17;
				};
				class Jump
				{
					soundLookupTable = "PawMediumJump_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 18;
				};
				class Impact
				{
					soundLookupTable = "PawMediumImpact_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 19;
				};
			};
			class Sounds
			{
				class WolfBark
				{
					soundSet = "PseDogAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 1;
				};
				class WolfBark_1
				{
					soundSet = "PseDogAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 61;
				};
				class WolfBark_2
				{
					soundSet = "PseDogAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 71;
				};
				class WolfBark2
				{
					soundSet = "PseDogAttack2_SoundSet";
					noise = "WolfRoarNoise";
					id = 2;
				};
				class WolfBark3
				{
					soundSet = "PseDogAttack2_SoundSet";
					noise = "WolfRoarNoise";
					id = 3;
				};
				class WolfBreath
				{
					soundSet = "WolfBreath_SoundSet";
					noise = "WolfRoarNoise";
					id = 4;
				};
				class WolfGroans
				{
					soundSet = "PseDogGroan_SoundSet";
					noise = "WolfRoarNoise";
					id = 5;
				};
				class WolfGrowl_A
				{
					soundSet = "PseDogGrowl_SoundSet";
					noise = "WolfRoarNoise";
					id = 6;
				};
				class WolfGrowl_B
				{
					soundSet = "PseDogGrowl_SoundSet";
					noise = "WolfRoarNoise";
					id = 7;
				};
				class WolfGrowl
				{
					soundSet = "PseDogGrowl_SoundSet";
					noise = "WolfRoarNoise";
					id = 8;
				};
				class WolfPant
				{
					soundSet = "PseDogIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 9;
				};
				class WolfPantShort
				{
					soundSet = "PseDogIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 10;
				};
				class WolfPantLong
				{
					soundSet = "PseDogIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 18;
				};
				class WolfSnarl
				{
					soundSet = "WolfSnarl_SoundSet";
					noise = "WolfRoarNoise";
					id = 11;
				};
				class WolfSnarlShort
				{
					soundSet = "WolfSnarlShort_SoundSet";
					noise = "WolfRoarNoise";
					id = 12;
				};
				class WolfWhimper
				{
					soundSet = "WolfWhimper_SoundSet";
					noise = "WolfRoarNoise";
					id = 13;
				};
				class WolfYelp
				{
					soundSet = "PseDogDie_SoundSet";
					noise = "WolfRoarNoise";
					id = 14;
				};
				class WolfYawn
				{
					soundSet = "PseDogDie_SoundSet";
					noise = "WolfRoarNoise";
					id = 15;
				};
				class WolfDeath
				{
					soundSet = "PseDogHurt_SoundSet";
					noise = "WolfRoarNoise";
					id = 20;
				};
				class WolfHowl
				{
					soundSet = "PseDogHowl_SoundSet";
					noise = "WolfRoarNoise";
					id = 16;
				};
				class WolfHowls
				{
					soundSet = "PseDogDistant_SoundSet";
					noise = "WolfRoarNoise";
					id = 17;
				};
			};
			class Damages
			{
				class Bite
				{
					damage = "PseudoDogBiteDamage";
					id = 1;
				};
				class BiteLow
				{
					damage = "PseudoDogLowBiteDamage";
					id = 2;
				};
			};
		};
		class CommandMoveSettings
		{
			useSpeedMapping = 1;
			movementSpeedMapping[] = { 0,0.25,0.5,1.2,4.5,12.2 };
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout = 0.5;
			lookAtFilterSpeed = 1.57;
		};
	};
	class Inventory_Base;
	class FS_PseDog_Head : Inventory_Base {};
	class X18_Loot_Mutant_Animal_PseudoDog_Head : FS_PseDog_Head
	{
		scope = 2;
		displayName = "$STR_PseudoDog_Head";
		descriptionShort = "$STR_DSC_PseudoDog_Head";
		weight = 1300;
		itemSize[] = { 3,4 };
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
	class Mutant_AoD_Pdog_Tail : Inventory_Base {};
	class X18_Loot_Mutant_Animal_PseudoDog_Tail : Mutant_AoD_Pdog_Tail
	{
		scope = 2;
		displayName = "$STR_PseudoDog_Tail";
		descriptionShort = "$STR_DSC_PseudoDog_Tail";
		weight = 400;
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