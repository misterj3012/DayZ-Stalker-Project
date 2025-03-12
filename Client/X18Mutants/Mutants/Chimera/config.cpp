class CfgPatches
{
	class X18Mutants_Animals_Chimera
	{
		units[] = { "Mutant_AoD_Himera1","Mutant_AoD_Himera2","Mutant_AoD_Himera3" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Animals","DZ_Data_Bliss","DZ_AI_Bliss","DZ_Weapons_Melee","DZ_AoD_Mutant_Himera","DZ_AoD_Mutant_Himera_Kogot" };
		ammo[] = { "MeleeHimera","MeleeHimeraShock" };
	};
};
class GroupBehaviourTemplates
{
	class DZChimeraGroupBeh
	{
		type = "Bear";
		agentPathLength = 20.0;
		simpleLodGroupSpeed = 1.0;
		singleAgentSafeKeeperDelayMin = 30.0;
		singleAgentSafeKeeperDelayMax = 50.0;
		safeKeeperIntervalMin = 30.0;
		safeKeeperIntervalMax = 50.0;
		class LifeCycleDayTime
		{
			class Activity1
			{
				endTimeMin = 8.0;
				endTimeMax = 9.0;
				zoneType = "Graze";
			};
			class Activity2
			{
				endTimeMin = 10.0;
				endTimeMax = 11.0;
				zoneType = "Graze";
			};
			class Activity3
			{
				endTimeMin = 13.0;
				endTimeMax = 14.0;
				zoneType = "Graze";
			};
			class Activity4
			{
				endTimeMin = 17.0;
				endTimeMax = 18.0;
				zoneType = "Graze";
			};
			class Activity5
			{
				endTimeMin = 20.0;
				endTimeMax = 21.0;
				zoneType = "Graze";
			};
		};
	};
};
class CfgAIBehaviours
{
	class Predator_Chimera
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "Predator";
		defaultGroupTemplateName = "DZChimeraGroupBeh";
		class PathAgent
		{
			radius = 0.25;
			height = 1.8;
		};
		class BehaviourHLBear
		{
			instantAlertRangeMin = 15.0;
			instantAlertRangeMax = 50.0;
			instantAlertStrength = 10.0;
			enragedReachDistanceMax = 6.0;
			enragedReachDistanceMin = 2.5;
			predictReachFollowingMaxDistance = 10.0;
			predictReachFollowingTime = 0.5;
			annoyanceDistance = 30.0;
			annoyanceTimerMin = 8.0;
			annoyanceTimerMax = 12.0;
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 5;
					grazeWalkingWeight = 5;
					restWeight = 0;
					travelWeight = 0;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 60;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 60;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 15;
					safetyDurationMax = 20;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 2.6;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.24;
						minSpeed = 0.24;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.5;
						minSpeed = 0.55;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
				};
			};
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 0;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 40;
					grazeWalkingDurationMin = 10;
					grazeWalkingDurationMax = 15;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 15;
					safetyDurationMax = 25;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 2.6;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.24;
						minSpeed = 0.24;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.5;
						minSpeed = 0.55;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
				};
			};
			class SlotCalmTravelling
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 0;
					travelWeight = 20;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 30;
					grazeWalkingDurationMin = 10;
					grazeWalkingDurationMax = 15;
					restingDurationMin = 0;
					restingDurationMax = 0;
					travelingDurationMin = 30;
					travelingDurationMax = 50;
					safetyDurationMin = 15;
					safetyDurationMax = 25;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 2.6;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.24;
						minSpeed = 0.24;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.5;
						minSpeed = 0.55;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
				};
			};
			class SlotDrinking
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 0;
					travelWeight = 10;
					drinkingWeight = 0;
					grazeOnSpotDurationMin = 100;
					grazeOnSpotDurationMax = 100;
					grazeWalkingDurationMin = 100;
					grazeWalkingDurationMax = 100;
					restingDurationMin = 200;
					restingDurationMax = 200;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					drinkingDurationMin = 150;
					drinkingDurationMax = 150;
					safetyDurationMin = 15;
					safetyDurationMax = 20;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 2.6;
					safetyLookAngleChangeInterval = 7;
					class DrinkingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
					class GrazeMovement
					{
						maxSpeed = 0.24;
						minSpeed = 0.24;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.5;
						minSpeed = 0.55;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 10;
					walkToWeight = 0;
					stayLookAtWeight = 15;
					stayWeight = 0;
					walkAwaySpreadAngle = 3.5;
					walkAwayInitialAngle = 3.5;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 12;
					walkAwayDurationMax = 18;
					walkToDurationMin = 4;
					walkToDurationMax = 8;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 15;
					stayDurationMin = 5;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
				};
			};
			class SlotSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 10;
					walkToWeight = 10;
					stayLookAtWeight = 20;
					stayWeight = 0;
					walkAwaySpreadAngle = 3.5;
					walkAwayInitialAngle = 3.5;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 12;
					walkAwayDurationMax = 18;
					walkToDurationMin = 10;
					walkToDurationMax = 15;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 15;
					stayDurationMin = 5;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.56;
					};
				};
			};
			class SlotIntimidate
			{
				class BehaviourInfectedPackEnraged
				{
					class Movement
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						acceleration = 4.0;
						maxAngleSpeed = 120.0;
						slowRadius = 1.5;
						stopRadius = 0.8;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
					class MovementApproaching
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						optimalSpeed = 0.6;
						acceleration = 1.5;
						maxAngleSpeed = 40.0;
						slowRadius = 1.0;
						stopRadius = 0.2;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
					class MovementReach
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						acceleration = 4.0;
						maxAngleSpeed = 120.0;
						slowRadius = 5.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
				};
			};
			class SlotEnraged
			{
				class BehaviourInfectedPackEnraged
				{
					class Movement
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						acceleration = 4.0;
						maxAngleSpeed = 120.0;
						slowRadius = 1.5;
						stopRadius = 0.8;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
					class MovementApproaching
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						acceleration = 1.5;
						maxAngleSpeed = 40.0;
						slowRadius = 1.0;
						stopRadius = 0.2;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
					class MovementReach
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						acceleration = 4.0;
						maxAngleSpeed = 120.0;
						slowRadius = 5.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
				};
			};
			class SlotScared
			{
				class BehaviourGoToTarget
				{
					class Movement
					{
						maxSpeed = 3.3;
						optimalSpeed = 1.0;
						minSpeed = 0.55;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 20.0;
						acceleration = 5.0;
						maxAngleSpeed = 60.0;
						slowRadius = 4.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 0.61;
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 6.0;
				noiseToAlertMultiplier = 1.2;
				noiseShotToAlertMultiplier = 0.5;
				damageToAlertMultiplier = 1e+06;
				class Calm
				{
					dropSpeed = 9;
					dropDelay = 1;
					maxAlertValue = 25;
				};
				class NonSpecificThreat
				{
					dropSpeed = 9;
					dropDelay = 25;
					maxAlertValue = 50;
				};
				class SpecificThreat
				{
					dropSpeed = 5;
					dropDelay = 15;
					maxAlertValue = 75;
				};
				class Alerted
				{
					dropSpeed = 5;
					dropDelay = 5;
					maxAlertValue = 200;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 20.0;
			rangeMax = 110.0;
			rangeShotMin = 100.0;
			rangeShotMax = 300.0;
			class NoiseStrengthTeamMultipliers
			{
				BigGame = 0.8;
				Zombies = 1.0;
				Player = 1.0;
			};
		};
		class TargetSystemDZBase
		{
			class VisionTeamMultipliers
			{
				BigGame = 1.0;
				Zombies = 1.0;
				Player = 1.0;
				Predator = 1.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.5;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.5;
			visionRangeMin = 20;
			visionRangeMax = 60;
			visionFov = 2.0;
			visionPeripheralRangeMin = 1;
			visionPeripheralRangeMax = 30;
			visionPeripheralFov = 3.2;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.75;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 0.9;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 0.7;
		};
	};

};
class CfgVehicles
{
	class Mutant_AoD_Himera1;
	class Mutant_AoD_Himera2;
	class Mutant_AoD_Himera3;
	class X18_Mutant_Animal_Chimera : Mutant_AoD_Himera1
	{
		scope = 2;
		displayName = "$STR_AoD_Mutant_Himera_Name";
		aiAgentTemplate = "Predator_Chimera";
		DamageSphereAmmos[] = { "MeleeChimera","MeleeChimeraShock" };
		injuryLevels[] = { 1.0,0.5,0.2,0.0 };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 3000;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
				class Blood
				{
					hitpoints = 5000;
				};
				class Shock
				{
					hitpoints = 5000;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[] = { "Zone_Head" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.1;
					canBleed = 0;
					class Health
					{
						hitpoints = 940;
						transferToGlobalCoef = 1;
					};
					class Blood : Health
					{
						hitpoints = 5000;
					};
					class Shock : Health
					{
						hitpoints = 5000;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.51;
							};
						};
						class Projectile : Melee
						{
							class Health : Health
							{
								damage = 0.25;
							};
						};
						class FragGrenade : Melee {};
					};
				};
				class Zone_Neck : Zone_Head
				{
					componentNames[] = { "Zone_Neck" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.1;
					class Health
					{
						hitpoints = 1125;
						transferToGlobalCoef = 1;
					};
					class ArmorType : ArmorType
					{
						class Melee : Melee
						{
							class Health : Health
							{
								damage = 0.15;
							};
						};
						class Projectile : Projectile
						{
							class Health : Health
							{
								damage = 0.25;
							};
						};
					};
				};
				class Zone_Belly : Zone_Head
				{
					componentNames[] = { "Zone_Belly" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health : Health
					{
						hitpoints = 1500;
					};
					class ArmorType : ArmorType
					{
						class Melee : Melee
						{
							class Health : Health
							{
								damage = 0.15;
							};
						};
					};
				};
				class Zone_Pelvis : Zone_Head
				{
					componentNames[] = { "Zone_Pelvis" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health : Health
					{
						hitpoints = 1875;
					};
					class ArmorType : ArmorType
					{
						class Melee : Melee
						{
							class Health : Health
							{
								damage = 0.15;
							};
						};
					};
				};
				class Zone_Legs : Zone_Head
				{
					componentNames[] = { "Zone_Legs" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health : Health
					{
						hitpoints = 750;
						transferToGlobalCoef = 0.0;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedHead
			{
				item = "X18_Loot_Mutant_Animal_Chimera_Head";
				count = 1;
			};
			class ObtainedClaw
			{
				item = "X18_Loot_Mutant_Animal_Chimera_Claw";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Animal_Chimera_SteakMeat";
				count = 6;
				quantityMinMaxCoef[] = { 0.2,1 };
			};
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 8;
				};
				class Bodyfall
				{
					soundLookupTable = "PawBigBodyfall_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 11;
				};
				class Settle
				{
					soundLookupTable = "PawBigSettle_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 12;
				};
				class Rest2standA
				{
					soundLookupTable = "PawBigRest2standA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 13;
				};
				class Rest2standB
				{
					soundLookupTable = "PawBigRest2standB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 14;
				};
				class Stand2restA
				{
					soundLookupTable = "PawBigStand2restA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 15;
				};
				class Stand2restB
				{
					soundLookupTable = "PawBigStand2restB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 16;
				};
				class Stand2restC
				{
					soundLookupTable = "PawBigStand2restC_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 17;
				};
				class Jump
				{
					soundLookupTable = "PawBigJump_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 18;
				};
				class Impact
				{
					soundLookupTable = "PawBigImpact_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 19;
				};
			};
			class Sounds
			{
				class BearAttack
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 21;
				};
				class BearBreath
				{
					soundSet = "BearBreath_SoundSet";
					noise = "WolfRoarNoise";
					id = 1;
				};
				class BearGrowl
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 2;
				};
				class BearMumble
				{
					soundSet = "PGigantHurt_SoundSet";
					noise = "WolfRoarNoise";
					id = 3;
				};
				class BearRoar
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 4;
				};
				class BearRoarShort
				{
					soundSet = "ChimeraDeath_SoundSet";
					noise = "WolfRoarNoise";
					id = 12;
				};
				class BearSigh
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 5;
				};
				class BearSighLong
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 6;
				};
				class BearSighShort
				{
					soundSet = "ChimeraDeath_SoundSet";
					noise = "WolfRoarNoise";
					id = 7;
				};
				class BearSnarl
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 8;
				};
				class BearSnarlLong
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 9;
				};
				class BearSnort
				{
					soundSet = "ChimeraDeath_SoundSet";
					noise = "WolfRoarNoise";
					id = 10;
				};
				class BearGrowl_1
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 11;
				};
				class BearGrowl_3
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 13;
				};
				class BearGrowl_4
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 14;
				};
				class BearGrowl_5
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 15;
				};
				class BearGrowl_6
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 16;
				};
				class BearGrowl_7
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 17;
				};
				class BearGrowl_8
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 18;
				};
				class BearGrowl_9
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 19;
				};
				class BearGrowl_10
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 20;
				};
				class BearGrowl_12
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 22;
				};
				class BearGrowl_13
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 23;
				};
				class BearRoar_1
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 24;
				};
				class BearRoar_2
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 25;
				};
				class BearRoar_3
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 26;
				};
				class BearRoar_5
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 27;
				};
				class BearRoar_6
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 28;
				};
				class BearRoar_7
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 29;
				};
				class BearSighLong_0
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 30;
				};
				class BearSighLong_1
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 31;
				};
				class BearSighLong_2
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 32;
				};
				class BearSnarlLong_0
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 33;
				};
				class BearSnarlLong_1
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 34;
				};
				class BearSnarlLong_2
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 35;
				};
			};
			class Damages
			{
				class BearBiteDamage
				{
					damage = "ChimeraBiteDamage";
					id = 1;
				};
				class BearLeftPawDamage
				{
					damage = "ChimeraLeftPawDamage";
					id = 2;
				};
				class BearRightPawDamage
				{
					damage = "ChimeraRightPawDamage";
					id = 3;
				};
				class BearBiteDamageIntimidate
				{
					damage = "ChimeraBiteDamageIntimidate";
					id = 11;
				};
				class BearLeftPawDamageIntimidate
				{
					damage = "ChimeraLeftPawDamageIntimidate";
					id = 12;
				};
				class BearRightPawDamageIntimidate
				{
					damage = "ChimeraRightPawDamageIntimidate";
					id = 13;
				};
			};
		};
		class CommandMoveSettings
		{
			useSpeedMapping = 1;
			movementSpeedMapping[] = { 0,0.24,0.55,1.72,3.5,8 };
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout = 0.5;
			lookAtFilterSpeed = 1.57;
		};
	};
	class X18_Mutant_Animal_Chimera_Brown : Mutant_AoD_Himera2
	{
		scope = 2;
		displayName = "$STR_AoD_Mutant_Himera_Name";
		aiAgentTemplate = "Predator_Chimera";
		DamageSphereAmmos[] = { "MeleeChimera" };
		injuryLevels[] = { 1.0,0.5,0.2,0.0 };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 3000;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
				class Blood
				{
					hitpoints = 5000;
				};
				class Shock
				{
					hitpoints = 5000;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[] = { "Zone_Head" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.1;
					canBleed = 0;
					class Health
					{
						hitpoints = 940;
						transferToGlobalCoef = 1;
					};
					class Blood : Health
					{
						hitpoints = 5000;
					};
					class Shock : Health
					{
						hitpoints = 5000;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.51;
							};
						};
						class Projectile : Melee
						{
							class Health : Health
							{
								damage = 0.25;
							};
						};
						class FragGrenade : Melee {};
					};
				};
				class Zone_Neck : Zone_Head
				{
					componentNames[] = { "Zone_Neck" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.1;
					class Health
					{
						hitpoints = 1125;
						transferToGlobalCoef = 1;
					};
					class ArmorType : ArmorType
					{
						class Melee : Melee
						{
							class Health : Health
							{
								damage = 0.15;
							};
						};
						class Projectile : Projectile
						{
							class Health : Health
							{
								damage = 0.25;
							};
						};
					};
				};
				class Zone_Belly : Zone_Head
				{
					componentNames[] = { "Zone_Belly" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health : Health
					{
						hitpoints = 1500;
					};
					class ArmorType : ArmorType
					{
						class Melee : Melee
						{
							class Health : Health
							{
								damage = 0.15;
							};
						};
					};
				};
				class Zone_Pelvis : Zone_Head
				{
					componentNames[] = { "Zone_Pelvis" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health : Health
					{
						hitpoints = 1875;
					};
					class ArmorType : ArmorType
					{
						class Melee : Melee
						{
							class Health : Health
							{
								damage = 0.15;
							};
						};
					};
				};
				class Zone_Legs : Zone_Head
				{
					componentNames[] = { "Zone_Legs" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health : Health
					{
						hitpoints = 750;
						transferToGlobalCoef = 0.0;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedHead
			{
				item = "X18_Loot_Mutant_Animal_Chimera_Head";
				count = 1;
			};
			class ObtainedClaw
			{
				item = "X18_Loot_Mutant_Animal_Chimera_Claw";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Animal_Chimera_SteakMeat";
				count = 6;
				quantityMinMaxCoef[] = { 0.2,1 };
			};
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 8;
				};
				class Bodyfall
				{
					soundLookupTable = "PawBigBodyfall_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 11;
				};
				class Settle
				{
					soundLookupTable = "PawBigSettle_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 12;
				};
				class Rest2standA
				{
					soundLookupTable = "PawBigRest2standA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 13;
				};
				class Rest2standB
				{
					soundLookupTable = "PawBigRest2standB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 14;
				};
				class Stand2restA
				{
					soundLookupTable = "PawBigStand2restA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 15;
				};
				class Stand2restB
				{
					soundLookupTable = "PawBigStand2restB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 16;
				};
				class Stand2restC
				{
					soundLookupTable = "PawBigStand2restC_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 17;
				};
				class Jump
				{
					soundLookupTable = "PawBigJump_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 18;
				};
				class Impact
				{
					soundLookupTable = "PawBigImpact_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 19;
				};
			};
			class Sounds
			{
				class BearAttack
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 21;
				};
				class BearBreath
				{
					soundSet = "BearBreath_SoundSet";
					noise = "WolfRoarNoise";
					id = 1;
				};
				class BearGrowl
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 2;
				};
				class BearMumble
				{
					soundSet = "PGigantHurt_SoundSet";
					noise = "WolfRoarNoise";
					id = 3;
				};
				class BearRoar
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 4;
				};
				class BearRoarShort
				{
					soundSet = "ChimeraDeath_SoundSet";
					noise = "WolfRoarNoise";
					id = 12;
				};
				class BearSigh
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 5;
				};
				class BearSighLong
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 6;
				};
				class BearSighShort
				{
					soundSet = "ChimeraDeath_SoundSet";
					noise = "WolfRoarNoise";
					id = 7;
				};
				class BearSnarl
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 8;
				};
				class BearSnarlLong
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 9;
				};
				class BearSnort
				{
					soundSet = "ChimeraDeath_SoundSet";
					noise = "WolfRoarNoise";
					id = 10;
				};
				class BearGrowl_1
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 11;
				};
				class BearGrowl_3
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 13;
				};
				class BearGrowl_4
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 14;
				};
				class BearGrowl_5
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 15;
				};
				class BearGrowl_6
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 16;
				};
				class BearGrowl_7
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 17;
				};
				class BearGrowl_8
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 18;
				};
				class BearGrowl_9
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 19;
				};
				class BearGrowl_10
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 20;
				};
				class BearGrowl_12
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 22;
				};
				class BearGrowl_13
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 23;
				};
				class BearRoar_1
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 24;
				};
				class BearRoar_2
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 25;
				};
				class BearRoar_3
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 26;
				};
				class BearRoar_5
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 27;
				};
				class BearRoar_6
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 28;
				};
				class BearRoar_7
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 29;
				};
				class BearSighLong_0
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 30;
				};
				class BearSighLong_1
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 31;
				};
				class BearSighLong_2
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 32;
				};
				class BearSnarlLong_0
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 33;
				};
				class BearSnarlLong_1
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 34;
				};
				class BearSnarlLong_2
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 35;
				};
			};
			class Damages
			{
				class BearBiteDamage
				{
					damage = "HimeraBiteDamage";
					id = 1;
				};
				class BearLeftPawDamage
				{
					damage = "HimeraLeftPawDamage";
					id = 2;
				};
				class BearRightPawDamage
				{
					damage = "HimeraRightPawDamage";
					id = 3;
				};
				class BearBiteDamageIntimidate
				{
					damage = "HimeraBiteDamageIntimidate";
					id = 11;
				};
				class BearLeftPawDamageIntimidate
				{
					damage = "HimeraLeftPawDamageIntimidate";
					id = 12;
				};
				class BearRightPawDamageIntimidate
				{
					damage = "HimeraRightPawDamageIntimidate";
					id = 13;
				};
			};
		};
		class CommandMoveSettings
		{
			useSpeedMapping = 1;
			movementSpeedMapping[] = { 0,0.24,0.55,1.72,3.5,8 };
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout = 0.5;
			lookAtFilterSpeed = 1.57;
		};
	};
	class X18_Mutant_Animal_Chimera_Black : Mutant_AoD_Himera3
	{
		scope = 2;
		displayName = "$STR_AoD_Mutant_Himera_Name";
		aiAgentTemplate = "Predator_Chimera";
		DamageSphereAmmos[] = { "MeleeChimera" };
		injuryLevels[] = { 1.0,0.5,0.2,0.0 };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 3000;
					healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
				};
				class Blood
				{
					hitpoints = 5000;
				};
				class Shock
				{
					hitpoints = 5000;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[] = { "Zone_Head" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.1;
					canBleed = 0;
					class Health
					{
						hitpoints = 940;
						transferToGlobalCoef = 1;
					};
					class Blood : Health
					{
						hitpoints = 5000;
					};
					class Shock : Health
					{
						hitpoints = 5000;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.51;
							};
						};
						class Projectile : Melee
						{
							class Health : Health
							{
								damage = 0.25;
							};
						};
						class FragGrenade : Melee {};
					};
				};
				class Zone_Neck : Zone_Head
				{
					componentNames[] = { "Zone_Neck" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.1;
					class Health
					{
						hitpoints = 1125;
						transferToGlobalCoef = 1;
					};
					class ArmorType : ArmorType
					{
						class Melee : Melee
						{
							class Health : Health
							{
								damage = 0.15;
							};
						};
						class Projectile : Projectile
						{
							class Health : Health
							{
								damage = 0.25;
							};
						};
					};
				};
				class Zone_Belly : Zone_Head
				{
					componentNames[] = { "Zone_Belly" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health : Health
					{
						hitpoints = 1500;
					};
					class ArmorType : ArmorType
					{
						class Melee : Melee
						{
							class Health : Health
							{
								damage = 0.15;
							};
						};
					};
				};
				class Zone_Pelvis : Zone_Head
				{
					componentNames[] = { "Zone_Pelvis" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health : Health
					{
						hitpoints = 1875;
					};
					class ArmorType : ArmorType
					{
						class Melee : Melee
						{
							class Health : Health
							{
								damage = 0.15;
							};
						};
					};
				};
				class Zone_Legs : Zone_Head
				{
					componentNames[] = { "Zone_Legs" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health : Health
					{
						hitpoints = 750;
						transferToGlobalCoef = 0.0;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedHead
			{
				item = "X18_Loot_Mutant_Animal_Chimera_Head";
				count = 1;
			};
			class ObtainedClaw
			{
				item = "X18_Loot_Mutant_Animal_Chimera_Claw";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_Animal_Chimera_SteakMeat";
				count = 6;
				quantityMinMaxCoef[] = { 0.2,1 };
			};
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 8;
				};
				class Bodyfall
				{
					soundLookupTable = "PawBigBodyfall_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 11;
				};
				class Settle
				{
					soundLookupTable = "PawBigSettle_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 12;
				};
				class Rest2standA
				{
					soundLookupTable = "PawBigRest2standA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 13;
				};
				class Rest2standB
				{
					soundLookupTable = "PawBigRest2standB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 14;
				};
				class Stand2restA
				{
					soundLookupTable = "PawBigStand2restA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 15;
				};
				class Stand2restB
				{
					soundLookupTable = "PawBigStand2restB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 16;
				};
				class Stand2restC
				{
					soundLookupTable = "PawBigStand2restC_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 17;
				};
				class Jump
				{
					soundLookupTable = "PawBigJump_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 18;
				};
				class Impact
				{
					soundLookupTable = "PawBigImpact_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = { "WolfStepEffect1","WolfStepEffect2" };
					id = 19;
				};
			};
			class Sounds
			{
				class BearAttack
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 21;
				};
				class BearBreath
				{
					soundSet = "BearBreath_SoundSet";
					noise = "WolfRoarNoise";
					id = 1;
				};
				class BearGrowl
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 2;
				};
				class BearMumble
				{
					soundSet = "PGigantHurt_SoundSet";
					noise = "WolfRoarNoise";
					id = 3;
				};
				class BearRoar
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 4;
				};
				class BearRoarShort
				{
					soundSet = "ChimeraDeath_SoundSet";
					noise = "WolfRoarNoise";
					id = 12;
				};
				class BearSigh
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 5;
				};
				class BearSighLong
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 6;
				};
				class BearSighShort
				{
					soundSet = "ChimeraDeath_SoundSet";
					noise = "WolfRoarNoise";
					id = 7;
				};
				class BearSnarl
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 8;
				};
				class BearSnarlLong
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 9;
				};
				class BearSnort
				{
					soundSet = "ChimeraDeath_SoundSet";
					noise = "WolfRoarNoise";
					id = 10;
				};
				class BearGrowl_1
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 11;
				};
				class BearGrowl_3
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 13;
				};
				class BearGrowl_4
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 14;
				};
				class BearGrowl_5
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 15;
				};
				class BearGrowl_6
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 16;
				};
				class BearGrowl_7
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 17;
				};
				class BearGrowl_8
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 18;
				};
				class BearGrowl_9
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 19;
				};
				class BearGrowl_10
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 20;
				};
				class BearGrowl_12
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 22;
				};
				class BearGrowl_13
				{
					soundSet = "ChimeraIdle_SoundSet";
					noise = "WolfRoarNoise";
					id = 23;
				};
				class BearRoar_1
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 24;
				};
				class BearRoar_2
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 25;
				};
				class BearRoar_3
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 26;
				};
				class BearRoar_5
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 27;
				};
				class BearRoar_6
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 28;
				};
				class BearRoar_7
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 29;
				};
				class BearSighLong_0
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 30;
				};
				class BearSighLong_1
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 31;
				};
				class BearSighLong_2
				{
					soundSet = "ChimeraAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 32;
				};
				class BearSnarlLong_0
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 33;
				};
				class BearSnarlLong_1
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 34;
				};
				class BearSnarlLong_2
				{
					soundSet = "ChimeraAggressive_SoundSet";
					noise = "WolfRoarNoise";
					id = 35;
				};
			};
			class Damages
			{
				class BearBiteDamage
				{
					damage = "HimeraBiteDamage";
					id = 1;
				};
				class BearLeftPawDamage
				{
					damage = "HimeraLeftPawDamage";
					id = 2;
				};
				class BearRightPawDamage
				{
					damage = "HimeraRightPawDamage";
					id = 3;
				};
				class BearBiteDamageIntimidate
				{
					damage = "HimeraBiteDamageIntimidate";
					id = 11;
				};
				class BearLeftPawDamageIntimidate
				{
					damage = "HimeraLeftPawDamageIntimidate";
					id = 12;
				};
				class BearRightPawDamageIntimidate
				{
					damage = "HimeraRightPawDamageIntimidate";
					id = 13;
				};
			};
		};
		class CommandMoveSettings
		{
			useSpeedMapping = 1;
			movementSpeedMapping[] = { 0,0.24,0.55,1.72,3.5,8 };
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout = 0.5;
			lookAtFilterSpeed = 1.57;
		};
	};
	class Inventory_Base;
	class FS_HIMERA_HEAD : Inventory_Base {};
	class X18_Loot_Mutant_Animal_Chimera_Head : FS_HIMERA_HEAD
	{
		scope = 2;
		displayName = "$STR_Chimera_Head";
		descriptionShort = "$STR_DSC_Chimera_Head";
		weight = 4700;
		itemSize[] = { 4,5 };
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
	class Mutant_AoD_Himera_Kogot : Inventory_Base {};
	class X18_Loot_Mutant_Animal_Chimera_Claw : Mutant_AoD_Himera_Kogot
	{
		scope = 2;
		displayName = "$STR_AoD_Mutant_Himera_Kogot_Name";
		descriptionShort = "$STR_AoD_Mutant_Himera_Kogot_Decr";
		weight = 800;
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