modded class X18_Anomaly_Space
{
	void X18_Anomaly_Space()
	{
		GetAnomalyManager().AddSpaceAnomaly(this);
	}
	void ~X18_Anomaly_Space()
	{
		GetAnomalyManager().RemoveSpaceAnomaly(this);
	}
	override void DamageAreaDamageActions(Object obj)
	{
		if (obj)
		{
			protected Anomaly_Base m_Exit;
			protected vector m_Destination;
			if (GetDestination() < 0)
				m_Destination = GetAnomalyManager().GetRandomSpaceAnomalyPosition(2, 4);
			else
				m_Destination = GetAnomalyManager().GetSpaceAnomalyDestination(GetDestination());

			PlayerBase m_Player;
			if (Class.CastTo(m_Player, obj))
			{
				m_Player.SetEnteredSpaceAnomaly(true);

				X18_Artefact_Compass_Base m_Compass = X18_Artefact_Compass_Base.Cast(m_Player.GetHumanInventory().GetEntityInHands());
				if (m_Compass && GetDestination() < 0)
				{
					int m_CompassLocationID = m_Compass.GetLocationIndex();
					m_Destination = GetAnomalyManager().GetSpaceAnomalyDestination(m_CompassLocationID);
					GetGame().ObjectDelete(m_Compass);
				}

				TeleportObject(m_Player, m_Destination);
				if (m_Player.GetFaction() != EFactions.Sin)
				{
					m_Player.AddHealth("", "Shock", -70);
					m_Player.GetStatStamina().Set(0);
				}
				m_Exit = Anomaly_Base.Cast(GetGame().CreateObjectEx("X18_Anomaly_Space_ExitFX", m_Destination, ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS | ECE_KEEPHEIGHT));
			}
			else
			{
				m_Exit = Anomaly_Base.Cast(GetGame().CreateObjectEx("X18_Anomaly_Space_ExitSoundFX", m_Destination, ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS | ECE_KEEPHEIGHT));
				obj.SetPosition(m_Destination);
			}

			if (m_Exit)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(m_Exit.Delete, 3000, false);
				PrintLog("Object: " + obj.GetType() + " has been teleported to: " + m_Destination);
			}
		}
	}
}