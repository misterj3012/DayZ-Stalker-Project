modded class X18_Artefact_MeatChunk_Base : X18_Artefact_Base
{
	override void OnTickNegative(PlayerBase player)
	{
		player.AddHealth("", "Shock", -2.5);
		BrokenLegs(player, 20);
	}
	override void OnPassivePositiveActivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(-0.1);
	}
	override void OnPassivePositiveDeactivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(0.1);
	}
}