modded class MissionGameplay
{
	override void OnKeyRelease(int key)
	{
		super.OnKeyRelease(key);
		PluginPDA m_PluginPDA;
		if (key == KeyCode.KC_ESCAPE)
		{
			if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)) && m_PluginPDA.IsOpen())
				m_PluginPDA.Close();
		}
		else if (key == KeyCode.KC_RETURN)
		{
			if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)) && m_PluginPDA.IsOpen())
				m_PluginPDA.m_PDAMenu.m_externalSendEvent = true;
		}
	}
}