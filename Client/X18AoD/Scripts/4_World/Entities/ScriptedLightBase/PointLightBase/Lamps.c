/*class Land_light_lamp2 : House
{
	LampLight   m_LampLight;
	protected ref Timer m_timer;
	const static string SOUNDIDLE = "lamp_squeaks_1";

	void Land_light_lamp2()
	{

		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			m_LampLight = LampLight.Cast(ScriptedLightBase.CreateLight(LampLight, "0 0 0"));
			m_LampLight.AttachOnMemoryPoint(this, "light");

			m_timer = new Timer(CALL_CATEGORY_SYSTEM);
			m_timer.Run(0, this, "Spawn");

			vector selection_pos = ModelToWorld(GetMemoryPointPos("light"));
		}
	}

	override void EEDelete(EntityAI parent)
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			if (m_LampLight)
				m_LampLight.Destroy();
		}
	}

	void Spawn()
	{
		if (GetGame().IsClient())
			PlaySoundLoop(SOUNDIDLE, 20);
	}
};

class Land_light_lamp3 : House
{
	LampLight   m_LampLight;

	void Land_light_lamp3()
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			m_LampLight = LampLight.Cast(ScriptedLightBase.CreateLight(LampLight, "0 0 0"));
			m_LampLight.AttachOnMemoryPoint(this, "light");

			vector selection_pos = ModelToWorld(GetMemoryPointPos("light"));
		}
	}

	override void EEDelete(EntityAI parent)
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			if (m_LampLight)
				m_LampLight.Destroy();
		}
	}
};

class Land_light_lamp4 : House
{
	LampLight   m_LampLight;

	void Land_light_lamp4()
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			m_LampLight = LampLight.Cast(ScriptedLightBase.CreateLight(LampLight, "0 0 0"));
			m_LampLight.AttachOnMemoryPoint(this, "light");

			vector selection_pos = ModelToWorld(GetMemoryPointPos("light"));
		}
	}

	override void EEDelete(EntityAI parent)
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			if (m_LampLight)
				m_LampLight.Destroy();
		}
	}
};*/

class Land_light_lamp2_AlwaysOn : House
{
	LampLightAlwaysOn   m_LampLightAlwaysOn;
	protected ref Timer m_timer;
	const static string SOUNDIDLE = "lamp_squeaks_1";

	void Land_light_lamp2_AlwaysOn()
	{

		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			m_LampLightAlwaysOn = LampLightAlwaysOn.Cast(ScriptedLightBase.CreateLight(LampLightAlwaysOn, "0 0 0"));
			m_LampLightAlwaysOn.AttachOnMemoryPoint(this, "light");

			m_timer = new Timer(CALL_CATEGORY_SYSTEM);
			m_timer.Run(0, this, "Spawn");

			vector selection_pos = ModelToWorld(GetMemoryPointPos("light"));
		}
	}

	override void EEDelete(EntityAI parent)
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			if (m_LampLightAlwaysOn)
				m_LampLightAlwaysOn.Destroy();
		}
	}

	void Spawn()
	{
		if (GetGame().IsClient())
			PlaySoundLoop(SOUNDIDLE, 20);
	}
};

class Land_light_lamp3_AlwaysOn : House
{
	LampLightAlwaysOn   m_LampLightAlwaysOn;

	void Land_light_lamp3_AlwaysOn()
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			m_LampLightAlwaysOn = LampLightAlwaysOn.Cast(ScriptedLightBase.CreateLight(LampLightAlwaysOn, "0 0 0"));
			m_LampLightAlwaysOn.AttachOnMemoryPoint(this, "light");

			vector selection_pos = ModelToWorld(GetMemoryPointPos("light"));
		}
	}

	override void EEDelete(EntityAI parent)
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			if (m_LampLightAlwaysOn)
				m_LampLightAlwaysOn.Destroy();
		}
	}
};

class Land_light_lamp4_AlwaysOn : House
{
	LampLightAlwaysOn   m_LampLightAlwaysOn;

	void Land_light_lamp4_AlwaysOn()
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			m_LampLightAlwaysOn = LampLightAlwaysOn.Cast(ScriptedLightBase.CreateLight(LampLightAlwaysOn, "0 0 0"));
			m_LampLightAlwaysOn.AttachOnMemoryPoint(this, "light");

			vector selection_pos = ModelToWorld(GetMemoryPointPos("light"));
		}
	}

	override void EEDelete(EntityAI parent)
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			if (m_LampLightAlwaysOn)
				m_LampLightAlwaysOn.Destroy();
		}
	}
};

/*class LampLight : PointLightBase
{
	void LampLight()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo(10);
		SetBrightnessTo(3.5);
		SetCastShadow(true);
		//SetFadeOutTime(1);
		SetDiffuseColor(1.0, 0.45, 0.25);
		SetAmbientColor(1.0, 0.45, 0.25);
		SetFlareVisible(false);
		//SetFlickerAmplitude(0.3);
		//SetFlickerSpeed(0.0001);
		//SetDancingShadowsMovementSpeed(0.00001);
		//SetDancingShadowsAmplitude(0.00001);
		//SetDisableShadowsWithinRadius(1);
		EnableHeatHaze(true);
		SetHeatHazeRadius(0.08);
		SetHeatHazePower(0.015);
	}
};*/

class LampLightAlwaysOn : PointLightBase
{
	void LampLightAlwaysOn()
	{
		SetVisibleDuringDaylight(true);
		SetRadiusTo(10);
		SetBrightnessTo(3.5);
		SetCastShadow(true);
		//SetFadeOutTime(1);
		SetDiffuseColor(1.0, 0.45, 0.25);
		SetAmbientColor(1.0, 0.45, 0.25);
		SetFlareVisible(false);
		//SetFlickerAmplitude(0.3);
		//SetFlickerSpeed(0.0001);
		//SetDancingShadowsMovementSpeed(0.00001);
		//SetDancingShadowsAmplitude(0.00001);
		//SetDisableShadowsWithinRadius(1);
		EnableHeatHaze(true);
		SetHeatHazeRadius(0.08);
		SetHeatHazePower(0.015);
	}
};