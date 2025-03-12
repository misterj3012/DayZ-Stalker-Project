class CfgPatches
{
	class DZ_Characters_Vests
	{
		units[] = { "TacticalVest","UKAssVest" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Characters" };
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class GorkaPants_Summer;
	class Clothing : Clothing_Base {};
	class X18_GorkaPants_ColorBase : GorkaPants_Summer
	{
		scope = 0;
		model = "\Noosphere\X18Clothing\Pants\Gorka\Model\GorkaPants_g.p3d";
		hiddenSelections[] = { "camo1","personality" };
		hiddenSelectionsTextures[] = {};
		class ClothingTypes
		{
			male = "\Noosphere\X18Clothing\Pants\Gorka\Model\GorkaPants.p3d";
			female = "\Noosphere\X18Clothing\Pants\Gorka\Model\GorkaPants.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
				};
			};
		};
	};
	class X18_GorkaPants_Bandit : X18_GorkaPants_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Clothing\Pants\Gorka\Data\Assault_Vest_bandit.paa" };
	};
	class X18_GorkaPants_ClearSky : X18_GorkaPants_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Clothing\Pants\Gorka\Data\Assault_Vest_clear.paa" };
	};
	class X18_GorkaPants_Duty : X18_GorkaPants_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Clothing\Pants\Gorka\Data\Assault_Vest_dolg.paa" };
	};
	class X18_GorkaPants_Freedom : X18_GorkaPants_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Clothing\Pants\Gorka\Data\Assault_Vest_free.paa" };
	};
	class X18_GorkaPants_Loner : X18_GorkaPants_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Clothing\Pants\Gorka\Data\Assault_Vest_stalker.paa" };
	};
	class X18_GorkaPants_Mercenary : X18_GorkaPants_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Clothing\Pants\Gorka\Data\Assault_Vest_merc.paa" };
	};
	class X18_GorkaPants_Military : X18_GorkaPants_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Clothing\Pants\Gorka\Data\Assault_Vest_mill.paa" };
	};
	class X18_GorkaPants_Monolith : X18_GorkaPants_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "\Noosphere\X18Clothing\Pants\Gorka\Data\Assault_Vest_monolit.paa" };
	};
};