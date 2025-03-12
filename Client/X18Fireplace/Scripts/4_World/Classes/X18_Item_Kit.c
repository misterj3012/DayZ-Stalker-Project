class X18_Item_Kit: ItemBase
{		
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
		if (GetGame().IsServer())
		{
			EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx(Get_ItemName(), position, ECE_PLACE_ON_SURFACE));
			kitItem.SetPosition(position);
			kitItem.SetOrientation(orientation);
		}
		
		SetIsPlaceSound(true);
	}	
	
	override bool IsBasebuildingKit()
	{
		return true;
	}
	
	override bool IsDeployable()
	{
		return true;
	}

    override void SetActions()
    {
        super.SetActions();        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};