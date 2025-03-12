modded class ActionForceDrinkVodka
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		PlayerBase ntarget = PlayerBase.Cast(action_data.m_Target.GetObject());
		Param1<float> nacdata = Param1<float>.Cast(action_data.m_ActionComponent.GetACData());
		float delta = nacdata.param1;
		ntarget.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_ANTIRADVODKA);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
	}
};