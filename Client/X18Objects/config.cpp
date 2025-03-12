class CfgPatches
{
	class X18Objects
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts", "DayZExpansion_Market_Objects", "DayZExpansion_Market_Scripts" };
	};
};

class CfgMods
{
	class X18Objects
	{
		name = "X18Objects";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };

		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Objects/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Objects/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Objects/Scripts/5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class X18_Floating_Stone1 : HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\rocks\stone1.p3d";
	};
	class X18_Floating_Stone2 : HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\rocks\stone2.p3d";
	};
	class X18_Floating_Stone3 : HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\rocks\stone3.p3d";
	};
	class X18_Floating_Stone4 : HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\rocks\stone4.p3d";
	};
	class X18_Floating_Stone5 : HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\rocks\stone5.p3d";
	};
	class X18_Floating_Stone6 : HouseNoDestruct
	{
		scope = 1;
		model = "DZ\rocks_bliss\stone6.p3d";
	};
	class X18_Floating_Stone7 : HouseNoDestruct
	{
		scope = 1;
		model = "DZ\rocks_bliss\stone7.p3d";
	};
	class X18_Floating_Wreck_BMP : HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\wrecks\vehicles\wreck_bmp2.p3d";
	};
	class Land_Train_vagon11;
	class X18_Floating_Wagon : Land_Train_vagon11
	{
		scope = 1;
	};
	class X18_Floating_Cordon_Wagon : Land_Train_vagon11
	{
		scope = 1;
	};
	class Land_Wreck_Lada_Green;
	class X18_Floating_Lada_Green : Land_Wreck_Lada_Green
	{
		scope = 1;
	};
	class Land_Wreck_Lada_Red;
	class X18_Floating_Lada_Red : Land_Wreck_Lada_Red
	{
		scope = 1;
	};
	class X18_Floating_Trash_1 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_1.p3d";
	};
	class X18_Floating_Trash_2 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_2.p3d";
	};
	class X18_Floating_Trash_3 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_3.p3d";
	};
	class X18_Floating_Trash_4 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_4.p3d";
	};
	class X18_Floating_Trash_5 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_5.p3d";
	};
	class X18_Floating_Trash_6 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_6.p3d";
	};
	class X18_Floating_Trash_7 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_7.p3d";
	};
	class X18_Floating_Trash_8 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_8.p3d";
	};
	class X18_Floating_Trash_9 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_9.p3d";
	};
	class X18_Floating_Trash_10 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_10.p3d";
	};
	class X18_Floating_Trash_11 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_11.p3d";
	};
	class X18_Floating_Trash_12 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_12.p3d";
	};
	class X18_Floating_Trash_13 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_13.p3d";
	};
	class X18_Floating_Trash_14 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_14.p3d";
	};
	class X18_Floating_Trash_15 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_15.p3d";
	};
	class X18_Floating_Trash_16 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_16.p3d";
	};
	class X18_Floating_Trash_17 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_17.p3d";
	};
	class X18_Floating_Trash_18 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_18.p3d";
	};
	class X18_Floating_Trash_19 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_19.p3d";
	};
	class X18_Floating_Trash_20 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_20.p3d";
	};
	class X18_Floating_Trash_21 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_21.p3d";
	};
	class X18_Floating_Trash_22 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_22.p3d";
	};
	class X18_Floating_Trash_23 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_23.p3d";
	};
	class X18_Floating_Trash_24 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_24.p3d";
	};
	class X18_Floating_Trash_25 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_25.p3d";
	};
	class X18_Floating_Trash_26 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_26.p3d";
	};
	class X18_Floating_Trash_27 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_27.p3d";
	};
	class X18_Floating_Trash_28 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_28.p3d";
	};
	class X18_Floating_Trash_29 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_29.p3d";
	};
	class X18_Floating_Trash_30 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_30.p3d";
	};
	class X18_Floating_Trash_31 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_31.p3d";
	};
	class X18_Floating_Trash_32 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_32.p3d";
	};
	class X18_Floating_Trash_33 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_33.p3d";
	};
	class X18_Floating_Trash_34 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_34.p3d";
	};
	class X18_Floating_Trash_35 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_35.p3d";
	};
	class X18_Floating_Trash_36 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_36.p3d";
	};
	class X18_Floating_Trash_37 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_37.p3d";
	};
	class X18_Floating_Trash_38 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trash\trash_38.p3d";
	};
	class Land_mi24_2;
	class X18_Wreck_Mi24_1 : Land_mi24_2
	{
		scope = 1;
	};
	class Land_mi24_repairs;
	class X18_Wreck_Mi24_2 : Land_mi24_repairs
	{
		scope = 1;
	};
	class X18_Anomaly_Oakpine : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Anomaly\Oakpine.p3d";
	};
	class X18_Trees_Swamp_1 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trees\Swamp_Tree_1.p3d";
	};
	class X18_Trees_Swamp_2 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trees\Swamp_Tree_2.p3d";
	};
	class X18_Trees_Swamp_3 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trees\Swamp_Tree_3.p3d";
	};
	class X18_Trees_Swamp_4 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Trees\Swamp_Tree_4.p3d";
	};
	class X18_Sink : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Sink\Sink.p3d";
	};
	class X18_Console : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Console\Console.p3d";
	};
	class X18_Console_2 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Console\Console_2.p3d";
	};
	class X18_SwitchCabinet : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\SwitchCabinet\SwitchCabinet.p3d";
	};
	class X18_SwitchCabinet_2 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\SwitchCabinet\SwitchCabinet_2.p3d";
	};
	class X18_Growth : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Growth\Growth.p3d";
	};
	class X18_Growth_Big : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Growth\Growth_Big.p3d";
	};
	class X18_Growth_1 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Growth\Growth_2.p3d";
	};
	class X18_Growth_1_Big : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Growth\Growth_2_Big.p3d";
	};
	class X18_Growth_2 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Growth\Growth_3.p3d";
	};
	class X18_Growth_2_Big : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Growth\Growth_3_Big.p3d";
	};
	class X18_Growth_3 : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Growth\Growth_4.p3d";
	};
	class X18_Growth_3_Big : HouseNoDestruct
	{
		scope = 1;
		model = "\Noosphere\X18Objects\Data\Growth\Growth_4_Big.p3d";
	};
	class X18_ClutterCutter1x1 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\ClutterCutter\GrassCutter1x1.p3d";
	};
	class X18_ClutterCutter2x1 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\ClutterCutter\GrassCutter2x1.p3d";
	};
	class X18_ClutterCutter2x2 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\ClutterCutter\GrassCutter2x2.p3d";
	};
	class X18_ClutterCutter4x2 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\ClutterCutter\GrassCutter4x2.p3d";
	};
	class X18_ClutterCutter4x4 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\ClutterCutter\GrassCutter4x4.p3d";
	};
	class X18_ClutterCutter6x3 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\ClutterCutter\GrassCutter6x3.p3d";
	};
	class X18_ClutterCutter6x6 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\ClutterCutter\GrassCutter6x6.p3d";
	};
	class X18_ClutterCutter8x4 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\ClutterCutter\GrassCutter8x4.p3d";
	};
	class X18_ClutterCutter8x8 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\ClutterCutter\GrassCutter8x8.p3d";
	};
	class X18_ClutterCutter10x5 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\ClutterCutter\GrassCutter10x5.p3d";
	};
	class X18_ClutterCutter10x10 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\ClutterCutter\GrassCutter10x10.p3d";
	};
	class X18_AnomalousPlant_Small : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\AnomalousPlant\AnomalousPlant_Small.p3d";
	};
	class X18_AnomalousPlant_Medium : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\AnomalousPlant\AnomalousPlant_Medium.p3d";
	};
	class X18_AnomalousPlant_Big : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\AnomalousPlant\AnomalousPlant_Big.p3d";
	};
	class X18_AnomalousPlant_Tall : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\AnomalousPlant\AnomalousPlant_Tall.p3d";
	};
	class X18_Platform : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Platforms\dz_platform.p3d";
	};
	class X18_Platform_slim : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Platforms\dz_platform_slim.p3d";
	};
	class X18_Platform_slim_d : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Platforms\dz_platform_slim_d.p3d";
	};
	class X18_Wall_dr_1 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_dr_1.p3d";
	};
	class X18_Wall_dr_2 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_dr_2.p3d";
	};
	class X18_Wall_dr_3 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_dr_3.p3d";
	};
	class X18_Wall_dr_4 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_dr_4.p3d";
	};
	class X18_Wall_dr_5 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_dr_5.p3d";
	};
	class X18_Wall_dr_6 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_dr_6.p3d";
	};
	class X18_Wall_ent_1 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_ent_1.p3d";
	};
	class X18_Wall_ent_2 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_ent_2.p3d";
	};
	class X18_Wall_ent_3 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_ent_3.p3d";
	};
	class X18_Wall_ent_4 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_ent_4.p3d";
	};
	class X18_Wall_ent_5 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_ent_5.p3d";
	};
	class X18_Wall_ent_6 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_ent_6.p3d";
	};
	class X18_Wall_gu_1 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_gu_1.p3d";
	};
	class X18_Wall_gu_2 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_gu_2.p3d";
	};
	class X18_Wall_gu_3 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_gu_3.p3d";
	};
	class X18_Wall_gu_4 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_gu_4.p3d";
	};
	class X18_Wall_gu_5 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_gu_5.p3d";
	};
	class X18_Wall_gu_6 : HouseNoDestruct
	{
		scope = 1;
		model = "Noosphere\X18Objects\Data\Walls\dz_wall_gu_6.p3d";
	};
};