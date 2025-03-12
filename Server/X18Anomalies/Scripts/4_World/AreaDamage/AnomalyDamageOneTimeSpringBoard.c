modded class AnomalyDamageOneTimeSpringBoard
{
	override void OnEnter(Object obj)
	{
		PreDamageActions();
		PostDamageActions();
		PlayerBase m_Player;
		if (Class.CastTo(m_Player, obj))
			SetPlayerFalling(m_Player, 10);
		else
			dBodyApplyImpulse(obj, "100 1000 100");
	}
}