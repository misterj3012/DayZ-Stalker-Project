class X18_FirewoodStorage : X18_Item
{
    override string Get_KitName()
	{
		return "X18_FirewoodStorageKit";
	}

   static const ref array<typename> ITEM_WHITELIST = { Firewood };

    override bool DamageItemInCargo( float damage )
    {
        return false;
    }

    override bool CanReceiveItemIntoCargo( EntityAI item )
    {
        if ( item.IsAnyInherited( ITEM_WHITELIST ) )
        {
            return super.CanReceiveItemIntoCargo( item );
        }
        return false;
    }
};

class X18_FirewoodStorageKit : X18_Item_Kit
{
    override string Get_ItemName()
	{
		return "X18_FirewoodStorage";
	} 
	
	override vector Get_ItemPlacingPos()
	{
		return "0 0.20 0";
	}
};