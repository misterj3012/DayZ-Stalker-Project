modded class SoundManager
{
	ref array<Object> sirens = new array<Object>();
	ref array<Object> transmitters = new array<Object>();
	ref array<Object> radios = new array<Object>();
	void AddSiren(Object obj)
	{
		if (obj && sirens.Find(obj) == -1)
		{
			sirens.Insert(obj);
			PrintInfo("Siren: %1 has been added!", obj.GetType());
		}
	}
	void StartSirenSounds(string soundSet, float volume = 1)
	{
		if (GetGame().IsDedicatedServer())
		{
			PrintDebug("Starting Sirens all over the Server... " + sirens.Count());
			int start = GetGame().GetTime();
			vector m_ampLocalPosition;
			foreach(Object obj : sirens)
			{
				EntityAI m_Amp;
				if (Class.CastTo(m_Amp, obj))
				{
					switch (m_Amp.GetType())
					{
						case "Land_Power_Pole_Conc1_Amp":
							m_ampLocalPosition = "0 7.060 0";
							break;
						case "Land_Power_Pole_Conc4_Lamp_Amp":
							m_ampLocalPosition = "1.507 8.944 -0.443";
							break;
						case "Land_Power_Pole_Wood1_Amp":
							m_ampLocalPosition = "0.391 7.461 -0.188";
							break;
						case "Land_Power_Pole_Wood1_Lamp_Amp":
							m_ampLocalPosition = "0.391 7.461 -0.188";
							break;
						case "Land_Lamp_City1_amp":
							m_ampLocalPosition = "-0.725 7.632 2.920";
							break;
					}
					PlayEnvironmentSoundServer(soundSet, m_Amp.GetPosition() + m_ampLocalPosition, volume);
				}

			}
			PrintDebug("Time to start all Sirens: " + (GetGame().GetTime() - start) + "ms");
		}
	}
	void AddTransmitter(Object obj)
	{
		if (obj && transmitters.Find(obj) == -1)
		{
			transmitters.Insert(obj);
			PrintInfo("Transmitter: %1 has been added!", obj.GetType());
		}
	}
	void RemoveTransmitter(Object obj)
	{
		if (!obj)
			return;
		transmitters.RemoveItem(obj);
		PrintInfo("Transmitter: %1 has been removed!", obj.GetType());
	}
	void StartTransmitterSounds(string soundSet, float volume = 1)
	{
		if (GetGame().IsDedicatedServer()) {
			PrintDebug("Starting Transmitters all over the Server... " + transmitters.Count());
			int start = GetGame().GetTime();
			foreach(Object obj : transmitters)
			{
				EntityAI entity;
				if (Class.CastTo(entity, obj))
					PlaySoundOnObjectServer(soundSet, entity, volume);
			}
			PrintDebug("Time to start all Transmitters: " + (GetGame().GetTime() - start) + "ms");
		}
	}
	void AddRadio(Object obj)
	{
		if (obj && radios.Find(obj) == -1)
		{
			radios.Insert(obj);
			PrintInfo("Radio: %1 has been added!", obj.GetType());
		}
	}
	void RemoveRadio(Object obj)
	{
		if (!obj)
			return;
		radios.RemoveItem(obj);
		PrintInfo("Radio: %1 has been removed!", obj.GetType());
	}
	void StartRadioSounds(string soundSet, float volume = 0.25, bool loop = false)
	{
		if (GetGame().IsDedicatedServer())
		{
			PrintDebug("Starting Radios all over the Server... " + radios.Count());
			int start = GetGame().GetTime();
			foreach(Object obj : radios)
			{
				RadioObject entity;
				if (Class.CastTo(entity, obj))
					PlaySoundOnRadioObjectServer(soundSet, entity, volume);
			}
			PrintDebug("Time to start all Radios: " + (GetGame().GetTime() - start) + "ms");
		}
	}
	void StartAmbientSound(string soundSet, vector position, float volume = 1)
	{
		if (GetGame().IsDedicatedServer())
		{
			PrintDebug("Starting Ambient all over the Server...");
			thread PlayEnvironmentSoundServer(soundSet, position, volume);
		}
	}
	void PlayEnvironmentSoundServer(string soundSet, vector position, float volume = 1)
	{
		GetGame().RPCSingleParam(null, SoundManagerRPCs.RPC_PLAY_SOUND_ENVIRONMENT, new Param3<string, vector, float>(soundSet, position, volume), true);
	}
	void PlaySoundOnObjectServer(string soundSet, EntityAI entity, float volume = 1)
	{
		GetGame().RPCSingleParam(null, SoundManagerRPCs.RPC_PLAY_SOUND_OBJECT, new Param3<string, EntityAI, float>(soundSet, entity, volume), true);
	}
	void PlaySoundOnPlayerServer(string soundSet, float volume = 1)
	{
		GetGame().RPCSingleParam(null, SoundManagerRPCs.RPC_PLAY_SOUND_PLAYER, new Param2<string, float>(soundSet, volume), true);
	}
	void PlaySoundOnRadioObjectServer(string soundSet, RadioObject entity, float volume = 1)
	{
		GetGame().RPCSingleParam(null, SoundManagerRPCs.RPC_PLAY_SOUND_RADIO, new Param3<string, RadioObject, float>(soundSet, entity, volume), true);
	}
}