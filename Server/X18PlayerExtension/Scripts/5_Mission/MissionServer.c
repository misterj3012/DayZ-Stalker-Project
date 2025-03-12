modded class MissionServer
{
	protected PluginPlayerData m_PluginPlayerDataExtended;
	override void OnInit()
	{
		super.OnInit();
		m_PluginPlayerDataExtended = PluginPlayerData.Cast(GetPlugin(PluginPlayerData));
	}
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		if (m_PluginPlayerDataExtended)
			m_PluginPlayerDataExtended.GetPlayerDataExtended(player);

	}
	override void InvokeOnDisconnect(PlayerBase player)
	{
		super.InvokeOnDisconnect(player);
		if (m_PluginPlayerDataExtended)
			m_PluginPlayerDataExtended.UpdateLastBeardLength(player);

	}
}