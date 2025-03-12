class RadioObject : BuildingSuper
{
	protected ref EffectSound m_ObjectSound;
	bool IsPlaying()
	{
		if (!m_ObjectSound)
			return false;
		return true;
	}
	EffectSound PlaySoundSet(string soundSet, float volume, bool loop)
	{
		if (!IsPlaying())
			m_ObjectSound = SEffectManager.PlaySoundOnObject(soundSet, this, 0, 0, loop);
		if (!m_ObjectSound)
		{
			PrintDebug("Sound failed to play %1", soundSet);
			return m_ObjectSound;
		}
		PrintDebug("PlaySoundSet SoundSet: " + soundSet + " on Object: " + this.GetType());
		m_ObjectSound.SetParent(this);
		m_ObjectSound.SetSoundAutodestroy(true);
		m_ObjectSound.GetSoundObject().SetVolume(volume);
		return m_ObjectSound;
	}
}
class bldr_radio_b : RadioObject {}