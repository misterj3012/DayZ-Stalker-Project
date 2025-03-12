class Detector_Base : ItemBase
{
	private float LootDistance = -1;
	private int timeNearArtefact = 0;
	void DetectorBase()
	{
		RegisterNetSyncVariableFloat("LootDistance");
	}
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		ItemBase itemBase = ItemBase.Cast(item);
		if (itemBase && itemBase.IsKindOf("Battery9V"))
		{
			if (!GetGame().IsDedicatedServer())
				SEffectManager.PlaySoundOnObject("BatteryInsert_SoundSet", this);
		}
		ResetValues();
	}
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		ItemBase itemBase = ItemBase.Cast(item);
		if (itemBase && itemBase.IsKindOf("Battery9V"))
		{
			if (!GetGame().IsDedicatedServer())
				SEffectManager.PlaySoundOnObject("BatteryRemove_SoundSet", this);
		}
		ResetValues();
	}
	override void OnWork(float consumed_energy)
	{
		super.OnWork(consumed_energy);
		if (!GetGame().IsDedicatedServer())
		{
			PlayerBase m_Source = PlayerBase.Cast(this.GetHierarchyParent());
			int m_Tier = GetTier();
			ItemBase m_Battery;
			if (CastTo(m_Battery, this.FindAttachmentBySlotName("BatteryD")) && m_Battery.IsKindOf("Battery15V") && (m_Battery.GetCompEM().GetEnergy() >= m_Battery.GetCompEM().GetEnergyMaxPristine() / 2))
				m_Tier++;
			LootDistance = -1;
			ref array<Object> nearest_objects = new array<Object>;
			ref array<CargoBase> proxy_cargos = new array<CargoBase>;
			GetGame().GetObjectsAtPosition(GetPosition(), GetLootDetectRadius(), nearest_objects, proxy_cargos);
			foreach(ref Object obj : nearest_objects)
			{
				if (obj.IsInherited(X18_Artefact_Spawn_Base))
				{
					X18_Artefact_Spawn_Base m_Artefact = X18_Artefact_Spawn_Base.Cast(obj);
					if (m_Artefact && m_Artefact.GetTier() <= m_Tier)
					{
						float distance = Distance2D(m_Artefact.GetPosition(), GetPosition());
						if (distance <= GetLootDetectRadius())
						{
							LootDistance = distance;
							if (distance <= 4.0)
							{
								timeNearArtefact++;
								if (timeNearArtefact >= GetDetectTime())
								{
									ResetValues();
									if (m_Source)
										GetRPCManager().SendRPC("X18_RPCManager", "SpawnArtefact", new Param2<X18_Artefact_Spawn_Base, vector>(m_Artefact, m_Artefact.GetPosition()), true);
								}
							}
							else
								timeNearArtefact = 0;
							return;
						}
					}
				}
			}
		}
	}
	void ResetValues()
	{
		this.LootDistance = -1;
		this.timeNearArtefact = 0;
	}
	float GetLootDetectRadius() { return 0; }
	int GetTier() { return 0; }
	int GetDetectTime() { return 0; }
	override void OnWorkStart()
	{}
	override void OnWorkStop()
	{
		super.OnWorkStop();
		ResetValues();
	}
	float GetLootDistance()
	{
		return LootDistance;
	}
}