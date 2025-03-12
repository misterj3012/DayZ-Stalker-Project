class AnomalyElectraActivate : WeatherEvent
{
	override void InitPhaseServer()
	{
		super.InitPhaseServer();
		GetAnomalyManager().StartElectraAnomalies();
	}
}
class AnomalyElectraRandomActivate : WeatherEvent
{
	override void InitPhaseServer()
	{
		super.InitPhaseServer();
		GetAnomalyManager().StartElectraAnomaliesRandom();
	}
}
class AnomalyBurnerActivate : WeatherEvent
{
	override void InitPhaseServer()
	{
		super.InitPhaseServer();
		GetAnomalyManager().StartBurnerAnomalies();
	}
}
class AnomalyBurnerRandomActivate : WeatherEvent
{
	override void InitPhaseServer()
	{
		super.InitPhaseServer();
		GetAnomalyManager().StartBurnerAnomaliesRandom();
	}
}