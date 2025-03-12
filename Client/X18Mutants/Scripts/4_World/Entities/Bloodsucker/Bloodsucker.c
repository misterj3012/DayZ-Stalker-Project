modded class Mutant_AoD_Krovosos2 : Mutant_AoD_Krovosos1_Base
{
	override void ChangeVisible(bool v)
	{
		super.ChangeVisible(v);
		SetAllowDamage(true);
	}
}

modded class Mutant_AoD_Krovosos3 : Mutant_AoD_Krovosos1_Base
{
	override void ChangeVisible(bool v)
	{
		super.ChangeVisible(v);
		SetAllowDamage(true);
	}
}

modded class Mutant_AoD_Krovosos5 : Mutant_AoD_Krovosos2_Base
{
	override void ChangeVisible(bool v)
	{
		super.ChangeVisible(v);
		SetAllowDamage(true);
	}
}

modded class Mutant_AoD_Krovosos6 : Mutant_AoD_Krovosos2_Base
{
	override void ChangeVisible(bool v)
	{
		super.ChangeVisible(v);
		SetAllowDamage(true);
	}
}

class X18_Mutant_Bloodsucker : Mutant_AoD_Krovosos1 {}
class X18_Mutant_Bloodsucker_Normal : Mutant_AoD_Krovosos2 {}
class X18_Mutant_Bloodsucker_MarshCreature : Mutant_AoD_Krovosos3 {}
class X18_Mutant_Bloodsucker_MarshCreature_2 : Mutant_AoD_Krovosos3 {}
class X18_Mutant_Bloodsucker_Red : Mutant_AoD_Krovosos4 {}
class X18_Mutant_Bloodsucker_Dark : Mutant_AoD_Krovosos5 {}
class X18_Mutant_Bloodsucker_Green : Mutant_AoD_Krovosos6 {}