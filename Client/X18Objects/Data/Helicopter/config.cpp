class CfgPatches
{
	class X18Objects_Helicopter
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data" };
	};
};
class PreloadVehicles
{
	class X18_Mi24_NonInteractive
	{
		loadStyle = 2;
	};
};
class CfgVehicles
{
	class OffroadHatchback;
	class Inventory_Base;
	class X18_Mi24_NonInteractive : Inventory_Base
	{
		scope = 2;
		displayName = "Helicopter";
		descriptionShort = "Helicopter";
		model = "\Noosphere\X18Objects\Data\Helicopter\mi24.p3d";
		weight = 8500000;
		itemsCargoSize[] = { 10,100 };
		itemSize[] = { 10,10 };
		forceFarBubble = "true";
		wreck_object = "Wreck_Mi8_Crashed";
		storageCategory = 10;
		destrType = "DestructDefault";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = { {1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}} };
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.05;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.3;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 8;
					};
				};
			};
			class DamageZones
			{
				class Body
				{
					class Health
					{
						hitpoints = 600;
						transferToGlobalCoef = 0.5;
						healthLevels[] = { {1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}} };
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.05;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] = { "body" };
					fatalInjuryCoef = -1;
				};
			};
		};
	};
};