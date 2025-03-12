class AnomalyDamageRegular : AnomalyDamageBase
{
    protected ref Timer m_Timer = new Timer(CALL_CATEGORY_SYSTEM);
    protected ref array<Object> m_Insider = new array<Object>;
    protected float m_LoopInterval;
    void AnomalyDamageRegular(Anomaly_Base anomaly, vector min, vector max, string ammo, array<string> hitzones, float interval)
    {
        m_LoopInterval = interval;
    }
    void ~AnomalyDamageRegular()
    {
        if (m_Timer && m_Timer.IsRunning())
            m_Timer.Stop();
    }
    override void OnEnter(Object obj)
    {
        if (m_Insider)
        {
            m_Insider.Insert(obj);
            if (!m_Timer.IsRunning())
                m_Timer.Run(m_LoopInterval, this, "EvaluateDamage_Loop", null, true);
        }
    }
    override void OnLeave(Object obj)
    {
        if (m_Insider)
        {
            for (int i = 0; i < m_Insider.Count(); i++)
            {
                Object _obj = m_Insider.Get(i);
                if (_obj == obj)
                    m_Insider.Remove(i);
            }
        }
        if (m_Timer && (!m_Insider || m_Insider.Count() == 0))
            m_Timer.Stop();
    }
    protected void EvaluateDamage_Loop()
    {
        PreDamageActions();
        if (m_Insider)
        {
            foreach(Object obj : m_Insider)
            {
                EvaluateDamage(obj);
            }
        }
        PostDamageActions();
    }
}
