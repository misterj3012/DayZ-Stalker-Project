class CfgPatches
{
    class X18Underground
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = { "X18CoreScripts" };
    };
};
class CfgMods
{
    class X18Underground
    {
        name = "X18Underground";
        type = "mod";
        //inputs = "Noosphere/X18Underground/inputs.xml";
        dependencies[] = { "Game","World","Mission" };
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = { "Noosphere/X18Underground/Scripts/3_Game" };
            };
            class worldScriptModule
            {
                value = "";
                files[] = { "Noosphere/X18Underground/Scripts/4_World" };
            };
            class missionScriptModule
            {
                value = "";
                files[] = { "Noosphere/X18Underground/Scripts/5_Mission" };
            };
        };
    };
};
