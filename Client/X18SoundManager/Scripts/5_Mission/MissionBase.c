modded class MissionBase
{
	protected SoundManager m_SoundManager;
	override void OnInit()
	{
		super.OnInit();
		m_SoundManager = GetSoundManager();
	}
}