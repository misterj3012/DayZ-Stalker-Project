class CfgPatches
{
	class X18Objects_HumanZombie
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data" };
	};
};
class cfgWeapons
{
	class RifleCore;
	class Rifle_Base : RifleCore
	{
		inventorySlot[] = { "Shoulder","Melee","Shoulder1","Shoulder2","Shoulder3","Shoulder4","Shoulder5","Shoulder6","Shoulder7","Shoulder8","Shoulder9","Shoulder10","Shoulder11","Shoulder12","Shoulder13","Shoulder14","Shoulder15","Shoulder16","Shoulder17","Shoulder18","Shoulder19","Shoulder20","Shoulder21","Shoulder22","Shoulder23","Shoulder24","Shoulder25","Shoulder26","Shoulder27","Shoulder28","Shoulder29","Shoulder30" };
	};
};
class CfgSlots
{
	class Slot_Shoulder {};
	class Slot_Shoulder1 : Slot_Shoulder
	{
		name = "Shoulder1";
	};
};
class CfgVehicles
{
	class DZ_LightAI;
	class DayZInfected : DZ_LightAI {};
	class ZombieBase : DayZInfected
	{
		class Cargo
		{
			itemsCargoSize[] = { 10,5 };
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		attachments[] = { "Shoulder1","Melee","Vest","Body","Hips","Legs","Back","Headgear","Mask","Eyewear","Gloves","Feet","Armband" };
		class InventoryEquipment
		{
			playerSlots[] = { "Slot_Shoulder1","Slot_Melee","Slot_Vest","Slot_Body","Slot_Hips","Slot_Legs","Slot_Back","Slot_Headgear","Slot_Mask","Slot_Eyewear","Slot_Gloves","Slot_Feet","Slot_Armband" };
		};
	};
	class ZmbM_SoldierNormal_Base;
	class X18_HumanZombie : ZmbM_SoldierNormal_Base
	{
		scope = 2;
		model = "Noosphere\X18Objects\Data\HumanZombie\HumanZombie.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = { {1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}} };
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 200;
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
						hitpoints = 400;
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
					inventorySlotsCoefs[] = { 1,1,1 };
				};
				class LeftArm : Torso
				{
					componentNames[] = { "LeftArm","LeftForeArm" };
					inventorySlots[] = { "Vest","Body","Back" };
					inventorySlotsCoefs[] = { 1,1,1 };
					fatalInjuryCoef = -1;
				};
				class RightArm : LeftArm
				{
					componentNames[] = { "RightArm","RightForeArm" };
					inventorySlots[] = { "Vest","Body","Back" };
					inventorySlotsCoefs[] = { 1,1,1 };
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 400;
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
						hitpoints = 400;
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
	};
};