class CfgPatches
{
    class X18Sounds_Artefacts
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
    class ArtefactFound_SoundShader
    {
        samples[] = { {"Noosphere\X18Sounds\Artefacts\Sounds\Artefact_Found",1} };
        range = 80;
        volume = 1;
    };
};
class CfgSoundSets
{
    class ArtefactFound_SoundSet
    {
        soundShaders[] = { "ArtefactFound_SoundShader" };
    };
};