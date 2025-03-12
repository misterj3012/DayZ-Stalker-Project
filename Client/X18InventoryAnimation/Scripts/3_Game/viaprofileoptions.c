enum EVIAProfileOptions
{
    ANIMATION,
    PREVIEW,
};

typedef Param3<string, int, int> VIAProfileOptionData;

class VIAProfileOption
{
    static const string OPTION_ANIMATION = "viaanimation";
    static const string OPTION_PREVIEW = "viapreview";

    private ref map<EVIAProfileOptions, ref VIAProfileOptionData> m_CustomOptions = new map<EVIAProfileOptions, ref VIAProfileOptionData>;

    void RegisterProfileOption( EVIAProfileOptions option, string profileOptionName, int def = 1 )
    {
        if ( !m_CustomOptions.Contains( option ) )
        {
            string value;
            GetGame().GetProfileString( profileOptionName, value );
            if ( value == string.Empty )
            {
                m_CustomOptions.Set( option, new VIAProfileOptionData( profileOptionName, def, def ) );
                SetProfileOptionVal( option, def );
            }
            else
            {
                m_CustomOptions.Set( option, new VIAProfileOptionData( profileOptionName, Math.Clamp( value.ToInt(), 0, 1 ), def ) );
                SetProfileOptionVal( option, value.ToInt() );
            }
        }
    }

    void ResetOptions()
    {
        foreach ( EVIAProfileOptions e_opt, VIAProfileOptionData r_opt : m_CustomOptions )
        {
            string value;
            if ( GetGame().GetProfileString( r_opt.param1, value ) )
            {
                SetProfileOptionVal( e_opt, value.ToInt() );
            }
            else
            {
                SetProfileOptionVal( e_opt, r_opt.param3 );
            }
        }
    }

    void SetProfileOptionVal( EVIAProfileOptions option, int value )
    {
        if ( m_CustomOptions && m_CustomOptions.Contains( option ) )
        {
            VIAProfileOptionData po = m_CustomOptions.Get( option );

            po.param2 = Math.Clamp( value, 0, 1 );
            GetGame().SetProfileString( po.param1, value.ToString() );
            GetGame().SaveProfile();
        }
    }

    int GetProfileOptionVal( EVIAProfileOptions option )
    {
        if ( m_CustomOptions && m_CustomOptions.Contains( option ) )
        {
            VIAProfileOptionData po = m_CustomOptions.Get( option );
            return po.param2;
        }

        return 1;
    }
}