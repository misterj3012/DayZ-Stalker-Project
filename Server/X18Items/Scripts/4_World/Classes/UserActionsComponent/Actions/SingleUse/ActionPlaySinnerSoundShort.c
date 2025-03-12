modded class ActionPlaySinnerSoundShort
{
	override void OnExecuteServer(ActionData action_data)
	{
		Sin_BeastMaster_SS m_SinnerSound = Sin_BeastMaster_SS.Cast(action_data.m_MainItem);
		if (m_SinnerSound && !m_SinnerSound.HasActivatedSinnerSound())
		{
			m_SinnerSound.SetSinnerSoundPlayed(true, 30);
			GetSoundManager().PlaySoundOnObjectServer("Factions_SinnerSound_Short_SoundSet", m_SinnerSound, 1);
		}
	}
}