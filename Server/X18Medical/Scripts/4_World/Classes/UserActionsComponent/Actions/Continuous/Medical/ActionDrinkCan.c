modded class ActionDrinkCan
{
	override void OnEndServer(ActionData action_data)
	{
		if (action_data.m_MainItem && action_data.m_MainItem.GetQuantity() <= 0.01 && action_data.m_MainItem.GetType() == "X18_EnergyStalker")
		{
			PlayerBase m_Player = action_data.m_Player;
			if (m_Player.GetModifiersManager().IsModifierActive(X18MedicalModifiers.MDF_ENERGYSTALKER))
				m_Player.GetModifiersManager().DeactivateModifier(X18MedicalModifiers.MDF_ENERGYSTALKER);
			m_Player.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_ENERGYSTALKER);
		}
		super.OnEndServer(action_data);
	}
};