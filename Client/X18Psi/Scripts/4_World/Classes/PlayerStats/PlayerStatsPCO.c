enum PlayerStats_Psi : PlayerStats_Ecology
{
	PSI,
}

modded class PlayerStatsPCO_current
{
	override void Init()
	{
		super.Init();
		RegisterStat(PlayerStats_Psi.PSI, new PlayerStatPsi(0, 99999, 0, "Psi", EPSstatsFlags.EMPTY));
	}
}