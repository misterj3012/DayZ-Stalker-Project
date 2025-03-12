class CfgPatches
{
	class DZ_Plants
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class ChristmasTree : HouseNoDestruct
	{
		model = "DZ\plants\tree\t_PiceaAbies_2s_xmas.p3d";
	};
	class ChristmasTree_Green : HouseNoDestruct
	{
		model = "DZ\plants\tree\t_PiceaAbies_2s_green_xmas.p3d";
	};
};
class CfgNonAIVehicles
{
	class BushSoft;
	class BushHard;
	class TreeSoft;
	class TreeHard;
	class BushSoft_b_betulaHumilis_1s : BushSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushSoft_b_corylusAvellana_1f : BushSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushSoft_b_crataegusLaevigata_1s : BushSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushSoft_b_PiceaAbies_1f : BushSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushSoft_b_quercusRobur_1f : BushSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "WoodenStick";
		secondaryOutput = "";
	};
	class BushSoft_b_rosaCanina_1s : BushSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushSoft_b_rosaCanina_2s : BushSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushSoft_b_sambucusNigra_1s : BushSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushSoft_t_PinusSylvestris_1s : BushSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushHard_b_BetulaPendula_1f : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushHard_b_corylusAvellana_2s : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushHard_b_crataegusLaevigata_2s : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushHard_b_FagusSylvatica_1f : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushHard_b_naked_2s : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushHard_b_PiceaAbies_1fb : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class BushHard_b_prunusSpinosa_1s : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "WoodenStick";
	};
	class BushHard_b_prunusSpinosa_2s : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class BushHard_b_sambucusNigra_2s : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class BushHard_t_FagusSylvatica_1fb : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "WoodenStick";
	};
	class BushHard_t_FraxinusExcelsior_2w : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "WoodenStick";
	};
	class BushHard_t_PiceaAbies_1s : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "";
	};
	class BushHard_t_PiceaAbies_1sb : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "";
	};
	class BushHard_t_PinusSylvestris_1f : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class BushHard_t_quercusRobur_1fb : BushHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "";
	};
	class TreeSoft_BetulaPendula_Base : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "WoodenStick";
		barkType = "Bark_Birch";
	};
	class TreeSoft_t_BetulaPendula_1f : TreeSoft_BetulaPendula_Base
	{
		isCuttable = 1;
		primaryDropsAmount = 6;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
		barkType = "Bark_Birch";
	};
	class TreeSoft_t_BetulaPendula_1fb : TreeSoft_BetulaPendula_Base
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
		barkType = "Bark_Birch";
	};
	class TreeSoft_t_BetulaPendula_1s : TreeSoft_BetulaPendula_Base
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
		barkType = "Bark_Birch";
	};
	class TreeSoft_t_BetulaPendula_2f : TreeSoft_BetulaPendula_Base
	{
		isCuttable = 1;
		primaryDropsAmount = 6;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
		barkType = "Bark_Birch";
	};
	class TreeSoft_t_BetulaPendula_2fb : TreeSoft_BetulaPendula_Base
	{
		isCuttable = 1;
		primaryDropsAmount = 6;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
		barkType = "Bark_Birch";
	};
	class TreeSoft_t_BetulaPendula_2fc : TreeSoft_BetulaPendula_Base
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
		barkType = "Bark_Birch";
	};
	class TreeSoft_t_BetulaPendula_2w : TreeSoft_BetulaPendula_Base
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
		barkType = "Bark_Birch";
	};
	class TreeSoft_t_FagusSylvatica_1f : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "LongWoodenStick";
		secondaryOutput = "WoodenStick";
	};
	class TreeSoft_t_FagusSylvatica_1fc : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_FagusSylvatica_1fd : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_FagusSylvatica_1s : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_FagusSylvatica_2sb : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_FagusSylvatica_2sb_Trail_B : TreeSoft_t_FagusSylvatica_2sb
	{
	};
	class TreeSoft_t_FagusSylvatica_2sb_Trail_G : TreeSoft_t_FagusSylvatica_2sb
	{
	};
	class TreeSoft_t_FagusSylvatica_2sb_Trail_R : TreeSoft_t_FagusSylvatica_2sb
	{
	};
	class TreeSoft_t_FagusSylvatica_2sb_Trail_Y : TreeSoft_t_FagusSylvatica_2sb
	{
	};
	class TreeSoft_t_FraxinusExcelsior_2w : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_malusDomestica_1s : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_malusDomestica_2s : TreeSoft_t_malusDomestica_1s
	{
	};
	class TreeSoft_t_malusDomestica_3s : TreeSoft_t_malusDomestica_1s
	{
	};
	class TreeSoft_t_PiceaAbies_1f : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 4;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_PiceaAbies_2sb : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 4;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_populusAlba_1f : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "";
	};
	class TreeSoft_t_pyrusCommunis_2s : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 4;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_quercusRobur_1f : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_quercusRobur_1fc : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_quercusRobur_1fd : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_quercusRobur_1s : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_quercusRobur_2fb : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 4;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_quercusRobur_2fc : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 4;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_robiniaPseudoacacia_1f : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_town_1s : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_town_1sb : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_LarixDecidua_1f : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeSoft_t_LarixDecidua_1s : TreeSoft
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeHard_BetulaPendula : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "WoodenStick";
		barkType = "Bark_Birch";
	};
	class TreeHard_t_BetulaPendula_2s : TreeHard_BetulaPendula
	{
		isCuttable = 1;
		primaryDropsAmount = 6;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
		barkType = "Bark_Birch";
	};
	class TreeHard_t_BetulaPendula_3f : TreeHard_BetulaPendula
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
		barkType = "Bark_Birch";
	};
	class TreeHard_t_BetulaPendula_3fb : TreeHard_BetulaPendula
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
		barkType = "Bark_Birch";
	};
	class TreeHard_t_BetulaPendula_3fc : TreeHard_BetulaPendula
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
		barkType = "Bark_Birch";
	};
	class TreeHard_t_BetulaPendula_3s : TreeHard_BetulaPendula
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
		barkType = "Bark_Birch";
	};
	class TreeHard_t_FagusSylvatica_1fe : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_FagusSylvatica_2d : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_FagusSylvatica_2f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeHard_t_FagusSylvatica_2fb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeHard_t_FagusSylvatica_2fc : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 2;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeHard_t_FagusSylvatica_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_FagusSylvatica_3d : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 4;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_FagusSylvatica_3f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_FagusSylvatica_3fb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_FagusSylvatica_3s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_FraxinusExcelsior_2f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_FraxinusExcelsior_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_FraxinusExcelsior_3s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_juglansRegia_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_juglansRegia_3s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_LarixDecidua_2f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 4;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_LarixDecidua_2fb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 4;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_LarixDecidua_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_LarixDecidua_3f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 4;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_LarixDecidua_3fb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_naked_1s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_naked_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 4;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_piceaabies_2d : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 6;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PiceaAbies_2f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PiceaAbies_2fb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PiceaAbies_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 4;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_piceaabies_3d : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 6;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PiceaAbies_3f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 0;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "";
	};
	class TreeHard_t_PiceaAbies_3f_Trail_B : TreeHard_t_PiceaAbies_3f
	{
	};
	class TreeHard_t_PiceaAbies_3f_Trail_G : TreeHard_t_PiceaAbies_3f
	{
	};
	class TreeHard_t_PiceaAbies_3f_Trail_R : TreeHard_t_PiceaAbies_3f
	{
	};
	class TreeHard_t_PiceaAbies_3f_Trail_Y : TreeHard_t_PiceaAbies_3f
	{
	};
	class TreeHard_t_PiceaAbies_3s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 4;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeHard_t_PinusSylvestris_2f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PinusSylvestris_2fb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PinusSylvestris_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PinusSylvestris_2sb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PinusSylvestris_3d : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 6;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PinusSylvestris_3f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PinusSylvestris_3fb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PinusSylvestris_3fc : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_PinusSylvestris_3s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_populusAlba_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_populusAlba_3s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 5;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_populusNigra_3s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 3;
		secondaryDropsAmount = 4;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_prunusDomestica_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeHard_t_pyrusCommunis_3s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeHard_t_pyrusCommunis_3sb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 1;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeHard_t_quercusRobur_2d : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 6;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_quercusRobur_2f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_quercusRobur_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_quercusRobur_2sb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_quercusRobur_2sc : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_quercusRobur_3d : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 8;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_quercusRobur_3f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 2;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_quercusRobur_3fb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 4;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_quercusRobur_3s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 4;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_quercusRobur_3sb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 4;
		secondaryDropsAmount = 6;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_robiniaPseudoacacia_2f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 4;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_robiniaPseudoacacia_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_robiniaPseudoacacia_3f : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_salixAlba_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 2;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
	class TreeHard_t_salixAlba_2sb : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 6;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeHard_t_salixAlba_2sb_swamp : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 6;
		secondaryDropsAmount = 3;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "FireWood";
		secondaryOutput = "LongWoodenStick";
	};
	class TreeHard_t_sorbus_2s : TreeHard
	{
		isCuttable = 1;
		primaryDropsAmount = 1;
		secondaryDropsAmount = 4;
		toolDamage = 4;
		cycleTimeOverride = 3;
		primaryOutput = "WoodenLog";
		secondaryOutput = "FireWood";
	};
};

class CfgEnvSounds
{
	class CfgEnvSpatialSounds
	{
		class Sound_Reed
		{
			memPoint = "Sound_Reed";
			soundSets[] =
			{
				"ReedDay_SoundSet",
				"ReedNight_SoundSet",
				"WindBush_SoundSet"
			};
		};
	};
};

class CfgSoundSets
{
	class ReedDay_SoundSet
	{
		soundShaders[] =
		{
			"ReedDay_SoundShader"
		};
		volumeFactor = "0.075 * 2.4";     //"0.075 * 1.6";
		volumeRandomizer = 8;
		frequencyFactor = 1;
		frequencyRandomizer = 4;
		spatial = 1;
		doppler = 0;
		loop = 1;
		volumeCurve[] =
		{
			{0,0.5},
			{3,0.5},
			{4,0.25},
			{5,0.111},
			{6,0.063000001},
			{7,0.028000001},
			{8,0.02},
			{9,0.016000001},
			{10,0.012},
			{11,0.0099999998},
			{12,0}
		};
		sound3DProcessingType = "Insect3DProcessingType";
	};

	class ReedNight_SoundSet
	{
		soundShaders[] =
		{
			"ReedNight_SoundShader"
		};
		volumeFactor = "0.075 * 2.6";
		volumeRandomizer = 8;
		frequencyFactor = 1;
		frequencyRandomizer = 4;
		spatial = 1;
		doppler = 0;
		loop = 1;
		volumeCurve = "insectsVolumeCurve";
		sound3DProcessingType = "Insect3DProcessingType";
	};
};

class CfgSoundShaders
{
	class ReedDay_SoundShader
	{
		samples[] =
		{

			{
				"DZ\plants\clutter\data\frogs_1",
				0.33
			},

			{
				"DZ\plants\clutter\data\frogs_2",
				0.33
			},

			{
				"DZ\plants\clutter\data\frogs_3",
				0.33
			}
		};
		volume = "(1-night) * (rain factor [0.4, 0.1]) * (windy factor[0.9,0]) * ((overcast factor[0.8,0.6]) min (fog factor[0.9,0.4])) * (shooting factor [0.6,1]) * (randomPos factor[0.5, 0.51])";
		range = 40;
	};

	class ReedNight_SoundShader
	{
		samples[] =
		{

			{
				"DZ\plants\clutter\data\frogs_choir_1",
				0.33
			},

			{
				"DZ\plants\clutter\data\frogs_choir_2",
				0.33
			},

			{
				"DZ\plants\clutter\data\frogs_choir_3",
				0.33
			}

		};
		volume = "night * (rain factor [0.4, 0.1]) * (windy factor[0.9,0]) * ((overcast factor[0.8,0.6]) min (fog factor[0.9,0.4])) * (shooting factor [0.6,1]) * (randomPos factor[0.5, 0.51])";
		range = 40;
	};
};