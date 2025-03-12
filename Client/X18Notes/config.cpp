class CfgPatches
{
	class X18Notes
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18Notes
	{
		name = "X18Notes";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Notes/Scripts/Common", "Noosphere/X18Notes/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Notes/Scripts/Common", "Noosphere/X18Notes/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18Notes/Scripts/Common", "Noosphere/X18Notes/Scripts/5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Paper : Inventory_Base
	{
		canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 5;
		varStackMax = 5;
		varQuantityDestroyOnMin = 1;
	};
	class X18_Note : Paper
	{
		scope = 2;
		model = "\dz\gear\consumables\Paper.p3d";
		displayName = "$STR_X18NoteTxt";
		descriptionShort = "$STR_X18NoteDesc";
		canBeSplit = 0;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 1;
		varStackMax = 1;
	};
	class Pen_ColorBase
	{
		quantityBar = 1;
		varQuantityInit = 100;
		varQuantityMin = 0;
		varQuantityMax = 100;
		stackedUnit = "percentage";
	};
	class Pen_Black : Pen_ColorBase
	{
		scope = 2;
		displayName = "$STR_X18Pen_Black";
		penColor[] = { 10,10,10 };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Notes\Data\Textures\loot_pen_black_co.paa" };
	};
	class Pen_Red : Pen_ColorBase
	{
		scope = 2;
		displayName = "$STR_X18Pen_Red";
		penColor[] = { 200,20,20 };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Notes\Data\Textures\loot_pen_red_co.paa" };
	};
	class Pen_Green : Pen_ColorBase
	{
		scope = 2;
		displayName = "$STR_X18Pen_Green";
		penColor[] = { 24,150,24 };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Notes\Data\Textures\loot_pen_green_co.paa" };
	};
	class Pen_Blue : Pen_ColorBase
	{
		scope = 2;
		displayName = "$STR_X18Pen_Blue";
		penColor[] = { 0,65,200 };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Notes\Data\Textures\loot_pen_blue_co.paa" };
	};
	class Pen_Pink : Pen_ColorBase
	{
		scope = 2;
		displayName = "$STR_X18Pen_Pink";
		penColor[] = { 255,0,162 };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Notes\Data\Textures\loot_pen_pink_co.paa" };
	};
	class Pen_Purple : Pen_ColorBase
	{
		scope = 2;
		displayName = "$STR_X18Pen_Purple";
		penColor[] = { 144,0,255 };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Notes\Data\Textures\loot_pen_purple_co.paa" };
	};
	class Pen_Orange : Pen_ColorBase
	{
		scope = 2;
		displayName = "$STR_X18Pen_Orange";
		penColor[] = { 255,150,0 };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Notes\Data\Textures\loot_pen_orange_co.paa" };
	};
};