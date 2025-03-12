modded class PlayerBase
{
	bool m_Surrender;
	protected ref Timer m_UpdateTimer;
	protected bool m_IsTeleporting;
	const ref array<string> m_BleedingZones = { "Head", "Neck", "Pelvis", "Spine", "LeftShoulder", "LeftArm", "LeftArmRoll", "LeftForeArm", "RightShoulder", "RightArm", "RightArmRoll", "RightForeArm", "LeftForeArmRoll", "RightForeArmRoll", "LeftLeg", "LeftLegRoll", "LeftUpLeg", "LeftUpLegRoll", "RightLeg", "RightLegRoll", "RightUpLeg", "RightUpLegRoll", "LeftFoot", "LeftToeBase", "RightFoot", "RightToeBase" };
	protected bool m_Admin = false;
	override void Init()
	{
		super.Init();
		if (GetGame().IsServer())
		{
			m_UpdateTimer = new Timer(CALL_CATEGORY_GAMEPLAY);
			m_UpdateTimer.Run(0.01, this, "UpdateSurrender", NULL, true);
		}
		RegisterNetSyncVariableBool("m_Surrender");
		RegisterNetSyncVariableBool("m_Admin");
		SetSynchDirty();

		GetRPCManager().AddRPC("X18", "CreateCameraShake", this, SingleplayerExecutionType.Both);
	}
	bool MouthClosed()
	{
		ItemBase m_Mask = ItemBase.Cast(this.GetInventory().FindAttachment(InventorySlots.MASK));
		ItemBase m_Helmet = ItemBase.Cast(this.GetInventory().FindAttachment(InventorySlots.HEADGEAR));
		if ((m_Mask && !m_Mask.GetType().Contains("3H")) || (m_Helmet && m_Helmet.GetType().Contains("Seva")))
			return true;
		return false;
	}
	void SendMessage(string message)
	{
		Param1<string> Msgparam;
		Msgparam = new Param1<string>(message);
		GetGame().RPCSingleParam(this, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, GetIdentity());
		Print("[Noosphere] " + message);
	}
	void CreateCameraShake(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			Param1<float> cameraShakeData;
			if (!ctx.Read(cameraShakeData))
				return;
			DayZPlayerCamera camera = GetGame().GetPlayer().GetCurrentCamera();
			if (camera)
				camera.SpawnCameraShake(Math.Clamp(cameraShakeData.param1, 0.2, 1), 2, 5, 3.5);
		}
	}
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		float spawnDistance = vector.Distance(GetPosition(), "4695 55 1074");
		if (spawnDistance <= 337.0)
		{
			ref array<Object> m_ObjectsAroundDeathPlayer = new array<Object>;
			ref array<CargoBase> m_ProxyCargosAroundDeathPlayer = new array<CargoBase>;
			GetGame().GetObjectsAtPosition(GetPosition(), 10.0, m_ObjectsAroundDeathPlayer, m_ProxyCargosAroundDeathPlayer);
			for (int i = 0; i < m_ObjectsAroundDeathPlayer.Count(); i++)
			{
				Object m_ObjectAroundDeathPlayer = Object.Cast(m_ObjectsAroundDeathPlayer.Get(i));
				if (m_ObjectAroundDeathPlayer.IsInherited(ItemBase))
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().ObjectDelete, 2000, false, m_ObjectAroundDeathPlayer);
			}
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().ObjectDelete, 2000, false, this);
			EntityAI m_EntityAI = this.GetHumanInventory().GetEntityInHands();
			if (m_EntityAI)
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.DeleteItemInHands, 2000, false, m_EntityAI);
		}
	}
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		/*if (ammo.Contains("Melee"))
		{
			float stat = GetStatMeleeProtection().Get() * -1;
			float health = damageResult.GetDamage(dmgZone, "Health") * stat;
			float blood = damageResult.GetDamage(dmgZone, "Blood") * stat;
			float shock = damageResult.GetDamage(dmgZone, "Shock") * stat;
			if (damageResult.GetDamage(dmgZone, "Health") < GetHealth("", "Health"))
			{
				AddHealth("", "Health", health);
				AddHealth("", "Blood", blood);
				AddHealth("", "Shock", shock);
			}
			if (source.GetType().Contains("Bloodsucker"))
			{
				blood = blood + source.GetHealth();
				source.SetHealth("", "Health", blood);
			}
		}
		else if (ammo.Contains("Bullet"))
		{
			stat = GetStatBulletProtection().Get() * -1;
			health = damageResult.GetDamage(dmgZone, "Health") * stat;
			blood = damageResult.GetDamage(dmgZone, "Blood") * stat;
			shock = damageResult.GetDamage(dmgZone, "Shock") * stat;
			if (damageResult.GetDamage(dmgZone, "Health") < GetHealth("", "Health"))
			{
				AddHealth("", "Health", health);
				AddHealth("", "Blood", blood);
				AddHealth("", "Shock", shock);
			}
		}*/
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
	}
	override float GetPlayerLoad()
	{
		return super.GetPlayerLoad() * (1.0 + GetStatInventoryWeightReduction().Get());
	}
	override void AddPlayerLoad(float addedload)
	{
		float newload = m_CargoLoad + addedload;
		SetPlayerLoad(newload);
	}
	PlayerStat<float> GetStatBloodLossModifier()
	{
		if (GetPlayerStats())
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EX18PlayerStats_Core.BLOOD_LOSS));
			return stat;
		}
		return null;
	}
	PlayerStat<float> GetStatInventoryWeightReduction()
	{
		if (GetPlayerStats())
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EX18PlayerStats_Core.WEIGHT_REDUCTION));
			return stat;
		}
		return null;
	}
	PlayerStat<float> GetStatBulletProtection()
	{
		if (GetPlayerStats())
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EX18PlayerStats_Core.BULLET_PROTECTION));
			return stat;
		}
		return null;
	}
	PlayerStat<float> GetStatMeleeProtection()
	{
		if (GetPlayerStats())
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EX18PlayerStats_Core.MELEE_PROTECTION));
			return stat;
		}
		return null;
	}
	void DeleteItemInHands(EntityAI m_EntityAI)
	{
		if (!m_EntityAI.GetHierarchyRootPlayer())
			GetGame().ObjectDelete(m_EntityAI);
	}
	EntityAI HasWorkingItem(string type)
	{
		array<EntityAI> itemsArray = new array<EntityAI>;
		this.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
		ItemBase itemInHands = this.GetItemInHands();
		if (itemInHands)
			itemsArray.Insert(itemInHands);
		ItemBase item;
		for (int i = 0; i < itemsArray.Count(); i++)
		{
			ItemBase.CastTo(item, itemsArray.Get(i));
			if (item && item.IsKindOf(type) && !item.IsRuined() && item.HasEnergyManager() && item.GetCompEM().CanWork() && item.GetCompEM().IsWorking())
				return item;
		}
		return NULL;
	}
	array<EntityAI> CheckItemsInPlayerItemList(typename itemType, array<string> BlackList_Classnames, bool n_CheckInPlayersInventory = true, bool m_CheckInPlayersHands = true, bool SearchClassNamesInBlackList = false)
	{
		if (this && itemType)
		{
			private array<EntityAI> m_FoundItemsList = new array<EntityAI>;
			private array<EntityAI> m_ItemListPlayer = GetAllItemsInPlayer(BlackList_Classnames, n_CheckInPlayersInventory, m_CheckInPlayersHands, SearchClassNamesInBlackList);
			if (m_ItemListPlayer)
			{
				if (m_ItemListPlayer.Count() > 0)
				{
					foreach(private EntityAI m_TempItem : m_ItemListPlayer)
					{
						if (m_TempItem)
						{
							if (m_TempItem.IsInherited(itemType))
								m_FoundItemsList.Insert(m_TempItem);
						}
					}
				}
			}
			if (m_FoundItemsList)
				return m_FoundItemsList;
		}
		return NULL;
	}
	private array<EntityAI> GetAllItemsInPlayer(array<string> BlackList_Classnames, bool n_CheckInPlayersInventory = true, bool m_CheckInPlayersHands = true, bool SearchClassNamesInBlackList = false)
	{
		private array<EntityAI> m_ItemListPlayer = new array<EntityAI>;
		private array<EntityAI> m_ItemsInPlayer = new array<EntityAI>;
		if (m_CheckInPlayersHands)
		{
			private EntityAI m_ItemInPlayersHands = this.GetHumanInventory().GetEntityInHands();
			if (m_ItemInPlayersHands != NULL)
			{
				if (!SearchClassNamesInBlackList)
				{
					if (BlackList_Classnames.Find(m_ItemInPlayersHands.GetType()) < 0)
						m_ItemsInPlayer.Insert(m_ItemInPlayersHands);
				}
				else
					m_ItemsInPlayer.Insert(m_ItemInPlayersHands);
			}
		}
		if (n_CheckInPlayersInventory)
		{
			m_ItemListPlayer = GetItemListInObject(NULL, true);
			if (m_ItemListPlayer.Count() > 0)
			{
				foreach(EntityAI m_ItemPlayer : m_ItemListPlayer)
				{
					if (m_ItemPlayer)
					{
						private bool can_next_action = true;
						if (!SearchClassNamesInBlackList)
						{
							if (BlackList_Classnames.Find(m_ItemPlayer.GetType()) >= 0)
								can_next_action = false;
						}
						if (can_next_action)
						{
							private array<EntityAI> m_ItemInItemInInventory = GetItemListInObject(m_ItemPlayer, false);
							private CargoBase m_Cargo = m_ItemPlayer.GetInventory().GetCargo();
							if (m_Cargo)
							{
								if (m_Cargo.GetItemCount() > 0)
								{
									for (int f = 0; f < m_Cargo.GetItemCount(); f++)
									{
										if (m_Cargo.GetItem(f))
										{
											if (!SearchClassNamesInBlackList)
											{
												if (BlackList_Classnames.Find((m_Cargo.GetItem(f)).GetType()) < 0)
													m_ItemsInPlayer.Insert(m_Cargo.GetItem(f));
											}
											else
												m_ItemsInPlayer.Insert(m_Cargo.GetItem(f));
										}
									}
								}
							}
							if (m_ItemInItemInInventory.Count() > 0)
							{
								foreach(EntityAI m_TempItems : m_ItemInItemInInventory)
								{
									if (m_TempItems)
									{
										if (!SearchClassNamesInBlackList)
										{
											if (BlackList_Classnames.Find(m_TempItems.GetType()) < 0)
												m_ItemsInPlayer.Insert(m_TempItems);
										}
										else
											m_ItemsInPlayer.Insert(m_TempItems);
									}
								}
							}
							m_ItemsInPlayer.Insert(m_ItemPlayer);
						}
					}
				}
			}
		}
		if (m_ItemsInPlayer.Count() > 0)
			return m_ItemsInPlayer;
		else
			return NULL;
	}
	private array<EntityAI> GetItemListInObject(EntityAI item, bool check_player)
	{
		array<EntityAI> EntityAI_list_items = new array<EntityAI>;
		EntityAI_list_items.Clear();
		int	attIdx = 0; int attCount = 0; EntityAI		item_in_object;
		if ((this) && (check_player))
		{
			attCount = this.GetInventory().AttachmentCount();
			for (attIdx = 0; attIdx < attCount; attIdx++)
			{
				item_in_object = this.GetInventory().GetAttachmentFromIndex(attIdx);
				if (item_in_object.IsItemBase())
					EntityAI_list_items.Insert(item_in_object);
			}
		}
		if ((item) && !check_player)
		{
			attCount = item.GetInventory().AttachmentCount();
			for (attIdx = 0; attIdx < attCount; attIdx++)
			{
				item_in_object = item.GetInventory().GetAttachmentFromIndex(attIdx);
				if (item_in_object.IsItemBase())
					EntityAI_list_items.Insert(item_in_object);
			}
		}
		return EntityAI_list_items;
	}
	void UpdateSurrender()
	{
		if (m_EmoteManager && m_EmoteManager.m_Callback && m_EmoteManager.m_Callback.m_callbackID == 1113)
			m_Surrender = true;
		if (m_EmoteManager && m_EmoteManager.m_Callback && m_EmoteManager.m_Callback.m_callbackID == 1114)
			m_Surrender = false;
		SetSynchDirty();
	}
	override bool CanManipulateInventory()
	{
		if (IsControlledPlayer())
			return !IsRestrained() && !IsRestrainPrelocked() && !m_Surrender;
		return true;
	}
	bool IsTeleporting()
	{
		return m_IsTeleporting;
	}
	void SetTeleporting(bool state)
	{
		m_IsTeleporting = state;
	}
	float GetSingleAgentMaxCount(int agent_id)
	{
		return PluginTransmissionAgents.GetAgentMaxCount(agent_id);
	}
	void SetAgentCount(int agent_id, float value)
	{
		m_AgentPool.SetAgentCount(agent_id, value);
	}
	EStatLevels GetStatLevelReverse(float stat_value, float critical, float low, float normal, float high)
	{
		if (stat_value >= critical)
			return EStatLevels.CRITICAL;
		if (stat_value >= high)
			return EStatLevels.LOW;
		if (stat_value >= normal)
			return EStatLevels.MEDIUM;
		if (stat_value >= low)
			return EStatLevels.HIGH;
		return EStatLevels.GREAT;
	}
	bool IsAdminActive()
	{
		return m_Admin;
	}
}