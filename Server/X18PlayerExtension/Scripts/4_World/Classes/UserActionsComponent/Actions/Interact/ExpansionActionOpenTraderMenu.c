modded class ExpansionActionOpenTraderMenu
{
	protected PluginPlayerData m_PlayerDataExtended;
	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);
		m_TraderObject = ExpansionMarketModule.GetTraderFromObject(action_data.m_Target.GetObject(), false);
		m_PlayerDataExtended = PluginPlayerData.Cast(GetPlugin(PluginPlayerData));
		string m_TraderName = m_TraderObject.GetTraderMarket().m_FileName;
		if (m_PlayerDataExtended && m_TraderName == "SIDOROVICH")
			m_PlayerDataExtended.UpdateLastTalkedTrader(action_data.m_Player, 1);
		else if (m_PlayerDataExtended && m_TraderName == "DR_I_FEELGOOD")
			m_PlayerDataExtended.UpdateLastTalkedTrader(action_data.m_Player, 2);
	}
}