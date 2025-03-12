modded class ModifiersManager
{
	override void Init()
	{
		super.Init();
		AddModifier(new MexaminMdfr);
		AddModifier(new MexaminInjectorMdfr);
		AddModifier(new AntiRadVodkaMdfr);
		AddModifier(new AntiRadCigaretteMdfr);
		AddModifier(new AntiRadJointMdfr);
		AddModifier(new PC1Mdfr);
		AddModifier(new RadioProtectantMdfr);
		AddModifier(new MediKitTier1Mdfr);
		AddModifier(new MediKitTier2Mdfr);
		AddModifier(new MediKitTier3Mdfr);
		AddModifier(new StalkerEnergyMdfr);
	}
}