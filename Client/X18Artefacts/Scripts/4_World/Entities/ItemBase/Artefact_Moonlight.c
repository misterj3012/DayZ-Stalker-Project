class X18_Artefact_Moonlight_Base : X18_Artefact_Base
{
	override void ActivateEffects()
	{
		m_ParticleEfx = Particle.PlayOnObject(ParticleList.MOONLIGHT, this);
		m_Light = ArtefactLight.Cast(ScriptedLightBase.CreateLight(ArtefactLight, "0 0 0"));
		m_Light.AttachOnObject(this, "0 0.3 0", "0 0 0");
		m_Light.SetColorToWhite();
	}
}

class X18_Artefact_Moonlight_Spawn : X18_Artefact_Spawn_Base
{
	override int GetTier()
	{
		return 4;
	}

	override string GetArtefact()
	{
		return "X18_Artefact_Moonlight";
	}
}