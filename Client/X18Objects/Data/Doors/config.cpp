class CfgPatches
{
	class X18ObjectsDoors
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};

class CfgMods
{
	class X18ObjectsDoors
	{
		name = "X18ObjectsDoors";
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
	class DoorsBase : HouseNoDestruct
	{
		scope = 0;
		displayName = "Door";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		carveNavmesh = 1;
		hiddenSelections[] = { "door1", "door_1" };
	};
	class X18_Door_Wood : DoorsBase
	{
		scope = 2;
		displayName = "Small Door";
		descriptionShort = "Just A Door, you must be bored if your bothering to read the description on some door...";
		model = "Noosphere\X18Objects\Data\Doors\WoodenDoor\WoodenDoor.p3d";
		class Doors
		{
			class Door1
			{
				displayName = "door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorWoodLargeOpen";
				soundClose = "doorWoodLargeClose";
				soundLocked = "doorWoodLargeRattle";
				soundOpenABit = "doorWoodLargeOpenABit";
			};
		};
	};
	class X18_Door_Wood2 : DoorsBase
	{
		scope = 2;
		displayName = "Small Shanty Door";
		descriptionShort = "Just Crappy A Door, you must be bored if your bothering to read the description on some door...";
		model = "Noosphere\X18Objects\Data\Doors\ShantyDoor\ShantyDoor.p3d";
		class Doors
		{
			class Door1
			{
				displayName = "door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.0;
				soundOpen = "doorWoodLargeOpen";
				soundClose = "doorWoodLargeClose";
				soundLocked = "doorWoodLargeRattle";
				soundOpenABit = "doorWoodLargeOpenABit";
			};
		};
	};
	class X18_Door_Metal : DoorsBase
	{
		scope = 2;
		displayName = "Small Metal Door";
		descriptionShort = "Just A Door, you must be bored if your bothering to read the description on some door...";
		model = "Noosphere\X18Objects\Data\Doors\MetalDoor\MetalDoor.p3d";
		class Doors
		{
			class Door1
			{
				displayName = "door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 2.0;
				initPhase = 0;
				initOpened = 0.0;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
	};
	/*class X18_Door_Safe : DoorsBase
	{
		scope = 2;
		displayName = "Small Safe";
		descriptionShort = "Just A Safe, you can lock this with a combo lock or codelock";
		model = "Noosphere\X18Objects\Data\Doors\Safe\Safe.p3d";
		itemsCargoSize[] = { 9,9 };
		itemSize[] = { 5,5 };
		itemBehaviour = 2;
		class Cargo
		{
			itemsCargoSize[] = { 9,9 };
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};*/
};