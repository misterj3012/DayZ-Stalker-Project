modded class MissionGameplay
{
	bool downstateMenuOpened = false;
	protected Widget m_RadioPtt;
	override void OnInit()
	{
		super.OnInit();
		if (m_UIManager)
		{
			if (m_HudRootWidget && m_Hud)
			{
				m_RadioPtt = m_HudRootWidget.FindAnyWidget("radio");
				m_RadioPtt.Show(false);
			}
		}
	}
	override void OnEvent(EventType eventTypeId, Param params)
	{
		super.OnEvent(eventTypeId, params);
		if (eventTypeId == VONStateEventTypeID)
		{
			VONStateEventParams vonStateParams = VONStateEventParams.Cast(params);
			Man player = GetGame().GetPlayer();
			PlayerBase player_base = PlayerBase.Cast(player);
			if (player_base)
			{
				if (vonStateParams.param1)
				{
					player_base.SynchronizeRadioPushToTalk();
					if (player_base.IsRadioPushToTalk())
						player_base.PlayRadioPttOnSound();
				}
				else
				{
					if (player_base.IsRadioPushToTalk())
						player_base.PlayRadioPttOffSound();
				}
			}
		}
	}
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		Man player = GetGame().GetPlayer();
		PlayerBase player_base = PlayerBase.Cast(player);
		UIScriptedMenu menu = m_UIManager.GetMenu();
		Input input = GetGame().GetInput();
		if (player_base && GetUApi() && !m_UIManager.IsMenuOpen(MENU_CHAT_INPUT))
		{
			if (input.LocalPress("UARadioPushToTalk", false))
			{
				if (IsRadioPushToTalk())
					DisableRadioPushToTalk();
				else
					EnableRadioPushToTalk();
			}
		}
	}
	void EnableRadioPushToTalk()
	{
		Man player = GetGame().GetPlayer();
		PlayerBase player_base = PlayerBase.Cast(player);
		if (player_base)
		{
			if (!player_base.IsRadioPushToTalk())
			{
				player_base.EnableRadioPushToTalk();
				m_RadioPtt.Show(true);
			}
		}
	}
	void DisableRadioPushToTalk()
	{
		Man player = GetGame().GetPlayer();
		PlayerBase player_base = PlayerBase.Cast(player);
		if (player_base)
		{
			if (player_base.IsRadioPushToTalk())
			{
				player_base.DisableRadioPushToTalk();
				m_RadioPtt.Show(false);
			}
		}
	}
	bool IsRadioPushToTalk()
	{
		Man player = GetGame().GetPlayer();
		PlayerBase player_base = PlayerBase.Cast(player);
		return player_base && player_base.IsRadioPushToTalk();
	}
}