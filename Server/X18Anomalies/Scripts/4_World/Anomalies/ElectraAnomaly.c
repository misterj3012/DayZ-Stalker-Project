modded class X18_Anomaly_Electra
{
	void X18_Anomaly_Electra()
	{
		GetAnomalyManager().AddElectraAnomaly(this);
	}
	void ~X18_Anomaly_Electra()
	{
		GetAnomalyManager().RemoveElectraAnomaly(this);
	}
}