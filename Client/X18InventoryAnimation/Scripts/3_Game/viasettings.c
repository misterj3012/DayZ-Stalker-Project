class VIASettings
{
	static const string FILE_NAME = "$profile:/Noosphere/VIA.json";
	static ref VIASettings SETTINGS = new VIASettings();

	bool forcePreview = true; // force animation to be player in preview. disables local menu
	bool forceAnimation = true; // force animation to be played. disables local menu
	float delay = 0.6; // delay on when to start the animation after opening the inventory
}