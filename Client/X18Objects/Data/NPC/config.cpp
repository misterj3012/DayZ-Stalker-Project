class CfgPatches
{
	class X18Objects_NPC
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DayZExpansion_Market_Objects", "DayZExpansion_Market_Scripts" };
	};
};
class CfgVehicles
{
	class ExpansionTraderStaticBase;
	class X18_NPC_Sidorovich : ExpansionTraderStaticBase
	{
		scope = 2;
		displayName = "Sidorovich";
		model = "Noosphere\X18Objects\Data\NPC\Sidorovich\Sidorovich.p3d";
	};
	class X18_NPC_Sidorovich_2 : ExpansionTraderStaticBase
	{
		scope = 2;
		displayName = "Sidorovich";
		model = "SFP2\1_AI\sidor\sidor_completed.p3d";
	};
	class X18_NPC_Babka : ExpansionTraderStaticBase
	{
		scope = 2;
		displayName = "Babka";
		model = "Noosphere\X18Objects\Data\NPC\Babka\Babka.p3d";
	};
	class X18_NPC_Barman : ExpansionTraderStaticBase
	{
		scope = 2;
		displayName = "Barman";
		model = "SFP2\1_AI\barmen\barmen.p3d";
	};
};