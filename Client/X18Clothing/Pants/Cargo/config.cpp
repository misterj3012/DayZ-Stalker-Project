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
	class CargoPants_Beige;
	class Clothing : Clothing_Base {};
	class X18_CargoPants_Base : CargoPants_Beige
	{
		scope = 0;
		model = "\Noosphere\X18Clothing\Pants\Cargo\Model\Gorka_Pants_g.p3d";
		hiddenSelections[] = { "camo1","camo2" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\gorkapants.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
		class ClothingTypes
		{
			male = "\Noosphere\X18Clothing\Pants\Cargo\Model\Gorka_Pants.p3d";
			female = "\Noosphere\X18Clothing\Pants\Cargo\Model\Gorka_Pants.p3d";
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
	class X18_CargoPants_Bandit : X18_CargoPants_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\gorkapants_bratva.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
	};
	class X18_CargoPants_ClearSky : X18_CargoPants_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\gorkapants_clear.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
	};
	class X18_CargoPants_Duty : X18_CargoPants_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\gorkapants_dolg.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
	};
	class X18_CargoPants_Freedom : X18_CargoPants_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\gorkapants_free.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
	};
	class X18_CargoPants_Loner : X18_CargoPants_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\gorkapants_stalker.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
	};
	class X18_CargoPants_Loner_2 : X18_CargoPants_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\gorkapants_co.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
	};
	class X18_CargoPants_Loner_3 : X18_CargoPants_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\gorkapants_neutarl.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
	};
	class X18_CargoPants_Mercenary : X18_CargoPants_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\gorkapants_merc.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
	};
	class X18_CargoPants_Military : X18_CargoPants_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\gorkapants_voen.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
	};
	class X18_CargoPants_Military_2 : X18_CargoPants_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\kont.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
	};
	class X18_CargoPants_Monolith : X18_CargoPants_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Clothing\Pants\Cargo\Data\gorkapants_monolit.paa","Noosphere\X18Clothing\Pants\Cargo\Data\kneepads.paa" };
	};
};