class HeavyFog : WeatherEvent
{
	override float GetInitPhaseLength()
	{
		return 300.0;
	}
	override float GetMidPhaseLength()
	{
		return Math.RandomFloat(300, 600);
	}
	override float GetEndPhaseLength()
	{
		return GetInitPhaseLength();
	}
	override float GetFogTarget()
	{
		return Math.RandomFloatInclusive(0.10, 0.20);
	}
	override float GetOvercastTarget()
	{
		return Math.RandomFloatInclusive(0.75, 0.90);
	}
	override float GetEventCooldown()
	{
		return 1800.0;
	}
	override TTypenameArray GetDisallowedEvents()
	{
		return { Emission, Foggy, Sunny, Cloudy };
	}
}