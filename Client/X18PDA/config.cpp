class CfgPatches
{
	class X18PDA
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "X18CoreScripts" };
	};
};
class CfgMods
{
	class X18PDA
	{
		name = "X18PDA";
		credits = "MisterJ";
		extra = 0;
		type = "mod";
		inputs = "Noosphere/X18PDA/Data/Inputs.xml";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18PDA/Scripts/Common", "Noosphere/X18PDA/Scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18PDA/Scripts/Common", "Noosphere/X18PDA/Scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "Noosphere/X18PDA/Scripts/Common", "Noosphere/X18PDA/Scripts/5_Mission" };
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class X18_PDA : Inventory_Base
	{
		scope = 2;
		displayName = "#pda_item_name";
		descriptionShort = "#pda_item_desc";
		model = "Noosphere\X18PDA\Data\Model\PDA.p3d";
		animClass = "ItemPDA";
		itemSize[] = { 1,2 };
		inventorySlot[] =
		{
			"WalkieTalkie",
			"VestGrenadeA"
		};
		weight = 250;
		repairableWithKits[] = { 5,7 };
		repairCosts[] = { 30,25 };
		attachments[] = { "BatteryD" };
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.002;
			plugType = 1;
			attachmentAction = 1;
			wetnessExposure = 0.1;
			updateInterval = 1;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = { {1,{"DZ\gear\radio\data\WalkieTalkie.rvmat"}},{0.7,{"DZ\gear\radio\data\WalkieTalkie.rvmat"}},{0.5,{"DZ\gear\radio\data\WalkieTalkie_damage.rvmat"}},{0.3,{"DZ\gear\radio\data\WalkieTalkie_damage.rvmat"}},{0,{"DZ\gear\radio\data\WalkieTalkie_destruct.rvmat"}} };
				};
			};
		};
	};
};
class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class PDA_TurnOn_SoundShader : baseCharacter_SoundShader
	{
		samples[] = { {"Noosphere\X18PDA\Data\Sounds\pda_turnon",1} };
		volume = 0.5;
	};
	class PDA_TurnOff_SoundShader : baseCharacter_SoundShader
	{
		samples[] = { {"Noosphere\X18PDA\Data\Sounds\pda_turnoff",1} };
		volume = 0.5;
	};
	class PDA_GlobalMessage_SoundShader : baseCharacter_SoundShader
	{
		samples[] = { {"Noosphere\X18PDA\Data\Sounds\pda_message_global",1} };
		volume = 0.5;
	};
	class PDA_FactionMessage_SoundShader : baseCharacter_SoundShader
	{
		samples[] = { {"Noosphere\X18PDA\Data\Sounds\pda_message_faction",1} };
		volume = 0.5;
	};
	class PDA_PrivateMessage_SoundShader : baseCharacter_SoundShader
	{
		samples[] = { {"Noosphere\X18PDA\Data\Sounds\pda_message_private",1} };
		volume = 0.5;
	};
	class PDA_Button_SoundShader : baseCharacter_SoundShader
	{
		samples[] = { {"Noosphere\X18PDA\Data\Sounds\pda_button",1} };
		volume = 0.5;
	};
	class PDA_BatteryInsert_SoundShader : baseCharacter_SoundShader
	{
		samples[] = { {"Noosphere\X18PDA\Data\Sounds\pda_battery_insert",1} };
		volume = 0.5;
	};
	class PDA_BatteryRemove_SoundShader : baseCharacter_SoundShader
	{
		samples[] = { {"Noosphere\X18PDA\Data\Sounds\pda_battery_remove",1} };
		volume = 0.5;
	};
};
class CfgSoundSets
{
	class baseCharacter_SoundSet;
	class PDA_TurnOn_SoundSet : baseCharacter_SoundSet
	{
		soundShaders[] = { "PDA_TurnOn_SoundShader" };
	};
	class PDA_TurnOff_SoundSet : baseCharacter_SoundSet
	{
		soundShaders[] = { "PDA_TurnOff_SoundShader" };
	};
	class PDA_GlobalMessage_SoundSet : baseCharacter_SoundSet
	{
		soundShaders[] = { "PDA_GlobalMessage_SoundShader" };
	};
	class PDA_FactionMessage_SoundSet : baseCharacter_SoundSet
	{
		soundShaders[] = { "PDA_FactionMessage_SoundShader" };
	};
	class PDA_PrivateMessage_SoundSet : baseCharacter_SoundSet
	{
		soundShaders[] = { "PDA_PrivateMessage_SoundShader" };
	};
	class PDA_Button_SoundSet : baseCharacter_SoundSet
	{
		soundShaders[] = { "PDA_Button_SoundShader" };
	};
	class PDA_BatteryInsert_SoundSet : baseCharacter_SoundSet
	{
		soundShaders[] = { "PDA_BatteryInsert_SoundShader" };
	};
	class PDA_BatteryRemove_SoundSet : baseCharacter_SoundSet
	{
		soundShaders[] = { "PDA_BatteryRemove_SoundShader" };
	};
};