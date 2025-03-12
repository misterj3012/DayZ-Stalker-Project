modded class MissionServer
{
	ref MedicalSystem m_MedicalSystem;
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		if (!m_MedicalSystem)
			m_MedicalSystem = new MedicalSystem();
	}
}