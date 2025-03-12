class X18_Wallet_Base : Inventory_Base
{
	ref TStringArray AcceptableItems =
	{
		"Coin_Base",
		"Money_Base",
		"License_Base",
		"Paper",
		"X18_Note"
	};
	ref TStringArray NonAcceptableItems =
	{
		"SFP_Collection_base"
	};
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < NonAcceptableItems.Count();i++)
		{
			if (item.IsKindOf(NonAcceptableItems[i]))
				return false;
		}
		for (i = 0; i < AcceptableItems.Count();i++)
		{
			if (item.IsKindOf(AcceptableItems[i]))
				return true;
		}
		return false;
	}
	override bool CanLoadItemIntoCargo(EntityAI item)
	{
		// for (int i = 0; i < NonAcceptableItems.Count();i++)
		// {
		// 	if (item.IsKindOf(NonAcceptableItems[i]))
		// 		return false;
		// }
		for (int i = 0; i < AcceptableItems.Count();i++)
		{
			if (item.IsKindOf(AcceptableItems[i]))
				return true;
		}
		return false;
	}
}