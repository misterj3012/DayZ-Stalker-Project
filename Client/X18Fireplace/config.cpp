class CfgPatches
{
	class X18Fireplace
	{
		units[]=
		{
			"X18_FirewoodStorage",
			"X18_FirewoodStorageKit"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Consumables",
			"DZ_Gear_Cooking"
		};
	};
};
class CfgMods
{
	class X18Fireplace
	{
		dir="X18Fireplace";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="X18Fireplace";
		credits="Katha";
		author="Katha";
		authorID="76561198027986382";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"Noosphere\X18Fireplace\Scripts\4_World"
				};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class X18_Item: Inventory_Base
	{
		scope=0;
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		quantityBar=1;
		carveNavmesh=1;
		visibilityModifier=0.94999999;
		canBeDigged=0;
		alignHologramToTerain=1;
		heavyItem=1;
		weight=10;
		itemSize[]={10,10};
		itemBehaviour=2;
		physLayer="item_large";
		rotationFlags=2;
		class Cargo
		{
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000000;
				};
			};
		};
	};
	class X18_Item_WithoutCollision: X18_Item
	{
		physLayer="item_small";
	};
	class X18_Item_Kit: X18_Item
	{
		scope=0;
		descriptionShort="";
		displayName="";
		itemSize[]={5,4};
		simulation="inventoryItem";
		physLayer="item_small";
		weight=300;
	};
	class X18_FirewoodStorage: X18_Item
	{
		scope=2;
		displayName="";
		descriptionShort="";
		hologramMaterial="sea_chest";
		hologramMaterialPath="dz\gear\camping";
		model="\DZ\structures\residential\misc\misc_woodpile1.p3d";
		slopeTolerance=0.40000001;
		itemSize[]={10,10};
		itemBehaviour=0;
		rotationFlags=2;
		yawPitchRollLimit[]={45,45,45};
		canBeDigged=0;
		heavyItem=1;
		carveNavmesh=1;
		weight=10000;
		physLayer="item_large";
		alignHologramToTerain=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=600;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\camping\data\sea_chest.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\camping\data\sea_chest.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\camping\data\sea_chest_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\camping\data\sea_chest_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\camping\data\sea_chest_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage=8;
					};
					class Blood
					{
						damage=8;
					};
					class Shock
					{
						damage=8;
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,5};
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"WoodenStick",
			"Rags",
			"MedicalBandage",
			"Paper",
			"Bark"
		};
		class GUIInventoryAttachmentsProps
		{
			class Fuel
			{
				name="$STR_attachment_Fuel0";
				description="";
				attachmentSlots[]=
				{
					"WoodenStick"
				};
				icon="set:dayz_inventory image:cat_fp_fuel";
				view_index=5;
			};
			class Kindling
			{
				name="$STR_attachment_Kindling0";
				description="";
				attachmentSlots[]=
				{
					"Rags",
					"MedicalBandage",
					"Paper",
					"Bark"
				};
				icon="set:dayz_inventory image:cat_fp_kindling";
				view_index=6;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet="seachest_movement_SoundSet";
					id=1;
				};
				class pickUpItem_Light
				{
					soundSet="pickUpSeaChest_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpSeaChest_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="seachest_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class X18_FirewoodStorageKit: X18_Item_Kit
	{
		scope=2;
		displayName="";
		descriptionShort="";
		model="\DZ\structures\residential\misc\misc_woodpile1.p3d";
	};
	class HouseNoDestruct;
	class X18_FireBarrel: HouseNoDestruct
	{
		scope=1;
		model="Noosphere\X18Fireplace\Data\FireBarrel.p3d";
	};
	class Firewood: Inventory_Base
	{
		itemSize[]={2,5};
		varQuantityMax=6;
		varStackMax=6;
	};
	class Pot;
	class X18_Pot: Pot
	{
		scope=2;
		displayName="$STR_CfgVehicles_Pot0";
		descriptionShort="$STR_CfgVehicles_Pot1";
		model="\dz\gear\cooking\CookingPot.p3d";
		weight=440;
		itemSize[]={4,3};
		itemsCargoSize[]={4,3};
		inventorySlot[]=
		{
			"CookingEquipment",
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC"
		};
		stackedRandom=0;
		canBeDigged=1;
		allowOwnedCargoManipulation=1;
		varLiquidTypeInit=512;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256) -32768";
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=2000;
		varTemperatureMax=200;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\cooking\data\cooking_pot.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cooking\data\cooking_pot.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\cooking\data\cooking_pot_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\cooking\data\cooking_pot_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\cooking\data\cooking_pot_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimationSources
		{
			class handleRotate
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpPotLight
				{
					soundSet="pickUpPotLight_SoundSet";
					id=796;
				};
				class pickUpPot
				{
					soundSet="pickUpPot_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="pot_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};