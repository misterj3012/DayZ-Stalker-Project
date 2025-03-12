class Cloudy : WeatherEvent
{
	override float GetFogTarget()
	{
		return 0.0;
	}
	override float GetRainTarget()
	{
		return 0.0;
	}
	override float GetOvercastTarget()
	{
		return Math.RandomFloatInclusive(0.75, 0.8);
	}
	override float GetInitPhaseLength()
	{
		return 300.0;
	}
	override float GetMidPhaseLength()
	{
		return Math.RandomFloat(600, 1200);
	}
	override float GetEndPhaseLength()
	{
		return GetInitPhaseLength();
	}
	override TTypenameArray GetDisallowedEvents()
	{
		return { Emission, Stormy, Rainy, Foggy, HeavyFog, Sunny };
	}
}