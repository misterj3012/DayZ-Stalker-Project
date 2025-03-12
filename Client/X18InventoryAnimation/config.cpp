class CfgPatches
{
	class X18InventoryAnimation
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18InventoryAnimation
	{
		name = "X18InventoryAnimation";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18InventoryAnimation/Scripts/Common", "Noosphere/X18InventoryAnimation/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18InventoryAnimation/Scripts/Common", "Noosphere/X18InventoryAnimation/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18InventoryAnimation/Scripts/Common", "Noosphere/X18InventoryAnimation/Scripts/5_Mission" };
			};
		};
	};
};