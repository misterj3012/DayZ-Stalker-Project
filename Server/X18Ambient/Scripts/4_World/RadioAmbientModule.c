class RadioAmbientModule : AmbientModuleBase
{
    ref RadioConfig m_RadioConfig;
    ref RadioLocation m_RadioLocations;
    ref Timer m_SyncAmbientRadioTimer;
    void RadioAmbientModule()
    {}
    void ~RadioAmbientModule()
    {}
    override void OnInit()
    {
        if (GetGame().IsServer() || !GetGame().IsMultiplayer())
        {
            m_RadioConfig = GetDayZGame().GetRadioConfig();
            m_SyncAmbientRadioTimer = new Timer();
            m_SyncAmbientRadioTimer.Run(30, this, "AmbientRadio", NULL, true);
        }
    }
    private void AmbientRadio()
    {
        if (GetGame().IsClient() || !GetGame().IsMultiplayer())
            return;
        int m_Song = m_RadioConfig.m_RadioPlayList.GetRandomElement();
        int m_NumberOfLocations = m_RadioConfig.m_RadioLocations.Count();
        vector m_RadioRotation, m_RadioPosition;
        string m_RadioObjectClassName;
        RadioObject m_RadioObject;
        for (int i = 0; i < m_NumberOfLocations; i++)
        {
            m_RadioLocations = m_RadioConfig.m_RadioLocations.Get(i);
            m_RadioObjectClassName = m_RadioLocations.m_RadioObjectClassName;
            m_RadioPosition = m_RadioLocations.m_RadioPosition.ToVector();
            m_RadioRotation = m_RadioLocations.m_RadioRotation.ToVector();
            m_RadioObject = GetRadioObject(m_RadioPosition);
            if (!m_RadioObject)
            {
                m_RadioObject = RadioObject.Cast(GetGame().CreateObjectEx(m_RadioObjectClassName, m_RadioPosition, ECE_KEEPHEIGHT));
                m_RadioObject.SetOrientation(m_RadioRotation);
            }
        }
        GetSoundManager().StartRadioSounds("Radio_" + m_Song.ToString() + "_SoundSet");
    }
    RadioObject GetRadioObject(vector location)
    {
        ref array<Object> m_Objects = new array<Object>;
        GetGame().GetObjectsAtPosition(location, 0.5, m_Objects, NULL);
        for (int i = 0; i < m_Objects.Count(); ++i)
        {
            Object obj;
            obj = Object.Cast(m_Objects.Get(i));
            if (GetGame().ObjectIsKindOf(obj, "RadioObject"))
                return RadioObject.Cast(obj);
        }
        return NULL;
    }
}