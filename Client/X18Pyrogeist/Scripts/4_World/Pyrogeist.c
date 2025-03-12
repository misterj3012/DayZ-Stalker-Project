class X18_Mutant_Pyrogeist : Animal_GallusGallusDomesticus
{
	Particle 				m_Alive;
	MainPyrogeist_Light m_Light;
	EffectSound 			m_IdleEffectSound;
	override void EEInit()
	{
		super.EEInit();
		VisualsON();
		PlayIdleSound();
	}
	override void EEDelete(EntityAI parent)
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			if (m_Alive)
				m_Alive.Stop();
			if (m_Light)
				m_Light.FadeOut();
			GetGame().ObjectDelete(m_Alive);
			StopSoundSet(m_IdleEffectSound);

		}
		super.EEDelete(parent);
	}
	void VisualsON()
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			m_Alive = Particle.PlayOnObject(ParticleList.PYROGEIST_MAIN, this);
			m_Light = MainPyrogeist_Light.Cast(ScriptedLightBase.CreateLight(MainPyrogeist_Light, "0 0 0", 0.5));
			m_Light.AttachOnObject(this, "0 0 0", "0 0 0");
		}
	}
	override bool CanBeSkinned()
	{
		return false;
	}
	protected void PlayIdleSound()
	{
		PlaySoundSetLoop(m_IdleEffectSound, "Pyrogeist_idle_SoundSet", 0.1, 0.1);
	}
}