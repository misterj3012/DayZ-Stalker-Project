modded class X18_Artefact_Kolobok_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.AddHealth("", "Health", 10);
		BrokenLegs(player, 15, false);
	}
	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(0.5);
		player.GetStatMeleeProtection().Add(0.5);
	}
	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(-0.5);
		player.GetStatMeleeProtection().Add(-0.5);
	}
}