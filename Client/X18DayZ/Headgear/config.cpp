class CfgPatches
{
	class DZ_Characters_Headgear
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Characters" };
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing : Clothing_Base {};
	class Switchable_Base;
	class Headtorch_ColorBase : Switchable_Base
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
				};
			};
		};
	};
	class NBCHoodBase : Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
				};
			};
		};
	};
};