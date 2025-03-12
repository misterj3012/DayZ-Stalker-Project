class Ambient
{
	private autoptr array< ref AmbientModuleBase > m_Modules;
	void Ambient()
	{
		m_Modules = new array< ref AmbientModuleBase >;
		m_Modules.Insert(new GlobalSoundAmbientModule);
		m_Modules.Insert(new GlobalObjectAmbientModule);
		m_Modules.Insert(new RadioAmbientModule);
	}
	void OnInit()
	{
		for (int i = 0; i < m_Modules.Count(); i++)
		{
			m_Modules[i].OnInit();
		}
	}
	void OnUpdate(float timeslice)
	{}
}
static ref Ambient g_Ambient;
static ref Ambient GetAmbient()
{
	if (!g_Ambient)
		g_Ambient = new Ambient();
	return g_Ambient;
}