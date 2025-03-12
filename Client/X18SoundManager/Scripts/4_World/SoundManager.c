class SoundManager
{
	void SoundManager()
	{
		DayZGame.Event_OnRPC.Insert(OnRPC);
	}
	void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			switch (rpc_type) {
			case SoundManagerRPCs.RPC_PLAY_SOUND_ENVIRONMENT:
			{
				Param3<string, vector, float> sound_environment_param;
				if (!ctx.Read(sound_environment_param))
					break;
				thread PlayEnvironmentSound(sound_environment_param.param1, sound_environment_param.param2, sound_environment_param.param3);
				break;
			}
			case SoundManagerRPCs.RPC_PLAY_SOUND_OBJECT:
			{
				Param3<string, EntityAI, float> sound_object_param;
				if (!ctx.Read(sound_object_param))
					break;
				thread PlaySoundOnObject(sound_object_param.param1, sound_object_param.param2, sound_object_param.param3);
				break;
			}
			case SoundManagerRPCs.RPC_PLAY_SOUND_RADIO:
			{
				Param3<string, EntityAI, float> sound_radio_param;
				if (!ctx.Read(sound_radio_param))
					break;
				thread PlaySoundOnRadio(sound_radio_param.param1, sound_radio_param.param2, sound_radio_param.param3);
				break;
			}
			case SoundManagerRPCs.RPC_PLAY_SOUND_PLAYER:
			{
				Param2<string, float> sound_player_param;
				if (!ctx.Read(sound_player_param))
					break;
				thread PlaySoundOnPlayer(sound_player_param.param1, sound_player_param.param2);
				break;
			}
			}
		}
	}

	void PrintDebug(string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
#ifdef X18SOUNDMANAGERDEBUG
		PrintLog(string.Format("[" + Type() + "]: " + msg, param1, param2, param3, param4, param5, param6, param7, param8, param9), "SoundManager");
#endif
	}
	void PrintInfo(string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
		PrintLog(string.Format("[" + Type() + "]: " + msg, param1, param2, param3, param4, param5, param6, param7, param8, param9), "SoundManager");
	}
}

static ref SoundManager g_SoundManager;
static SoundManager GetSoundManager()
{
	if (!g_SoundManager)
		g_SoundManager = new SoundManager();
	return g_SoundManager;
}