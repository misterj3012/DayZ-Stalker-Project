class StashSpawner
{
	protected static ref StashSpawner Instance;
	const private string m_ConfigFile = "StashSpawner.json";
	const private string m_LogText = "StashSpawner";
	bool m_StashConfigLoaded = false;
	ref StashConfig m_StashConfig;
	private ref array<string> m_WrongSymbols = { ">","<","," };
	private bool m_AllStashesSpawned = false;
	private float m_StashesDelayTimer = 0.0;
	protected ref array<ref SpawnedStashes> m_SpawnedStashArray = new ref array<ref SpawnedStashes>;
	string m_ImageUrl = GetDayZGame().GetX18Config().HostURL + GetDayZGame().GetX18Config().LogosPath;
	string m_DiscordMessagePath = GetDayZGame().GetX18Config().DiscordPath + "DiscordMessage.json";
	void StashSpawner()
	{
		if (GetDayZGame().GetX18Config().HostURL == "http:			m_ImageUrl = "http:		thread LoadConfigServer();
	}
	void ~StashSpawner()
	{
	}
	void _CheckForStashes(float deltaTime)
	{
		if (m_AllStashesSpawned && m_SpawnedStashArray.Count() > 0)
		{
			if (m_StashesDelayTimer >= GetConfig().TimeToCheckForStashFilling)
				thread CheckForStashes();
				m_StashesDelayTimer += deltaTime;
		}
	}
	void CheckForStashes()
	{
		for (int i = 0; i < m_SpawnedStashArray.Count(); ++i)
		{
			ref SpawnedStashes m_SpawnedStash = m_SpawnedStashArray.Get(i);
			if (m_SpawnedStash)
			{
				int deltaInSeconds = m_SpawnedStash.GetFillTime() - JMDate.Now(false).GetTimestamp();
				if (deltaInSeconds <= 0)
				{
					X18_StashesBase m_Stash = X18_StashesBase.Cast(m_SpawnedStash.GetStash());
					if (!m_Stash)
					{
						m_SpawnedStashArray.Remove(i);
						break;
					}
					SpawnInStash(m_Stash, m_SpawnedStash.GetItems(), m_SpawnedStash.GetItemLimit());
					m_SpawnedStashArray.Remove(i);
				}
			}
			else
				m_SpawnedStashArray.Remove(i);
		}
		m_StashesDelayTimer = 0.0;
	}
	private bool CreateDefaultConfig()
	{
		ref StashConfig t_StashConfig = CreateStashConfig();
		JsonFileLoader<StashConfig>.JsonSaveFile((StashesPath + m_ConfigFile), t_StashConfig);
		if (FileExist((StashesPath + m_ConfigFile)))
			return true;
		else
			return false;
	}
	void LoadConfigServer()
	{
		if (!FileExist(StashesPath))
			MakeDirectory(StashesPath);
		private bool m_ConfigReadSuccessful = false;
		ref StashConfig t_StashConfig;
		if (FileExist((StashesPath + m_ConfigFile))) {
			JsonFileLoader<StashConfig>.JsonLoadFile((StashesPath + m_ConfigFile), t_StashConfig);
			if (CheckConfigJSON(t_StashConfig))
				m_ConfigReadSuccessful = true;
		}
		else
		{
			if (CreateDefaultConfig())
			{
				JsonFileLoader<StashConfig>.JsonLoadFile((StashesPath + m_ConfigFile), t_StashConfig);
				if (CheckConfigJSON(t_StashConfig))
					m_ConfigReadSuccessful = true;
			}
		}
		if (m_ConfigReadSuccessful)
		{
			m_StashConfig = t_StashConfig;
			m_StashConfigLoaded = true;
		}
		LoadedConfigInfo();
	}
	void LoadedConfigInfo()
	{
		if (m_StashConfig)
		{
			if (m_StashConfig.Areas.Count() > 0)
				thread SpawnStashes();
		}
	}
	private bool CheckConfigJSONVector(vector position, bool position_only_more_null)
	{
		private bool m_CorrectConfig = true;
		if (!position)
			m_CorrectConfig = false;
		else
		{
			private TStringArray TempLoc = new TStringArray;
			private string pos_check = position.ToString();
			for (private int i = 0; i < m_WrongSymbols.Count(); i++)
			{
				if (pos_check.Contains(m_WrongSymbols.Get(i)))
					pos_check.Replace(m_WrongSymbols.Get(i), "");
			}
			if ((pos_check).Contains(" "))
				(pos_check).Split(" ", TempLoc);
			else
				m_CorrectConfig = false;
			if (TempLoc.Count() != 3)
				m_CorrectConfig = false;
			else
			{
				if (position_only_more_null)
				{
					foreach(string elem : TempLoc)
					{
						private float control_value = 0.0;
						if (elem.ToFloat() <= control_value)
							m_CorrectConfig = false;
					}
				}
			}
		}
		return m_CorrectConfig;
	}
	bool CheckConfigJSON(StashConfig DefaultCFG)
	{
		private bool m_CorrectConfig = true;
		if (DefaultCFG)
		{
			if (DefaultCFG.Areas.Count() < 1)
				m_CorrectConfig = false;
		}
		else
			m_CorrectConfig = false;
		return m_CorrectConfig;
	}
	private StashConfig CreateStashConfig()
	{
		ref StashConfig DefaultCFGMAIN = new StashConfig();
		ref map<string, map<string, float>> m_Areas = new map<string, map<string, float>>;
		map<string, float> m_AreasDetail = new map<string, float>;
		m_AreasDetail.Insert("Tier1", 50.0);
		m_Areas.Insert("Cordon", m_AreasDetail);
		m_Areas.Insert("GreatSwamps", m_AreasDetail);
		DefaultCFGMAIN.Areas = m_Areas;
		return DefaultCFGMAIN;
	}
	ref StashConfig GetConfig()
	{
		if (m_StashConfig && m_StashConfigLoaded)
			return m_StashConfig;
		else
			return NULL;
	}
	map<string, map<string, float>> GetAreas()
	{
		if (m_StashConfig && m_StashConfigLoaded)
			return m_StashConfig.Areas;
		else
			return NULL;
	}
	StashArea LoadBinFile(string file)
	{
		StashArea save_data = new StashArea();
		if (!FileExist(file))
			return save_data;
		FileSerializer file_serializer = new FileSerializer();
		if (!file_serializer.Open(file, FileMode.READ))
			return save_data;
		if (!save_data.Read(file_serializer))
		{
			file_serializer.Close();
			return save_data;
		}
		file_serializer.Close();
		return save_data;
	}
	ref array <ref StashObject> GetStashesList(string stashArea)
	{
		StashArea import_data = new StashArea();
		if (!FileExist(stashArea))
			return NULL;
		if (StashArea.IsBinnedFile(stashArea))
			import_data = LoadBinFile(stashArea);
		if (import_data)
			return import_data.Stashes;
		return NULL;
	}
	ref array <ref StashItems> GetItemsList(string m_LootFile)
	{
		if (FileExist(m_LootFile))
		{
			private ref StashLoot m_StashLoot;
			JsonFileLoader<StashLoot>.JsonLoadFile(m_LootFile, m_StashLoot);
			return m_StashLoot.Items;
		}
		return NULL;
	}
	string VectorToString(vector value)
	{
		private string return_val = "0 0 0";
		if (value)
		{
			return_val = value.ToString();
			for (private int i = 0; i < m_WrongSymbols.Count(); i++)
			{
				if (return_val.Contains(m_WrongSymbols.Get(i)))
					return_val.Replace(m_WrongSymbols.Get(i), "");
			}
		}
		return return_val;
	}
	void SpawnStashes()
	{
		private map<string, map<string, float>> m_Areas = GetAreas();
		private int m_MaxStashCount = 0;
		private string m_DiscordAreaMessage = "";
		for (int i = 0; i < m_Areas.Count(); ++i)
		{
			private int m_StashCount = 0;
			string m_StashFile = StashesPath + "Areas/" + m_Areas.GetKey(i) + ".ssf";
			if (FileExist(m_StashFile))
			{
				float m_SpawnChance = 0.0;
				private ref array <ref StashObject> m_TempStashes = GetStashesList(m_StashFile);
				private ref array <ref StashItems> m_TempItems;
				map<string, float> m_Test = m_Areas.GetElement(i);
				if (m_Test != NULL)
				{
					for (int j = 0; j < m_Areas.GetElement(i).Count(); ++j)
					{
						string m_LootFile = StashesPath + "Loot/" + m_Areas.GetElement(i).GetKey(j) + ".json";
						m_TempItems = GetItemsList(m_LootFile);
						m_SpawnChance = m_Areas.GetElement(i).GetElement(j);
					}
				}
				foreach(ref StashObject m_TempStash : m_TempStashes)
				{
					if (CalculateChance(m_SpawnChance))
					{
						if (m_Areas.GetKey(i) == "Documents" && !StashNearOtherStash(m_TempStash.Position, 150))
						{
							SpawnStash(m_TempStash.ClassName, VectorToString(m_TempStash.Position), VectorToString(m_TempStash.Orientation), m_TempItems, 3);
							m_StashCount++;
						}
						else if (m_Areas.GetKey(i) != "Documents")
						{
							SpawnStash(m_TempStash.ClassName, VectorToString(m_TempStash.Position), VectorToString(m_TempStash.Orientation), m_TempItems);
							m_StashCount++;
						}
					}
				}
				m_DiscordAreaMessage += "" + m_Areas.GetKey(i) + " has " + m_StashCount + " Stashes | Chance " + m_SpawnChance + "%!\n";
				m_MaxStashCount = m_MaxStashCount + m_StashCount;
				if (m_StashConfig.DebugLogs)
					PrintLog("From File: \"" + m_Areas.GetKey(i) + ".ssf\" were " + m_StashCount + " Stashes spawned!", m_LogText);
				m_StashCount = 0;
			}
		}
		m_AllStashesSpawned = true;
		m_DiscordAreaMessage += "\nSummary: " + m_MaxStashCount + " were spawned in total!";
		if (m_StashConfig.DebugLogs)
			PrintLog("Summary Count: " + m_MaxStashCount + " stashes were spawned in total!", m_LogText);
		if (GetConfig().PostToDiscord && GetConfig().DiscordWebhook != "")
		{
			ref DiscordMessage m_DiscordMessage;
			JsonFileLoader<DiscordMessage>.JsonLoadFile(m_DiscordMessagePath, m_DiscordMessage);
			string formattedUsername = m_DiscordMessage.username;
			formattedUsername.Replace("USERNAME", "StashSpawner");
			m_DiscordMessage.username = formattedUsername;
			string formattedAvatar = m_DiscordMessage.avatar_url;
			formattedAvatar.Replace("AVATARURL", m_ImageUrl + "Stash.png");
			m_DiscordMessage.avatar_url = formattedAvatar;
			foreach(ref DiscordMessageEmbeds globalEmbeds : m_DiscordMessage.embeds)
			{
				foreach(ref DiscordMessageEmbedsFields globalFields : globalEmbeds.fields)
				{
					string formattedMessageTitle = globalFields.name;
					formattedMessageTitle.Replace("MESSAGETITLE", "Nachricht");
					globalFields.name = formattedMessageTitle;
					string formattedString = globalFields.value;
					formattedString.Replace("MESSAGE", m_DiscordAreaMessage);
					globalFields.value = formattedString;
				}
				string formattedThumbnail = globalEmbeds.thumbnail.url;
				formattedThumbnail.Replace("THUMBNAILURL", m_ImageUrl + "Stash.png");
				globalEmbeds.thumbnail.url = formattedThumbnail;
			}
			GetDiscordHook().SetAlias("StashSpawner", GetConfig().DiscordWebhook);
			GetDiscordHook().SendEmbed("StashSpawner", m_DiscordMessage);
		}
		m_MaxStashCount = 0;
	}
	void SpawnStash(string ClassName, string StashPosition, string StashOrientation, array <ref StashItems> Items, int ItemLimit = 1000)
	{
		private vector position = StashPosition.ToVector();
		private vector orientation = StashOrientation.ToVector();
		if (ClassName && position)
		{
			X18_StashesBase m_Stash = X18_StashesBase.Cast(GetGame().CreateObjectEx(ClassName, position, ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS | ECE_KEEPHEIGHT));
			if (m_Stash)
			{
				m_Stash.SetPosition(position);
				m_Stash.SetOrientation(orientation);
				m_Stash.SetOrientation(m_Stash.GetOrientation());
				m_Stash.SetFlags(EntityFlags.STATIC, false);
				m_Stash.Update();
				m_Stash.SetAffectPathgraph(true, false);
				if (m_Stash.CanAffectPathgraph())
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, m_Stash);
				int m_Rnd = Math.RandomIntInclusive((GetConfig().MinTimeToStartSpawnItems * 60), (GetConfig().MaxTimeToStartSpawnItems * 60));
				int m_TimeToFillStash = JMDate.Now(false).GetTimestamp() + m_Rnd;
				if (m_StashConfig.DebugLogs)
					PrintLog("Spawn: [" + m_Stash.GetType() + "] at Position: [" + m_Stash.GetPosition().ToString() + "] with an ItemLimit of [" + ItemLimit + "] with timestamp: " + m_TimeToFillStash + "", m_LogText);
				InsertStash(m_Stash, Items, m_TimeToFillStash, ItemLimit);
			}
			else
			{
				if (m_StashConfig.DebugLogs)
					PrintLog("Could not spawn Stash: [" + ClassName + "] at Position: [" + position.ToString() + "]", m_LogText);
			}
		}
	}
	bool StashNearOtherStash(vector position, float radius = 1)
	{
		ref array<Object> nearest_objects = new array<Object>;
		ref array<CargoBase> proxy_cargos = new array<CargoBase>;
		GetGame().GetObjectsAtPosition(position, radius, nearest_objects, proxy_cargos);
		foreach(ref Object obj : nearest_objects)
		{
			if (obj.IsInherited(X18_StashesBase))
			{
				PrintLog("Stash found!");
				return true;
			}
		}
		return false;
	}
	void SpawnInStash(X18_StashesBase m_Stash, array <ref StashItems> Items, int ItemLimit = 1000)
	{
		if (m_Stash && Items.Count() > 0)
		{
			foreach(private ref StashItems Item : Items)
			{
				private string ClassName = Item.Item.ClassName;
				for (private int i = 0; i < Item.Item.Quantity; i++)
				{
					if (ClassName && CalculateChance(Item.Item.SpawnChance) && m_Stash.GetNumberOfItems() <= ItemLimit)
					{
						private bool was_closed = false;
						if (!m_Stash.IsOpen())
						{
							was_closed = true;
							m_Stash.Open();
						}
						EntityAI m_StashItem = EntityAI.Cast(m_Stash.GetInventory().CreateInInventory(ClassName));
						if (m_StashItem)
						{
							private ref array <ref StashItem> ItemAttachments = Item.ItemAttachments;
							private string Damaged = Item.Item.Damaged;
							private float Wet = Item.Item.Wet;
							private float Temperature = Item.Item.Temperature;
							private bool IsStacked = Item.Item.IsStacked;
							private float CountStack = Item.Item.CountStack;
							private string MeatFoodStage = Item.Item.MeatFoodStage;
							SetDamage(m_StashItem, Damaged);
							SetWet(m_StashItem, Wet);
							SetTemperature(m_StashItem, Temperature);
							SetStack(m_StashItem);
							SetStateForItem(ItemBase.Cast(m_StashItem), MeatFoodStage);
							if (was_closed)
								m_Stash.Close();
							if (m_StashConfig.DebugLogs)
								PrintLog("Spawn Item: [" + m_StashItem.GetType() + "] in Stash: [" + m_Stash.GetType() + "] at Position: [" + m_Stash.GetPosition().ToString() + "]", m_LogText);
							AddAttachments(m_Stash, m_StashItem, ItemAttachments);
						}
						else
						{
							if (m_StashConfig.DebugLogs)
								PrintLog("Could not spawn Item: [" + ClassName + "] in Stash: [" + m_Stash.GetType() + "] at Position: [" + m_Stash.GetPosition().ToString() + "]", m_LogText);
						}
					}
				}
			}
		}
	}
	void AddAttachments(X18_StashesBase m_Stash, EntityAI Item, array <ref StashItem> AttMassive)
	{
		if (m_Stash && Item && AttMassive.Count() > 0)
		{
			foreach(private ref StashItem Attachment : AttMassive)
			{
				private string ClassName = Attachment.ClassName;
				if (ClassName && CalculateChance(Attachment.SpawnChance))
				{
					private EntityAI m_ItemAttachment = EntityAI.Cast(Item.GetInventory().CreateAttachment(ClassName));
					if (m_ItemAttachment)
					{
						private string Damaged = Attachment.Damaged;
						private float Wet = Attachment.Wet;
						private float Temperature = Attachment.Temperature;
						private bool IsStacked = Attachment.IsStacked;
						private float CountStack = Attachment.CountStack;
						private string MeatFoodStage = Attachment.MeatFoodStage;
						SetDamage(m_ItemAttachment, Damaged);
						SetWet(m_ItemAttachment, Wet);
						SetTemperature(m_ItemAttachment, Temperature);
						SetStack(m_ItemAttachment);
						SetStateForItem(ItemBase.Cast(m_ItemAttachment), MeatFoodStage);
						if (m_StashConfig.DebugLogs)
							PrintLog("Spawn Attachment: [" + m_ItemAttachment.GetType() + "] for: [" + Item.GetType() + "] in Stash: [" + m_Stash.GetType() + "] at Position: [" + m_Stash.GetPosition().ToString() + "]", m_LogText);
					}
				}
				else
				{
					if (m_StashConfig.DebugLogs)
						PrintLog("Could not spawn Attachment: [" + ClassName + "] for Item: [" + Item.GetType() + "] in Stash: [" + m_Stash.GetType() + "] at Position: [" + m_Stash.GetPosition().ToString() + "]", m_LogText);
				}
			}
		}
	}
	void SetStateForItem(ItemBase item, string state_item)
	{
		private Edible_Base item_to_Edible_Base = Edible_Base.Cast(item);
		if (item_to_Edible_Base)
		{
			if (item_to_Edible_Base.IsFood())
			{
				switch (state_item)
				{
					case "RAW":
						{
							item_to_Edible_Base.ChangeFoodStage(FoodStageType.RAW);
							break;
						}
					case "BAKED":
						{
							item_to_Edible_Base.ChangeFoodStage(FoodStageType.BAKED);
							break;
						}
					case "BOILED":
						{
							item_to_Edible_Base.ChangeFoodStage(FoodStageType.BOILED);
							break;
						}
					case "DRIED":
						{
							item_to_Edible_Base.ChangeFoodStage(FoodStageType.DRIED);
							break;
						}
					case "BURNED":
						{
							item_to_Edible_Base.ChangeFoodStage(FoodStageType.BURNED);
							break;
						}
					case "ROTTEN":
						{
							item_to_Edible_Base.ChangeFoodStage(FoodStageType.ROTTEN);
							break;
						}
				}
			}
		}
	}
	void SetDamage(EntityAI itemType, string DamageValue)
	{
		private EntityAI ItemCasted = EntityAI.Cast(itemType);
		if (ItemCasted && DamageValue)
		{
			if (DamageValue == "Ruined")
				ItemCasted.SetHealth01("", "", 0);
			else if (DamageValue == "BadlyDamaged")
				ItemCasted.SetHealth01("", "", Math.RandomFloatInclusive(0.01, 0.3));
			else if (DamageValue == "Damaged")
				ItemCasted.SetHealth01("", "", Math.RandomFloatInclusive(0.31, 0.5));
			else if (DamageValue == "Worn")
				ItemCasted.SetHealth01("", "", Math.RandomFloatInclusive(0.51, 0.7));
			else if (DamageValue == "Pristine")
				ItemCasted.SetHealth01("", "", Math.RandomFloatInclusive(0.71, 1.0));
			else if (DamageValue == "Random")
				ItemCasted.SetHealth01("", "", Math.RandomFloatInclusive(0.15, 0.85));
		}
	}
	void SetWet(EntityAI itemType, float Value)
	{
		private ItemBase ItemCasted = ItemBase.Cast(itemType);
		if (ItemCasted && Value >= 0.1)
			ItemCasted.SetWet(Value);
	}
	void SetTemperature(EntityAI itemType, float Value)
	{
		private ItemBase ItemCasted = ItemBase.Cast(itemType);
		if (ItemCasted && (Value >= 0.1 || Value <= 0.1))
			ItemCasted.SetTemperature(Value);
	}
	void SetStack(EntityAI itemType)
	{
		if (itemType)
		{
			ItemBase item;
			Ammunition_Base ammoItem;
			bool hasSomeQuant = (ItemHasCount(itemType.GetType()) || ItemHasQuantity(itemType.GetType())) && !HasQuantityBar(itemType.GetType());
			int m_Value = 0;
			Class.CastTo(item, itemType);
			if (item && (ItemHasCount(itemType.GetType()) || ItemHasQuantity(itemType.GetType())))
			{
				if (item.IsRuined())
					return;
				if (!item.IsMagazine())
				{
					m_Value = Math.RandomIntInclusive(1, item.GetQuantityMax());
					item.SetQuantityExtended(m_Value);
					if (m_StashConfig.DebugLogs)
						PrintLog("SetStack for Item: " + item.GetType() + " with Amount: " + m_Value, m_LogText);
				}
			}
			Class.CastTo(ammoItem, itemType);
			if (ammoItem)
			{
				if (ammoItem.IsRuined())
					return;
				if (ammoItem.IsAmmoPile())
				{
					m_Value = Math.RandomIntInclusive(0, ammoItem.GetAmmoMax());
					ammoItem.SetQuantityExtended(m_Value);
					if (m_StashConfig.DebugLogs)
						PrintLog("SetStack for AmmoPile: " + ammoItem.GetType() + " with Amount: " + m_Value, m_LogText);
				}
			}
			if (!hasSomeQuant)
			{
				Magazine newMagItem = Magazine.Cast(itemType);
				Ammunition_Base newammoItem = Ammunition_Base.Cast(itemType);
				if (newMagItem && !newammoItem)
				{
					m_Value = Math.RandomIntInclusive(0, newMagItem.GetAmmoMax());
					newMagItem.ServerSetAmmoCount(m_Value);
					if (m_StashConfig.DebugLogs)
						PrintLog("SetStack for Magazine: " + newMagItem.GetType() + " NewAmmoItem: " + newammoItem.GetType(), m_LogText);
				}
			}
		}
	}
	void InsertStash(X18_StashesBase m_Stash, array <ref StashItems> m_Items, int m_FillInSeconds, int m_ItemLimit)
	{
		ref SpawnedStashes m_SpawnedStash = SpawnedStashes(m_Stash, m_Items, m_FillInSeconds, m_ItemLimit);
		m_SpawnedStashArray.Insert(m_SpawnedStash);
	}
}
static ref StashSpawner g_StashSpawner;
static StashSpawner GetStashSpawner()
{
	if (!g_StashSpawner)
		g_StashSpawner = new StashSpawner();
	return g_StashSpawner;
}
class SpawnedStashes
{
	protected X18_StashesBase m_Stash;
	protected array <ref StashItems> m_Items;
	protected int m_FillInSeconds;
	protected int m_ItemLimit;
	void SpawnedStashes(X18_StashesBase l_Stash, array <ref StashItems> l_Items, int l_FillInSeconds, int l_ItemLimit)
	{
		m_Stash = l_Stash;
		m_Items = l_Items;
		m_FillInSeconds = l_FillInSeconds;
		m_ItemLimit = l_ItemLimit;
	}
	X18_StashesBase GetStash()
	{
		return m_Stash;
	}
	array <ref StashItems> GetItems()
	{
		return m_Items;
	}
	int GetFillTime()
	{
		return m_FillInSeconds;
	}
	int GetItemLimit()
	{
		return m_ItemLimit;
	}
}