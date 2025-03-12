modded class PluginPlayerStatus : PluginBase
{
	void ShowRadiationSicknessSymbol(bool show)
	{
		Mission mission = GetGame().GetMission();
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
				hud.ShowRadiationSicknessSymbol(show);
		}
	}
	void ShowGeigerCounter(float value)
	{
		Mission mission = GetGame().GetMission();
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
				hud.ShowGeigerCounter(value);
		}
	}
	void SetGeigerCounterValue(float value)
	{
		Mission mission = GetGame().GetMission();
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
				hud.SetGeigerCounterValue(value, player.GeigerCounter);
		}
	}
	void EnableRadiationOnPlayerDisplay(float status)
	{
		Mission mission = GetGame().GetMission();
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
				hud.EnableRadiationOnPlayerDisplay(status);
		}
	}
	void ShowRadiationOnPlayer(float value)
	{
		Mission mission = GetGame().GetMission();
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
				hud.ShowRadiationOnPlayer(value, player.GeigerCounter);
		}
	}
	void EnableRadiationOnTargetDisplay(float status)
	{
		Mission mission = GetGame().GetMission();
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
				hud.EnableRadiationOnTargetDisplay(status);
		}
	}
	void ShowRadiationOnTarget(float value)
	{
		Mission mission = GetGame().GetMission();
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
				hud.ShowRadiationOnTarget(value, player.GeigerCounter);
		}
	}
}