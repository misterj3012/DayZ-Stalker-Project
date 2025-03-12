class PlayerStatRadiation : PlayerStat<float>
{
	private float addDelta = 0.0;

	override void Add(float value, string system = "")
	{
		if (value > 0.0)
			addDelta = addDelta + value;

		super.Add(value, system);
	}
}