modded class DayZGame
{
    protected ref VIAProfileOption m_viaOptions;

    void DayZGame()
    {
        m_viaOptions = new VIAProfileOption();
    }

    override void DeferredInit()
    {
        super.DeferredInit();

        m_viaOptions.RegisterProfileOption( EVIAProfileOptions.ANIMATION, VIAProfileOption.OPTION_ANIMATION, 1 );
        m_viaOptions.RegisterProfileOption( EVIAProfileOptions.PREVIEW, VIAProfileOption.OPTION_PREVIEW, 1 );
    }

    int GetVIAProfileVal( EVIAProfileOptions option )
    {
        return m_viaOptions.GetProfileOptionVal( option );
    }

    void SetVIAProfileVal( EVIAProfileOptions option, int value )
    {
        m_viaOptions.SetProfileOptionVal( option, value );
    }
}