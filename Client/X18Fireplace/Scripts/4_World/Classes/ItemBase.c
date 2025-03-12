modded class ItemBase
{	
	vector Get_ItemPlacingPos()
	{
		return "0 0 0";
	}

	vector Get_ItemPlacingOrientation()
	{		
		return "0 0 0";
	}
	
	string Get_ItemName()
	{
		return GetType().Substring(0,GetType().Length() - 4);
	}

	string Get_KitName()
	{
		return GetType() + "_Kit";
	}

	bool IsInvEmpty()
	{   
		if (GetNumberOfItems() < 1 &&  GetInventory().AttachmentCount() < 1)
		{
			return true;
		}
		return false;
	}
	
	bool IsWallOrGate()
	{
		return false;
	}
	
	bool IsFacingPlayer( PlayerBase player)
	{
		vector fence_pos = GetPosition();
		vector player_pos = player.GetPosition();
		vector ref_dir = GetDirection();
		
		vector fence_player_dir = player.GetDirection();
		fence_player_dir.Normalize();
		fence_player_dir[1] = 0;
		
		ref_dir.Normalize();
		ref_dir[1] = 0;
		
		if ( ref_dir.Length() != 0 )
		{
			float angle = Math.Acos( fence_player_dir * ref_dir );
			
			if ( angle >= 1.3 )
			{
				return true;
			}
		}
		return false;
	}
};