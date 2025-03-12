class CfgPatches
{
	class X18Items_Ammunition_Stack
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Weapons_Ammunition","DZ_Weapons_Magazines" };
	};
};
class CfgMagazines
{
	class Magazine_Base;
	class Ammunition_Base : Magazine_Base {};
	/*class Ammo_45ACP : Ammunition_Base
	{
		count = 80;
	};
	class Ammo_308Win : Ammunition_Base
	{
		count = 60;
	};
	class Ammo_308WinTracer : Ammunition_Base
	{
		count = 60;
	};
	class Ammo_9x19 : Ammunition_Base
	{
		count = 80;
	};
	class Ammo_380 : Ammunition_Base
	{
		count = 100;
	};
	class Ammo_556x45 : Ammunition_Base
	{
		count = 60;
	};
	class Ammo_556x45Tracer : Ammunition_Base
	{
		count = 60;
	};
	class Ammo_762x54 : Ammunition_Base
	{
		count = 60;
	};
	class Ammo_762x54Tracer : Ammunition_Base
	{
		count = 60;
	};
	class Ammo_762x39 : Ammunition_Base
	{
		count = 60;
	};
	class Ammo_762x39Tracer : Ammunition_Base
	{
		count = 60;
	};
	class Ammo_9x39 : Ammunition_Base
	{
		count = 80;
	};
	class Ammo_9x39AP : Ammunition_Base
	{
		count = 80;
	};
	class Ammo_22 : Ammunition_Base
	{
		count = 200;
	};*/
	class Ammo_12gaPellets : Ammunition_Base
	{
		count = 20;
	};
	class Ammo_12gaSlug : Ammunition_Base
	{
		count = 20;
	};
	class Ammo_12gaRubberSlug : Ammunition_Base
	{
		count = 20;
	};
	class Ammo_12gaBeanbag : Ammunition_Base
	{
		count = 20;
	};
	/*class Ammo_357 : Ammunition_Base
	{
		count = 60;
	};
	class Ammo_545x39 : Ammunition_Base
	{
		count = 60;
	};
	class Ammo_545x39Tracer : Ammunition_Base
	{
		count = 60;
	};
	class Ammo_ArrowComposite : Ammunition_Base
	{
		count = 20;
	};
	class Ammo_SharpStick : Ammunition_Base
	{
		count = 20;
	};
	class Ammo_ArrowPrimitive : Ammunition_Base
	{
		count = 20;
	};
	class Ammo_ArrowBoned : Ammunition_Base
	{
		count = 20;
	};
	class Ammo_ArrowBolt : Ammunition_Base
	{
		count = 20;
	};
	class Ammo_DartSyringe : Ammunition_Base
	{
		count = 20;
	};
	class Ammo_Flare : Ammunition_Base
	{
		count = 15;
	};
	class Ammo_FlareBlue : Ammunition_Base
	{
		count = 15;
	};
	class Ammo_FlareRed : Ammunition_Base
	{
		count = 15;
	};
	class Ammo_FlareGreen : Ammunition_Base
	{
		count = 15;
	};*/
};
class CfgVehicles
{
	class Box_Base;
	/*class AmmoBox_556x45_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_556x45
			{
				value = 60;
			};
		};
	};
	class AmmoBox_556x45Tracer_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_556x45Tracer
			{
				value = 60;
			};
		};
	};
	class AmmoBox_308Win_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_308Win
			{
				value = 60;
			};
		};
	};
	class AmmoBox_308WinTracer_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_308WinTracer
			{
				value = 60;
			};
		};
	};
	class AmmoBox_762x54_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_762x54
			{
				value = 60;
			};
		};
	};
	class AmmoBox_762x54Tracer_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_762x54Tracer
			{
				value = 60;
			};
		};
	};
	class AmmoBox_762x39_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_762x39
			{
				value = 60;
			};
		};
	};
	class AmmoBox_762x39Tracer_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_762x39Tracer
			{
				value = 60;
			};
		};
	};
	class AmmoBox_22_50Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_22
			{
				value = 200;
			};
		};
	};
	class AmmoBox_357_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_357
			{
				value = 60;
			};
		};
	};
	class AmmoBox_45ACP_25rnd : Box_Base
	{
		class Resources
		{
			class Ammo_45ACP
			{
				value = 80;
			};
		};
	};
	class AmmoBox_9x19_25rnd : Box_Base
	{
		class Resources
		{
			class Ammo_9x19
			{
				value = 80;
			};
		};
	};
	class AmmoBox_380_35rnd : Box_Base
	{
		class Resources
		{
			class Ammo_380
			{
				value = 100;
			};
		};
	};*/
	class AmmoBox_00buck_10rnd : Box_Base
	{
		class Resources
		{
			class Ammo_12gaPellets
			{
				value = 20;
			};
		};
	};
	class AmmoBox_12gaSlug_10Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_12gaSlug
			{
				value = 20;
			};
		};
	};
	class AmmoBox_12gaRubberSlug_10Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_12gaRubberSlug
			{
				value = 20;
			};
		};
	};
	class AmmoBox_12gaBeanbag_10Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_12gaBeanbag
			{
				value = 20;
			};
		};
	};
	/*class AmmoBox_545x39_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_545x39
			{
				value = 60;
			};
		};
	};
	class AmmoBox_545x39Tracer_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_545x39Tracer
			{
				value = 60;
			};
		};
	};
	class AmmoBox_9x39AP_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_9x39AP
			{
				value = 80;
			};
		};
	};
	class AmmoBox_9x39_20Rnd : Box_Base
	{
		class Resources
		{
			class Ammo_9x39
			{
				value = 80;
			};
		};
	};*/
};