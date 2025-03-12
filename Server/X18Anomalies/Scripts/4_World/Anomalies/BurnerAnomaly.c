modded class X18_Anomaly_Burner
{
	void X18_Anomaly_Burner()
	{
		GetAnomalyManager().AddBurnerAnomaly(this);
	}
	void ~X18_Anomaly_Burner()
	{
		GetAnomalyManager().RemoveBurnerAnomaly(this);
	}
}