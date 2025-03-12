modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();

        if ( FileExist( VIASettings.FILE_NAME ) )
        {
            JsonFileLoader<VIASettings>.JsonLoadFile( VIASettings.FILE_NAME, VIASettings.SETTINGS );
        }
        else
        {
            JsonFileLoader<VIASettings>.JsonSaveFile( VIASettings.FILE_NAME, VIASettings.SETTINGS );
        }
    }
}