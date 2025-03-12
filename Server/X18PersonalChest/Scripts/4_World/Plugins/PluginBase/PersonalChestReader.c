class PersonalChestReader : PluginBase
{
	const protected string CFG_PATH = ProfilePath + "PersonalChest\\";
	private ref map<PlayerBase, PersonalChest> m_PersonalChest = new map <PlayerBase, PersonalChest>;
	protected ref array<ref Town> m_PCTownEntries;

	void PersonalChestReader()
	{
		m_PCTownEntries = Town.GetMapTowns(ExtendedTownFlags.PERSONALCHEST);
		CheckDir();
	}

	bool IsPersonalChestExist(PlayerBase player)
	{
		if (player)
		{
			if (m_PersonalChest.Get(player))
				return true;
		}
		return false;
	}
	protected string GetFileName(string uid)
	{
		return uid + ".json";
	}
	protected void CheckDir()
	{
		if (!FileExist(CFG_PATH))
			MakeDirectory(CFG_PATH);

		foreach(Town town : m_PCTownEntries)
		{
			if (!FileExist(CFG_PATH + town.Name))
				MakeDirectory(CFG_PATH + town.Name);
		}
	}
	void SaveChestToConfig(PlayerBase player)
	{
		if (player && m_PCTownEntries)
		{
			Town closest_town;
			foreach(Town town : m_PCTownEntries)
			{
				if (!closest_town || vector.Distance(player.GetPosition(), town.Position) < vector.Distance(player.GetPosition(), closest_town.Position))
					closest_town = town;
			}
			if (closest_town && vector.Distance(player.GetPosition(), closest_town.Position) <= 50)
			{
				ItemBase chest = m_PersonalChest.Get(player);
				EntityJSON data = CollectDataFromEntity(chest);
				data.width = chest.GetInventory().GetCargo().GetWidth();
				data.height = chest.GetInventory().GetCargo().GetHeight();
				JsonFileLoader<EntityJSON>.JsonSaveFile((CFG_PATH + closest_town.Name + "\\" + GetFileName(player.GetSteamID())), data);
				GetGame().ObjectDelete(chest);
				m_PersonalChest.Remove(player);
			}
		}
	}
	protected EntityJSON CollectDataFromEntity(ItemBase entity)
	{
		EntityJSON data = new EntityJSON();
		if (entity)
		{
			data.type = entity.GetType();
			data.health = entity.GetHealth01("", "");
			data.quantity = entity.GetQuantity();
			if (entity.IsAmmoPile() || entity.IsMagazine())
			{
				data.ammo = Magazine_Base.Cast(entity).GetAmmoCount();
				data.isAmmo = true;
			}
			else if (entity.IsFood() || entity.IsFruit() || entity.IsMeat() || entity.IsMushroom())
			{
				data.isFood = true;
				data.foodStage = Edible_Base.Cast(entity).GetFoodStageType();
			}
			data.attachments = ReadEntityAttachments(entity);
			data.cargo = ReadEntityCargo(entity);
		}
		return data;
	}
	protected array<ref EntityJSON> ReadEntityAttachments(ItemBase entity)
	{
		array<ref EntityJSON> entity_json_attachments = new array<ref EntityJSON>;
		int count = entity.GetInventory().GetAttachmentSlotsCount();
		if (count > 0)
		{
			ItemBase attachement_item;
			int slotId;
			EntityJSON data;
			for (int i = 0; i < count; i++)
			{
				slotId = entity.GetInventory().GetAttachmentSlotId(i);
				attachement_item = ItemBase.Cast(entity.GetInventory().FindAttachment(slotId));
				if (attachement_item)
				{
					data = CollectDataFromEntity(attachement_item);
					data.slotId = slotId;
					entity_json_attachments.Insert(data);
				}
			}
		}
		return entity_json_attachments;
	}
	protected array<ref EntityJSON> ReadEntityCargo(ItemBase entity)
	{
		array<ref EntityJSON> entity_json_cargo = new array<ref EntityJSON>;
		CargoBase cargo = entity.GetInventory().GetCargo();
		if (cargo)
		{
			int count = cargo.GetItemCount();
			if (count > 0)
			{
				int row, col, w, h;
				int flip;
				ItemBase cargo_item;
				EntityJSON data;
				for (int i = 0; i < count; i++)
				{
					cargo_item = ItemBase.Cast(cargo.GetItem(i));
					cargo.GetItemRowCol(i, row, col);
					cargo.GetItemSize(i, w, h);
					data = CollectDataFromEntity(cargo_item);
					data.row = row;
					data.col = col;
					data.width = w;
					data.height = h;
					data.flip = cargo_item.GetInventory().GetFlipCargo();
					entity_json_cargo.Insert(data);
				}
			}
		}
		return entity_json_cargo;
	}
	void ReadChestFromConfig(PlayerBase player)
	{
		if (player && m_PCTownEntries)
		{
			Town closest_town;
			foreach(Town town : m_PCTownEntries)
			{
				if (!closest_town || vector.Distance(player.GetPosition(), town.Position) < vector.Distance(player.GetPosition(), closest_town.Position))
					closest_town = town;
			}
			if (closest_town && vector.Distance(player.GetPosition(), closest_town.Position) <= 100)
			{
				EntityJSON data = new EntityJSON();
				ItemBase chest = m_PersonalChest.Get(player);
				if (!FileExist(CFG_PATH + closest_town.Name + "\\" + GetFileName(player.GetSteamID())))
				{
					PrintFormat("[PersonalChest]: Create default chest for %1 - %2 at: %3", player.GetSteamID(), player.GetIdentity().GetName(), closest_town.Name);
					if (closest_town.Name == "RookieVillage")
						data = CreateDefaultChest("PersonalChest_25_Guns2_Clothes");
					else
						data = CreateDefaultChest("PersonalChest_50");
				}
				else
				{
					data = ReadChestFromFile(player, closest_town);
				}
				GetGame().ObjectDelete(chest);
				SpawnChestByData(data, player);

			}
		}
	}
	protected EntityJSON CreateDefaultChest(string type)
	{
		EntityJSON data = new EntityJSON();
		data.type = type;
		return data;
	}
	protected EntityJSON ReadChestFromFile(PlayerBase player, Town town)
	{
		EntityJSON data;
		if (player && town)
			JsonFileLoader<EntityJSON>.JsonLoadFile((CFG_PATH + town.Name + "\\" + GetFileName(player.GetSteamID())), data);
		return data;
	}
	protected void SpawnChestByData(EntityJSON data, PlayerBase player)
	{
		if (player && data != NULL)
		{
			EntityAI personalChest = EntityAI.Cast(GetGame().CreateObject(data.type, player.GetPosition(), false));
			if (personalChest)
			{
				PersonalChest chest = PersonalChest.Cast(personalChest);
				m_PersonalChest.Set(player, chest);
				GetGame().RPCSingleParam(chest, X18PersonalChestERPCs.SET_PERSONAL, null, true, player.GetIdentity());
				CreateAttachments(personalChest, data.attachments, player.GetPosition());
				CreateCargo(personalChest, data.cargo, player.GetPosition());
			}
		}
	}
	protected void ConfigureChildEntity(EntityAI entity, EntityJSON data, vector pos = "0 0 0", bool is_in_attachment = false)
	{
		entity.SetHealth01("", "", data.health);
		ItemBase item;
		if (Class.CastTo(item, entity) && item.HasQuantity())
			item.SetQuantity(data.quantity);
		if (data.isAmmo)
			Magazine_Base.Cast(entity).ServerSetAmmoCount(data.ammo);
		else if (data.isFood)
			Edible_Base.Cast(entity).ChangeFoodStage(data.foodStage);
		CreateAttachments(entity, data.attachments, pos, is_in_attachment);
		CreateCargo(entity, data.cargo, pos, is_in_attachment);
	}
	protected void CreateAttachments(EntityAI entity, array<ref EntityJSON> attachments, vector pos, bool is_in_attachment = false)
	{
		if (attachments && attachments.Count() > 0)
		{
			foreach(EntityJSON attachment : attachments)
			{
				EntityAI new_attachment = EntityAI.Cast(entity.GetInventory().CreateAttachmentEx(attachment.type, attachment.slotId));
				if (new_attachment)
					ConfigureChildEntity(new_attachment, attachment, pos, true);
			}
		}
	}
	protected void CreateCargo(EntityAI entity, array<ref EntityJSON> cargos, vector pos, bool is_in_attachment = false)
	{
		if (cargos && cargos.Count() > 0)
		{
			foreach(EntityJSON cargo : cargos)
			{
				int cargo_index = entity.GetInventory().GetCargo().GetOwnerCargoIndex();
				EntityAI new_cargo;
				if (is_in_attachment)
					new_cargo = EntityAI.Cast(GetGame().CreateObject(cargo.type, pos, false));
				else
					new_cargo = EntityAI.Cast(entity.GetInventory().CreateEntityInCargoEx(cargo.type, cargo_index, cargo.row, cargo.col, cargo.flip));
				if (new_cargo)
				{
					ConfigureChildEntity(new_cargo, cargo, pos, is_in_attachment);
					if (is_in_attachment)
					{
						new_cargo.GetInventory().SetFlipCargo(cargo.flip);
						entity.GetInventory().TakeEntityToCargoEx(InventoryMode.SERVER, new_cargo, cargo_index, cargo.row, cargo.col);
					}
				}
			}
		}
	}
}
class EntityJSON
{
	int row, col, width, height, slotId;
	float health;
	string type;
	float quantity;
	bool isAmmo;
	int ammo;
	bool flip;
	bool isFood;
	int foodStage;
	ref array<ref EntityJSON> attachments;
	ref array<ref EntityJSON> cargo;
}
PersonalChestReader GetPersonalChestReader()
{
	return PersonalChestReader.Cast(GetPluginManager().GetPluginByType(PersonalChestReader));
}