class Anomaly_Base : BuildingSuper
{
	void Anomaly_Base()
	{
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
			SetEventMask(EntityEvent.INIT);
	}
	protected void ReActivate()
	{}
	void DamageAreaDamageActions(Object obj)
	{}
	void Delete()
	{
		if (GetGame().IsServer())
			GetGame().ObjectDelete(this);
	}

	void Tick(float timeSlice) {}
}