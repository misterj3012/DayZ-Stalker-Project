class Sin_BeastMaster_SS : Inventory_Base
{

	protected bool m_SinnerSoundPlayed = false;
	void SetSinnerSoundPlayed(bool status, float timeout = 10)
	{
		m_SinnerSoundPlayed = status;
		if (m_SinnerSoundPlayed)
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetSinnerSoundPlayed, timeout * 1000, false, false);
	}
	bool HasActivatedSinnerSound()
	{
		return m_SinnerSoundPlayed;
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionPlaySinnerSoundShort);
	}
};
class X18_Sin_BeastMaster_SS_Short : Sin_BeastMaster_SS {};