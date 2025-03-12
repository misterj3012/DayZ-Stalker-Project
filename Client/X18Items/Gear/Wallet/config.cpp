class CfgPatches
{
	class X18Items_Wallet
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Food" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class X18_Wallet_Base : Inventory_Base
	{
		scope = 0;
		displayName = "$STR_Wallet";
		descriptionShort = "$STR_Wallet_DSC";
		model = "Noosphere\X18Items\Gear\Wallet\Wallet_1.p3d";
		weight = 250;
		itemSize[] = { 1,1 };
		itemsCargoSize[] = { 6,4 };
		canBeDigged = 0;
		allowOwnedCargoManipulation = 1;
		hiddenSelections[] = { "camo" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = { {1.01,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_1.rvmat"}},{0.7,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_1.rvmat"}},{0.5,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_1.rvmat"}},{0.3,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_1_damage.rvmat"}},{0.1,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_1_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Wallet_1_Black : X18_Wallet_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Wallet\Data\Wallet_1_black_co.paa" };
	};
	class X18_Wallet_1_Blue : X18_Wallet_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Wallet\Data\Wallet_1_blue_co.paa" };
	};
	class X18_Wallet_1_Brown : X18_Wallet_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Wallet\Data\Wallet_1_brown_co.paa" };
	};
	class X18_Wallet_2_Brown : X18_Wallet_Base
	{
		scope = 2;
		model = "Noosphere\X18Items\Gear\Wallet\Wallet_2.p3d";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Wallet\Data\Wallet_2_brown_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = { {1.01,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_2.rvmat"}},{0.7,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_2.rvmat"}},{0.5,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_2.rvmat"}},{0.3,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_2_damage.rvmat"}},{0.1,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_2_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Wallet_3_Beige : X18_Wallet_Base
	{
		scope = 2;
		model = "Noosphere\X18Items\Gear\Wallet\Wallet_3.p3d";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Wallet\Data\Wallet_3_beige_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = { {1.01,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_3.rvmat"}},{0.7,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_3.rvmat"}},{0.5,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_3.rvmat"}},{0.3,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_3_damage.rvmat"}},{0.1,{"Noosphere\X18Items\Gear\Wallet\Data\Wallet_3_destruct.rvmat"}} };
				};
			};
		};
	};
};