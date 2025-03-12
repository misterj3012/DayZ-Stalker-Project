modded class TransmitterBase
{
	protected ref array<ref EffectSound> m_VoiceSounds = {};
	protected ref Timer m_VoicesTimer;
	void TransmitterBase()
	{
		if (GetGame().IsClient())
		{
			m_VoicesTimer = new Timer(CALL_CATEGORY_SYSTEM);
			m_VoicesTimer.Run(45.0, this, "RunVoices", null, true);
		}
	}
	override void OnWorkStart()
	{
		super.OnWorkStart();
		foreach(EffectSound sound : m_VoiceSounds) {
			if (sound)
				sound.SetSoundVolume(1.0);
		}
	}
	override void OnWorkStop()
	{
		super.OnWorkStop();
		foreach(EffectSound sound : m_VoiceSounds) {
			if (sound)
				sound.SetSoundVolume(0.0);
		}
	}
	void RunVoices()
	{
		EventManager event_manager = EventManager.GetInstance();
		if (!IsOn() || !event_manager)
			return;
		if (!event_manager.GetEvent(Emission))
			return;
		float distance = vector.Distance(GetGame().GetPlayer().GetPosition(), event_manager.GetEvent(Emission).GetEventPosition());
		// if (distance > 800)
		// 	return;
		EffectSound effect_sound = SEffectManager.PlaySoundOnObject("Emission_Voices_Static", this);
		if (!effect_sound)
			return;
		float volume = (Math.Clamp(distance / 800, 0.1, 1) * IsOn());
		effect_sound.GetSoundObject().SetVolume(volume);
		effect_sound.SetSoundAutodestroy(true);
		m_VoiceSounds.Insert(effect_sound);
	}
}