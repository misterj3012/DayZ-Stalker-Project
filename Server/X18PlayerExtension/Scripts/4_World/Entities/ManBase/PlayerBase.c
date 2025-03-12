modded class PlayerBase
{
	override void ShavePlayer()
	{
		super.ShavePlayer();
		protected PluginPlayerData m_PluginPlayerDataExtended;
		m_PluginPlayerDataExtended = PluginPlayerData.Cast(GetPlugin(PluginPlayerData));
		if (m_PluginPlayerDataExtended)
			m_PluginPlayerDataExtended.UpdateLastBeardLength(this);
	}
}