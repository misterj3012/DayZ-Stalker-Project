EffectSound PlaySoundOnPlayer(string soundSet, float volume = 1, bool loop = false)
{
	EffectSound effect_sound;
	if (GetGame().IsClient() || !GetGame().IsMultiplayer())
	{
		PrintDebug("PlaySoundOnPlayer SoundSet: " + soundSet);
		effect_sound = SEffectManager.PlaySoundOnObject(soundSet, GetGame().GetPlayer(), 0, 0, loop);
		if (!effect_sound)
		{
			PrintDebug("Sound failed to play %1", soundSet);
			return effect_sound;
		}
		effect_sound.SetParent(GetGame().GetPlayer());
		effect_sound.SetSoundAutodestroy(true);
		effect_sound.GetSoundObject().SetVolume(volume);
	}
	return effect_sound;
}
EffectSound PlaySoundOnObject(string soundSet, EntityAI entity, float volume = 1, bool loop = false)
{
	EffectSound effect_sound;
	if (GetGame().IsClient() || !GetGame().IsMultiplayer())
	{
		EntityAI obj;
		if (Class.CastTo(obj, entity))
			effect_sound = SEffectManager.PlaySoundOnObject(soundSet, obj, 0, 0, loop);
		if (!effect_sound)
		{
			PrintDebug("Sound failed to play %1", soundSet);
			return effect_sound;
		}
		PrintDebug("PlaySoundOnObject SoundSet: " + soundSet + " on Object: " + entity.GetType());
		effect_sound.SetParent(obj);
		effect_sound.SetSoundAutodestroy(true);
		effect_sound.GetSoundObject().SetVolume(volume);
	}
	return effect_sound;
}
EffectSound PlaySoundOnRadio(string soundSet, EntityAI entity, float volume = 1, bool loop = false)
{
	EffectSound effect_sound;
	if (GetGame().IsClient() || !GetGame().IsMultiplayer())
	{
		RadioObject obj;
		if (Class.CastTo(obj, entity) && !obj.IsPlaying())
			effect_sound = obj.PlaySoundSet(soundSet, volume, loop);
	}
	return effect_sound;
}

EffectSound PlayEnvironmentSound(string soundSet, vector position, float volume, bool loop = false, Object parent = null)
{
	EffectSound effect_sound;
	if (GetGame().IsClient() || !GetGame().IsMultiplayer())
	{
		effect_sound = SEffectManager.PlaySound(soundSet, position, 0, 0, loop);
		PrintDebug("PlayEnvironmentSound SoundSet: " + soundSet);
		if (!effect_sound)
		{
			PrintDebug("Sound failed to play %1", soundSet);
			return effect_sound;
		}
		effect_sound.SetParent(parent);
		effect_sound.GetSoundObject().SetVolume(volume);
		effect_sound.SetSoundAutodestroy(true);
	}
	return effect_sound;
}

void PrintDebug(string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
{
#ifdef X18SOUNDMANAGERDEBUG
	PrintLog(string.Format("[SoundEffects]: " + msg, param1, param2, param3, param4, param5, param6, param7, param8, param9), "SoundManager");
#endif
}
void PrintInfo(string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
{
	PrintLog(string.Format("[SoundEffects]: " + msg, param1, param2, param3, param4, param5, param6, param7, param8, param9), "SoundManager");
}