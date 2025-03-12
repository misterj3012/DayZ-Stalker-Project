class CfgPatches
{
	class X18PersonalChest
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18PersonalChest
	{
		name = "X18PersonalChest";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18PersonalChest/Scripts/Common", "Noosphere/X18PersonalChest/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18PersonalChest/Scripts/Common", "Noosphere/X18PersonalChest/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18PersonalChest/Scripts/Common", "Noosphere/X18PersonalChest/Scripts/5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class Container_Base;
	class X18_PersonalChest_Base : HouseNoDestruct
	{
		scope = 0;
		displayName = "";
		descriptionShort = "";
		model = "\DZ\gear\camping\sea_chest.p3d";
		hologramMaterial = "sea_chest";
		hologramMaterialPath = "dz\gear\camping\data";
		slopeTolerance = 0.4;
		yawPitchRollLimit[] = { 45,45,45 };
		weight = 10000;
		itemBehaviour = 0;
		itemSize[] = { 10,10 };
		carveNavmesh = 1;
		canBeDigged = 1;
		rotationFlags = 2;
		hiddenSelections[] = { "camoGround" };
		hiddenSelectionsTextures[] = { "\dz\gear\camping\data\sea_chest_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = { {1,{"DZ\gear\camping\data\sea_chest.rvmat"}},{0.7,{"DZ\gear\camping\data\sea_chest.rvmat"}},{0.5,{"DZ\gear\camping\data\sea_chest_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\sea_chest_damage.rvmat"}},{0,{"DZ\gear\camping\data\sea_chest_destruct.rvmat"}} };
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage = 8;
					};
					class Blood
					{
						damage = 8;
					};
					class Shock
					{
						damage = 8;
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "seachest_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "seachest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class X18_PersonalChest_Army_Box : X18_PersonalChest_Base
	{
		scope = 2;
		model = "\mmg_storage\data\crates\army_box.p3d";
		hiddenSelections[] = { "camo","decals" };
		hiddenSelectionsTextures[] = { "mmg_storage\data\crates\army_box\army_box_green.paa","mmg_storage\data\crates\army_box\army_box_decals.paa" };
	};
	class X18_PersonalChest_Army_Case : X18_PersonalChest_Base
	{
		scope = 2;
		model = "\mmg_storage\data\crates\military_case.p3d";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "mmg_storage\data\crates\military_case\military_case_green.paa" };
	};
	class X18_PersonalChest_MetalCrate_Black : X18_PersonalChest_Base
	{
		scope = 2;
		model = "\mmg_storage\data\crates\crate04.p3d";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "mmg_storage\data\crates\crate04\crate04_black.paa" };
	};
	class X18_PersonalChest_MetalCrate_Blue : X18_PersonalChest_Base
	{
		scope = 2;
		model = "\mmg_storage\data\crates\crate04.p3d";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "mmg_storage\data\crates\crate04\crate04_blue.paa" };
	};
	class X18_PersonalChest_MetalCrate_Olive : X18_PersonalChest_Base
	{
		scope = 2;
		model = "\mmg_storage\data\crates\crate04.p3d";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "mmg_storage\data\crates\crate04\crate04_olive.paa" };
	};
	class X18_PersonalChest_MetalCrate_Red : X18_PersonalChest_Base
	{
		scope = 2;
		model = "\mmg_storage\data\crates\crate04.p3d";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "mmg_storage\data\crates\crate04\crate04_red.paa" };
	};
	class X18_PersonalChest_MetalCrate_Yellow : X18_PersonalChest_Base
	{
		scope = 2;
		model = "\mmg_storage\data\crates\crate04.p3d";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "mmg_storage\data\crates\crate04\crate04_yellow.paa" };
	};
	class X18_PersonalChest_Palette : X18_PersonalChest_Base
	{
		scope = 2;
		model = "\mmg_storage\data\crates\palette_storage.p3d";
		hiddenSelections[] = { "straps","plain","palette","net" };
		hiddenSelectionsTextures[] = { "mmg_storage\data\crates\palette_storage\palette_storage_straps.paa","mmg_storage\data\crates\palette_storage\palette_storage_plain.paa","mmg_storage\data\crates\palette_storage\palette_storage_palette.paa","DZ\structures\military\improvised\data\camonet_east_co.paa" };
	};
	class X18_PersonalChest_SeaChest : X18_PersonalChest_Base
	{
		scope = 2;
		model = "\DZ\gear\camping\sea_chest.p3d";
		hiddenSelections[] = { "camoGround" };
		hiddenSelectionsTextures[] = { "\dz\gear\camping\data\sea_chest_co.paa" };
	};
	class X18_PersonalChest_SupplyCrate_Wood : X18_PersonalChest_Base
	{
		scope = 2;
		model = "\mmg_storage\data\crates\crate03.p3d";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "mmg_storage\data\crates\crate03\crate03_wood.paa" };
	};
	class X18_PersonalChest_SupplyCrate_Blue : X18_PersonalChest_Base
	{
		scope = 2;
		model = "\mmg_storage\data\crates\crate03.p3d";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "mmg_storage\data\crates\crate03\crate03_blue.paa" };
	};
	class PersonalChest : Container_Base
	{
		scope = 0;
		displayName = "$STR_Personal_Chest";
		descriptionShort = "$STR_Personal_Chest_Desc";
		model = "\DZ\gear\camping\sea_chest.p3d";
		hologramMaterial = "sea_chest";
		hologramMaterialPath = "dz\gear\camping\data";
		slopeTolerance = 0.4;
		yawPitchRollLimit[] = { 45,45,45 };
		weight = 10000;
		itemBehaviour = 0;
		itemSize[] = { 10,10 };
		carveNavmesh = 1;
		canBeDigged = 1;
		rotationFlags = 2;
		hiddenSelections[] = { "camoGround" };
		hiddenSelectionsTextures[] = { "\dz\gear\camping\data\sea_chest_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = { {1,{"DZ\gear\camping\data\sea_chest.rvmat"}},{0.7,{"DZ\gear\camping\data\sea_chest.rvmat"}},{0.5,{"DZ\gear\camping\data\sea_chest_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\sea_chest_damage.rvmat"}},{0,{"DZ\gear\camping\data\sea_chest_destruct.rvmat"}} };
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage = 8;
					};
					class Blood
					{
						damage = 8;
					};
					class Shock
					{
						damage = 8;
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = { 5,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "seachest_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "seachest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class PersonalChestDefault : PersonalChest
	{
		scope = 2;
		attachments[] = { "Rent" };
		class Cargo
		{
			itemsCargoSize[] = { 5,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_25_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 5,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_25_Guns : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee" };
		class Cargo
		{
			itemsCargoSize[] = { 5,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_25_Guns_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 5,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_25_Guns2 : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder" };
		class Cargo
		{
			itemsCargoSize[] = { 5,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_25_Guns2_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 5,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_50 : PersonalChestDefault
	{
		class Cargo
		{
			itemsCargoSize[] = { 10,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_50_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_50_Guns : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee" };
		class Cargo
		{
			itemsCargoSize[] = { 10,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_50_Guns_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_50_Guns2 : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder" };
		class Cargo
		{
			itemsCargoSize[] = { 10,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_50_Guns2_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,5 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_75 : PersonalChestDefault
	{
		class Cargo
		{
			itemsCargoSize[] = { 5,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_75_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 5,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_75_Guns : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee" };
		class Cargo
		{
			itemsCargoSize[] = { 5,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_75_Guns_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 5,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_75_Guns2 : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder" };
		class Cargo
		{
			itemsCargoSize[] = { 5,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_75_Guns2_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 5,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_100 : PersonalChestDefault
	{
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_100_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_100_Guns : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee" };
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_100_Guns_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_100_Guns2 : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder" };
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_100_Guns2_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,10 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_150 : PersonalChestDefault
	{
		class Cargo
		{
			itemsCargoSize[] = { 10,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_150_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_150_Guns : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee" };
		class Cargo
		{
			itemsCargoSize[] = { 10,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_150_Guns_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_150_Guns2 : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder" };
		class Cargo
		{
			itemsCargoSize[] = { 10,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_150_Guns2_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,15 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_200 : PersonalChestDefault
	{
		class Cargo
		{
			itemsCargoSize[] = { 10,20 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_200_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,20 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_200_Guns : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee" };
		class Cargo
		{
			itemsCargoSize[] = { 10,20 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_200_Guns_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,20 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_200_Guns2 : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder" };
		class Cargo
		{
			itemsCargoSize[] = { 10,20 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PersonalChest_200_Guns2_Clothes : PersonalChestDefault
	{
		attachments[] = { "Rent","Melee","Shoulder","Headgear","Vest","Body","Legs","Back" };
		class Cargo
		{
			itemsCargoSize[] = { 10,20 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
};
class CfgSlots
{
	class Slot_Rent
	{
		name = "Rent";
		displayName = "Miete";
		ghostIcon = "set:dayz_inventory image:cat_fp_upgrade";
	};
};