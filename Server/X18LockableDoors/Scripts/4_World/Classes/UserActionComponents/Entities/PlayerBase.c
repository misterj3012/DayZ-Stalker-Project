modded class PlayerBase
{
	override void OnConnect()
	{
		super.OnConnect();
		if (GetGame().IsServer())
		{
			ref LockDoorConfig m_Config = GetLDConfigHandler().GetConfig();
			if (m_Config != NULL)
				GetRPCManager().SendRPC("X18", "SetDoorDataFromServer", new Param1<ref LockDoorConfig>(m_Config), true, GetIdentity());
		}
	}
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		private EntityAI newItem;
		private ref array<EntityAI> m_FoundKey;
		m_FoundKey = this.FindInheritedItemInInventory(X18_Key_Base);

		if (m_FoundKey)
		{
			foreach(EntityAI m_Key : m_FoundKey)
			{
				newItem = EntityAI.Cast(m_Key);
				if (newItem)
				{
					float max = newItem.GetMaxHealth("", "");
					newItem.SetHealth("", "", max * GameConstants.DAMAGE_RUINED_VALUE);
				}
			}
		}
	}
};