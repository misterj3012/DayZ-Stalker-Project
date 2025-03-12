modded class ActionMeasureRadiationTarget
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		GeigerCounter_Base m_GeigerCounter;
		PlayerBase m_Player, m_Target;
		if (CastTo(m_GeigerCounter, action_data.m_MainItem) && CastTo(m_Player, action_data.m_Player) && CastTo(m_Target, action_data.m_Target.GetObject()))
			GetGame().RPCSingleParam(m_Player, EcologyRPC.SHOWRADIATIONONPLAYER, new Param2<int, float>(1, m_Target.GetStatRadiation().Get()), true, m_Player.GetIdentity());
	}
};