class CfgPatches
{
	class X18Stashes
	{
		units[] = { "TentMedium_Packed","TentMedium_Pitched" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "aod_structures_f" };
	};
};
class CfgMods
{
	class X18Stashes
	{
		dir = "X18Stashes";
		name = "X18Stashes";
		author = "MisterJ";
		version = "1.0";
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Stashes/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Stashes/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Stashes/Scripts/5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class ItemBase;
	class X18_StashesBase : ItemBase
	{
		scope = 0;
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		quantityBar = 1;
		carveNavmesh = 1;
		bounding = "BSphere";
		overrideDrawArea = "4.0";
		visibilityModifier = 0.95;
		canBeDigged = 0;
		alignHologramToTerain = 1;
		heavyItem = 1;
		weight = 10;
		itemSize[] = { 10,10 };
		itemBehaviour = 1;
		physLayer = "item_large";
		simulation = "inventoryItem";
		hiddenSelections[] = { "all" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class X18_Stashes_Box_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\box_black.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Box_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\woodenbox_big.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Box_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\box_blue.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Box_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\box_green.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Box_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\woodencrate_green.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,8 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Backpack_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\backpack_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Backpack_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\backpack_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Backpack_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\backpack_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Backpack_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\backpack_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Backpack_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\backpack_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_ElectricalBox_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_01.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_ElectricalBox_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_02.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_ElectricalBox_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_03.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_ElectricalBox_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_04.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_ElectricalBox_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_05.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_ElectricalBox_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_06.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_ElectricalBox_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_07.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_ElectricalBox_8 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_08.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_ElectricalBox_9 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\NH_ChernobylZoneFurniture\prop_electricalunit3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Stump_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\treestump.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Stump_2 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_fagussylvatica_stump.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Stump_3 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_fagussylvatica_stumpb.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Stump_4 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_fagussylvatica_stumpc.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Stump_5 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_pinussylvestris_stump.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Stump_6 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_pinussylvestris_stumpb.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Stump_7 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_quercusrobur_stump.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Stump_8 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_quercusrobur_stumpb.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Stump_9 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_piceaabies_stump.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Stump_10 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants_bliss\tree\d_piceaabies_stumpc.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Safe : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\safe.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Safe_Flattened : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\safe_flattened.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Pipe : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\pipe.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_GraveCross_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\cross.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_GraveCross_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\cross_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Military_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Military_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Military_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Military_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Military_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Military_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_6.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Military_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_7.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_6.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_7.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_Barricade_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_Barricade_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_Barricade_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_Barricade_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_Barricade_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_Barricade_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_6.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Monolit_Barricade_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_7.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Neutral_Barricade_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Neutral_Barricade_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Neutral_Barricade_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Neutral_Barricade_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Neutral_Barricade_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Neutral_Barricade_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_6.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Neutral_Barricade_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_7.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Spetsnaz_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Spetsnaz_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Spetsnaz_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Spetsnaz_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Spetsnaz_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Spetsnaz_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_6.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Spetsnaz_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_7.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_Stashes_Corpse_Spetsnaz_8 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_8.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Box_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\box_black.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Box_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\woodenbox_big.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Box_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\box_blue.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Box_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\box_green.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Box_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\woodencrate_green.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,8 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Backpack_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\backpack_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Backpack_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\backpack_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Backpack_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\backpack_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Backpack_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\backpack_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Backpack_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\backpack_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_ElectricalBox_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_01.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_ElectricalBox_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_02.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_ElectricalBox_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_03.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_ElectricalBox_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_04.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_ElectricalBox_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_05.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_ElectricalBox_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_06.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_ElectricalBox_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_07.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_ElectricalBox_8 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Electricians\el_box_08.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_ElectricalBox_9 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "\NH_ChernobylZoneFurniture\prop_electricalunit3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Stump_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\treestump.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Stump_2 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_fagussylvatica_stump.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Stump_3 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_fagussylvatica_stumpb.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Stump_4 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_fagussylvatica_stumpc.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Stump_5 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_pinussylvestris_stump.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Stump_6 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_pinussylvestris_stumpb.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Stump_7 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_quercusrobur_stump.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Stump_8 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_quercusrobur_stumpb.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Stump_9 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants\tree\d_piceaabies_stump.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Stump_10 : X18_StashesBase
	{
		scope = 2;
		model = "\DZ\plants_bliss\tree\d_piceaabies_stumpc.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Safe : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\safe.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Safe_Flattened : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\safe_flattened.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Pipe : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\pipe.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_GraveCross_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\cross.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_GraveCross_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\cross_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Military_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Military_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Military_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Military_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Military_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Military_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_6.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Military_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_military_7.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_6.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_7.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_Barricade_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_Barricade_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_Barricade_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_Barricade_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_Barricade_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_Barricade_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_6.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Monolit_Barricade_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_monolit_barikada_7.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Neutral_Barricade_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Neutral_Barricade_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Neutral_Barricade_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Neutral_Barricade_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Neutral_Barricade_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Neutral_Barricade_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_6.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Neutral_Barricade_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_neutral_baric_7.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Spetsnaz_1 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_1.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Spetsnaz_2 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_2.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Spetsnaz_3 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_3.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Spetsnaz_4 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_4.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Spetsnaz_5 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_5.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Spetsnaz_6 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_6.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Spetsnaz_7 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_7.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class X18_HighRisk_Loot_Corpse_Spetsnaz_8 : X18_StashesBase
	{
		scope = 2;
		displayName = "";
		model = "Noosphere\X18Stashes\Models\dead_spetsnaz_8.p3d";
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
};