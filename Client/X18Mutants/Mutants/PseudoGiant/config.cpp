class CfgPatches
{
	class X18Mutants_PseudoGigant
	{
		units[] = { "Mutant_AoD_PGigant" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "PseudoGiant_Scripts", "DZ_Gear_Food", "DZ_AoD_Mutant_Pgigant_Hand", "DZ_Characters_Zombies","DZ_Data","DZ_AI","DZ_Weapons_Melee","DZ_data_aiconfigs" };
		ammo[] = { "MeleePseudoGiant","PseudoGiant_SpecialAttack_Ammo" };
	};
};
class CfgAmmo
{
	class MeleeZombie;
	class DefaultAmmo;
	class MeleePseudoGiant : MeleeZombie
	{
		hitAnimation = 1;
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 1.0;
			class Health
			{
				damage = 40;
				armordamage = 1.0;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 30;
			};
		};
	};
	class PseudoGiant_SpecialAttack_Ammo : DefaultAmmo
	{
		indirectHit = 1;
		indirectHitRange = 26;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.05;
		soundSetExplosion[] = {};
		class DamageApplied
		{
			type = "FragGrenade";
			bleedThreshold = 0.4;
			class Health
			{
				damage = 7;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 6;
			};
		};
		class NoiseExplosion
		{
			strength = 0;
			type = "shot";
		};
	};
};
class CfgVehicles
{
	class PseudoGiant;
	class X18_Mutant_PseudoGiant : PseudoGiant
	{
		scope = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 8000;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[] = { "Zone_Head" };
					fatalInjuryCoef = 0.1;
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					canBleed = 0;
					class Health
					{
						hitpoints = 6000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1.0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.0;
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
				};
				class Zone_Torso : Zone_Head
				{
					componentNames[] = { "Zone_Torso" };
					fatalInjuryCoef = 0.01;
					class Health
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0.6;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1.0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.0;
							};
						};
					};
				};
				class Zone_Upperlimbs : Zone_Head
				{
					componentNames[] = { "Zone_Upperlimbs" };
					fatalInjuryCoef = 0.1;
					class Health
					{
						hitpoints = 4000;
						transferToGlobalCoef = 0.4;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1.0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.0;
							};
						};
					};
				};
				class Zone_Lowerlimbs : Zone_Head
				{
					componentNames[] = { "Zone_Lowerlimbs" };
					fatalInjuryCoef = 0.01;
					class Health
					{
						hitpoints = 4000;
						transferToGlobalCoef = 0.2;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1.0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.0;
							};
						};
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedHand
			{
				item = "X18_Loot_Mutant_PseudoGiant_Hand";
				count = 1;
			};
			class ObtainedPaw
			{
				item = "X18_Loot_Mutant_PseudoGiant_Paw";
				count = 1;
			};
			class ObtainedSteaks
			{
				item = "X18_Loot_Mutant_PseudoGiant_SteakMeat";
				count = 4;
				quantityMinMaxCoef[] = { 0.2,1 };
			};
		};
	};
	class Inventory_Base;
	class Mutant_AoD_Pgigant_Hand : Inventory_Base {};
	class X18_Loot_Mutant_PseudoGiant_Hand : Mutant_AoD_Pgigant_Hand
	{
		scope = 2;
		displayName = "$STR_AoD_Mutant_PGigant_Hand_Name";
		descriptionShort = "$STR_AoD_Mutant_PGigant_Hand_Decr";
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
	class SFP_Gigant_Otrezano_Lapa : Inventory_Base {};
	class X18_Loot_Mutant_PseudoGiant_Paw : SFP_Gigant_Otrezano_Lapa
	{
		scope = 2;
		displayName = "$STR_AoD_Mutant_PGigant_Hand_Name";
		descriptionShort = "$STR_AoD_Mutant_PGigant_Hand_Decr";
		weight = 3500;
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
};