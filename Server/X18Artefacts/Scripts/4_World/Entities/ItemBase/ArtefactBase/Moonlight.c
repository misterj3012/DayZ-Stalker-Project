modded class X18_Artefact_Moonlight_Base : X18_Artefact_Base
{
	override void OnTickNegative(PlayerBase player)
	{
		player.GetStatRadiation().Add(50);
	}
}