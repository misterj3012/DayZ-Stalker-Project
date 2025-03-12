modded class DayZPlayerImplementFallDamage
{
	override void HandleFallDamage(float pHeight)
	{
		if (GetGame().IsServer())
		{
			PlayerBase m_Player = PlayerBase.Cast(m_Player);
			if (m_Player && m_Player.IsTeleporting())
				return;
		}

		super.HandleFallDamage(pHeight);
	}
}