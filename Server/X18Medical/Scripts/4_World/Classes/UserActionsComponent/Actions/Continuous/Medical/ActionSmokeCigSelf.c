modded class ActionSmokeCigSelf : ActionContinuousBase
{
	private float clhealth;
	override void OnFinishProgressServer(ActionData action_data)
	{
		CP_Cigarette cig = CP_Cigarette.Cast(action_data.m_MainItem);
		if (cig)
		{
			cig.AddHealth("", "Health", -ReduceAmount);
			clhealth = cig.GetHealth();
			cig.SetSynchronizedHealth(clhealth);
			if (clhealth <= 0)
			{
				cig.SetSmokingState(ESmokeState.NOT_SMOKING);
				cig.UpdateParticles();
				cig.Delete();
				action_data.m_Player.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_ANTIRADCIGARETTE);
			}
		}
	}
};