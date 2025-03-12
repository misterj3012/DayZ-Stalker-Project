modded class MissionServer
{
	ref EcologySystem m_EcologySystem;
	override void OnInit()
	{
		super.OnInit();
	}
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		if (!m_EcologySystem)
			m_EcologySystem = new EcologySystem();
	}
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		if (player)
			m_EcologySystem.SendPlayerAllData(player);
	}
	override void OnClientReconnectEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReconnectEvent(identity, player);
		if (player)
			m_EcologySystem.SendPlayerAllData(player);
	}
}