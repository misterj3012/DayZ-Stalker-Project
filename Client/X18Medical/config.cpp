class CfgPatches
{
	class X18Medical
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18Medical
	{
		name = "X18Medical";
		credits = "Katha";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] =
				{ "Noosphere\X18Medical\scripts\3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] =
				{ "Noosphere\X18Medical\scripts\4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] =
				{ "Noosphere\X18Medical\scripts\5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class X18_Meds_MediKit_Tier1 : Inventory_Base
	{
		scope = 2;
		displayName = "Ziviles MediKit";
		descriptionShort = "Das AI-2 Erste-Hilfe-Set wurde als Standard für verschiedene Verteidigungs-, Strafverfolgungs- und zivile Verteidigungsstreitkräfte der UdSSR entwickelt. Im Falle eines totalen Krieges und der Benutzung von Massenvernichtungswaffen sollte das AI-2 an die Bevölkerung der betroffenen Gebiete verteilt werden. Dient der Behandlung von Verletzungen verschiedener Art und Schweregrade - Wunden, Verbrennungen, Vergiftungen und ähnliches.";
		model = "Noosphere\X18Medical\Data\Medikit\Medikit.p3d";
		itemSize[] = { 2,2 };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Medical\Data\Medikit\Medikit_orange_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] =
					{
						{ 1, { "Noosphere\X18Medical\Data\Medikit\Medikit.rvmat" } },

						{ 0.69999999, { "Noosphere\X18Medical\Data\Medikit\Medikit.rvmat" } },

						{ 0.5, { "Noosphere\X18Medical\Data\Medikit\Medikit_damage.rvmat" } },

						{ 0.30000001, { "Noosphere\X18Medical\Data\Medikit\Medikit_damage.rvmat" } },

						{ 0, { "Noosphere\X18Medical\Data\Medikit\Medikit_destruct.rvmat" } }
					};
				};
			};
		};
		class AnimationSources
		{
			class lid
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class compass_open
				{
					soundSet = "compass_open_SoundSet";
					id = 204;
				};
				class compass_close
				{
					soundSet = "compass_close_SoundSet";
					id = 205;
				};
			};
		};
	};
	class X18_Meds_MediKit_Tier2 : X18_Meds_MediKit_Tier1
	{
		scope = 2;
		displayName = "Millitärisches MediKit";
		descriptionShort = "Ein weiterentwickeltes Erste-Hilfe-Set entworfen um körperliche Verletzungen und Blutverlust zu bekämpfen, enthält medizinische Präparate zur Unterstützung der Blutgerinnung, zur Immunstimulation, Anitbiotika und Schmerzmittel. Diese Art von Erste-Hilfe-Sets werden insbesondere von Angehörigen des Militärs verwendet.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Medical\Data\Medikit\Medikit_blue_co.paa" };
	};
	class X18_Meds_MediKit_Tier3 : X18_Meds_MediKit_Tier1
	{
		scope = 2;
		displayName = "Wissenschaftliches MediKit";
		descriptionShort = "Wissenschatfliches Erste-Hilfe-Set speziell entworfen für die Nutzung in der Sperrzone von Chernobyl. Dieses Set beinhaltet medizinische Bestandteile zum Stoppen von Blutungen, Behandeln von Verbrennungen, Reinigen von Wunden und zum Therapieren einer Vielzahl verschiedener Verletzungen. Es beinhaltet außerdem Mittel zur Behandlung von Strahlenbelastung und Kontamination.";
		hiddenSelectionsTextures[] = { "Noosphere\X18Medical\Data\Medikit\Medikit_yellow_co.paa" };
	};
	class SodaCan_ColorBase;
	class X18_EnergyStalker : SodaCan_ColorBase
	{
		scope = 2;
		displayName = "Stalker Energy Drink";
		descriptionShort = "Wird oft von Stalkern auf langen Reisen verwendet, wenn keine Pausen möglich sind. Das Getränk enthält leicht verdauliche Kohlenhydrate sowie Medikamente, die die Freisetzung von Adrenalin in den Blutkreislauf anregen.";
		model = "Noosphere\X18Medical\Data\EnergyDrink\EnergyStalker.p3d";
		debug_ItemCategory = 6;
		stackedRandom = 0;
		itemSize[] = { 1,2 };
		weight = 15;
		stackedUnit = "";
		varQuantityInit = 300;
		varQuantityMin = 0;
		varQuantityMax = 300;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] =
					{
						{ 1, { "Noosphere\X18Medical\Data\EnergyDrink\EnergyStalker.rvmat" } },

						{ 0.69999999, { "Noosphere\X18Medical\Data\EnergyDrink\EnergyStalker.rvmat" } },

						{ 0.5, { "Noosphere\X18Medical\Data\EnergyDrink\EnergyStalker_damage.rvmat" } },

						{ 0.30000001, { "Noosphere\X18Medical\Data\EnergyDrink\EnergyStalker_damage.rvmat" } },

						{ 0, { "Noosphere\X18Medical\Data\EnergyDrink\EnergyStalker_destruct.rvmat" } }
					};
				};
			};
		};
		class Nutrition
		{
			totalVolume = 1;
			energy = 0;
			water = 10;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet = "SodaCan_in_B_SoundSet";
					id = 202;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
				class pickup
				{
					soundSet = "SodaCan_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SodaCan_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Morphine;
	class X18_Meds_Mexamin_Injector : Morphine
	{
		scope = 2;
		displayName = "Mexamin Injector";
		descriptionShort = "Eine hochkonzentrierte, schnell wirkende Form des Mexamin-Strahlenschutzmittels, welches in Notfällen bei einer starken Kontamination intravenös verabreicht werden kann. Mexamin-Strahlenschutzmittel sind in der Zone weit verbreitet. Bei der Anwendung dieses Medikaments kommt es zu einer Kontraktion der peripheren Blutgefäße und einem Sauerstoffentzug, was der Behandlung und Vorbeugung der Strahlenbelastung dient. Das Medikament hat keine schwerwiegenden Nebenwirkungen, obwohl vereinzelte Fälle von leichter Übelkeit, Schwindel, Krämpfen und Magenschmerzen gemeldet wurden.";
		model = "\dz\gear\medical\Morphine.p3d";
		rotationFlags = 17;
		itemSize[] = { 1,2 };
		weight = 60;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "Noosphere\X18Medical\Data\Injector\Mexamine_co.paa" };
	};
	class Edible_Base;
	class X18_Meds_AntiRad : Edible_Base
	{
		scope = 2;
		displayName = "Mexamine";
		descriptionShort = "Das Strahlenschutzmittel Mexamin ist in der Zone weit verbreitet. Bei der Anwendung dieses Medikaments kommt es zu einer Kontraktion der peripheren Blutgefäße und zu einem Sauerstoffentzug, was der Behandlung und Vorbeugung einer Strahlenbelastung dient. Das Medikament hat keine schwerwiegenden Nebenwirkungen, obwohl vereinzelte Fälle von leichter Übelkeit, Schwindel, Krämpfen und Magenschmerzen berichtet worden sind.";
		model = "FS_3_Items\dev_antirad\dev_antirad.p3d";
		varQuantityInit = 25;
		varQuantityMin = 0;
		varQuantityMax = 25;
		varQuantityDestroyOnMin = 1;
		canBeSplit = 1;
		itemSize[] = { 1,2 };
		weight = 50;
		stackedUnit = "pills";
		quantityBar = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = { {1.0,{"DZ\gear\medical\data\tetracycline.rvmat"}},{0.7,{"DZ\gear\medical\data\tetracycline.rvmat"}},{0.5,{"DZ\gear\medical\data\tetracycline_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\tetracycline_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\tetracycline_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Meds_RadioProtectant : Edible_Base
	{
		scope = 2;
		displayName = "B190 Indraline";
		descriptionShort = "B190 Indralin-Strahlenschutzmittel, das in den Medkits enthalten ist, die an das Personal von Kernkraftwerken ausgegeben werden. Wird in der Zone anstelle des übermäßig giftigen Cystaminhydrochlorids PC1 verwendet, dessen wiederholte Anwendung häufig zum Tod führte. Reduziert die Auswirkungen von Gammastrahlung auf lebendes Gewebe. Am besten vor der Exposition konsumieren, da die Wirkung nicht sofort eintritt. Die Wirkung der Droge ist lang anhaltend.";
		model = "Noosphere\X18Ecology\Data\B190.p3d";
		varQuantityInit = 10;
		varQuantityMin = 0;
		varQuantityMax = 10;
		varQuantityDestroyOnMin = 1;
		canBeSplit = 1;
		itemSize[] = { 1,2 };
		weight = 75;
		stackedUnit = "pills";
		quantityBar = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = { {1.0,{"DZ\gear\medical\data\tetracycline.rvmat"}},{0.7,{"DZ\gear\medical\data\tetracycline.rvmat"}},{0.5,{"DZ\gear\medical\data\tetracycline_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\tetracycline_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\tetracycline_destruct.rvmat"}} };
				};
			};
		};
	};
	class X18_Meds_PC1 : Edible_Base
	{
		scope = 2;
		displayName = "PC1 Cystamine Hydrochloride";
		descriptionShort = "PC1 Cystaminhydrochlorids-Strahlenschutzmittel, ist im Gegensatz zu B190 Indralin übermäßig giftig doch besitzt es einen höheren wirkungsgrad. Dessen wiederholte Anwendung führt oft zum Tod des Konsumenten und es ist deswegen nur in Ausnahmefällen einzunehmen. Reduziert die Auswirkungen von Gammastrahlung auf lebendes Gewebe. Am besten vor der Exposition konsumieren, da die Wirkung nicht sofort eintritt. Die Wirkung der Droge ist lang anhaltend.";
		model = "FS_3_Items\antibiotics\antibiotics.p3d";
		varQuantityInit = 5;
		varQuantityMin = 0;
		varQuantityMax = 5;
		varQuantityDestroyOnMin = 1;
		canBeSplit = 1;
		itemSize[] = { 1,2 };
		weight = 75;
		stackedUnit = "pills";
		quantityBar = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = { {1.0,{"DZ\gear\medical\data\tetracycline.rvmat"}},{0.7,{"DZ\gear\medical\data\tetracycline.rvmat"}},{0.5,{"DZ\gear\medical\data\tetracycline_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\tetracycline_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\tetracycline_destruct.rvmat"}} };
				};
			};
		};
	};
};