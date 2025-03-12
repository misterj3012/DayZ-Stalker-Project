modded class MissionServer
{
	protected StashSpawner m_StashSpawner;
	override void OnInit()
	{
		super.OnInit();
		m_StashSpawner = GetStashSpawner();
	}
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		m_StashSpawner._CheckForStashes(timeslice);
	}
}