modded class FireplaceLight extends PointLightBase
{	
	static float m_FireplaceRadius = 10;
	static float m_FireplaceBrightness = 4.75;
	
	void FireplaceLight()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo( m_FireplaceRadius );
		SetBrightnessTo(m_FireplaceBrightness);
		SetCastShadow(true);
		SetFadeOutTime(5);
		SetDiffuseColor(1.0, 0.5, 0.3);
		SetAmbientColor(1.0, 0.5, 0.3);
		SetFlareVisible(false);
		SetFlickerAmplitude(0.3);
		SetFlickerSpeed(0.9);
		SetExteriorMode();
		EnableHeatHaze(true);
		SetHeatHazeRadius(0.23);
		SetHeatHazePower(0.010);
	}	
	
	void SetInteriorMode()
	{
		SetDancingShadowsMovementSpeed(0.05);
		SetDancingShadowsAmplitude(0.05);
	}	
	
	void SetExteriorMode()
	{
		SetDancingShadowsMovementSpeed(0.25);
		SetDancingShadowsAmplitude(0.25);
	}
}