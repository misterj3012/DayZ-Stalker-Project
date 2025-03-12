class RadiationShieldHandler
{
	protected PlayerBase m_Player;
	ref array<string> m_Slots = { "Vest", "Body", "Back", "Legs", "Headgear", "Mask", "Gloves", "Feet" };
	void RadiationShieldHandler(PlayerBase player)
	{
		m_Player = player;
	}
	void UpdateRadiationShield()
	{
		if (!m_Player || !m_Player.IsAlive())
			return;
		int shield = 0;
		EntityAI find;
		array<ref RadiationSuitItem> items;
		if (m_Player.m_RadiationSuit)
		{
			for (int x = 0; x < m_Slots.Count();x++)
			{
				if (Class.CastTo(find, m_Player.FindAttachmentBySlotName(m_Slots.Get(x))))
				{
					items = m_Player.m_RadiationSuit.GetItems(m_Slots.Get(x));
					if (items)
					{
						for (int i = 0;i < items.Count();i++)
						{
							private RadiationSuitItem item = items.Get(i);
							if ((item.className == find.GetType() && !find.IsInherited(GasMask_Base) && find.GetHealthLevel() <= 3) || (item.className == find.GetType() && find.GetHealthLevel() <= 3 && (find.IsInherited(GasMask_Base) && find.GetCompEM().CanWork() && find.GetCompEM().IsWorking())))
							{
								switch (find.GetHealthLevel())
								{
								case 0:
								case 1:
									shield += item.shield;
									break;
								case 2:
									shield += item.shield * 0.75;
									break;
								case 3:
									shield += item.shield / 2;
									break;
								default:
									shield += item.shield;
									break;
								}
							}
						}
					}
				}
			}
		}
		if (m_Player.GetModifiersManager().IsModifierActive(X18MedicalModifiers.MDF_RADIOPROTECTANT))
			shield += MedicalConfig.ShieldGivenByB190;
		if (m_Player.GetModifiersManager().IsModifierActive(X18MedicalModifiers.MDF_PC1))
			shield += MedicalConfig.ShieldGivenByPC1;
		m_Player.Shield = shield;
	}
}