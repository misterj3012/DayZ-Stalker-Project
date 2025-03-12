class GlobalSoundAmbientModule : AmbientModuleBase
{
	ref Timer m_SyncAmbientMapTimer;
	void GlobalSoundAmbientModule()
	{}
	void ~GlobalSoundAmbientModule()
	{}
	override void OnInit()
	{
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_SyncAmbientMapTimer = new Timer();
			int rnd = Math.RandomIntInclusive(60, 180);
			m_SyncAmbientMapTimer.Run(rnd, this, "GlobalAmbientSoundMap", NULL, true);
		}
	}
	private void GlobalAmbientSoundMap()
	{
		TStringArray soundArray =
		{
			"Ambient_Global_1_SoundSet",
			"Ambient_Global_2_SoundSet",
			"Ambient_Global_3_SoundSet",
			"Ambient_Global_4_SoundSet",
			"Ambient_Global_5_SoundSet",
			"Ambient_Global_6_SoundSet",
			"Ambient_Global_7_SoundSet",
			"Ambient_Global_8_SoundSet",
			"Ambient_Global_9_SoundSet",
			"Ambient_Global_10_SoundSet",
			"Ambient_Global_11_SoundSet",
			"Ambient_Global_12_SoundSet",
			"Ambient_Global_13_SoundSet",
			"Ambient_Global_14_SoundSet",
			"Ambient_Global_15_SoundSet",
			"Ambient_Global_16_SoundSet",
			"Ambient_Global_17_SoundSet",
			"Ambient_Global_18_SoundSet",
			"Ambient_Global_19_SoundSet",
			"Ambient_Global_20_SoundSet",
			"Ambient_Global_21_SoundSet",
			"Ambient_Global_22_SoundSet",
			"Ambient_Global_23_SoundSet",
			"Ambient_Global_24_SoundSet",
			"Ambient_Global_25_SoundSet",
			"Ambient_Global_26_SoundSet",
			"Ambient_Global_27_SoundSet",
			"Ambient_Global_28_SoundSet",
			"Ambient_Global_29_SoundSet",
			"Ambient_Global_30_SoundSet",
			"Ambient_Global_31_SoundSet",
			"Ambient_Global_32_SoundSet",
			"Ambient_Global_33_SoundSet",
			"Ambient_Global_34_SoundSet",
			"Ambient_Global_35_SoundSet",
			"Ambient_Global_36_SoundSet",
			"Ambient_Global_37_SoundSet",
			"Ambient_Global_38_SoundSet",
			"Ambient_Global_39_SoundSet",
			"Ambient_Global_40_SoundSet",
			"Ambient_Global_41_SoundSet",
			"Ambient_Global_42_SoundSet",
			"Ambient_Global_43_SoundSet",
			"Ambient_Global_44_SoundSet",
			"Ambient_Global_45_SoundSet",
			"Ambient_Global_46_SoundSet",
			"Ambient_Global_47_SoundSet",
			"Ambient_Global_48_SoundSet",
			"Ambient_Global_49_SoundSet",
			"Ambient_Global_50_SoundSet",
			"Ambient_Global_51_SoundSet",
			"Ambient_Global_52_SoundSet",
			"Ambient_Global_53_SoundSet",
			"Ambient_Global_54_SoundSet",
			"Ambient_Global_55_SoundSet",
			"Ambient_Global_56_SoundSet",
			"Ambient_Global_57_SoundSet",
			"Ambient_Global_58_SoundSet",
			"Ambient_Global_59_SoundSet",
			"Ambient_Global_60_SoundSet",
			"Ambient_Global_61_SoundSet",
			"Ambient_Global_62_SoundSet",
			"Ambient_Global_63_SoundSet",
			"Ambient_Global_64_SoundSet",
			"Ambient_Global_65_SoundSet",
			"Ambient_Global_66_SoundSet",
			"Ambient_Global_67_SoundSet",
			"Ambient_Global_68_SoundSet",
			"Ambient_Global_69_SoundSet",
			"Ambient_Global_70_SoundSet",
			"Ambient_Global_71_SoundSet",
			"Ambient_Global_72_SoundSet",
			"Ambient_Global_73_SoundSet",
			"Ambient_Global_74_SoundSet",
			"Ambient_Global_75_SoundSet",
			"Ambient_Global_76_SoundSet",
			"Ambient_Global_77_SoundSet",
			"Ambient_Global_78_SoundSet",
			"Ambient_Global_79_SoundSet",
			"Ambient_Global_80_SoundSet"
		};

		vector position = GetRandomPosition(5200, 6400, 7500);
		position[1] = GetGame().SurfaceY(position[0], position[2]) + Math.RandomFloatInclusive(5, 50);

		GetSoundManager().StartAmbientSound(soundArray.GetRandomElement(), position);
	}
}