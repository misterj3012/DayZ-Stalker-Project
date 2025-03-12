class X18_Artefact_AlteredWheel_Base : X18_Artefact_Base
{
	override void ActivateEffects()
	{
		m_ParticleEfx = Particle.PlayOnObject(ParticleList.ALTEREDWHEEL, this);
		m_Light = ArtefactLight.Cast(ScriptedLightBase.CreateLight(ArtefactLight, "0 0 0"));
		m_Light.AttachOnObject(this, "0 0.3 0", "0 0 0");
		m_Light.SetColorToWhite();
	}
}

class X18_Artefact_AlteredWheel_Spawn : X18_Artefact_Spawn_Base
{
	override int GetTier()
	{
		return 5;
	}

	override string GetArtefact()
	{
		return "X18_Artefact_AlteredWheel";
	}
}