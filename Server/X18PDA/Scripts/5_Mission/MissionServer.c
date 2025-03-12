modded class MissionServer
{
	protected MessageManager m_MessageManager;
	protected PluginPDALogic m_PluginPDA;

	override void OnInit()
	{
		super.OnInit();
		m_MessageManager = GetMessageManager();
		m_PluginPDA = PluginPDALogic.Cast(GetPlugin(PluginPDALogic));
	}
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		ref PDAFactionConfig faction = null;
		if (m_PluginPDA)
		{
			if (m_PluginPDA.FindFactionMember(identity, faction) && faction)
			{
				player.SetFaction(faction.ID);
				m_PluginPDA.UpdatePlayerData(identity, faction.ID);
				m_PluginPDA.UpdatePlayerStatus(identity, faction.ID, true);
			}
		}
	}
	override void InvokeOnDisconnect(PlayerBase player)
	{
		super.InvokeOnDisconnect(player);
		ref PDAFactionConfig faction = null;
		if (m_PluginPDA)
		{
			PlayerIdentity identity;
			if (Class.CastTo(identity, player.GetIdentity()) && m_PluginPDA.FindFactionMember(identity, faction))
				m_PluginPDA.UpdatePlayerStatus(identity, faction.ID, false);
		}
	}
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		m_MessageManager._CheckForMessages(timeslice);
	}
	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReadyEvent(identity, player);
		ref PDAFactionConfig faction = null;
		if (m_PluginPDA)
		{
			if (m_PluginPDA.FindFactionMember(identity, faction) && faction)
				player.SetFaction(faction.ID);
		}
	}
}