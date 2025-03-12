modded class ActionMeasureRadiationSelf
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		GeigerCounter_Base m_GeigerCounter;
		PlayerBase m_Player;
		if (CastTo(m_GeigerCounter, action_data.m_MainItem) && CastTo(m_Player, action_data.m_Player))
			GetGame().RPCSingleParam(m_Player, EcologyRPC.SHOWRADIATIONONPLAYER, new Param2<int, float>(0, m_Player.GetStatRadiation().Get()), true, m_Player.GetIdentity());
	}
};