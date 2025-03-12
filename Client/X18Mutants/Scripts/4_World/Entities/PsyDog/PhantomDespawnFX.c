class PhantomDespawnFX : House
{
	SoundOnVehicle 				m_Sound;
	Particle 					m_Effect;
	void PhantomDespawnFX()
	{
		if (GetGame().IsServer())
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Delete, 3000, false);
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			PlayParticleFX();
			PlaySoundFX();
		}
	}
	void ~PhantomDespawnFX()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if (m_Effect)
				m_Effect.Stop();
			if (m_Sound)
			{
				GetGame().ObjectDelete(m_Sound);
				m_Sound = NULL;
			}
		}
	}
	override bool IsInventoryVisible()
	{
		return false;
	}
	void Delete()
	{
		if (GetGame().IsServer())
			GetGame().ObjectDelete(this);
	}
	void PlayParticleFX()
	{
		m_Effect = Particle.PlayOnObject(ParticleList.PHANTOM_DESPAWN_PTC, this, "0 0.5 0");
	}
	void PlaySoundFX()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
			m_Sound = PlaySound("phantom_spawn_sound", 30);
	}
}