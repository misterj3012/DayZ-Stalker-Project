modded class RadioObject
{
	void RadioObject()
	{
		if (GetGame().IsDedicatedServer())
			GetSoundManager().AddRadio(this);
	}
	void ~RadioObject()
	{
		if (m_ObjectSound)
			m_ObjectSound.SoundStop();
		if (GetGame().IsDedicatedServer())
			GetSoundManager().RemoveRadio(this);
	}
}