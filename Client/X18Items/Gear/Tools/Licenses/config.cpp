class CfgPatches
{
	class X18Items_Licenses
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
	class License_Base : Inventory_Base
	{
		scope = 0;
		displayName = "";
		descriptionShort = "";
		model = "Noosphere\X18Items\Gear\Tools\Licenses\License.p3d";
		weight = 100;
		itemSize[] = { 1,2 };
		rotationFlags = 63;
		hiddenSelections[] = { "vkcomfidovpubllc" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1,{"DZ\gear\food\data\rice.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\food\data\rice_damage.rvmat"}},{0.3,{}},{0,{"DZ\gear\food\data\rice_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Tools_License_L1 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_1";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl1.paa" };
	};
	class X18_Tools_License_L2 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_2";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl2.paa" };
	};
	class X18_Tools_License_L3 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_3";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl3.paa" };
	};
	class X18_Tools_License_L4 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_4";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl4.paa" };
	};
	class X18_Tools_License_L5 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_5";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl5.paa" };
	};
	class X18_Tools_License_L6 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_6";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl6.paa" };
	};
	class X18_Tools_License_Fake_L1 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_1";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl1_fake.paa" };
	};
	class X18_Tools_License_Fake_L2 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_2";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl2_fake.paa" };
	};
	class X18_Tools_License_Fake_L3 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_3";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl3_fake.paa" };
	};
	class X18_Tools_License_Fake_L4 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_4";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl4_fake.paa" };
	};
	class X18_Tools_License_Fake_L5 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_5";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl5_fake.paa" };
	};
	class X18_Tools_License_Fake_L6 : License_Base
	{
		scope = 2;
		displayName = "#STR_License";
		descriptionShort = "#STR_DSC_License_Level_6";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\lvl6_fake.paa" };
	};
	class X18_Tools_HuntingLicense_Beginner : License_Base
	{
		scope = 2;
		displayName = "#STR_HuntingLicense_Beginner";
		descriptionShort = "#STR_DSC_HuntingLicense_Beginner";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\cs_hunting_beginner.paa" };
	};
	class X18_Tools_HuntingLicense_Advanced : License_Base
	{
		scope = 2;
		displayName = "#STR_HuntingLicense_Advanced";
		descriptionShort = "#STR_DSC_HuntingLicense_Advanced";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\cs_hunting_advanced.paa" };
	};
	class X18_Tools_HuntingLicense_Expert : License_Base
	{
		scope = 2;
		displayName = "#STR_HuntingLicense_Expert";
		descriptionShort = "#STR_DSC_HuntingLicense_Expert";
		hiddenSelectionsTextures[] = { "Noosphere\X18Items\Gear\Tools\Licenses\Data\cs_hunting_expert.paa" };
	};
};