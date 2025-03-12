enum PlayerStats_Ecology : EX18PlayerStats_Core
{
	RADIATION,
}

modded class PlayerStatsPCO_current
{
	override void Init()
	{
		super.Init();
		RegisterStat(PlayerStats_Ecology.RADIATION, new PlayerStatRadiation(0, 99999, 0, "Radiation", EPSstatsFlags.EMPTY));
	}
}