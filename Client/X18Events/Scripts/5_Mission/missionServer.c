modded class MissionServer
{
	override void HandleBody(PlayerBase player)
	{
		if (!player)
			return;
		if (player.IsAlive() && !player.IsRestrained() && m_EventManager && m_EventManager.IsEventActive(Emission) && m_EventManager.GetEvent(Emission).GetCurrentPhase() > 0)
		{
			player.Delete();
			return;
		}
		super.HandleBody(player);
	}
	override void OnClientRespawnEvent(PlayerIdentity identity, PlayerBase player)
	{
		if (!player)
			return;
		if (m_EventManager && m_EventManager.IsEventActive(Emission) && m_EventManager.GetEvent(Emission).GetCurrentPhase() > 0)
			return;
		super.OnClientRespawnEvent(identity, player);
	}
};