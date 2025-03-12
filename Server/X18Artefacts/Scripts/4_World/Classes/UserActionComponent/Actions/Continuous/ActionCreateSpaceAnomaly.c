modded class ActionCreateSpaceAnomaly
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		if (action_data.m_Player.GetFaction() != EFactions.Sin)
			return;

		X18_Artefact_Compass_Base m_Compass = X18_Artefact_Compass_Base.Cast(action_data.m_MainItem);
		if (m_Compass)
		{
			X18_Anomaly_Space m_SpaceAnomaly = X18_Anomaly_Space.Cast(GetGame().CreateObjectEx("X18_Anomaly_Space", action_data.m_Target.GetCursorHitPos(), ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS | ECE_KEEPHEIGHT));
			if (m_SpaceAnomaly)
			{
				m_SpaceAnomaly.SetDestination(m_Compass.GetLocationIndex());
				GetGame().ObjectDelete(m_Compass);
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(m_SpaceAnomaly.Delete, 180000, false);
			}
		}
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		string message;
		X18_Artefact_Compass_Base m_Compass = X18_Artefact_Compass_Base.Cast(action_data.m_MainItem);
		if (m_Compass)
			message = string.Format("Player %1 created a Space Anomaly at position %2 with destination %3", action_data.m_Player, action_data.m_Target.GetCursorHitPos(), m_Compass.GetLocationIndex());
		else
			message = string.Format("Player %1 created a Space Anomaly at position %2", action_data.m_Player, action_data.m_Target.GetCursorHitPos());
		return message;
	}
};