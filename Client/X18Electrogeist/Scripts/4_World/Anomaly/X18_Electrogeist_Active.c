class X18_Electrogeist_Active : House
{
	Electrogeist_Light 			m_Light;
	Particle 					m_EffectSplash;
	SoundOnVehicle 				m_SEngineAnomaly_0;
	SoundOnVehicle 				m_SEngineAnomaly_1;
	void X18_Electrogeist_Active()
	{
		if (!GetGame().IsDedicatedServer())
			ActiveVisualsON();
		if (GetGame().IsDedicatedServer())
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Delete, 15000, false);
	}
	void ~X18_Electrogeist_Active()
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
			m_SEngineAnomaly_0 = PlaySound("Electrogeist_flame_charge", 100);
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlayBlowSound, 2000, false);
			m_EffectSplash = Particle.PlayOnObject(ParticleList.ELECTROGEIST_ANOMALY, this);
		}
	}
	void PlayBlowSound()
	{
		if (!GetGame().IsDedicatedServer())
		{
			m_Light = Electrogeist_Light.Cast(ScriptedLightBase.CreateLight(Electrogeist_Light, "0 0 0", 0.5));
			m_Light.AttachOnObject(this, "0 0 0", "0 0 0");
			m_SEngineAnomaly_1 = PlaySound("Electrogeist_flame_blow", 100);
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
class Electrogeist_Light : PointLightBase
{
	void Electrogeist_Light()
	{
		SetVisibleDuringDaylight(true);
		SetRadiusTo(10);
		SetBrightnessTo(50);
		SetFlareVisible(false);
		SetAmbientColor(0.7, 1.0, 1.0);
		SetDiffuseColor(0.7, 1.0, 1.0);
		SetFadeOutTime(2);
		SetLifetime(14.0);
		SetDisableShadowsWithinRadius(-1);
		SetDancingShadowsMovementSpeed(0.4);
		SetDancingShadowsAmplitude(0.5);
		SetFlickerAmplitude(0.5);
		SetFlickerSpeed(4.0);
		EnableHeatHaze(true);
		SetHeatHazeRadius(1.5);
		SetHeatHazePower(0.02);
		SetCastShadow(false);
	}
}
class MainElectrogeist_Light : PointLightBase
{
	void MainElectrogeist_Light()
	{
		SetVisibleDuringDaylight(true);
		SetRadiusTo(4);
		SetBrightnessTo(50);
		SetFlareVisible(false);
		SetAmbientColor(0.7, 1.0, 1.0);
		SetDiffuseColor(0.7, 1.0, 1.0);
		SetDisableShadowsWithinRadius(-1);
		SetDancingShadowsMovementSpeed(0.4);
		SetDancingShadowsAmplitude(0.5);
		SetFlickerAmplitude(0.5);
		SetFlickerSpeed(4.0);
		EnableHeatHaze(true);
		SetHeatHazeRadius(2);
		SetHeatHazePower(0.02);
	}
}