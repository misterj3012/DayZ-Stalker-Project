class X18_ElectrogeistDeath_Fx : House
{
	Particle 							m_EffectDeath;
	SoundOnVehicle 						m_DeathEffectSound;

	void X18_ElectrogeistDeath_Fx()
	{
		if (!GetGame().IsDedicatedServer())
			VisualsON();

		if (GetGame().IsDedicatedServer())
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Delete, 6000, false);
	}

	void ~X18_ElectrogeistDeath_Fx()
	{
		if (!GetGame().IsDedicatedServer())
		{
			if (m_EffectDeath)
				m_EffectDeath.Stop();
			if (m_DeathEffectSound)
			{
				GetGame().ObjectDelete(m_DeathEffectSound);
				m_DeathEffectSound = NULL;
			}
		}
	}

	void VisualsON()
	{
		if (!GetGame().IsDedicatedServer())
		{
			m_EffectDeath = Particle.PlayOnObject(ParticleList.ELECTROGEIST_DEATH, this);
			PlaySoundFX();
		}
	}

	void Delete()
	{
		GetGame().ObjectDelete(this);
	}

	void PlaySoundFX()
	{
		if (!GetGame().IsDedicatedServer())
		{
			int rnd = Math.RandomIntInclusive(0, 1);

			if (rnd == 0)
				m_DeathEffectSound = PlaySound("ELECTROGEIST_DEATH_0", 200);
			else if (rnd == 1)
				m_DeathEffectSound = PlaySound("ELECTROGEIST_DEATH_1", 200);
		}
	}
}