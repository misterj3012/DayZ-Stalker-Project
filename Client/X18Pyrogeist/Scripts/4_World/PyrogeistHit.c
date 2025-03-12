class X18_PyrogeistHit_Fx : House
{
	SoundOnVehicle 						m_HitEffectSound;
	SoundOnVehicle 						m_Hit1EffectSound;

	void X18_PyrogeistHit_Fx()
	{
		if (!GetGame().IsDedicatedServer())
			PlaySoundFX();

		if (GetGame().IsDedicatedServer())
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Delete, 2000, false);
	}

	void ~X18_PyrogeistHit_Fx()
	{
		if (!GetGame().IsDedicatedServer())
		{
			if (m_HitEffectSound)
			{
				GetGame().ObjectDelete(m_HitEffectSound);
				m_HitEffectSound = NULL;
			}

			if (m_Hit1EffectSound)
			{
				GetGame().ObjectDelete(m_Hit1EffectSound);
				m_Hit1EffectSound = NULL;
			}
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
			int rnd = Math.RandomIntInclusive(0, 2);

			if (rnd == 0)
				m_HitEffectSound = PlaySound("Pyrogeist_attack_0", 100);
			else if (rnd == 1)
				m_HitEffectSound = PlaySound("Pyrogeist_attack_1", 100);
			else if (rnd == 2)
				m_HitEffectSound = PlaySound("Pyrogeist_attack_2", 100);

			int rnd_1 = Math.RandomIntInclusive(0, 2);

			if (rnd == 0)
				m_Hit1EffectSound = PlaySound("Pyrogeist_damage_0", 100);
			else if (rnd == 1)
				m_Hit1EffectSound = PlaySound("Pyrogeist_damage_1", 100);
			else if (rnd == 2)
				m_Hit1EffectSound = PlaySound("Pyrogeist_damage_2", 100);
		}
	}
}