modded class TransmitterBase
{
	override void OnWorkStart()
	{
		super.OnWorkStart();
		if (GetGame().IsDedicatedServer())
			GetSoundManager().AddTransmitter(this);
	}
	override void OnWorkStop()
	{
		super.OnWorkStop();
		if (GetGame().IsDedicatedServer())
			GetSoundManager().RemoveTransmitter(this);
	}
}