class Rainy : WeatherEvent
{
	override float GetFogTarget()
	{
		return 0.0;
	}
	override float GetRainTarget()
	{
		return Math.RandomFloatInclusive(0.2, 0.8);
	}
	override float GetOvercastTarget()
	{
		return Math.RandomFloatInclusive(0.7, 0.8);
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
		return { Emission, Sunny, Foggy, HeavyFog };
	}
}