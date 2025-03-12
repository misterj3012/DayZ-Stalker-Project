class CfgPatches
{
	class X18Anomalies
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18Anomalies
	{
		name = "X18Anomalies";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Anomalies/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Anomalies/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Anomalies/Scripts/5_Mission" };
			};
		};
	};
};
class CfgAmmo
{
	class MeleeDamage;
	class DefaultAmmo;
	class AnomalyFruitPunchHit : MeleeDamage
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.0;
			class Health
			{
				damage = 30;
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
	class AnomalyBurntFuzzHit : MeleeDamage
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.0;
			class Health
			{
				damage = 7;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 0;
			};
		};
	};
	class AnomalySpringBoardHit : MeleeDamage
	{
		class DamageApplied
		{
			type = "Barbedwire";
			bleedThreshold = 0.0;
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
	class AnomalyElectraHit : MeleeDamage
	{
		hitAnimation = 1;
		class DamageApplied
		{
			type = "Barbedwire";
			bleedThreshold = 0.0;
			class Health
			{
				damage = 35;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 40;
			};
		};
	};
	class AnomalyBurnerHit : MeleeDamage
	{
		hitAnimation = 1;
		class DamageApplied
		{
			type = "Barbedwire";
			bleedThreshold = 0.0;
			class Health
			{
				damage = 35;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 30;
			};
		};
	};
	class AnomalyBurnerHit2 : MeleeDamage
	{
		class DamageApplied
		{
			type = "Barbedwire";
			bleedThreshold = 0.0;
			class Health
			{
				damage = 10;
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
	class AnomalyVortexHit : DefaultAmmo
	{
		indirectHit = 1;
		indirectHitRange = 1.5;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.050000001;
		soundSetExplosion[] =
		{
		};
		class DamageApplied
		{
			type = "FragGrenade";
			bleedThreshold = 1.0;
			class Health
			{
				damage = 25;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 75;
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
	class HouseNoDestruct;
	class Inventory_Base;
	class Box_Base;
	class X18_Anomaly_Burner : HouseNoDestruct
	{
		scope = 2;
	};
	class X18_Anomaly_BurntFuzz_Small : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Objects\Data\BurntFuzz\BurntFuzz_Small.p3d";
	};
	class X18_Anomaly_BurntFuzz_Middle : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Objects\Data\BurntFuzz\BurntFuzz_Middle.p3d";
	};
	class X18_Anomaly_BurntFuzz_Normal : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Objects\Data\BurntFuzz\BurntFuzz_Normal.p3d";
	};
	class X18_Anomaly_BurntFuzz_SemiTall : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Objects\Data\BurntFuzz\BurntFuzz_SemiTall.p3d";
	};
	class X18_Anomaly_BurntFuzz_Tall : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Objects\Data\BurntFuzz\BurntFuzz_Tall.p3d";
	};
	class X18_Anomaly_Carousel : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Anomalies\Models\EmptySphere.p3d";
	};
	class X18_Anomaly_Electra : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Anomalies\Models\EmptySphere.p3d";
	};
	class X18_Anomaly_FruitPunch : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Anomalies\Models\EmptySphere.p3d";
	};
	class X18_Anomaly_Portal : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Anomalies\Models\EmptySphere.p3d";
	};
	class X18_Anomaly_Space : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Anomalies\Models\EmptySphere.p3d";
	};
	class X18_Anomaly_SpringBoard : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Anomalies\Models\EmptySphere.p3d";
	};
	class X18_Anomaly_Vortex : HouseNoDestruct
	{
		scope = 2;
		model = "\Noosphere\X18Anomalies\Models\EmptySphere.p3d";
	};
	class X18_Anomaly_Portal_ExitFX : HouseNoDestruct
	{
		scope = 2;
		weight = 99999999;
	};
	class X18_Anomaly_Portal_ExitSoundFX : HouseNoDestruct
	{
		scope = 2;
		weight = 99999999;
	};
	class X18_Anomaly_Space_ExitFX : HouseNoDestruct
	{
		scope = 2;
		weight = 99999999;
	};
	class X18_Anomaly_Space_ExitSoundFX : HouseNoDestruct
	{
		scope = 2;
		weight = 99999999;
	};
	class X18_Bolt : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_X18_Bolt";
		descriptionShort = "$STR_DSC_X18_Bolt";
		model = "Noosphere\X18Anomalies\Models\Bolt.p3d";
		weight = 120;
		itemSize[] = { 1,2 };
		canBeSplit = 1;
		varQuantityInit = 25;
		varQuantityMin = 0;
		varQuantityMax = 25;
		varQuantityDestroyOnMin = 1;
		absorbency = 0;
		rotationFlags = 12;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1;
					healthLevels[] = { {1.01,{"DZ\vehicles\parts\data\sparkplug.rvmat"}},{0.7,{"DZ\vehicles\parts\data\sparkplug.rvmat"}},{0.5,{"DZ\vehicles\parts\data\sparkplug_damage.rvmat"}},{0.3,{"DZ\vehicles\parts\data\sparkplug_damage.rvmat"}},{0.01,{"DZ\vehicles\parts\data\sparkplug_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_BoltBox : Box_Base
	{
		scope = 2;
		displayName = "$STR_X18_BoltBox";
		descriptionShort = "$STR_DSC_X18_BoltBox";
		model = "Noosphere\X18Anomalies\Models\BoltBox.p3d";
		weight = 3000;
		absorbency = 0.80000001;
		itemSize[] = { 2,1 };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 80;
					healthLevels[] = { {1.01,{"DZ\gear\consumables\data\Box_of_Nails.rvmat"}},{0.7,{"DZ\gear\consumables\data\Box_of_Nails.rvmat"}},{0.5,{"DZ\gear\consumables\data\Box_of_Nails_damage.rvmat"}},{0.3,{"DZ\gear\consumables\data\Box_of_Nails_damage.rvmat"}},{0.01,{"DZ\gear\consumables\data\Box_of_Nails_destruct.rvmat"}} };
				};
			};
		};
		class Resources
		{
			class X18_Bolt
			{
				value = 25;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
};

class CfgSounds
{
	class default
	{
		name = "";
		titles[] = {};
	};
	class electra_hit : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\electra_hit",
			3.0,
			1.0,
			50 };
	};
	class electra_idle : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\electra_idle",
			1.0,
			1,
			30 };
	};
	class PortalIdle : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\teleport_idle",
			3.0,
			1.0,
			50
		};
	};
	class monolith_portal_incoming : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\teleport_incoming",
			3.0,
			1.0,
			100
		};
	};
	class PortalTrigger_1 : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\teleport_work_1",
			3.0,
			1.0,
			100
		};
	};
	class PortalTrigger_2 : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\teleport_work_2",
			3.0,
			1.0,
			200
		};
	};
	class monolith_portal_visible : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\teleport_visible",
			3.0,
			1.0,
			100
		};
	};
	class snow_SpringboardIdle : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\snow_tramplin_rumble",
			0.5,
			1.0,
			50
		};
	};
	class snow_SpringboardActive : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\snow_tramplin_blast",
			6.0,
			1.0,
			50
		};
	};
	class snow_VortexIdle : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\snow_voronka_idle",
			0.5,
			1.0,
			50
		};
	};
	class snow_VortexActive : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\snow_voronka_blowout",
			6.0,
			1.0,
			100
		};
	};
	class SpaceAnomalyIdle : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\space_anomaly_idle",
			1.0,
			0.5,
			50
		};
	};
	class SpaceAnomalyTrigger : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\space_anomaly_work",
			1.0,
			1.0,
			200
		};
	};
	class BurntFuzzIdle : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\buzz_idle",
			1.0,
			1,
			30
		};
	};
	class BurntFuzzHit : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\buzz_hit",
			3.0,
			1,
			30
		};
	};
	class SpringboardIdle : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\gravi_rumble1",
			0.5,
			1.0,
			50
		};
	};
	class SpringboardActive : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\anomaly_gravy_blast1",
			6.0,
			1.0,
			50
		};
	};
	class VortexIdle : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\gravi_idle00",
			0.5,
			1.0,
			50
		};
	};
	class VortexActive : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\gravi_blowout6",
			6.0,
			1.0,
			100
		};
	};
	class ZharkaIdle : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\gravi_rumble1",
			1.0,
			1.0,
			50
		};
	};
	class ZharkaActive : default
	{
		sound[] =
		{
			"\Noosphere\X18Anomalies\Sounds\zhar_blow",
			5.0,
			1.0,
			50
		};
	};
};