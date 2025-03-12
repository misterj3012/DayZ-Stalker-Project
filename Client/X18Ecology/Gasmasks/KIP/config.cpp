class CfgPatches
{
	class X18Ecology_GasMasks_KIP5
	{
		units[] = { "X18_GasMask_KIP5G","KIP5g_Black_AoD_GasBalon","KIP5g_M2_Green_AoD_GasBalon","KIP5g_M2_Black_AoD_GasBalon","X18_GasMask_KIP5G_CN2F","KIP5g_GP5_White_AoD_GasMask","KIP5g_GP5_Black_AoD_GasMask","X18_GasMask_KIP5G_RSH4","X18_GasMask_KIP5G_PMG","KIP5g_P1_Loner_White_AoD_GasMask","KIP5g_P1_Loner_Black_AoD_GasMask","KIP5g_P1_Duty_AoD_GasMask","KIP5g_P1_Freedom_AoD_GasMask","X18_GasMask_KIP5G_P2","KIP5g_P2_Loner_Black_AoD_GasMask","KIP5g_P2_Duty_AoD_GasMask","KIP5g_P2_Freedom_AoD_GasMask" };
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Characters" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class KIP5g_Green_AoD_GasBalon;
	class KIP5g_Black_AoD_GasBalon;
	class KIP5g_M2_Green_AoD_GasBalon;
	class KIP5g_M2_Black_AoD_GasBalon;
	class KIP5g_Cn2f_AoD_GasMask;
	class KIP5g_GP5_White_AoD_GasMask;
	class KIP5g_GP5_Black_AoD_GasMask;
	class KIP5g_RSH4_White_AoD_GasMask;
	class KIP5g_PMG_AoD_GasMask;
	class KIP5g_P2_Loner_White_AoD_GasMask;
	class KIP5g_P2_Loner_Black_AoD_GasMask;
	class KIP5g_P2_Duty_AoD_GasMask;
	class KIP5g_P2_Freedom_AoD_GasMask;

	class X18_GasMask_KIP5G : KIP5g_Green_AoD_GasBalon
	{
		scope = 2;
		displayName = "Балон с кислородом";
		descriptionShort = "";
		inventorySlot[] = { "Back" };
		attachments[] = { "WalkieTalkie","Chemlight","aod_gasmask_kip_mask","Left_KIP_BackPack_Gas","Right_KIP_BackPack_Gas" };
		itemInfo[] = { "Clothing","Back" };
		rotationFlags = 2;
		weight = 1000;
		itemSize[] = { 3,4 };
		heatIsolation = 0.5;
		class EnergyManager
		{
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			plugType = 1;
			attachmentAction = 1;
			wetnessExposure = 0.1;
			updateInterval = 1;
		};
	};
	class X18_GasMask_KIP5G_Black : KIP5g_Black_AoD_GasBalon
	{
		scope = 2;
		displayName = "Балон с кислородом";
		descriptionShort = "";
		inventorySlot[] = { "Back" };
		attachments[] = { "WalkieTalkie","Chemlight","aod_gasmask_kip_mask","Left_KIP_BackPack_Gas","Right_KIP_BackPack_Gas" };
		itemInfo[] = { "Clothing","Back" };
		rotationFlags = 2;
		weight = 1000;
		itemSize[] = { 3,4 };
		heatIsolation = 0.5;
		class EnergyManager
		{
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			plugType = 1;
			attachmentAction = 1;
			wetnessExposure = 0.1;
			updateInterval = 1;
		};
	};
	class X18_GasMask_KIP5G_M2 : KIP5g_M2_Green_AoD_GasBalon
	{
		scope = 2;
		displayName = "Балон с кислородом";
		descriptionShort = "";
		inventorySlot[] = { "Back" };
		attachments[] = { "WalkieTalkie","Chemlight","Melee","GasMaskContainer","Left_KIP_BackPack_Gas","Right_KIP_BackPack_Gas" };
		itemInfo[] = { "Clothing","Back" };
		rotationFlags = 2;
		weight = 1800;
		itemSize[] = { 3,4 };
		itemsCargoSize[] = { 7,9 };
		heatIsolation = 0.5;
		class EnergyManager
		{
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			plugType = 1;
			attachmentAction = 1;
			wetnessExposure = 0.1;
			updateInterval = 1;
		};
	};
	class X18_GasMask_KIP5G_M2_Black : KIP5g_M2_Black_AoD_GasBalon
	{
		scope = 2;
		displayName = "Балон с кислородом";
		descriptionShort = "";
		inventorySlot[] = { "Back" };
		attachments[] = { "WalkieTalkie","Chemlight","Melee","GasMaskContainer","Left_KIP_BackPack_Gas","Right_KIP_BackPack_Gas" };
		itemInfo[] = { "Clothing","Back" };
		rotationFlags = 2;
		weight = 1800;
		itemSize[] = { 3,4 };
		itemsCargoSize[] = { 7,9 };
		heatIsolation = 0.5;
		class EnergyManager
		{
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.01666666666666666666666666666667;
			plugType = 1;
			attachmentAction = 1;
			wetnessExposure = 0.1;
			updateInterval = 1;
		};
	};

	class X18_GasMask_KIP_GasTank : Inventory_Base
	{
		scope = 2;
		displayName = "Балон с кислородом";
		descriptionShort = "";
		model = "\fs_2\1_smot\tox\tox_ballon_g.p3d";
		rotationFlags = 16;
		itemSize[] = { 2,3 };
		weight = 5000;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 800;
		varQuantityMin = 0.0;
		varQuantityMax = 800;
		varQuantityDestroyOnMin = 0;
		inventorySlot[] = { "Left_KIP_BackPack_Gas","Right_KIP_BackPack_Gas" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1.0,{"DZ\gear\consumables\data\LootGasCannisterLarge.rvmat"}},{0.7,{"DZ\gear\consumables\data\LootGasCannisterLarge.rvmat"}},{0.5,{"DZ\gear\consumables\data\LootGasCannisterLarge_damage.rvmat"}},{0.3,{"DZ\gear\consumables\data\LootGasCannisterLarge_damage.rvmat"}},{0.0,{"DZ\gear\consumables\data\LootGasCannisterLarge_destruct.rvmat"}} };
				};
			};
		};
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			energyStorageMax = 20;
			energyAtSpawn = 20;
			convertEnergyToQuantity = 1;
			reduceMaxEnergyByDamageCoef = 1;
			powerSocketsCount = 1;
			compatiblePlugTypes[] = { 1 };
		};
	};
	class X18_GasMask_KIP5G_CN2F : KIP5g_Cn2f_AoD_GasMask
	{
		scope = 2;
		displayName = "Противогаз ЧН для «КИП5»";
		descriptionShort = "Индивидуальное средство защиты органов дыхания, кожи лица и органов зрения от радиоактивной пыли и токсичных веществ. Оснащён отводами трубок для подключения к «КИП5»";
		inventorySlot[] = { "Mask","Left_GasMask_KIP_Filter" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		rotationFlags = 2;
		weight = 1000;
		itemSize[] = { 3,4 };
		heatIsolation = 0.5;
		noHelmet = 0;
		class Protection
		{
			biological = 1;
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class X18_GasMask_KIP5G_GP5 : KIP5g_GP5_White_AoD_GasMask
	{
		scope = 2;
		displayName = "Противогаз ГП5 (Белый) для «КИП5»";
		descriptionShort = "Индивидуальное средство защиты органов дыхания, кожи лица и органов зрения от радиоактивной пыли и токсичных веществ. Оснащён отводами трубок для подключения к «КИП5»";
		inventorySlot[] = { "Mask","Left_GasMask_KIP_Filter" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		rotationFlags = 2;
		weight = 1000;
		itemSize[] = { 3,4 };
		heatIsolation = 0.6;
		noHelmet = 0;
		class Protection
		{
			biological = 1;
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class X18_GasMask_KIP5G_GP5_Black : KIP5g_GP5_Black_AoD_GasMask
	{
		scope = 2;
		displayName = "Противогаз ГП5 (Белый) для «КИП5»";
		descriptionShort = "Индивидуальное средство защиты органов дыхания, кожи лица и органов зрения от радиоактивной пыли и токсичных веществ. Оснащён отводами трубок для подключения к «КИП5»";
		inventorySlot[] = { "Mask","Left_GasMask_KIP_Filter" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		rotationFlags = 2;
		weight = 1000;
		itemSize[] = { 3,4 };
		heatIsolation = 0.6;
		noHelmet = 0;
		class Protection
		{
			biological = 1;
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class X18_GasMask_KIP5G_RSH4 : KIP5g_RSH4_White_AoD_GasMask
	{
		scope = 2;
		displayName = "Противогаз РШ4 для «КИП5»";
		descriptionShort = "Индивидуальное средство защиты органов дыхания, кожи лица и органов зрения от радиоактивной пыли и токсичных веществ. Оснащён отводами трубок для подключения к «КИП5»";
		inventorySlot[] = { "Mask","Left_GasMask_KIP_Filter" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		rotationFlags = 2;
		weight = 1000;
		itemSize[] = { 3,4 };
		heatIsolation = 0.6;
		noHelmet = 0;
		class Protection
		{
			biological = 1;
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class X18_GasMask_KIP5G_PMG : KIP5g_PMG_AoD_GasMask
	{
		scope = 2;
		displayName = "Противогаз ПМГ3 для «КИП5»";
		descriptionShort = "Индивидуальное средство защиты органов дыхания, кожи лица и органов зрения от радиоактивной пыли и токсичных веществ. Оснащён отводами трубок для подключения к «КИП5»";
		inventorySlot[] = { "Mask","Left_GasMask_KIP_Filter" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		rotationFlags = 2;
		weight = 1000;
		itemSize[] = { 3,4 };
		heatIsolation = 0.6;
		noHelmet = 0;
		class Protection
		{
			biological = 1;
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class X18_GasMask_KIP5G_P2 : KIP5g_P2_Loner_White_AoD_GasMask
	{
		scope = 2;
		displayName = "Противогаз П2 «Белый» для «КИП5» (Одиночка)";
		descriptionShort = "Индивидуальное средство защиты органов дыхания, кожи лица и органов зрения от радиоактивной пыли и токсичных веществ. Оснащён отводами трубок для подключения к «КИП5»";
		inventorySlot[] = { "Mask","Left_GasMask_KIP_Filter" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		rotationFlags = 2;
		weight = 1000;
		itemSize[] = { 3,4 };
		heatIsolation = 0.6;
		noHelmet = 0;
		class Protection
		{
			biological = 1;
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class X18_GasMask_KIP5G_P2_Black : KIP5g_P2_Loner_Black_AoD_GasMask
	{
		scope = 2;
		displayName = "Противогаз П2 «Белый» для «КИП5» (Одиночка)";
		descriptionShort = "Индивидуальное средство защиты органов дыхания, кожи лица и органов зрения от радиоактивной пыли и токсичных веществ. Оснащён отводами трубок для подключения к «КИП5»";
		inventorySlot[] = { "Mask","Left_GasMask_KIP_Filter" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		rotationFlags = 2;
		weight = 1000;
		itemSize[] = { 3,4 };
		heatIsolation = 0.6;
		noHelmet = 0;
		class Protection
		{
			biological = 1;
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class X18_GasMask_KIP5G_P2_Duty : KIP5g_P2_Duty_AoD_GasMask
	{
		scope = 2;
		displayName = "Противогаз П2 «Белый» для «КИП5» (Одиночка)";
		descriptionShort = "Индивидуальное средство защиты органов дыхания, кожи лица и органов зрения от радиоактивной пыли и токсичных веществ. Оснащён отводами трубок для подключения к «КИП5»";
		inventorySlot[] = { "Mask","Left_GasMask_KIP_Filter" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		rotationFlags = 2;
		weight = 1000;
		itemSize[] = { 3,4 };
		heatIsolation = 0.6;
		noHelmet = 0;
		class Protection
		{
			biological = 1;
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class X18_GasMask_KIP5G_P2_Freedom : KIP5g_P2_Freedom_AoD_GasMask
	{
		scope = 2;
		displayName = "Противогаз П2 «Белый» для «КИП5» (Одиночка)";
		descriptionShort = "Индивидуальное средство защиты органов дыхания, кожи лица и органов зрения от радиоактивной пыли и токсичных веществ. Оснащён отводами трубок для подключения к «КИП5»";
		inventorySlot[] = { "Mask","Left_GasMask_KIP_Filter" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = { "Clothing","Headgear" };
		rotationFlags = 2;
		weight = 1000;
		itemSize[] = { 3,4 };
		heatIsolation = 0.6;
		noHelmet = 0;
		class Protection
		{
			biological = 1;
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
};
class CfgSlots
{
	class Slot_Left_GasMask_KIP_Filter
	{
		name = "Left_GasMask_KIP_Filter";
		displayName = "Left_GasMask_KIP_Filter";
		ghostIcon = "mask";
	};
	class Slot_Left_KIP_BackPack_Gas
	{
		name = "Left_KIP_BackPack_Gas";
		displayName = "Left_KIP_BackPack_Gas";
		ghostIcon = "gascanister";
	};
	class Slot_Right_KIP_BackPack_Gas
	{
		name = "Right_KIP_BackPack_Gas";
		displayName = "Right_KIP_BackPack_Gas";
		ghostIcon = "gascanister";
	};
};