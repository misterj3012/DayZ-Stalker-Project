void TeleportObject(notnull Object object, vector position)
{
    PlayerBase m_Player;
    if (Class.CastTo(m_Player, object))
        m_Player.SetTeleporting(true);
    if (dBodyIsDynamic(object))
    {
        object.SetDynamicPhysicsLifeTime(0.001);
        dBodyActive(object, ActiveState.INACTIVE);
    }
    SetWorldPosition(object, position);
    dBodyActive(object, ActiveState.ACTIVE);
    thread FinishRandomTeleportObject(new Param2<Object, vector>(object, position));
}
static void SetWorldPosition(Object object, vector position)
{
    Object parent = object;
    while (parent) {
        object = parent;
        parent = Object.Cast(parent.GetParent());
    }
    Transport transport;
    if (Class.CastTo(transport, object)) {
        vector transform[4];
        transport.GetTransform(transform);
        transform[3] = position;
        transport.PlaceOnSurfaceRotated(transform, position, 0, 0, 0, false);
        transport.SetTransform(transform);
        transport.Synchronize();
        return;
    }
    object.SetPosition(position);
}
void FinishRandomTeleportObject(ref Param2<Object, vector> params_ref)
{
    Sleep(5000);
    PlayerBase m_Player;
    if (Class.CastTo(m_Player, params_ref.param1))
        m_Player.SetTeleporting(false);
    delete params_ref;
}
void SetPlayerFalling(PlayerBase player, float diff)
{
    PlayerBase m_Player;
    if (Class.CastTo(m_Player, player))
    {
        m_Player.SetTeleporting(true);
        if (dBodyIsDynamic(m_Player))
        {
            m_Player.SetDynamicPhysicsLifeTime(0.001);
            dBodyActive(m_Player, ActiveState.INACTIVE);
        }
        float m_Height = m_Player.GetPosition()[1];
        m_Player.SetFallYDiff((m_Height + diff));
        m_Player.StartCommand_Fall(20);
        dBodyActive(m_Player, ActiveState.ACTIVE);
        //thread FinishPlayerFalling(m_Player);
    }
}
void FinishPlayerFalling(PlayerBase player)
{
    Sleep(5000);
    PlayerBase m_Player;
    if (Class.CastTo(m_Player, player))
        m_Player.SetTeleporting(false);
}