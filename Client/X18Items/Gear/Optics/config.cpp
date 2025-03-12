class CfgPatches
{
    class DZ_Gear_Optics
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = { "DZ_Data","DZ_Pistols","DZ_Gear_Optics" };
    };
};
class CfgVehicles
{
    class ItemOptics;
    class Rangefinder : ItemOptics
    {
        itemSize[] = { 1,2 };
    };
    class Binoculars : ItemOptics
    {
        itemSize[] = { 3,1 };
    };
};