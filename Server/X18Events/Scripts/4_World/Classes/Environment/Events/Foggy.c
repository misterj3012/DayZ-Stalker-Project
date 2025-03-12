class Foggy : WeatherEvent
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
		return Math.RandomFloatInclusive(0.05, 0.10);
	}
	override float GetOvercastTarget()
	{
		return Math.RandomFloatInclusive(0.25, 0.40);
	}
	override float GetEventCooldown()
	{
		return 1800.0;
	}
	override TTypenameArray GetDisallowedEvents()
	{
		return { Emission, Sunny, HeavyFog, Foggy };
	}
}