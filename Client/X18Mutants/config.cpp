class CfgPatches
{
	class X18Mutants
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18Mutants
	{
		dir = "X18Mutants";
		name = "X18Mutants";
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] =
				{
					"Noosphere/X18Mutants/Scripts/Common",
					"Noosphere/X18Mutants/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] =
				{
					"Noosphere/X18Mutants/Scripts/Common",
					"Noosphere/X18Mutants/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] =
				{
					"Noosphere/X18Mutants/Scripts/Common",
					"Noosphere/X18Mutants/Scripts/5_Mission"
				};
			};
		};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class X18_Static_Cat_Tail : HouseNoDestruct
	{
		scope = 1;
		model = "\nh\gear\food\CatTail.p3d";
	};
	class X18_Static_Cat_Head : HouseNoDestruct
	{
		scope = 1;
		model = "FS_3\1_Muta\KotBaun\trof\golova_kot.p3d";
	};
	class X18_Static_Chimera_Head : HouseNoDestruct
	{
		scope = 1;
		model = "\FS_3\Monstro\trof\golova.p3d";
	};
	class X18_Static_Chimera_Claw : HouseNoDestruct
	{
		scope = 1;
		model = "\nh\gear\food\HimeraClaw.p3d";
	};
	class X18_Static_Bloodsucker_Head : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Head.p3d";
	};
	class X18_Static_Bloodsucker_Head_Red : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Head_Red.p3d";
	};
	class X18_Static_Bloodsucker_Head_Dark : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Head_Dark.p3d";
	};
	class X18_Static_Bloodsucker_Head_MarshCreature : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Head_MarshCreature.p3d";
	};
	class X18_Static_Bloodsucker_Tentacles : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Tentacle.p3d";
	};
	class X18_Static_Bloodsucker_Tentacles_Red : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Tentacle_Red.p3d";
	};
	class X18_Static_Bloodsucker_Tentacles_Dark : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Tentacle_Dark.p3d";
	};
	class X18_Static_Bloodsucker_Tentacles_MarshCreature : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Mutants\Mutants\Bloodsucker\Data\Tentacle_MarshCreature.p3d";
	};
	class X18_Static_Controller_Brain : HouseNoDestruct
	{
		scope = 1;
		model = "\nh\gear\food\brain.p3d";
	};
	class X18_Static_Pseudodog_Head : HouseNoDestruct
	{
		scope = 1;
		model = "\FV_ST_PACK\Mutants\Psedog\trof\golova.p3d";
	};
	class X18_Static_Pseudodog_Tail : HouseNoDestruct
	{
		scope = 1;
		model = "\nh\gear\food\pseudodog_tail.p3d";
	};
	class X18_Static_PseudoGiant_Paw : HouseNoDestruct
	{
		scope = 1;
		model = "\SFP\1_AI\Gigant\trofey\Lapa.p3d";
	};
	class X18_Static_PsyDog_Head : HouseNoDestruct
	{
		scope = 1;
		model = "\FV_ST_PACK\Mutants\Psedog\trof\golova.p3d";
	};
	class X18_Static_PsyDog_Tail : HouseNoDestruct
	{
		scope = 1;
		model = "\nh\gear\food\pseudodog_tail.p3d";
		hiddenSelections[] = { "zbytek","tex" };
		hiddenSelectionsTextures[] = { "nh\mutants\pseudodog\data\act_pseudodog1.paa","nh\mutants\pseudodog\data\act_pseudodog_fur1.paa" };
	};
	class X18_Static_Snork_Leg : HouseNoDestruct
	{
		scope = 1;
		model = "\SFP\1_AI\snork\trofey\botinok.p3d";
	};
	class X18_Static_Snork_Hand : HouseNoDestruct
	{
		scope = 1;
		model = "\SFP\1_AI\snork\trofey\ruka.p3d";
	};
	class X18_Static_Snork_Head : HouseNoDestruct
	{
		scope = 1;
		model = "\SFP\1_AI\snork\trofey\head.p3d";
	};
	class X18_Static_Snork_Boss_Head : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Mutants\Mutants\Snork\SnorkBossHead.p3d";
	};
};