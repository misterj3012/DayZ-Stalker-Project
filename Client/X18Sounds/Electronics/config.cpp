class CfgPatches
{
    class X18Sounds_Electronics
    {
        units[] = {};
        ammo[] = {};
        weapons[] = {};
        magazines[] = {};
        requiredVersion = 1.6;
        requiredAddons[] = {
            "DZ_Data"
        };
    };
};
class CfgSoundShaders
{
    class BatteryInsert_SoundShader
    {
        samples[] = {
            {"Noosphere\X18Sounds\Electronics\Sounds\BatteryInsert_1",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\BatteryInsert_2",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\BatteryInsert_3",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\BatteryInsert_4",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\BatteryInsert_5",0.2}
        };
        range = 5;
        volume = 0.5;
    };
    class BatteryRemove_SoundShader
    {
        samples[] = {
            {"Noosphere\X18Sounds\Electronics\Sounds\BatteryRemove_1",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\BatteryRemove_2",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\BatteryRemove_3",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\BatteryRemove_4",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\BatteryRemove_5",0.2}
        };
        range = 5;
        volume = 0.5;
    };
    class Click_SoundShader
    {
        samples[] = {
            {"Noosphere\X18Sounds\Electronics\Sounds\Click_1",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\Click_2",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\Click_3",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\Click_4",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\Click_5",0.2}
        };
        range = 5;
        volume = 0.5;
    };
    class Switch_SoundShader
    {
        samples[] = {
            {"Noosphere\X18Sounds\Electronics\Sounds\Switch_1",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\Switch_2",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\Switch_3",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\Switch_4",0.2},
            {"Noosphere\X18Sounds\Electronics\Sounds\Switch_5",0.2}
        };
        range = 5;
        volume = 0.5;
    };
};
class CfgSoundSets
{
    class BatteryInsert_SoundSet
    {
        soundShaders[] = {
            "BatteryInsert_SoundShader"
        };
    };
    class BatteryRemove_SoundSet
    {
        soundShaders[] = {
            "BatteryRemove_SoundShader"
        };
    };
    class Click_SoundSet
    {
        soundShaders[] = {
            "Click_SoundShader"
        };
    };
    class Switch_SoundSet
    {
        soundShaders[] = {
            "Switch_SoundShader"
        };
    };
};