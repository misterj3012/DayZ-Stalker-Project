modded class PluginPlayerStatus
{
	void ShowInsideIcon(bool show)
	{
		Mission mission = GetGame().GetMission();
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
				hud.ShowInsideIcon(show);
		}
	}
}