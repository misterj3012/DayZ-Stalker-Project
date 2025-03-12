class CfgPatches
{
	class X18Items_Tags
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Characters_Tops" };
	};
};
class CfgVehicles
{
	class Armband_ColorBase;
	class X18_Tag_Base : Armband_ColorBase
	{
		scope = 0;
		descriptionShort = "$STR_DSC_Tag";
		model = "Noosphere\X18Items\Gear\Tags\Tag_G.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot = "Armband";
		itemInfo[] = { "Clothing","Hips" };
		itemsCargoSize[] = { 1,2 };
		itemSize[] = { 1,1 };
		weight = 200;
		lootCategory = "Crafted";
		lootTag[] = { "Civilian" };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsMaterials[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag.rvmat" };
		class Cargo
		{
			itemsCargoSize[] = { 1,2 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1,{"DZ\characters\belts\data\belt_leather_beige.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\belts\data\belt_leather_beige_damage.rvmat"}},{0.3,{}},{0,{"DZ\characters\belts\data\belt_leather_beige_destruct.rvmat"}} };
				};
			};
		};
		class ClothingTypes
		{
			male = "Noosphere\X18Items\Gear\Tags\Tag_M.p3d";
			female = "Noosphere\X18Items\Gear\Tags\Tag_F.p3d";
		};
	};
	class X18_Tag_Bandits_1 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Bandits";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Bandit_1.paa" };
	};
	class X18_Tag_Bandits_2 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Bandits";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Bandit_2.paa" };
	};
	class X18_Tag_Bandits_3 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Bandits";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Bandit_3.paa" };
	};
	class X18_Tag_Bandits_4 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Bandits";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Bandit_4.paa" };
	};
	class X18_Tag_ClearSky_1 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_ClearSky";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_CS_Contractor.paa" };
	};
	class X18_Tag_ClearSky_2 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_ClearSky";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_CS_Medic.paa" };
	};
	class X18_Tag_ClearSky_3 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_ClearSky";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_CS_Specialist.paa" };
	};
	class X18_Tag_ClearSky_4 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_ClearSky";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_CS_Teamleader.paa" };
	};
	class X18_Tag_ClearSky_5 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_ClearSky";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_CS_Supervisor.paa" };
	};
	class X18_Tag_Duty_1 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Private.paa" };
	};
	class X18_Tag_Duty_2 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Private_First_Class.paa" };
	};
	class X18_Tag_Duty_3 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Lance_Corporal.paa" };
	};
	class X18_Tag_Duty_4 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Corporal.paa" };
	};
	class X18_Tag_Duty_5 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Junior_Sergeant.paa" };
	};
	class X18_Tag_Duty_6 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Sergeant.paa" };
	};
	class X18_Tag_Duty_7 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Senior_Sergeant.paa" };
	};
	class X18_Tag_Duty_8 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Master_Sergeant.paa" };
	};
	class X18_Tag_Duty_9 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Junior_Lieutenant.paa" };
	};
	class X18_Tag_Duty_10 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Lieutenant.paa" };
	};
	class X18_Tag_Duty_11 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Senior_Lieutenant.paa" };
	};
	class X18_Tag_Duty_12 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Captain.paa" };
	};
	class X18_Tag_Duty_13 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Major.paa" };
	};
	class X18_Tag_Duty_14 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Lieutenant_Colonel.paa" };
	};
	class X18_Tag_Duty_15 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Colonel.paa" };
	};
	class X18_Tag_Duty_16 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_Major.paa" };
	};
	class X18_Tag_Duty_17 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Duty_General.paa" };
	};
	class X18_Tag_Ecologists_1 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Duty";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Eco.paa" };
	};
	class X18_Tag_Freedom_1 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Freedom";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Freedom_Apprentice.paa" };
	};
	class X18_Tag_Freedom_2 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Freedom";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Freedom_Specialist.paa" };
	};
	class X18_Tag_Freedom_3 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Freedom";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Freedom_Guardian.paa" };
	};
	class X18_Tag_Freedom_4 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Freedom";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Freedom_Medic.paa" };
	};
	class X18_Tag_Freedom_5 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Freedom";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Freedom_Wardog.paa" };
	};
	class X18_Tag_Freedom_6 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Freedom";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Freedom_ACE.paa" };
	};
	class X18_Tag_Freedom_7 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Freedom";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Freedom_Spade.paa" };
	};
	class X18_Tag_ISG_1 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_ISG";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_ISG_1.paa" };
	};
	class X18_Tag_Loner_1 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Loner";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Loner_1.paa" };
	};
	class X18_Tag_Loner_2 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Loner";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Loner_2.paa" };
	};
	class X18_Tag_Loner_3 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Loner";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Loner_3.paa" };
	};
	class X18_Tag_Mercenary_AUS : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Mercenary";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Mercenary_AUS.paa" };
	};
	class X18_Tag_Mercenary_ENG : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Mercenary";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Mercenary_ENG.paa" };
	};
	class X18_Tag_Mercenary_GER : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Mercenary";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Mercenary_GER.paa" };
	};
	class X18_Tag_Mercenary_GRE : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Mercenary";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Mercenary_GRE.paa" };
	};
	class X18_Tag_Mercenary_RUS : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Mercenary";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Mercenary_RUS.paa" };
	};
	class X18_Tag_Mercenary_USA : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Mercenary";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Mercenary_USA.paa" };
	};
	class X18_Tag_Mercenary_Lead : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Mercenary";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Mercenary_Lead.paa" };
	};
	class X18_Tag_Military_1 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Soldier.paa" };
	};
	class X18_Tag_Military_2 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Senior_Soldier.paa" };
	};
	class X18_Tag_Military_3 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Medic.paa" };
	};
	class X18_Tag_Military_4 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Junior_Sergeant.paa" };
	};
	class X18_Tag_Military_5 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Sergeant.paa" };
	};
	class X18_Tag_Military_6 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Senior_Sergeant.paa" };
	};
	class X18_Tag_Military_7 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Staff_Sergeant.paa" };
	};
	class X18_Tag_Military_8 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Master_Sergeant.paa" };
	};
	class X18_Tag_Military_9 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Senior_Master_Sergeant.paa" };
	};
	class X18_Tag_Military_10 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Junior_Lieutenant.paa" };
	};
	class X18_Tag_Military_11 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Lieutenant.paa" };
	};
	class X18_Tag_Military_12 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Senior_Lieutenant.paa" };
	};
	class X18_Tag_Military_13 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Captain.paa" };
	};
	class X18_Tag_Military_14 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Military";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Military_Major.paa" };
	};
	class X18_Tag_Monolith_1 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Monolith";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Monolith.paa" };
	};
	class X18_Tag_Monolith_2 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Monolith";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Monolith_Preacher.paa" };
	};
	class X18_Tag_Sin_1 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Monolith";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Sin_1.paa" };
	};
	class X18_Tag_Wolf_1 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Wolf";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Wolf_1.paa" };
	};
	class X18_Tag_Wolf_2 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Wolf";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Wolf_2.paa" };
	};
	class X18_Tag_Wolf_3 : X18_Tag_Base
	{
		scope = 2;
		displayName = "$STR_Tag_Wolf";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tags\Data\Tag_Wolf_3.paa" };
	};
};