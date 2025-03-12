class CfgPatches
{
	class X18AoD
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Gear_Navigation", "X18CoreScripts", "dz_aod_client_core", "dz_aod_assets_part1", "DZ_AreaofDecay_Map" };
	};
};
class CfgMods
{
	class X18AoD
	{
		dir = "X18AoD";
		name = "X18AoD";
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18AoD/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18AoD/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18AoD/Scripts/5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class Land_light_lamp1 : HouseNoDestruct
	{
		scope = 2;
		displayName = "light lamp1";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Lamp\light_lamp1.p3d";
	};
	class Land_light_lamp2 : HouseNoDestruct
	{
		scope = 2;
		displayName = "light lamp2";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Lamp\light_lamp2.p3d";
	};
	class Land_light_lamp3 : HouseNoDestruct
	{
		scope = 2;
		displayName = "light lamp3";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Lamp\light_lamp3.p3d";
	};
	class Land_light_lamp4 : HouseNoDestruct
	{
		scope = 2;
		displayName = "light lamp4";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Lamp\light_lamp4.p3d";
	};
	class Land_light_lamp1_AlwaysOn : HouseNoDestruct
	{
		scope = 2;
		displayName = "light lamp1";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Lamp\light_lamp1.p3d";
	};
	class Land_light_lamp2_AlwaysOn : HouseNoDestruct
	{
		scope = 2;
		displayName = "light lamp2";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Lamp\light_lamp2.p3d";
	};
	class Land_light_lamp3_AlwaysOn : HouseNoDestruct
	{
		scope = 2;
		displayName = "light lamp3";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Lamp\light_lamp3.p3d";
	};
	class Land_light_lamp4_AlwaysOn : HouseNoDestruct
	{
		scope = 2;
		displayName = "light lamp4";
		model = "\areaofdecay\dz_aod_assets_part1\structures_f\Lamp\light_lamp4.p3d";
	};
};
class CfgWorlds
{
	class CAWorld;
	class ExclusionZone : CAWorld
	{
		class Names
		{
			delete aod_cordon_map;
			delete aod_cordon_south_kpp;
			delete aod_cordon_blockpost;
			delete aod_cordon_derevnya;
			delete aod_cordon_factory;
			delete aod_cordon_elevator;
			delete aod_cordon_ferma;
			delete aod_cordon_derevnya_2;
			delete aod_cordon_hutor;
			delete aod_cordon_north_kpp;
			class Map_Great_Swamps
			{
				name = "Great Swamps";
				position[] = {
					1849.1,
					1947.94
				};
				type = "Capital";
				radiusA = 800.0;
				radiusB = 800.0;
			};
			class Map_Cordon
			{
				name = "Cordon";
				position[] = {
					4774.33,
					2182.27
				};
				type = "Capital";
				radiusA = 800.0;
				radiusB = 800.0;
			};
			class Map_CordonRookieVillage
			{
				name = "Rookie Village";
				position[] = {
					4596.33,
					1819.11
				};
				type = "Village";
				radiusA = 75.0;
				radiusB = 75.0;
			};
			class Map_CordonCarpark
			{
				name = "Carpark";
				position[] = {
					5030.4,
					1944.76
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_CordonUnderpass
			{
				name = "Underpass";
				position[] = {
					4769.1,
					2186.07
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_CordonNorthernfarm
			{
				name = "Northern Farm";
				position[] = {
					4870.47,
					2357.42
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_CordonMill
			{
				name = "Mill";
				position[] = {
					4861.91,
					2114.69
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_CordonRailwayBridge
			{
				name = "Railway Bridge";
				position[] = {
					4934.73,
					2191.79
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Predbannik
			{
				name = "Predbannik";
				position[] = {
					6443.52,
					766.292
				};
				type = "Capital";
				radiusA = 600.0;
				radiusB = 600.0;
			};
			class Map_Darkscape
			{
				name = "Darkscape";
				position[] = {
					8798.56,
					1239.39
				};
				type = "Capital";
				radiusA = 900.0;
				radiusB = 900.0;
			};
			class Map_DarkscapeAbandonedSettlement
			{
				name = "Abandoned Settlement";
				position[] = {
					8838.54,
					1270.81
				};
				type = "Ruin";
				radiusA = 50.0;
				radiusB = 50.0;
			};
			class Map_DarkscapeServiceStation
			{
				name = "Service Station";
				position[] = {
					9269.76,
					1205.13
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_DarkscapeDocklands
			{
				name = "Docklands";
				position[] = {
					9432.54,
					1273.66
				};
				type = "Marine";
				radiusA = 100.0;
				radiusB = 100.0;
			};
			class Map_DarkscapeDerelictGenerators
			{
				name = "Derelict Generators";
				position[] = {
					8705.84,
					1480.15
				};
				type = "Lab";
				radiusA = 60.0;
				radiusB = 60.0;
			};
			class Map_DarkscapeSmallradarStation
			{
				name = "Small radar station";
				position[] = {
					8755.72,
					1722.02
				};
				type = "Lab";
				radiusA = 60.0;
				radiusB = 60.0;
			};
			class Map_Agroprom
			{
				name = "Agroprom";
				position[] = {
					1956.82,
					4591.09
				};
				type = "Capital";
				radiusA = 800.0;
				radiusB = 800.0;
			};
			class Map_AgropromResearchInstitute
			{
				name = "Research Institute";
				position[] = {
					1676.96,
					4082.45
				};
				type = "Lab";
				radiusA = 60.0;
				radiusB = 60.0;
			};
			class Map_AgropromFactory
			{
				name = "Factory";
				position[] = {
					2212.25,
					4822.09
				};
				type = "IndustrialSite";
				radiusA = 60.0;
				radiusB = 60.0;
			};
			class Map_AgropromSwamp
			{
				name = "Swamp";
				position[] = {
					1514.82,
					4959.8
				};
				type = "Local";
				radiusA = 200.0;
				radiusB = 200.0;
			};
			class Map_Garbage
			{
				name = "Garbage";
				position[] = {
					5250.77,
					4601.09
				};
				type = "Capital";
				radiusA = 800.0;
				radiusB = 800.0;
			};
			class Map_Garbage_VehicleGraveyard
			{
				name = "Vehicle graveyard";
				position[] = {
					4951.39,
					4022.56
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_GarbageTrainDepot
			{
				name = "Train Depot";
				position[] = {
					5034.44,
					4634.4
				};
				type = "RailroadStation";
				radiusA = 55.0;
				radiusB = 55.0;
			};
			class Map_GarbageFleaMarket
			{
				name = "Flea Market";
				position[] = {
					5428.35,
					5016.05
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_GarbageBanditCamp
			{
				name = "Small camp";
				position[] = {
					5405.81,
					4300.29
				};
				type = "Camp";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_DarkValley
			{
				name = "Dark Valley";
				position[] = {
					7596.29,
					4333.88
				};
				type = "Capital";
				radiusA = 750.0;
				radiusB = 750.0;
			};
			class Map_Yantar
			{
				name = "Yantar";
				position[] = {
					2463.8,
					6504.32
				};
				type = "Capital";
				radiusA = 800.0;
				radiusB = 800.0;
			};
			class Map_YantarCamp
			{
				name = "Small camp";
				position[] = {
					2548.75,
					6961.6
				};
				type = "Camp";
				radiusA = 60.0;
				radiusB = 60.0;
			};
			class Map_YantarProductionComplex
			{
				name = "Production complex";
				position[] = {
					2398.83,
					6529.31
				};
				type = "Factory";
				radiusA = 220.0;
				radiusB = 220.0;
			};
			class Map_Yantar_Swamp
			{
				name = "Swamp";
				position[] = {
					2323.86,
					6097.02
				};
				type = "Local";
				radiusA = 100.0;
				radiusB = 100.0;
			};
			class Map_YantarMobileScienceLab
			{
				name = "Mobile science lab";
				position[] = {
					2453.8,
					6214.46
				};
				type = "Lab";
				radiusA = 60.0;
				radiusB = 60.0;
			};
			class Map_Rostok
			{
				name = "Rostok";
				position[] = {
					4923.47,
					6742.35
				};
				type = "Capital";
				radiusA = 180.0;
				radiusB = 180.0;
			};
			class Map_Junkyard
			{
				name = "Junkyard";
				position[] = {
					7848.17,
					6560.79
				};
				type = "Capital";
				radiusA = 750.0;
				radiusB = 750.0;
			};
			class Map_DeadCity
			{
				name = "Dead City";
				position[] = {
					2836.5,
					8304.73
				};
				type = "Capital";
				radiusA = 650.0;
				radiusB = 650.0;
			};
			class Map_ArmyWarehouses
			{
				name = "Army Warehouses";
				position[] = {
					5709.21,
					8184.0
				};
				type = "Capital";
				radiusA = 500.0;
				radiusB = 500.0;
			};
			class Map_Barrier
			{
				name = "Barrier";
				position[] = {
					6363.56,
					9308.79
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_NorthernSwamps
			{
				name = "Northern Swamps";
				position[] = {
					8643.78,
					9495.36
				};
				type = "Capital";
				radiusA = 1250.0;
				radiusB = 1250.0;
			};
			class Map_RedForest
			{
				name = "Red Forest";
				position[] = {
					3815.91,
					10359.4
				};
				type = "Capital";
				radiusA = 400.0;
				radiusB = 400.0;
			};
			class Map_Tuzla_tunnel
			{
				name = "Tuzla Tunnel";
				position[] = {
					1272.11,
					2407.91
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Northern_farmstead
			{
				name = "Northern Farmstead";
				position[] = {
					2436.99,
					2307.96
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Burnt_farmstead
			{
				name = "Burnt Farmstead";
				position[] = {
					2029.92,
					1857.27
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Southern_farmstead
			{
				name = "Southern Farmstead";
				position[] = {
					2318.87,
					1553.79
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Settlement_ruins
			{
				name = "Settlement Ruins";
				position[] = {
					1610.12,
					2129.87
				};
				type = "Ruin";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Church
			{
				name = "Church";
				position[] = {
					2028.1,
					1566.51
				};
				type = "Church";
				radiusA = 30.0;
				radiusB = 30.0;
			};
			class Map_Fishing_hamlet
			{
				name = "Fishing hamlet";
				position[] = {
					1720.98,
					1501.08
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Pump_station
			{
				name = "Pump station";
				position[] = {
					1675.55,
					1793.67
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Machine_yard
			{
				name = "Machine yard";
				position[] = {
					2200.74,
					2095.34
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Rostok_Bar_100
			{
				name = "Bar 100";
				position[] = {
					4872.06,
					6657.86
				};
				type = "Local";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Wild_Territory
			{
				name = "Wild Territory";
				position[] = {
					4550.72,
					6752
				};
				type = "Capital";
				radiusA = 220.0;
				radiusB = 220.0;
			};
			class Map_Predbannik_Military
			{
				name = "Military Base";
				position[] = {
					6313.1,
					723.912
				};
				type = "BigMilitary";
				radiusA = 75.0;
				radiusB = 75.0;
			};
			class Map_Checkpoint1
			{
				name = "Checkpoint";
				position[] = {
					5278.94,
					5291.65
				};
				type = "BorderCrossing";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Checkpoint2
			{
				name = "Checkpoint";
				position[] = {
					4655.95,
					1583.61
				};
				type = "BorderCrossing";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Checkpoint3
			{
				name = "Checkpoint";
				position[] = {
					4866.01,
					2864.75
				};
				type = "BorderCrossing";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Checkpoint4
			{
				name = "Checkpoint";
				position[] = {
					5332.53,
					3792.64
				};
				type = "BorderCrossing";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Checkpoint5
			{
				name = "Checkpoint";
				position[] = {
					5444.92,
					8419.48
				};
				type = "BorderCrossing";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Checkpoint6
			{
				name = "Checkpoint";
				position[] = {
					5819.08,
					1018.11
				};
				type = "BorderCrossing";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Checkpoint7
			{
				name = "Checkpoint";
				position[] = {
					5259.16,
					1984.06
				};
				type = "BorderCrossing";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Checkpoint8
			{
				name = "Checkpoint";
				position[] = {
					5278.94,
					5291.65
				};
				type = "BorderCrossing";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Checkpoint9
			{
				name = "Checkpoint";
				position[] = {
					4666.29,
					1579.23
				};
				type = "BorderCrossing";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_Checkpoint10
			{
				name = "Checkpoint";
				position[] = {
					4868.47,
					2864.42
				};
				type = "BorderCrossing";
				radiusA = 25.0;
				radiusB = 25.0;
			};
			class Map_PC_RookieVilla
			{
				name = "RookieVillage";
				position[] = {
					4619.92,
					1812.57
				};
				type = "PersonalChest";
			};
			class Map_PC_Bar100
			{
				name = "Bar100";
				position[] = {
					4872.06,
					6657.86
				};
				type = "PersonalChest";
			};
			class Map_PC_ClearSky
			{
				name = "ClearSky";
				position[] = {
					1497.592896,
					1399.780029
				};
				type = "PersonalChest";
			};
		};
	};
};
class MapDefaults
{
	scaleMin = 0.075;
	scaleMax = 0.4;
	scaleDefault = 0.075;
	ptsPerSquareSea = 8;
	ptsPerSquareTxt = 10;
	ptsPerSquareCLn = 10;
	ptsPerSquareExp = 10;
	ptsPerSquareCost = 10;
	ptsPerSquareFor = 99;
	ptsPerSquareForEdge = 99;
	ptsPerSquareRoad = 4;
	ptsPerSquareObj = 15;
	maxSatelliteAlpha = 1;
	alphaFadeStartScale = 1;
	alphaFadeEndScale = 1;
	userMapPath = "areaofdecay\dz_aod_exclusion_zone\data\layers";
	maxUserMapAlpha = 0.2;
	alphaUserMapFadeStartScale = 0.5;
	alphaUserMapFadeEndScale = 0.8;
	showCountourInterval = 1;
	colorLevels[] = {
		0.65,
		0.6,
		0.45,
		0.3
	};
	colorSea[] = {
		0.2,
		0.5,
		0.7,
		1
	};
	colorForest[] = {
		0.36,
		0.78,
		0.08,
		0
	};
	colorRocks[] = {
		0.5,
		0.5,
		0.5,
		0.2
	};
	colorCountlines[] = {
		0.85,
		0.8,
		0.65,
		0.1
	};
	colorMainCountlines[] = {
		0.45,
		0.4,
		0.25,
		1
	};
	colorCountlinesWater[] = {
		0.25,
		0.4,
		0.5,
		0.3
	};
	colorMainCountlinesWater[] = {
		0.25,
		0.4,
		0.5,
		0.9
	};
	colorPowerLines[] = {
		0.1,
		0.1,
		0.1,
		1
	};
	colorRailWay[] = {
		0.8,
		0.2,
		0,
		1
	};
	colorForestBorder[] = {
		0.4,
		0.8,
		0,
		1
	};
	colorRocksBorder[] = {
		0.5,
		0.5,
		0.5,
		1
	};
	colorOutside[] = {
		1,
		1,
		1,
		1
	};
	colorTracks[] = {
		0.78,
		0.66,
		0.34,
		1
	};
	colorRoads[] = {
		0.69,
		0.43,
		0.23,
		1
	};
	colorMainRoads[] = {
		0.53,
		0.35,
		0,
		1
	};
	colorTracksFill[] = {
		0.96,
		0.91,
		0.6,
		1
	};
	colorRoadsFill[] = {
		0.92,
		0.73,
		0.41,
		1
	};
	colorMainRoadsFill[] = {
		0.84,
		0.61,
		0.21,
		1
	};
	colorGrid[] = {
		0.9,
		0.9,
		0.9,
		0.0
	};
	colorGridMap[] = {
		0.9,
		0.9,
		0.9,
		0.0
	};
	fontNames = "gui/fonts/sdf_MetronBook24";
	sizeExNames = 0.03;
	colorNames[] = {
		1,
		1,
		1,
		1
	};
	fontGrid = "gui/fonts/sdf_MetronBook24";
	sizeExGrid = 0.02;
	fontLevel = "gui/fonts/sdf_MetronBook24";
	sizeExLevel = 0.01;
	colorMountPoint[] = {
		0.45,
		0.4,
		0.25,
		0
	};
	mapPointDensity = 0.12;
	text = "";
	fontLabel = "gui/fonts/sdf_MetronBook24";
	fontInfo = "gui/fonts/sdf_MetronBook24";
	class Legend
	{
		x = 0.05;
		y = 0.85;
		w = 0.4;
		h = 0.1;
		font = "gui/fonts/sdf_MetronBook24";
		sizeEx = 0.02;
		colorBackground[] = { 1,1,1,0 };
		color[] = { 0,0,0,0 };
	};
	class Bush
	{
		icon = "\dz\gear\navigation\data\map_bush_ca.paa";
		color[] = { 0.4,0.8,0,0 };
		size = 14;
		importance = "0.2 * 14 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class SmallTree
	{
		icon = "\dz\gear\navigation\data\map_smalltree_ca.paa";
		color[] = { 0.4,0.8,0,0 };
		size = 12;
		importance = "0.6 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Tree
	{
		icon = "\dz\gear\navigation\data\map_tree_ca.paa";
		color[] = { 0.4,0.8,0,0 };
		size = 12;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Rock
	{
		icon = "\dz\gear\navigation\data\map_rock_ca.paa";
		color[] = { 0.1,0.1,0.1,0.8 };
		size = 12;
		importance = "0.5 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fuelstation
	{
		icon = "\Noosphere\X18AoD\Data\fuelstation.paa";
		size = 16;
		color[] = { 1,1,1,1 };
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.75;
		coefMax = 2;
	};
	class Lighthouse
	{
		icon = "\Noosphere\X18AoD\Data\lighthouse.paa";
		size = 30;
		color[] = { 1,1,1,1 };
		importance = "0.9 * 16 * 0.05";
		coefMin = 1;
		coefMax = 4;
	};
	class Stack
	{
		icon = "\dz\gear\navigation\data\map_stack_ca.paa";
		size = 16;
		color[] = { 1,1,1,0 };
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Transmitter
	{
		icon = "\Noosphere\X18AoD\Data\radiotower.paa";
		color[] = { 1,1,1,1 };
		size = 30;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.7;
		coefMax = 4;
	};
	class Watertower
	{
		icon = "\Noosphere\X18AoD\Data\watertower.paa";
		color[] = { 1,1,1,1 };
		size = 30;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.7;
		coefMax = 4;
	};
	class Shipwreck
	{
		icon = "\dz\gear\navigation\data\map_shipwreck_ca.paa";
		color[] = { 1,1,1,1 };
		size = 16;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Monument
	{
		icon = "\dz\gear\navigation\data\map_monument_ca.paa";
		color[] = { 1,1,1,0 };
		size = 20;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class BusStop
	{
		icon = "\dz\gear\navigation\data\map_busstop_ca.paa";
		color[] = { 1,1,1,0 };
		size = 16;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fountain
	{
		icon = "\dz\gear\navigation\data\map_fountain_ca.paa";
		color[] = { 1,1,1,0 };
		size = 20;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Waterpump
	{
		icon = "\Noosphere\X18AoD\Data\waterpump.paa";
		color[] = { 1,1,1,1 };
		size = 20;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 2;
	};
	class Hospital
	{
		icon = "\Noosphere\X18AoD\Data\hospital.paa";
		color[] = { 1,1,1,1 };
		size = 25;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 2;
	};
	class Store
	{
		icon = "\Noosphere\X18AoD\Data\shopping.paa";
		color[] = { 1,1,1,1 };
		size = 20;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 2;
	};
	class Police
	{
		icon = "\Noosphere\X18AoD\Data\police.paa";
		color[] = { 1,1,1,1 };
		size = 25;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 2;
	};
	class FireDep
	{
		icon = "\Noosphere\X18AoD\Data\firestation.paa";
		color[] = { 1,1,1,1 };
		size = 25;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 2;
	};
	class TouristSign
	{
		icon = "\dz\gear\navigation\data\map_tsign_ca.paa";
		color[] = { 1,1,1,0 };
		size = 15;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Tourism
	{
		icon = "\Noosphere\X18AoD\Data\bar.paa";
		color[] = { 1,1,1,1 };
		size = 20;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 2;
	};
	class Cross
	{
		icon = "\dz\gear\navigation\data\map_cross_ca.paa";
		size = 20;
		color[] = { 1,1,0,0 };
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Chapel
	{
		icon = "\Noosphere\X18AoD\Data\church.paa";
		color[] = { 1,1,1,1 };
		size = 25;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 2;
	};
	class Church
	{
		icon = "\Noosphere\X18AoD\Data\church.paa";
		color[] = { 1,1,1,1 };
		size = 35;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 2;
	};
	class ViewTower
	{
		icon = "\Noosphere\X18AoD\Data\watchtower.paa";
		color[] = { 1,1,1,1 };
		size = 22;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 2;
	};
	class TouristShelter
	{
		icon = "\dz\gear\navigation\data\map_tshelter_ca.paa";
		color[] = { 1,1,1,1 };
		size = 18;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Quay
	{
		icon = "\dz\gear\navigation\data\map_quay_ca.paa";
		size = 16;
		color[] = { 1,1,1,1 };
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Bunker
	{
		icon = "\dz\gear\navigation\data\map_bunker_ca.paa";
		color[] = { 0.6,0.6,0.6,1 };
		size = 20;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fortress
	{
		icon = "\dz\gear\navigation\data\map_fortress_ca.paa";
		size = 20;
		color[] = { 0.6,0.6,0.6,1 };
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Rocks
	{
		icon = "\dz\gear\navigation\data\map_rock_ca.paa";
		color[] = { 0.6,0.6,0.6,1 };
		size = 12;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Ruin
	{
		icon = "\dz\gear\navigation\data\map_ruin_ca.paa";
		size = 16;
		color[] = { 0.6,0.6,0.6,1 };
		importance = "1.2 * 16 * 0.05";
		coefMin = 1;
		coefMax = 4;
	};
};
class CfgMaterials
{
	class Water
	{
		PixelShaderID = "Water";
		VertexShaderID = "Water";
		ambient[] = { 0.07058824,0.17254902,0.14509805,0.4 };
		diffuse[] = { 0.07058824,0.17254902,0.14509805,1 };
		forcedDiffuse[] = { 0.0264,0.03,0.013,0 };
		specular[] = { 1.5,1.5,1.5,0 };
		specularPower = 4;
		emmisive[] = { 0,0,0,0 };
		class Stage1
		{
			texture = "DZ\Data\data\water_nofhq.paa";
			uvSource = "texWaterAnim";
			class uvTransform
			{
				aside[] = { 0,1,0 };
				up[] = { 1,0,0 };
				dir[] = { 0,0,1 };
				pos[] = { 0.3,0.4,0 };
			};
		};
		class Stage2
		{
			texture = "DZ\Data\data\sea_foam_lco.paa";
			uvSource = "none";
		};
		class Stage3
		{
			texture = "DZ\Data\data\water2_nohq.paa";
			uvSource = "none";
		};
	};
	class Shore
	{
		PixelShaderID = "Shore";
		VertexShaderID = "Shore";
		ambient[] = { 0.07058824,0.17254902,0.14509805,0.4 };
		diffuse[] = { 0.07058824,0.17254902,0.14509805,1 };
		forcedDiffuse[] = { 0.0264,0.03,0.013,0 };
		specular[] = { 1.5,1.5,1.5,0 };
		specularPower = 4;
		emmisive[] = { 0,0,0,0 };
		class Stage1
		{
			texture = "DZ\Data\data\water_nofhq.paa";
			uvSource = "texWaterAnim";
			class uvTransform
			{
				aside[] = { 0,1,0 };
				up[] = { 0.1,0,0 };
				dir[] = { 0,0,1 };
				pos[] = { 0.3,0.4,0 };
			};
		};
		class Stage2
		{
			texture = "DZ\Data\data\sea_foam_lco.paa";
			uvSource = "none";
		};
		class Stage3
		{
			texture = "DZ\Data\data\water2_nohq.paa";
			uvSource = "none";
		};
	};
	class ShoreWet
	{
		PixelShaderID = "ShoreWet";
		VertexShaderID = "Shore";
	};
};
class CfgLocationTypes
{
	class Name
	{
		name = "keypoint";
		drawStyle = "name";
		texture = "#(argb,1,1,1)color(1,1,1,1)";
		color[] = { 1,1,1,1 };
		size = 0;
		font = "gui/fonts/sdf_MetronBook24";
		textSize = 0.03;
		shadow = 0.1;
		importance = 1;
	};
	class NameIcon
	{
		name = "keypoint";
		drawStyle = "icon";
		texture = "#(argb,1,1,1)color(1,1,1,1)";
		color[] = { 1,1,1,1 };
		size = 0;
		font = "gui/fonts/sdf_MetronBook24";
		textSize = 0.03;
		shadow = 0;
		importance = 1;
	};
	class Capital : Name
	{
		color[] = { 1,1,1,1 };
		textSize = 0.06;
		importance = 7;
	};
	class BigMilitary : Name
	{
		color[] = { 1,0.1,0.1,1 };
		textSize = 0.05;
		importance = 6;
	};
	class City : Name
	{
		textSize = 0.05;
		importance = 6;
	};
	class MediumMilitary : Name
	{
		color[] = { 1,0.1,0.1,1 };
		textSize = 0.04;
		importance = 5;
	};
	class SmallMilitary : Name
	{
		color[] = { 1,0.1,0.1,1 };
		textSize = 0.035;
		importance = 5;
	};
	class Village : Name
	{
		textSize = 0.04;
		importance = 3;
	};
	class Local : Name
	{
		color[] = { 0.44,0.38,0.3,1 };
		textSize = 0.03;
	};
	class Marine : Name
	{
		color[] = { 0.05,0.4,0.8,0.8 };
		textSize = 0.03;
	};
	class FeedShack : NameIcon
	{
		texture = "\Noosphere\X18AoD\Data\feedshack.paa";
		importance = 1;
		size = 10;
	};
	class Deerstand : NameIcon
	{
		texture = "\Noosphere\X18AoD\Data\deerstand.paa";
		importance = 1;
		size = 10;
	};
	class Ruin : NameIcon
	{
		texture = "\DZ\gear\navigation\data\map_ruin_ca.paa";
		textSize = 0.03;
		importance = 2;
		size = 10;
	};
	class Camp : NameIcon
	{
		color[] = { 0.44,0.38,0.3,1 };
		texture = "\DZ\gear\navigation\data\map_camp_ca.paa";
		textSize = 0.02;
		size = 10;
	};
	class Hill : NameIcon
	{
		color[] = { 0.7,0.7,0.7,1 };
		texture = "\DZ\gear\navigation\data\map_hill_ca.paa";
		textSize = 0.02;
		size = 10;
	};
	class ViewPoint : NameIcon
	{
		color[] = { 0.78,0,0.05,0 };
		texture = "\DZ\gear\navigation\data\map_viewpoint_ca.paa";
		size = 9;
	};
	class RockArea : NameIcon
	{
		color[] = { 0,0,0,1 };
		texture = "\DZ\gear\navigation\data\map_rock_ca.paa";
		size = 9;
	};
	class RailroadStation : NameIcon
	{
		color[] = { 0,0,0,1 };
		texture = "\DZ\gear\navigation\data\map_station_ca.paa";
		size = 10;
	};
	class IndustrialSite : NameIcon
	{
		color[] = { 0,0,0,1 };
		texture = "\DZ\gear\navigation\data\map_factory_ca.paa";
		size = 10;
	};
	class LocalOffice : NameIcon
	{
		color[] = { 0.22,0.21,0.51,0 };
		texture = "\DZ\gear\navigation\data\map_govoffice_ca.paa";
		size = 10;
	};
	class BorderCrossing : NameIcon
	{
		color[] = { 0.78,0,0.05,1 };
		texture = "\DZ\gear\navigation\data\map_border_cross_ca.paa";
		size = 10;
	};
	class Bar : NameIcon
	{
		color[] = { 0.78,0,0.05,1 };
		texture = "\Noosphere\X18AoD\Data\bar.paa";
		size = 10;
	};
	class Church : NameIcon
	{
		color[] = { 0.78,0,0.05,1 };
		texture = "\Noosphere\X18AoD\Data\church.paa";
		size = 10;
	};
	class Lab : NameIcon
	{
		color[] = { 0.78,0,0.05,1 };
		texture = "\Noosphere\X18AoD\Data\radiotower.paa";
		size = 10;
	};
	class VegetationBroadleaf : NameIcon
	{
		color[] = { 0.25,0.4,0.2,1 };
		texture = "\DZ\gear\navigation\data\map_broadleaf_ca.paa";
		size = 9;
	};
	class VegetationFir : NameIcon
	{
		color[] = { 0.25,0.4,0.2,1 };
		texture = "\DZ\gear\navigation\data\map_fir_ca.paa";
		size = 9;
	};
	class VegetationPalm : NameIcon
	{
		color[] = { 0.25,0.4,0.2,1 };
		texture = "\DZ\gear\navigation\data\map_palm_ca.paa";
		size = 9;
	};
	class VegetationVineyard : NameIcon
	{
		color[] = { 0.25,0.4,0.2,1 };
		texture = "\DZ\gear\navigation\data\map_vineyard_ca.paa";
		size = 9;
	};
};