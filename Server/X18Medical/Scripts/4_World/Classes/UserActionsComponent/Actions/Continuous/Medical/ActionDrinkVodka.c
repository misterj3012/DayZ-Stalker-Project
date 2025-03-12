modded class ActionDrinkVodka
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		if (action_data.m_MainItem.GetLiquidType() == LIQUID_VODKA)
		{
			action_data.m_MainItem.TransferModifiers(action_data.m_Player);
			action_data.m_Player.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_ANTIRADVODKA);
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
		}
	}
};