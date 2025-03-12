modded class X18_Artefact_Soul_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.AddHealth("", "Health", 6);
		player.AddHealth("", "Blood", 10);
	}
	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(0.2);
		player.GetStatMeleeProtection().Add(0.2);
	}
	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(-0.2);
		player.GetStatMeleeProtection().Add(-0.2);
	}
}