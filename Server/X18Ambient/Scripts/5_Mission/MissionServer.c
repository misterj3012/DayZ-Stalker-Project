modded class MissionServer
{
	void MissionServer()
	{
		GetAmbient();
	}
	override void OnInit()
	{
		GetDayZGame().SetRadioConfig(RadioConfigServer.LoadConfig("Radios.json"));
		GetAmbient().OnInit();
		super.OnInit();
	}
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		GetAmbient().OnUpdate(timeslice);
	}
}