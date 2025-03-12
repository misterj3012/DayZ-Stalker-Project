modded class MissionServer
{
	protected AnomalyManager m_AnomalyManager;
	override void OnInit()
	{
		super.OnInit();
		AnomalySpawner.ClearInstance();
		AnomalySpawner.GetInstance();
		if (m_AnomalyManager)
			m_AnomalyManager = GetAnomalyManager();
	}
}