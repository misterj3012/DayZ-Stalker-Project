class CfgPatches
{
	class X18Items_Money
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
	class Money_Base : Inventory_Base
	{
		scope = 0;
		model = "Noosphere\X18Items\Gear\Money\Bill.p3d";
		overrideDrawArea = "5.0";
		rotationFlags = 16;
		lootCategory = "Materials";
		lootTag[] = { "Civilian","Work" };
		itemSize[] = { 2,1 };
		weight = 10;
		quantityBar = 0;
		canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 100;
		varQuantityDestroyOnMin = 1;
		destroyOnEmpty = 1;
		isMeleeWeapon = 0;
		absorbency = 1;
		hiddenSelections[] = { "texture" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1,{"Noosphere\X18Items\Gear\Money\Data\bill.rvmat"}},{0.7,{"Noosphere\X18Items\Gear\Money\Data\bill.rvmat"}},{0.5,{"Noosphere\X18Items\Gear\Money\Data\bill_damage.rvmat"}},{0.3,{"Noosphere\X18Items\Gear\Money\Data\bill_damage.rvmat"}},{0,{"Noosphere\X18Items\Gear\Money\Data\bill_destruct.rvmat"}} };
				};
			};
		};
	};
	class Coin_Base : Money_Base
	{
		model = "Noosphere\X18Items\Gear\Money\Coin.p3d";
		itemSize[] = { 1,1 };
	};
	class X18_Ruble_1 : Coin_Base
	{
		scope = 2;
		displayName = "1 Ruble Coin";
		descriptionShort = "This Currency is still in use.";
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 50;
		varQuantityDestroyOnMin = 1;
		destroyOnEmpty = 1;
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_1.paa" };
		hiddenSelectionsMaterials[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_1.rvmat" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1,{"Noosphere\X18Items\Gear\Money\Data\Ruble_1.rvmat"}},{0.7,{"Noosphere\X18Items\Gear\Money\Data\Ruble_1.rvmat"}},{0.5,{"Noosphere\X18Items\Gear\Money\Data\Ruble_1_damage.rvmat"}},{0.3,{"Noosphere\X18Items\Gear\Money\Data\Ruble_1_damage.rvmat"}},{0,{"Noosphere\X18Items\Gear\Money\Data\Ruble_1_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Ruble_2 : Coin_Base
	{
		scope = 2;
		displayName = "2 Ruble Coin";
		descriptionShort = "This Currency is still in use.";
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 50;
		varQuantityDestroyOnMin = 1;
		destroyOnEmpty = 1;
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_2.paa" };
		hiddenSelectionsMaterials[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_2.rvmat" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1,{"Noosphere\X18Items\Gear\Money\Data\Ruble_2.rvmat"}},{0.7,{"Noosphere\X18Items\Gear\Money\Data\Ruble_2.rvmat"}},{0.5,{"Noosphere\X18Items\Gear\Money\Data\Ruble_2_damage.rvmat"}},{0.3,{"Noosphere\X18Items\Gear\Money\Data\Ruble_2_damage.rvmat"}},{0,{"Noosphere\X18Items\Gear\Money\Data\Ruble_2_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Ruble_5 : Money_Base
	{
		scope = 2;
		displayName = "5 Russian Ruble Note";
		descriptionShort = "This Currency is still in use.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_5.paa" };
	};
	class X18_Ruble_10 : Money_Base
	{
		scope = 2;
		displayName = "10 Russian Ruble Note";
		descriptionShort = "This Currency is still in use.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_10.paa" };
	};
	class X18_Ruble_50 : Money_Base
	{
		scope = 2;
		displayName = "50 Russian Ruble Note";
		descriptionShort = "This Currency is still in use.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_50.paa" };
	};
	class X18_Ruble_100 : Money_Base
	{
		scope = 2;
		displayName = "100 Russian Ruble Note";
		descriptionShort = "This Currency is still in use.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_100.paa" };
	};
	class X18_Ruble_200 : Money_Base
	{
		scope = 2;
		displayName = "200 Russian Ruble Note";
		descriptionShort = "This Currency is still in use.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_200.paa" };
	};
	class X18_Ruble_500 : Money_Base
	{
		scope = 2;
		displayName = "500 Russian Ruble Note";
		descriptionShort = "This Currency is still in use.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_500.paa" };
	};
	class X18_Ruble_1000 : Money_Base
	{
		scope = 2;
		displayName = "1000 Russian Ruble Note";
		descriptionShort = "This Currency is still in use.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_1000.paa" };
	};
	class X18_Ruble_2000 : Money_Base
	{
		scope = 2;
		displayName = "2000 Russian Ruble Note";
		descriptionShort = "This Currency is still in use.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_2000.paa" };
	};
	class X18_Ruble_5000 : Money_Base
	{
		scope = 2;
		displayName = "5000 Russian Ruble Note";
		descriptionShort = "This Currency is still in use.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Money\Data\Ruble_5000.paa" };
	};
};