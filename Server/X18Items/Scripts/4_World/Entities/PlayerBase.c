modded class PlayerBase
{
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		private EntityAI newItem;
		private ref array<EntityAI> m_ItemToRuin;
		float max;
		m_ItemToRuin = this.FindInheritedItemInInventory(Sin_BeastMaster_SS);

		if (m_ItemToRuin)
		{
			foreach(EntityAI m_DeathWhistle : m_ItemToRuin)
			{
				newItem = EntityAI.Cast(m_DeathWhistle);
				if (newItem)
				{
					max = newItem.GetMaxHealth("", "");
					newItem.SetHealth("", "", max * GameConstants.DAMAGE_RUINED_VALUE);
				}
			}
			m_ItemToRuin.Clear();
		}
		m_ItemToRuin = this.FindInheritedItemInInventory(VoiceExtortionItem);
		if (m_ItemToRuin)
		{
			foreach(EntityAI m_ExtortionItem : m_ItemToRuin)
			{
				newItem = EntityAI.Cast(m_ExtortionItem);
				if (newItem)
				{
					max = newItem.GetMaxHealth("", "");
					newItem.SetHealth("", "", max * GameConstants.DAMAGE_RUINED_VALUE);
				}
			}
			m_ItemToRuin.Clear();
		}
		m_ItemToRuin = this.FindInheritedItemInInventory(X18_GasMask_CN2F);
		if (m_ItemToRuin)
		{
			foreach(EntityAI m_GasMaskCN2F : m_ItemToRuin)
			{
				newItem = EntityAI.Cast(m_GasMaskCN2F);
				if (newItem)
				{
					max = newItem.GetMaxHealth("", "");
					newItem.SetHealth("", "", max * GameConstants.DAMAGE_RUINED_VALUE);
				}
			}
			m_ItemToRuin.Clear();
		}
	}
};