// modded class WorldLighting
// {
// 	protected string DarkOvercastNight = "Noosphere\\X18CoreScripts\\Data\\DarkOvercastNight.txt";
// 	protected string DarkOvercastNightNoise = "Noosphere\\X18CoreScripts\\Data\\DarkOvercastNightNoise.txt";
// 	protected string BrighterOvercastNight = "Noosphere\\X18CoreScripts\\Data\\BrighterOvercastNight.txt";
// 	protected string BrighterOvercastNightNoise = "Noosphere\\X18CoreScripts\\Data\\BrighterOvercastNightNoise.txt";

// 	override void SetGlobalLighting(int lightingID)
// 	{
// 		super.SetGlobalLighting(lightingID);
// 		switch (lightingID)
// 		{
// 		case 2:
// 			GetGame().GetWorld().LoadNewLightingCfg(DarkOvercastNight);
// 			break;

// 		case 3:
// 			GetGame().GetWorld().LoadNewLightingCfg(DarkOvercastNightNoise);
// 			break;
// 		case 4:
// 			GetGame().GetWorld().LoadNewLightingCfg(BrighterOvercastNight);
// 			break;

// 		case 5:
// 			GetGame().GetWorld().LoadNewLightingCfg(BrighterOvercastNightNoise);
// 			break;
// 		}
// 	}
// }