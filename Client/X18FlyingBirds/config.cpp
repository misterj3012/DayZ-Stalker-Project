class CfgPatches
{
    class X18FlyingBirds
    {
        requiredAddons[] = { "X18CoreScripts", "Flying_Birds" };
        units[] = {};
        weapons[] = {};
    };
};
class CfgMods
{
    class X18FlyingBirds
    {
        dir = "X18FlyingBirds";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "FlyingBirds Extension";
        author = "Zedmag";
        authorID = "2039448058";
        version = "1.5";
        extra = 0;
        type = "mod";
        dependencies[] = { "Game", "World", "Mission" };

        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = { "Noosphere/X18FlyingBirds/Scripts/3_Game" };
            };
            class worldScriptModule
            {
                value = "";
                files[] = { "Noosphere/X18FlyingBirds/Scripts/4_World" };
            };
            class missionScriptModule
            {
                value = "";
                files[] = { "Noosphere/X18FlyingBirds/Scripts/5_Mission" };
            };
        };
    };
};