enum EX18PlayerStats_Core : EPlayerStats_current
{
	BLOOD_LOSS,
	WEIGHT_REDUCTION,
	MELEE_PROTECTION,
	BULLET_PROTECTION,
}

modded class PlayerStatsPCO_current
{
	override void Init()
	{
		super.Init();
		RegisterStat(EX18PlayerStats_Core.BLOOD_LOSS, new PlayerAdditionalStat(-100.0, 100.0, 0.0, "BloodLoss", EPSstatsFlags.EMPTY));
		RegisterStat(EX18PlayerStats_Core.WEIGHT_REDUCTION, new PlayerAdditionalStat(-100.0, 100.0, 0.0, "WeightReduction", EPSstatsFlags.EMPTY));
		RegisterStat(EX18PlayerStats_Core.MELEE_PROTECTION, new PlayerAdditionalStat(-100.0, 100.0, 0.0, "MeleeProtection", EPSstatsFlags.EMPTY));
		RegisterStat(EX18PlayerStats_Core.BULLET_PROTECTION, new PlayerAdditionalStat(-100.0, 100.0, 0.0, "BulletProtection", EPSstatsFlags.EMPTY));
	}
}