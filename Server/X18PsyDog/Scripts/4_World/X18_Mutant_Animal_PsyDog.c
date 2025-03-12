class X18_Mutant_Animal_PsyDog : Animal_CanisLupus
{
	private int 				m_PhantomsCount = 7;
	private int 				m_PhantomSpawnTimer = 2;
	private int 				m_PhantomCheckTimer = 2;
	private float				m_radius = 7;
	private float				m_PhantomHealth = 1;
	private	string				m_Classname = "X18_Mutant_Animal_PsyDog_Phantom";
	private	ref	array<Object>	m_Objects = new array<Object>;
	private int					v_Alive = 0;
	protected ref 				Timer 					m_Timer;
	protected ref 				Timer 					m_Alive;
	protected PhantomSpawnFX 	m_PhantomSpawnFX;
	protected PhantomDespawnFX 	m_PhantomDespawnFX;
	void X18_Mutant_Animal_PsyDog()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PhantomSpawnTimer, 100, false);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PhantomsAliveTimer, 100, false);
		m_Timer = new Timer(CALL_CATEGORY_GAMEPLAY);
		m_Alive = new Timer(CALL_CATEGORY_GAMEPLAY);
	}
	void ~X18_Mutant_Animal_PsyDog()
	{
		m_Timer.Stop();
		m_Alive.Stop();
		int v_I = 0;
		for (v_I = 0; v_I < m_PhantomsCount; v_I++)
		{
			DespawnPhantom(0);
		}
	}
	void PhantomSpawnTimer()
	{
		m_Timer.Run(m_PhantomSpawnTimer, this, "_SpawnPhantom", NULL, true);
	}
	void PhantomsAliveTimer()
	{
		m_Alive.Run(m_PhantomCheckTimer, this, "_CheckPhantomsAlive", NULL, true);
	}
	void _CheckPhantomsAlive()
	{
		thread CheckPhantomsAlive();
	}
	void CheckPhantomsAlive()
	{
		int v_I = 0;
		for (v_I = 0; v_I < m_PhantomsCount && v_I < v_Alive; v_I++)
		{
			if (!m_Objects[v_I].IsAlive())
			{
				DespawnPhantom(v_I);
				v_Alive--;
			}
		}
	}
	void _SpawnPhantom()
	{
		thread SpawnPhantom();
	}
	void SpawnPhantom()
	{
		int v_I = 0;
		Object v_Object;
		vector v_Position = GetPosition();
		if (!IsAlive())
		{
			m_Timer.Stop();
			m_Alive.Stop();
			for (v_I = 0; v_I < m_PhantomsCount; v_I++)
			{
				DespawnPhantom(0);
			}
			return;
		}
		if (!IsPlayerInRange(GetPosition(), m_radius + 50))
		{
			for (v_I = 0; v_I < m_PhantomsCount; v_I++)
			{
				DespawnPhantom(0);
			}
			return;
		}
		if (IsPlayerInRange(GetPosition(), m_radius + 25))
		{
			for (v_I = 0; v_I < m_PhantomsCount && v_Alive < m_PhantomsCount; v_I++)
			{
				v_Position[0] = v_Position[0] + Math.RandomInt(-m_radius, m_radius);
				v_Position[2] = v_Position[2] + Math.RandomInt(-m_radius, m_radius);
				v_Object = GetGame().CreateObject(m_Classname, v_Position, false, true);
				v_Object.SetHealth(m_PhantomHealth);
				m_Objects.Insert(v_Object);
				v_Alive++;
				SpawnFX(v_Position);
				return;
			}
		}
	}
	void DespawnPhantom(int v_I)
	{
		Object m_Object = Object.Cast(m_Objects[v_I]);
		if (!m_Object)
			return;

		DespawnFX(v_I);
		GetGame().ObjectDelete(m_Objects[v_I]);
		m_Objects.Remove(v_I);
	}
	void SpawnFX(vector position)
	{
		m_PhantomSpawnFX = PhantomSpawnFX.Cast(GetGame().CreateObject("PhantomSpawnFX", position, false));
	}
	void DespawnFX(int v_I)
	{
		m_PhantomDespawnFX = PhantomDespawnFX.Cast(GetGame().CreateObject("PhantomDespawnFX", (m_Objects[v_I].GetPosition()), false));
	}
};
class X18_Mutant_Animal_PsyDog_Phantom : Animal_CanisLupus {};