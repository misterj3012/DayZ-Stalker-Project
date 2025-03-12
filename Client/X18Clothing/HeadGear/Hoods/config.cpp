class CfgPatches
{
	class DZ_Characters_Headgear
	{
		units[] = { "BaseballCap_Blue","BaseballCap_Beige","BaseballCap_Black","BaseballCap_Olive","BaseballCap_Pink","BaseballCap_Red","BaseballCap_Camo","BaseballCap_CMMG_Black","BaseballCap_CMMG_Pink","MotoHelmet_Black","MotoHelmet_Blue","MotoHelmet_Green","MotoHelmet_Red","MotoHelmet_White","Headtorch_Grey","CowboyHat_Brown","CowboyHat_black","CowboyHat_darkBrown","CowboyHat_green","BoonieHat_black","BoonieHat_Blue","BoonieHat_DPM","BoonieHat_dubok","BoonieHat_flecktran","BoonieHat_NavyBlue","BoonieHat_olive","BoonieHat_orange","BoonieHat_red","BoonieHat_Tan","FlatCap_Black","FlatCap_Grey","FlatCap_Brown","FlatCap_Blue","FlatCap_Red","FlatCap_Check_Black","FlatCap_Check_Brown","FlatCap_Check_Grey","GhillieHoodWoodland" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Characters" };
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class NBCHoodGray;
	class X18_Hood_Base : NBCHoodGray
	{
		scope = 0;
		displayName = "$STR_Hood";
		descriptionShort = "$STR_DSC_Hood";
		model = "\Noosphere\X18Clothing\HeadGear\Hoods\Model\Hood_g.p3d";
		hiddenSelections[] = { "camoGround","camoMale","camoFemale" };
		class ClothingTypes
		{
			male = "\Noosphere\X18Clothing\HeadGear\Hoods\Model\Hood.p3d";
			female = "\Noosphere\X18Clothing\HeadGear\Hoods\Model\Hood.p3d";
		};
		class Protection
		{
			biological = 0;
			chemical = 0;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_Hood_Bandit : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_bandit.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_bandit.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_bandit.paa" };
	};
	class X18_Hood_ClearSky : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_chn1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_chn1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_chn1.paa" };
	};
	class X18_Hood_ClearSky_2 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_chn2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_chn2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_chn2.paa" };
	};
	class X18_Hood_ClearSky_3 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap8.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap8.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap8.paa" };
	};
	class X18_Hood_ClearSky_4 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_clearsky.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_clearsky.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_clearsky.paa" };
	};
	class X18_Hood_ClearSky_5 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_ChistoeNebo.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_ChistoeNebo.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_ChistoeNebo.paa" };
	};
	class X18_Hood_Duty : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\dolg.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\dolg.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\dolg.paa" };
	};
	class X18_Hood_Duty_2 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_dolg.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_dolg.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_dolg.paa" };
	};
	class X18_Hood_Ecologist_1 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_uchen_1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_uchen_1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_uchen_1.paa" };
	};
	class X18_Hood_Ecologist_2 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_uchen_2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_uchen_2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_uchen_2.paa" };
	};
	class X18_Hood_Freedom : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_svoboda_2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_svoboda_2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_svoboda_2.paa" };
	};
	class X18_Hood_Freedom_2 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_svoboda1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_svoboda1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_svoboda1.paa" };
	};
	class X18_Hood_Freedom_3 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_svoboda.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_svoboda.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_svoboda.paa" };
	};
	class X18_Hood_Loner_1 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap1.paa" };
	};
	class X18_Hood_Loner_2 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap2.paa" };
	};
	class X18_Hood_Loner_3 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap3.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap3.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap3.paa" };
	};
	class X18_Hood_Loner_4 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap4.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap4.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap4.paa" };
	};
	class X18_Hood_Loner_5 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap5.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap5.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap5.paa" };
	};
	class X18_Hood_Loner_6 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6.paa" };
	};
	class X18_Hood_Loner_7 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap7.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap7.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap7.paa" };
	};
	class X18_Hood_Loner_8 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap9.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap9.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap9.paa" };
	};
	class X18_Hood_Loner_9 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap10.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap10.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap10.paa" };
	};
	class X18_Hood_Loner_10 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap11.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap11.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap11.paa" };
	};
	class X18_Hood_Loner_11 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap12.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap12.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap12.paa" };
	};
	class X18_Hood_Loner_12 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\neutral.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\neutral.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\neutral.paa" };
	};
	class X18_Hood_Loner_13 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker5.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker5.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker5.paa" };
	};
	class X18_Hood_Loner_14 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker4.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker4.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker4.paa" };
	};
	class X18_Hood_Loner_15 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker2.paa" };
	};
	class X18_Hood_Loner_16 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker3.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker3.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker3.paa" };
	};
	class X18_Hood_Loner_17 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_stalker1.paa" };
	};
	class X18_Hood_Loner_18 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\HoodSonen.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\HoodSonen.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\HoodSonen.paa" };
	};
	class X18_Hood_Loner_19 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_naym.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_naym.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\kapyushen_naym.paa" };
	};
	class X18_Hood_Loner_20 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_naim.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_naim.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_naim.paa" };
	};
	class X18_Hood_Loner_21 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_stalker_1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_stalker_1.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_stalker_1.paa" };
	};
	class X18_Hood_Loner_22 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_stalker_2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_stalker_2.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_stalker_2.paa" };
	};
	class X18_Hood_Loner_23 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_stalker_3.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_stalker_3.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_stalker_3.paa" };
	};
	class X18_Hood_Loner_24 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_Neitral.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_Neitral.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_Neitral.paa" };
	};
	class X18_Hood_Mercenary : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_merc.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_merc.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_merc.paa" };
	};
	class X18_Hood_Military : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_save.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_save.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\hooders_save.paa" };
	};
	class X18_Hood_Military_2 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_voen.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_voen.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_voen.paa" };
	};
	class X18_Hood_Monolith : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\monolit_kapyushen.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\monolit_kapyushen.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\monolit_kapyushen.paa" };
	};
	class X18_Hood_Monolith_2 : X18_Hood_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_monolit.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_monolit.paa","Noosphere\X18Clothing\HeadGear\Hoods\Data\Cap6_monolit.paa" };
	};
};