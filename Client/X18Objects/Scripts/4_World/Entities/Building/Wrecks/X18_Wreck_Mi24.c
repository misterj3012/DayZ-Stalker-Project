class X18_Wreck_Mi24_1 extends CrashBase
{
	void X18_Wreck_Mi24_1()
	{
		if (!GetGame().IsDedicatedServer())
		{
			m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_HELI_WRECK, this, Vector(-0.5, 0, -2)); // First: Left/Right | Middle: Up/Down | Last: Forward/Backward
		}
	}
	/*override string EventType()
	{
		return "Wreck_Mi24";
	}*/
}
class X18_Wreck_Mi24_2 extends CrashBase
{
	void X18_Wreck_Mi24_2()
	{
		if (!GetGame().IsDedicatedServer())
		{
			m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_HELI_WRECK, this, Vector(2, 0, -2)); // First: Left/Right | Middle: Up/Down | Last: Forward/Backward
		}
	}
	/*override string EventType()
	{
		return "Wreck_Mi24";
	}*/
}