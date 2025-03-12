
class CfgPatches
{
	class X18LockableDoors
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18LockableDoors
	{
		name = "X18LockableDoors";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18LockableDoors/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18LockableDoors/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18LockableDoors/Scripts/5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class SledgeHammer;
	class Hammer;
	class Inventory_Base;
	class X18_Key_Base : Inventory_Base
	{
		scope = 0;
		weight = 10;
		inventorySlot[] = {};
		rotationFlags = 0;
		displayName = "Key";
		descriptionShort = "";
		animClass = "Knife";
		model = "\dz\gear\tools\Handcuff_Keys.p3d";
		hiddenSelections[] = { "WholeObject" };
		itemSize[] = { 1,1 };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1.0,{"DZ\gear\tools\data\Handcuff_Key.rvmat"}},{0.7,{"DZ\gear\tools\data\Handcuff_Key.rvmat"}},{0.5,{"DZ\gear\tools\data\Handcuff_Key_damage.rvmat"}},{0.3,{"DZ\gear\tools\data\Handcuff_Key_damage.rvmat"}},{0.0,{"DZ\gear\tools\data\Handcuff_Key_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Key_Admin : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (Admin)";
		descriptionShort = "";
	};
	class X18_Key_Loner : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (Loner)";
		descriptionShort = "";
	};
	class X18_Key_Bandit : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (Bratya)";
		descriptionShort = "";
	};
	class X18_Key_ClearSky : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (Clear Sky)";
		descriptionShort = "";
	};
	class X18_Key_Duty : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (Duty)";
		descriptionShort = "";
	};
	class X18_Key_UNISG : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (UNISG)";
		descriptionShort = "";
	};
	class X18_Key_Freedom : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (Freedom)";
		descriptionShort = "";
	};
	class X18_Key_Mercenary : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (Mercenary)";
		descriptionShort = "";
	};
	class X18_Key_Military : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (Military)";
		descriptionShort = "";
	};
	class X18_Key_Monolith : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (Monolith)";
		descriptionShort = "";
	};
	class X18_Key_Sin : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (Sin)";
		descriptionShort = "";
	};
	class X18_Key_Wolf : X18_Key_Base
	{
		scope = 2;
		displayName = "Key (Wolf)";
		descriptionShort = "";
	};
	class X18_Tools_SledgeHammer : SledgeHammer
	{
		scope = 2;
	};
	class X18_Tools_Hammer : Hammer
	{
		scope = 2;
	};
};