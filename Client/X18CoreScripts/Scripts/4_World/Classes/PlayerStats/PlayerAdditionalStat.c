class PlayerAdditionalStat : PlayerStat<float>
{
    const float MAX_VALUE = 1.0;
    const float MIN_VALUE = -1.0;

    override float Get()
    {
        return Math.Clamp(super.Get(), MIN_VALUE, MAX_VALUE);
    }

    override void OnStoreSave(ParamsWriteContext ctx)
    {
        float value = 0.0;
        ctx.Write(value);
    }

    override bool OnStoreLoad(ParamsReadContext ctx)
    {
        float value = 0.0;
        if (ctx.Read(value))
            m_Value = 0.0;

        return true;
    }
}