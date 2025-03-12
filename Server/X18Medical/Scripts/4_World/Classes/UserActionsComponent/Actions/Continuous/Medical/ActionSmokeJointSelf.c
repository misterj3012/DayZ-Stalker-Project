modded class ActionSmokeJointSelf : ActionContinuousBase
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		CP_JointBase joint = CP_JointBase.Cast(action_data.m_MainItem);
		if (joint)
		{
			ApplyModifiers(action_data);
			joint.AddHealth("", "Health", -ReduceAmount);
			clhealth = joint.GetHealth();
			joint.SetSynchronizedHealth(clhealth);
			if (clhealth <= 0)
			{
				joint.SetSmokingState(ESmokeState.NOT_SMOKING);
				joint.UpdateParticles();
				joint.Delete();
				action_data.m_Player.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_ANTIRADJOINT);
			}
		}
	}
};