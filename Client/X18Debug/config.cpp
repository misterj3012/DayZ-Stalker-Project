class CfgPatches
{
    class X18Debug
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = { "X18CoreScripts" };
    };
};

class CfgMods
{
    class X18Debug
    {
        name = "X18Debug";
        extra = 0;
        type = "mod";
        dependencies[] = { "Game", "World", "Mission" };

        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = { "Noosphere/X18Debug/Scripts/3_Game" };
            };
            class worldScriptModule
            {
                value = "";
                files[] = { "Noosphere/X18Debug/Scripts/4_World" };
            };
            class missionScriptModule
            {
                value = "";
                files[] = { "Noosphere/X18Debug/Scripts/5_Mission" };
            };
        };
    };
};
class CfgVehicles
{
    class Inventory_Base;
    class X18_Debug_Cylinder_Base : Inventory_Base
    {
        scope = 0;
        model = "\DZ\structures\walls\wall_indcnc_pole.p3d";
    };
    class X18_Debug_Cylinder_2 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_3 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_5 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_10 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_15 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_20 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_25 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_50 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_75 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_100 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_125 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_150 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_200 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_250 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Cylinder_300 : X18_Debug_Cylinder_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_Base : Inventory_Base
    {
        scope = 0;
        model = "\DZ\structures\walls\wall_indcnc_pole.p3d";
    };
    class X18_Debug_Sphere_2 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_3 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_5 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_10 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_15 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_20 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_25 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_50 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_75 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_100 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_125 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_150 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_200 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_250 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
    class X18_Debug_Sphere_300 : X18_Debug_Sphere_Base
    {
        scope = 2;
    };
};