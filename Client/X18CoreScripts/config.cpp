class CfgPatches
{
	class X18CoreScripts
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "JM_CF_Scripts", "ModularVestSystem", "mmg_storage", "JPC_Vest" };
	};
};
class CfgMods
{
	class X18CoreScripts
	{
		dir = "X18CoreScripts";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "X18CoreScripts";
		author = "MisterJ";
		version = "1.0";
		extra = 0;
		dependencies[] = { "Core", "Game","World","Mission" };
		type = "mod";
		inputs = "Noosphere\X18CoreScripts\Data\Inputs.xml";
		class defs
		{
			class engineScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18CoreScripts/Scripts/1_Core" };
			};
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18CoreScripts/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18CoreScripts/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18CoreScripts/Scripts/5_Mission" };
			};
		};
	};
};
class cfgVehicles
{
	class AllVehicles;
	class Man : AllVehicles {};
	class SurvivorBase : Man
	{
		class Skinning
		{
			class Steaks
			{
				item = "HumanSteakMeat";
				count = 0;
				quantityMinMaxCoef[] = { 0.0,0 };
			};
			class Guts
			{
				item = "Guts";
				count = 0;
				quantityMinMaxCoef[] = { 0.0,0.0 };
			};
			class Lard
			{
				item = "Lard";
				count = 0;
				quantityMinMaxCoef[] = { 0.0,0 };
			};
			class Bones
			{
				item = "Bone";
				count = 0;
				quantityMinMaxCoef[] = { 0.0,0 };
			};
		};
	};
	class DamageSystem
	{
		class GlobalHealth
		{
			class Health
			{
				hitpoints = 100;
				healthLevels[] = { {1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}} };
			};
			class Blood
			{
				hitpoints = 5000;
			};
			class Shock
			{
				hitpoints = 100;
			};
		};
		class DamageZones
		{
			class Head
			{
				class Health
				{
					hitpoints = 100;
					transferToGlobalCoef = 2;
				};
				class Blood
				{
					hitpoints = 100;
					transferToGlobalCoef = 0;
				};
				class Shock
				{
					hitpoints = 0;
					transferToGlobalCoef = 1;
				};
				class ArmorType
				{
					class Projectile
					{
						class Health
						{
							damage = 1;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 3;
						};
					};
					class Melee
					{
						class Health
						{
							damage = 0.5;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 1;
						};
					};
					class Infected
					{
						class Health
						{
							damage = 0.5;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 1;
						};
					};
				};
				componentNames[] = { "dmgZone_head" };
				fatalInjuryCoef = 0.1;
				inventorySlots[] = { "Headgear","Mask","Eyewear" };
				inventorySlotsCoefs[] = { 1.0,1.0,0.5 };
			};
			class Brain
			{
				class Health
				{
					hitpoints = 100;
					transferToGlobalCoef = 1;
				};
				class Blood
				{
					hitpoints = 100;
					transferToGlobalCoef = 0;
				};
				class Shock
				{
					hitpoints = 0;
					transferToGlobalCoef = 1;
				};
				class ArmorType
				{
					class Melee
					{
						class Health
						{
							damage = 0;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 1;
						};
					};
					class Projectile
					{
						class Health
						{
							damage = 1;
						};
						class Blood
						{
							damage = 0;
						};
						class Shock
						{
							damage = 0;
						};
					};
					class FragGrenade
					{
						class Health
						{
							damage = 0;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 1;
						};
					};
				};
				componentNames[] = { "dmgZone_brain" };
				fatalInjuryCoef = 1;
			};
			class Torso
			{
				class Health
				{
					hitpoints = 100;
					transferToGlobalCoef = 1.0;
				};
				class Blood
				{
					hitpoints = 100;
					transferToGlobalCoef = 0;
				};
				class Shock
				{
					hitpoints = 0;
					transferToGlobalCoef = 1;
				};
				class ArmorType
				{
					class Projectile
					{
						class Health
						{
							damage = 1;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 1;
						};
					};
				};
				componentNames[] = { "dmgZone_torso","dmgZone_lungs","dmgZone_spine","dmgZone_liver","dmgZone_heart" };
				fatalInjuryCoef = -1;
				inventorySlots[] = { "Vest","Body","Back","Hips" };
				inventorySlotsCoefs[] = { 1.0,1.0,0.5,0.35 };
			};
			class LeftArm
			{
				class Health
				{
					hitpoints = 100;
					transferToGlobalCoef = 0.1;
				};
				class Blood
				{
					hitpoints = 100;
					transferToGlobalCoef = 0;
				};
				class Shock
				{
					hitpoints = 0;
					transferToGlobalCoef = 1;
				};
				class ArmorType
				{
					class Projectile
					{
						class Health
						{
							damage = 1;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 0.33;
						};
					};
				};
				componentNames[] = { "dmgZone_leftArm" };
				inventorySlotsCoefs[] = { 1.0 };
				fatalInjuryCoef = -1;
			};
			class RightArm
			{
				class Health
				{
					hitpoints = 100;
					transferToGlobalCoef = 0.1;
				};
				class Blood
				{
					hitpoints = 100;
					transferToGlobalCoef = 0;
				};
				class Shock
				{
					hitpoints = 0;
					transferToGlobalCoef = 1;
				};
				class ArmorType
				{
					class Projectile
					{
						class Health
						{
							damage = 1;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 0.33;
						};
					};
				};
				componentNames[] = { "dmgZone_rightArm" };
				inventorySlotsCoefs[] = { 1.0 };
				fatalInjuryCoef = -1;
			};
			class LeftHand
			{
				class Health
				{
					hitpoints = 100;
					transferToGlobalCoef = 0.1;
				};
				class Blood
				{
					hitpoints = 100;
					transferToGlobalCoef = 0;
				};
				class Shock
				{
					hitpoints = 0;
					transferToGlobalCoef = 1;
				};
				class ArmorType
				{
					class Projectile
					{
						class Health
						{
							damage = 1;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 0.1;
						};
					};
				};
				transferToZonesNames[] = { "LeftArm" };
				transferToZonesCoefs[] = { 0.1 };
				componentNames[] = { "dmgZone_leftHand" };
				fatalInjuryCoef = -1;
				inventorySlots[] = { "Gloves" };
			};
			class RightHand
			{
				class Health
				{
					hitpoints = 100;
					transferToGlobalCoef = 0.1;
				};
				class Blood
				{
					hitpoints = 100;
					transferToGlobalCoef = 0;
				};
				class Shock
				{
					hitpoints = 0;
					transferToGlobalCoef = 1;
				};
				class ArmorType
				{
					class Projectile
					{
						class Health
						{
							damage = 1;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 0.1;
						};
					};
				};
				transferToZonesNames[] = { "RightArm" };
				transferToZonesCoefs[] = { 0.1 };
				componentNames[] = { "dmgZone_rightHand" };
				fatalInjuryCoef = -1;
				inventorySlots[] = { "Gloves" };
			};
			class LeftLeg
			{
				class Health
				{
					hitpoints = 125;
					transferToGlobalCoef = 0.25;
				};
				class Blood
				{
					hitpoints = 100;
					transferToGlobalCoef = 0;
				};
				class Shock
				{
					hitpoints = 0;
					transferToGlobalCoef = 1;
				};
				class ArmorType
				{
					class Projectile
					{
						class Health
						{
							damage = 1.2;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 0.33;
						};
					};
				};
				fatalInjuryCoef = -1;
				componentNames[] = { "dmgZone_leftLeg" };
				inventorySlots[] = { "Legs" };
			};
			class RightLeg : LeftLeg
			{
				componentNames[] = { "dmgZone_rightLeg" };
				inventorySlots[] = { "Legs" };
			};
			class LeftFoot
			{
				class Health
				{
					hitpoints = 125;
					transferToGlobalCoef = 0.1;
				};
				class Blood
				{
					hitpoints = 100;
					transferToGlobalCoef = 0;
				};
				class Shock
				{
					hitpoints = 0;
					transferToGlobalCoef = 1;
				};
				class ArmorType
				{
					class Projectile
					{
						class Health
						{
							damage = 1.2;
						};
						class Blood
						{
							damage = 1;
						};
						class Shock
						{
							damage = 0.1;
						};
					};
				};
				fatalInjuryCoef = -1;
				componentNames[] = { "dmgZone_leftFoot" };
				inventorySlots[] = { "Feet" };
				transferToZonesNames[] = { "LeftLeg" };
				transferToZonesCoefs[] = { 0.2 };
			};
			class RightFoot : LeftFoot
			{
				componentNames[] = { "dmgZone_rightFoot" };
				transferToZonesNames[] = { "RightLeg" };
				transferToZonesCoefs[] = { 0.2 };
			};
		};
	};
};
class CfgWorlds
{
	initWorld = "ExclusionZone";
	class DefaultLighting
	{
		groundReflection[] = { 0.085,0.068,0.034 };
		moonObjectColorFull[] = { 0.9,0.9,1,1.2 };
		moonHaloObjectColorFull[] = { 0.9,0.9,1,0.11 };
		moonsetObjectColor[] = { 0.9,0.75,0.4 };
		moonsetHaloObjectColor[] = { 0.9,0.5,0.2 };
		nightAngle = 5;
		sunSunset = 20;
		endSunset = 10;
	};
	class DefaultWorld
	{
		class Weather
		{
			class Overcast
			{
				class Weather1;
				class Weather2;
				class Weather3;
				class Weather4;
				class Weather5;
				class Weather6;
				class Weather7;
				class Weather8;
				class Weather9;
				class Weather10;
			};
		};
	};
	class CAWorld : DefaultWorld
	{
		class Weather : Weather
		{
			class VolFog
			{
				CameraFog = 0.0;
				Item1[] = { 800, 0.06, 0.93, 0.13, 1 };
				Item2[] = { 1300, 0.02, 0.9, 0.05, 1 };
			};
			class Overcast : Overcast
			{
				class Weather1 : Weather1
				{
					overcast = 0.0;
					lightingOvercast = 0.0;
					skyColorInfluencesFogColor = 0;
					sky = "Noosphere\X18CoreScripts\Data\SkyBox\01.paa";
					skyR = "DZ\data\data\sky_clear_lco.paa";
					horizon = "DZ\data\data\sky_clear_horizont_sky.paa";
					alpha = 0.0; // Transparenz Wolkendecke
					bright = 1.0; // Helligkeit der Wolken
					speed = 0.0; // Geschwindigkeit der Wolken
					size = 0.1; // Größe der Wolken Modelle
					height = 1.0; // Höhe Wolkendecke
					through = 0.6; // Lichtdurchlässigkeit der Wolken 1 Komplett 0 Garnicht
					diffuse = 1.0; // Verteilung der Wolken vermutlich unter den Layern
					cloudDiffuse = 1.0; // Verteilung der Wolken vermutlich in den Layern
					waves = 0.0;
				};
				class Weather2 : Weather2
				{
					overcast = 0.2;
					lightingOvercast = 0.2;
					skyColorInfluencesFogColor = 0;
					sky = "Noosphere\X18CoreScripts\Data\SkyBox\02.paa";
					skyR = "DZ\data\data\sky_clear_lco.paa";
					horizon = "DZ\data\data\sky_clear_horizont_sky.paa";
					alpha = 0.0; // Transparenz Wolkendecke
					bright = 1.0; // Helligkeit der Wolken
					speed = 0.0; // Geschwindigkeit der Wolken
					size = 0.2; // Größe der Wolken Modelle
					height = 1.0; // Höhe Wolkendecke
					through = 0.5; // Lichtdurchlässigkeit der Wolken 1 Komplett 0 Garnicht
					diffuse = 1.0; // Verteilung der Wolken vermutlich unter den Layern
					cloudDiffuse = 1.0; // Verteilung der Wolken vermutlich in den Layern
					waves = 0.0;
				};
				class Weather3 : Weather3
				{
					overcast = 0.4;
					lightingOvercast = 0.4;
					skyColorInfluencesFogColor = 0;
					sky = "Noosphere\X18CoreScripts\Data\SkyBox\03.paa";
					skyR = "DZ\data\data\sky_clear_lco.paa";
					horizon = "DZ\data\data\sky_clear_horizont_sky.paa";
					alpha = 0.05; // Transparenz Wolkendecke
					bright = 0.8; // Helligkeit der Wolken
					speed = 0.1; // Geschwindigkeit der Wolken
					size = 0.3; // Größe der Wolken Modelle
					height = 1.0; // Höhe Wolkendecke
					through = 0.4; // Lichtdurchlässigkeit der Wolken 1 Komplett 0 Garnicht
					diffuse = 1.0; // Verteilung der Wolken vermutlich unter den Layern
					cloudDiffuse = 1.0; // Verteilung der Wolken vermutlich in den Layern
					waves = 0.0;
				};
				class Weather4 : Weather4
				{
					overcast = 0.6;
					lightingOvercast = 0.6;
					skyColorInfluencesFogColor = 0;
					sky = "Noosphere\X18CoreScripts\Data\SkyBox\04.paa";
					skyR = "DZ\data\data\sky_clear_lco.paa";
					horizon = "DZ\data\data\sky_clear_horizont_sky.paa";
					alpha = 0.05; // Transparenz Wolkendecke
					bright = 0.8; // Helligkeit der Wolken
					speed = 0.1; // Geschwindigkeit der Wolken
					size = 0.4; // Größe der Wolken Modelle
					height = 1.0; // Höhe Wolkendecke
					through = 0.3; // Lichtdurchlässigkeit der Wolken 1 Komplett 0 Garnicht
					diffuse = 1.0; // Verteilung der Wolken vermutlich unter den Layern
					cloudDiffuse = 1.0; // Verteilung der Wolken vermutlich in den Layern
					waves = 0.0;
				};
				class Weather5 : Weather5
				{
					overcast = 0.7;
					lightingOvercast = 0.7;
					skyColorInfluencesFogColor = 0;
					sky = "Noosphere\X18CoreScripts\Data\SkyBox\05.paa";
					skyR = "DZ\data\data\sky_mostlycloudy_lco.paa";
					horizon = "DZ\data\data\sky_mostlycloudy_horizont_sky.paa";
					alpha = 0.05; // Transparenz Wolkendecke
					bright = 0.075; // Helligkeit der Wolken
					speed = 0.1; // Geschwindigkeit der Wolken
					size = 0.4; // Größe der Wolken Modelle
					height = 1.0; // Höhe Wolkendecke
					through = 0.2; // Lichtdurchlässigkeit der Wolken 1 Komplett 0 Garnicht
					diffuse = 1.0; // Verteilung der Wolken vermutlich unter den Layern
					cloudDiffuse = 1.0; // Verteilung der Wolken vermutlich in den Layern
					waves = 0.0;
				};
				class Weather6 : Weather6
				{
					overcast = 0.8;
					lightingOvercast = 0.8;
					skyColorInfluencesFogColor = 0;
					sky = "Noosphere\X18CoreScripts\Data\SkyBox\06.paa";
					skyR = "DZ\data\data\sky_mostlycloudy_lco.paa";
					horizon = "DZ\data\data\sky_mostlycloudy_horizont_sky.paa";
					alpha = 0.05; // Transparenz Wolkendecke
					bright = 0.075; // Helligkeit der Wolken
					speed = 0.25; // Geschwindigkeit der Wolken
					size = 0.5; // Größe der Wolken Modelle
					height = 1.0; // Höhe Wolkendecke
					through = 0.1; // Lichtdurchlässigkeit der Wolken 1 Komplett 0 Garnicht
					diffuse = 1.0; // Verteilung der Wolken vermutlich unter den Layern
					cloudDiffuse = 1.0; // Verteilung der Wolken vermutlich in den Layern
					waves = 0.0;
				};
				class Weather7 : Weather7
				{
					overcast = 0.9;
					lightingOvercast = 0.9;
					skyColorInfluencesFogColor = 0;
					sky = "Noosphere\X18CoreScripts\Data\SkyBox\07.paa";
					skyR = "DZ\data\data\sky_mostlycloudy_lco.paa";
					horizon = "DZ\data\data\sky_mostlycloudy_horizont_sky.paa";
					alpha = 0.05; // Transparenz Wolkendecke
					bright = 0.05; // Helligkeit der Wolken
					speed = 0.25; // Geschwindigkeit der Wolken
					size = 0.6; // Größe der Wolken Modelle
					height = 1.0; // Höhe Wolkendecke
					through = 0.0; // Lichtdurchlässigkeit der Wolken 1 Komplett 0 Garnicht
					diffuse = 1.0; // Verteilung der Wolken vermutlich unter den Layern
					cloudDiffuse = 1.0; // Verteilung der Wolken vermutlich in den Layern
					waves = 0.0;
				};
				class Weather8 : Weather8
				{
					overcast = 0.95;
					lightingOvercast = 1.0;
					skyColorInfluencesFogColor = 1;
					sky = "Noosphere\X18CoreScripts\Data\SkyBox\08.paa";
					skyR = "DZ\data\data\sky_mostlycloudy_lco.paa";
					horizon = "DZ\data\data\sky_mostlycloudy_horizont_sky.paa";
					alpha = 0.05; // Transparenz Wolkendecke
					bright = 0.0; // Helligkeit der Wolken
					speed = 0.25; // Geschwindigkeit der Wolken
					size = 0.6; // Größe der Wolken Modelle
					height = 0.9; // Höhe Wolkendecke
					through = 0.0; // Lichtdurchlässigkeit der Wolken 1 Komplett 0 Garnicht
					diffuse = 1.0; // Verteilung der Wolken vermutlich unter den Layern
					cloudDiffuse = 1.0; // Verteilung der Wolken vermutlich in den Layern
					waves = 0.0;
				};
				class Weather9 : Weather9
				{
					overcast = 0.975;
					lightingOvercast = 1.0;
					skyColorInfluencesFogColor = 1;
					sky = "Noosphere\X18CoreScripts\Data\SkyBox\09.paa";
					skyR = "DZ\data\data\sky_mostlycloudy_lco.paa";
					horizon = "DZ\data\data\sky_mostlycloudy_horizont_sky.paa";
					alpha = 0.05; // Transparenz Wolkendecke
					bright = 0.0; // Helligkeit der Wolken
					speed = 0.25; // Geschwindigkeit der Wolken
					size = 0.75; // Größe der Wolken Modelle
					height = 0.85; // Höhe Wolkendecke
					through = 0.0; // Lichtdurchlässigkeit der Wolken 1 Komplett 0 Garnicht
					diffuse = 1.0; // Verteilung der Wolken vermutlich unter den Layern
					cloudDiffuse = 1.0; // Verteilung der Wolken vermutlich in den Layern
					waves = 0.0;
				};
				class Weather10 : Weather10
				{
					overcast = 1.0;
					lightingOvercast = 1.0;
					skyColorInfluencesFogColor = 1;
					sky = "Noosphere\X18CoreScripts\Data\SkyBox\10.paa";
					skyR = "DZ\data\data\sky_mostlycloudy_lco.paa";
					horizon = "DZ\data\data\sky_mostlycloudy_horizont_sky.paa";
					alpha = 0.05; // Transparenz Wolkendecke
					bright = 0.0; // Helligkeit der Wolken
					speed = 0.25; // Geschwindigkeit der Wolken
					size = 0.75; // Größe der Wolken Modelle
					height = 0.85; // Höhe Wolkendecke
					through = 0.0; // Lichtdurchlässigkeit der Wolken 1 Komplett 0 Garnicht
					diffuse = 1.0; // Verteilung der Wolken vermutlich unter den Layern
					cloudDiffuse = 1.0; // Verteilung der Wolken vermutlich in den Layern
					waves = 0.0;
				};
			};
		};
		skyObject = "Noosphere\X18CoreScripts\Data\SkyBox\SkySphere.p3d";
		moonObject = "DZ\Data\data\moon.p3d";
		starsIntensity = 0.181;
		hazeDistCoef = 0;
		hazeFogCoef = 0;
		volFogOffset = 0;
		rainMaterial = "{AD76A616D0EF1ABC}Graphics/Materials/postprocess/rain.emat";
		satelliteNormalBlendStart = 100;
		satelliteNormalBlendEnd = 500;
		flareMinDistance = 2;
		flareMinDistanceLerp = 1;
		farLightSpotMul = 2;
		farLightPointMul = 2;
		minTreesInForestSquare = 10;
		minRocksInRockSquare = 5;
		soundMapAttenCoef = 0.01;
	};
	class ExclusionZone : CAWorld
	{
		longitude = 30;
		latitude = 51;
		class DefaultClutter;
		class Clutter
		{
			class Helianthus : DefaultClutter
			{
				scaleMin = 0.3;
				scaleMax = 1.5;
			};
			class Anthoxanthum : DefaultClutter
			{
				scaleMin = 0.3;
				scaleMax = 1.5;
			};
			class Anthoxanthum_bended : DefaultClutter
			{
				scaleMin = 0.3;
				scaleMax = 1.5;
			};
			class Calamagrostis : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.5;
			};
			class Carduus : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.2;
			};
			class Carduus_f : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.2;
			};
			class Elytrigia : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.7;
			};
			class ElytrigiaGreen : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.7;
			};
			class ElytrigiaTall : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class Hypericum : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.2;
			};
			class Hypericum_f : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.2;
			};
			class phragmites : DefaultClutter
			{
				scaleMin = 0.3;
				scaleMax = 0.9;
			};
			class Lolium : DefaultClutter
			{
				scaleMin = 0.88;
				scaleMax = 1.7;
			};
			class Taraxacum : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			class ConcreteGrass : DefaultClutter
			{
				scaleMin = 0.4;
				scaleMax = 1.7;
			};
			class DirtGrass : DefaultClutter
			{
				scaleMin = 0.4;
				scaleMax = 1.7;
			};
			class ElytrigiaDirt : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class Cones : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.0;
			};
			class ElytrigiaForest : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class Leafs_spread : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.5;
			};
			class Broadleaf_Undergrowth : DefaultClutter
			{
				scaleMin = 0.3;
				scaleMax = 0.8;
			};
			class Broadleaf_Undergrowth_Red : DefaultClutter
			{
				scaleMin = 0.3;
				scaleMax = 0.8;
			};
			class c_Broadleaf_Sprouts : DefaultClutter
			{
				scaleMin = 0.4;
				scaleMax = 0.8;
			};
			class c_Broadleaf_Sprouts_Tall : DefaultClutter
			{
				scaleMin = 0.5;
				scaleMax = 0.8;
			};
			class SmallPicea : DefaultClutter
			{
				scaleMin = 0.5;
				scaleMax = 1.7;
			};
			class Polypodiophyta : DefaultClutter
			{
				scaleMin = 0.5;
				scaleMax = 1.7;
			};
			class Polypodiophyta_b : DefaultClutter
			{
				scaleMin = 0.5;
				scaleMax = 1.7;
			};
			class Polypodiophyta_c : DefaultClutter
			{
				scaleMin = 0.5;
				scaleMax = 1.7;
			};
			class PolypodiophytaTall : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1;
			};
			class Vaccinium : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.6;
			};
			class VacciniumGreen : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class VacciniumRed : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class VacciniumTall : DefaultClutter
			{
				scaleMin = 0.5;
				scaleMax = 1.7;
			};
			class Twigs : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class Twigs_b : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.8;
			};
			class Wheat_summer : DefaultClutter
			{
				scaleMin = 0.5;
				scaleMax = 1.7;
			};
			class WheatTall_summer : DefaultClutter
			{
				scaleMin = 1.0;
				scaleMax = 2.7;
			};
			class Stubble_summer : DefaultClutter
			{
				scaleMin = 0.9;
				scaleMax = 1.7;
			};
			class Vaccinium_summer : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.7;
			};
			class Fern_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class FernTall_summer : DefaultClutter
			{
				scaleMin = 0.7;
				scaleMax = 1.7;
			};
			class branches_picea_summer : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.7;
			};
			class branchesBig_picea_summer : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.7;
			};
			class branches_deciduous_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class Pines_summer : DefaultClutter
			{
				scaleMin = 0.5;
				scaleMax = 1.7;
			};
			class Cones_summer : DefaultClutter
			{
				scaleMin = 1.0;
				scaleMax = 1.7;
			};
			class leaves_dead_summer : DefaultClutter
			{
				scaleMin = 0.9;
				scaleMax = 1.7;
			};
			class leaves_dead_half_summer : DefaultClutter
			{
				scaleMin = 0.9;
				scaleMax = 1.7;
			};
			class plantsSmall1_summer : DefaultClutter
			{
				scaleMin = 0.9;
				scaleMax = 1.7;
			};
			class plantsSmall2_summer : DefaultClutter
			{
				scaleMin = 0.9;
				scaleMax = 1.7;
			};
			class GrassSmall_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.6;
			};
			class GrassTiny_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.8;
			};
			class beech_big_summer : DefaultClutter
			{
				scaleMin = 0.4;
				scaleMax = 1.5;
			};
			class beech_mid_summer : DefaultClutter
			{
				scaleMin = 0.7;
				scaleMax = 1.7;
			};
			class beech_small_summer : DefaultClutter
			{
				scaleMin = 0.7;
				scaleMax = 1.7;
			};
			class GrassPlant1_summer : DefaultClutter
			{
				scaleMin = 0.9;
				scaleMax = 1.7;
			};
			class GrassPlant2_summer : DefaultClutter
			{
				scaleMin = 0.9;
				scaleMax = 1.7;
			};
			class Grass_summer : DefaultClutter
			{
				scaleMin = 0.9;
				scaleMax = 1.6;
			};
			class GrassLow_summer : DefaultClutter
			{
				scaleMin = 0.9;
				scaleMax = 1.7;
			};
			class GrassAnthoxanthum_summer : DefaultClutter
			{
				scaleMin = 0.9;
				scaleMax = 1.7;
			};
			class GrassAnthoxanthum_bended_summer : DefaultClutter
			{
				scaleMin = 0.9;
				scaleMax = 1.7;
			};
			class GrassTall2_summer : DefaultClutter
			{
				scaleMin = 1.0;
				scaleMax = 2;
			};
			class GrassTall3_summer : DefaultClutter
			{
				scaleMin = 1.0;
				scaleMax = 2;
			};
			class Grass_flower1_summer : DefaultClutter
			{
				scaleMin = 1.0;
				scaleMax = 1.2;
			};
			class GrassDry_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class GrassDry2_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.8;
			};
			class GrassDry3_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class GrassDryPlant1_summer : DefaultClutter
			{
				scaleMin = 1.0;
				scaleMax = 1.7;
			};
			class GrassDryTall_summer : DefaultClutter
			{
				scaleMin = 1.0;
				scaleMax = 2;
			};
			class GrassDryTall2_summer : DefaultClutter
			{
				scaleMin = 1.0;
				scaleMax = 2;
			};
			class GrassBaseHypericum_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			class GrassBaseCarduus_f_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			class GrassDryHypericum_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			class GrassDryCarduus_f_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			class GrassCropHypericum_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			class GrassCropCarduus_f_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			class GrassDryTall3_summer : DefaultClutter
			{
				scaleMin = 1.0;
				scaleMax = 1.7;
			};
			class GrassSmallConc_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class GrassTinyConc_summer : DefaultClutter
			{
				scaleMin = 1.0;
				scaleMax = 1.8;
			};
			class Elytrigia_summer : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.7;
			};
			class ElytrigiaGreen_summer : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.7;
			};
			class ElytrigiaTall_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class ElytrigiaTall2_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
			class GrassFlowersWhite_summer : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.3;
			};
			class GrassFlowersWhiteShort_summer : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.4;
			};
			class GrassFlowersWhiteTall_summer : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.2;
			};
			class GrassFlowersYellow_summer : DefaultClutter
			{
				scaleMin = 0.4;
				scaleMax = 1.3;
			};
			class GrassFlowersYellowShort_summer : DefaultClutter
			{
				scaleMin = 0.4;
				scaleMax = 1.4;
			};
			class GrassFlowersYellowTall_summer : DefaultClutter
			{
				scaleMin = 0.4;
				scaleMax = 1.2;
			};
			class GrassFlowersPurple_summer : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.3;
			};
			class GrassFlowersPurpleShort_summer : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.4;
			};
			class GrassFlowersPurpleTall_summer : DefaultClutter
			{
				scaleMin = 0.6;
				scaleMax = 1.2;
			};
			class Wheat2_summer : DefaultClutter
			{
				scaleMin = 0.4;
				scaleMax = 2;
			};
			class ConcreteGrass_summer : DefaultClutter
			{
				scaleMin = 0.4;
				scaleMax = 1.7;
			};
			class DirtGrass_summer : DefaultClutter
			{
				scaleMin = 0.4;
				scaleMax = 1.7;
			};
			class ElytrigiaDirt_summer : DefaultClutter
			{
				scaleMin = 0.8;
				scaleMax = 1.7;
			};
		};
	};
};
class CfgCoreData
{
	skysphere = "Noosphere\X18CoreScripts\Data\SkyBox\SkySphere.p3d";
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
		color[] = {
			1,
			1,
			1,
			1
		};
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
		color[] = {
			1,
			1,
			1,
			1
		};
		size = 0;
		font = "gui/fonts/sdf_MetronBook24";
		textSize = 0.03;
		shadow = 0;
		importance = 1;
	};
	class Capital : Name
	{
		color[] = {
			1,
			1,
			1,
			1
		};
		textSize = 0.05;
		importance = 7;
	};
	class City : Name
	{
		textSize = 0.045;
		importance = 6;
	};
	class Village : Name
	{
		textSize = 0.04;
		importance = 3;
	};
	class Local : Name
	{
		color[] = {
			0.44,
			0.38,
			0.3,
			1
		};
		textSize = 0.035;
	};
	class Ruin : NameIcon
	{
		texture = "\DZ\gear\navigation\data\map_ruin_ca.paa";
		textSize = 0.02;
		importance = 2;
		size = 7;
	};
	class Camp : NameIcon
	{
		color[] = {
			0.44,
			0.38,
			0.3,
			1
		};
		texture = "\DZ\gear\navigation\data\map_camp_ca.paa";
		textSize = 0.02;
		size = 5;
	};
	class Hill : NameIcon
	{
		color[] = {
			0.7,
			0.7,
			0.7,
			1
		};
		texture = "\DZ\gear\navigation\data\map_hill_ca.paa";
		textSize = 0.02;
		size = 3;
	};
	class ViewPoint : NameIcon
	{
		color[] = {
			0.78,
			0,
			0.05,
			0
		};
		texture = "\DZ\gear\navigation\data\map_viewpoint_ca.paa";
		size = 9;
	};
	class RockArea : NameIcon
	{
		color[] = {
			0,
			0,
			0,
			1
		};
		texture = "\DZ\gear\navigation\data\map_rock_ca.paa";
		size = 9;
	};
	class RailroadStation : NameIcon
	{
		color[] = {
			0,
			0,
			0,
			0
		};
		texture = "\DZ\gear\navigation\data\map_station_ca.paa";
		textSize = 0.02;
		size = 9;
	};
	class IndustrialSite : NameIcon
	{
		color[] = {
			0,
			0,
			0,
			0
		};
		texture = "\DZ\gear\navigation\data\map_factory_ca.paa";
		textSize = 0.02;
		size = 9;
	};
	class LocalOffice : NameIcon
	{
		color[] = {
			0.22,
			0.21,
			0.51,
			0
		};
		texture = "\DZ\gear\navigation\data\map_govoffice_ca.paa";
		size = 10;
	};
	class BorderCrossing : NameIcon
	{
		color[] = {
			0.78,
			0,
			0.05,
			1
		};
		texture = "\DZ\gear\navigation\data\map_border_cross_ca.paa";
		size = 9;
	};
	class VegetationBroadleaf : NameIcon
	{
		color[] = {
			0.25,
			0.4,
			0.2,
			1
		};
		texture = "\DZ\gear\navigation\data\map_broadleaf_ca.paa";
		size = 9;
	};
	class VegetationFir : NameIcon
	{
		color[] = {
			0.25,
			0.4,
			0.2,
			1
		};
		texture = "\DZ\gear\navigation\data\map_fir_ca.paa";
		size = 9;
	};
	class VegetationPalm : NameIcon
	{
		color[] = {
			0.25,
			0.4,
			0.2,
			1
		};
		texture = "\DZ\gear\navigation\data\map_palm_ca.paa";
		size = 9;
	};
	class VegetationVineyard : NameIcon
	{
		color[] = {
			0.25,
			0.4,
			0.2,
			1
		};
		texture = "\DZ\gear\navigation\data\map_vineyard_ca.paa";
		size = 9;
	};
};
class CfgSlots
{
	class Slot_magazine
	{
		name = "magazine";
		displayName = "#STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine";
		autoAttach = "false";
	};
	class Slot_magazine2
	{
		name = "magazine2";
		displayName = "#STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine";
		autoAttach = "false";
	};
	class Slot_magazine3
	{
		name = "magazine3";
		displayName = "#STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine";
		autoAttach = "false";
	};
	class Slot_magazine4
	{
		name = "magazine4";
		displayName = "#STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine";
		autoAttach = "false";
	};
	class Slot_magazine5
	{
		name = "magazine5";
		displayName = "#STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine";
		autoAttach = "false";
	};
	class Slot_magazine6
	{
		name = "magazine6";
		displayName = "#STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine";
		autoAttach = "false";
	};
	class Slot_magazine7
	{
		name = "magazine7";
		displayName = "#STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine";
		autoAttach = "false";
	};
	class Slot_magazine8
	{
		name = "magazine8";
		displayName = "#STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine";
		autoAttach = "false";
	};
	class Slot_magazine9
	{
		name = "magazine9";
		displayName = "#STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine";
		autoAttach = "false";
	};
	class Slot_magazine10
	{
		name = "magazine10";
		displayName = "#STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine";
		autoAttach = "false";
	};
};