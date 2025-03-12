modded class AnomalyDamageOneTimeSpace
{
    override void OnEnter(Object obj)
    {
        PlayerBase m_Player;
        if ((Class.CastTo(m_Player, obj) && (!m_Player.HasEnteredSpaceAnomaly() && !m_Player.IsInTransport() && !m_Player.IsTeleporting())) || !obj.IsInherited(PlayerBase))
        {
            PreDamageActions();
            DamageActions(obj);
            PostDamageActions();
        }
    }
}