class X18_Pyrogeist_Active : House
{
	Pyrogeist_Light 			m_Light;
	Particle 					m_EffectSplash;
	SoundOnVehicle 				m_SEngineAnomaly_0;
	SoundOnVehicle 				m_SEngineAnomaly_1;
	void X18_Pyrogeist_Active()
	{
		if (!GetGame().IsDedicatedServer())
			ActiveVisualsON();
		if (GetGame().IsDedicatedServer())
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Delete, 15000, false);
	}
	void ~X18_Pyrogeist_Active()
	{
		if (m_EffectSplash)
			m_EffectSplash.Stop();
		if (m_Light)
			m_Light.FadeOut();
		if (m_SEngineAnomaly_0)
			GetGame().ObjectDelete(m_SEngineAnomaly_0);
		if (m_SEngineAnomaly_1)
			GetGame().ObjectDelete(m_SEngineAnomaly_1);
	}
	void ActiveVisualsON()
	{
		if (!GetGame().IsDedicatedServer())
		{
			m_SEngineAnomaly_0 = PlaySound("Pyrogeist_flame_charge", 100);
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlayBlowSound, 2000, false);
			m_EffectSplash = Particle.PlayOnObject(ParticleList.PYROGEIST_ANOMALY, this);
		}
	}
	void PlayBlowSound()
	{
		if (!GetGame().IsDedicatedServer())
		{
			m_Light = Pyrogeist_Light.Cast(ScriptedLightBase.CreateLight(Pyrogeist_Light, "0 0 0", 0.5));
			m_Light.AttachOnObject(this, "0 0 0", "0 0 0");
			m_SEngineAnomaly_1 = PlaySound("Pyrogeist_flame_blow", 100);
			if (m_SEngineAnomaly_0)
				GetGame().ObjectDelete(m_SEngineAnomaly_0);
		}
	}
	void Delete()
	{
		if (GetGame().IsDedicatedServer())
			GetGame().ObjectDelete(this);
	}
}
class Pyrogeist_Light : PointLightBase
{
	void Pyrogeist_Light()
	{
		SetVisibleDuringDaylight(true);
		SetRadiusTo(10);
		SetBrightnessTo(50);
		SetFlareVisible(false);
		SetAmbientColor(0.9, 0.5, 0.3);
		SetDiffuseColor(0.9, 0.5, 0.3);
		SetFadeOutTime(2);
		SetLifetime(14.0);
		SetDisableShadowsWithinRadius(-1);
		SetDancingShadowsMovementSpeed(0.4);
		SetDancingShadowsAmplitude(0.5);
		SetFlickerAmplitude(0.5);
		SetFlickerSpeed(4.0);
		EnableHeatHaze(true);
		SetHeatHazeRadius(2);
		SetHeatHazePower(0.02);
		SetCastShadow(false);
	}
}
class MainPyrogeist_Light : PointLightBase
{
	void MainPyrogeist_Light()
	{
		SetVisibleDuringDaylight(true);
		SetRadiusTo(4);
		SetBrightnessTo(50);
		SetFlareVisible(false);
		SetAmbientColor(0.9, 0.5, 0.3);
		SetDiffuseColor(0.9, 0.5, 0.3);
		SetDisableShadowsWithinRadius(-1);
		SetDancingShadowsMovementSpeed(0.4);
		SetDancingShadowsAmplitude(0.5);
		SetFlickerAmplitude(0.5);
		SetFlickerSpeed(4.0);
		EnableHeatHaze(true);
		SetHeatHazeRadius(3);
		SetHeatHazePower(0.02);
	}
}