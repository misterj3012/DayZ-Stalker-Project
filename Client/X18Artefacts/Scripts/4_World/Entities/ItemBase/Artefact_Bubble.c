class X18_Artefact_Bubble_Base : X18_Artefact_Base
{
	override void ActivateEffects()
	{
		m_ParticleEfx = Particle.PlayOnObject(ParticleList.BUBBLE, this);
		m_Light = ArtefactLight.Cast(ScriptedLightBase.CreateLight(ArtefactLight, "0 0 0"));
		m_Light.AttachOnObject(this, "0 0.3 0", "0 0 0");
		m_Light.SetColorToGreen();
	}
}

class X18_Artefact_Bubble_Spawn : X18_Artefact_Spawn_Base
{
	override int GetTier()
	{
		return 2;
	}

	override string GetArtefact()
	{
		return "X18_Artefact_Bubble";
	}
}