class CfgPatches
{
	class DZ_Weapons_Melee
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Weapons_Projectiles","DZ_Weapons_Firearms" };
	};
};
class CfgAmmo
{
	class MeleeWolf;
	class MeleeBlindDog : MeleeWolf
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.80;
			class Health
			{
				damage = 16;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 12;
			};
		};
	};
	class MeleeBlindDog_Heavy : MeleeBlindDog {};
	class MeleeBoar : MeleeWolf
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.80;
			class Health
			{
				damage = 40;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 110;
			};
		};
	};
	class MeleeBoar_Heavy : MeleeBoar {};
	class MeleeCat : MeleeWolf
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.80;
			class Health
			{
				damage = 20;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 12;
			};
		};
	};
	class MeleeCat_Heavy : MeleeCat {};
	class MeleeDamage;
	class MeleeChimera : MeleeDamage
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.85;
			class Health
			{
				damage = 25;
			};
			class Blood
			{
				damage = 110;
			};
			class Shock
			{
				damage = 35;
			};
			additionAnimalMeleeMultiplier = 5;
		};
	};
	class MeleeChimera_Heavy : MeleeChimera {};
	class MeleeChimeraShock : MeleeDamage
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.85;
			class Health
			{
				damage = 25;
			};
			class Blood
			{
				damage = 350;
			};
			class Shock
			{
				damage = 110;
			};
			additionAnimalMeleeMultiplier = 5;
		};
	};
	class MeleeChimeraShock_Heavy : MeleeChimeraShock {};
	class MeleeFlesh : MeleeWolf
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.80;
			class Health
			{
				damage = 12;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 50;
			};
		};
	};
	class MeleeFlesh_Heavy : MeleeFlesh {};
	class MeleePseudoDog : MeleeWolf
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.80;
			class Health
			{
				damage = 18;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 14;
			};
		};
	};
	class MeleePseudoDog_Heavy : MeleePseudoDog {};
	class MeleePsyDog : MeleeWolf
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.80;
			class Health
			{
				damage = 20;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 17;
			};
		};
	};
	class MeleePsyDog_Heavy : MeleePsyDog {};
	class MeleePsyDogPhantom : MeleeWolf
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.0;
			class Health
			{
				damage = 0.1;
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
	class MeleePsyDogPhantom_Heavy : MeleePsyDogPhantom {};
	class MeleeRodent : MeleeWolf
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.75;
			class Health
			{
				damage = 1;
			};
			class Blood
			{
				damage = 25;
			};
			class Shock
			{
				damage = 1;
			};
		};
	};
	class MeleeRodent_Heavy : MeleeRodent {};
	class MeleeSnorkWolf : MeleeWolf
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.80;
			class Health
			{
				damage = 20;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 12;
			};
		};
	};
	class MeleeSnorkWolf_Heavy : MeleeSnorkWolf {};
};