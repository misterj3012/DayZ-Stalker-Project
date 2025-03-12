modded class ItemBase
{
	void ItemBase()
	{
		if (GetGame().IsDedicatedServer())
			SetFlags(EntityFlags.TOUCHTRIGGERS, false);
	}
};
class X18_Bolt : ItemBase {};