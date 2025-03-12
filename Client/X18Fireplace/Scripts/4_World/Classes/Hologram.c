modded class Hologram
{
	override void UpdateHologram(float timeslice)
	{
		super.UpdateHologram(timeslice);
		ItemBase Item = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		if (Item.IsKindOf("X18_Item_Kit") || Item.IsKindOf("X18_Item_Storage"))
		{			
			vector containerPos = GetProjectionEntityPosition( m_Player ) + Item.Get_ItemPlacingPos();
			vector containerOrientation = AlignProjectionOnTerrain( timeslice ) + Item.Get_ItemPlacingOrientation();
			SetProjectionPosition( containerPos );
			SetProjectionOrientation( containerOrientation );		
			m_Projection.OnHologramBeingPlaced( m_Player );
			return;
		}
	}

	override string GetProjectionName(ItemBase item)
	{
		if (item.IsInherited(X18_Item_Kit))
			return item.Get_ItemName();

		return super.GetProjectionName(item);
	}

	override void EvaluateCollision(ItemBase action_item = null)
	{
		if (m_Parent.IsInherited(X18_Item_Kit) || m_Parent.IsInherited(X18_Item_Storage))
		{
			SetIsColliding(false);
			return;
		}
		super.EvaluateCollision();
	}

	override bool IsFloating()
	{
		if (m_Parent.IsInherited(X18_Item_Kit) || m_Parent.IsInherited(X18_Item_Storage))
		{
			return true;
		}

		return super.IsFloating();
	}

	override void SetProjectionPosition(vector position)
	{
		if (m_Parent.IsInherited(X18_Item_Kit) || m_Parent.IsInherited(X18_Item_Storage) && IsFloating())
		{ 
			vector itemPos = SetOnGroundOld( position ) + m_Parent.Get_ItemPlacingPos();
			m_Projection.SetPosition( itemPos );
			return;
		}
		super.SetProjectionPosition(position);
	}

	vector SetOnGroundOld( vector position )
	{
		vector from = position;
		vector ground;
		vector player_to_projection_vector;
		float projection_diameter = GetProjectionDiameter();
			
		ground = Vector(0, - Math.Max( projection_diameter, SMALL_PROJECTION_GROUND ), 0);	
		vector to = from + ground;
		vector contact_pos;
		int contact_component;
		
		DayZPhysics.RaycastRV( from, to, contact_pos, m_ContactDir, contact_component, NULL, NULL, m_Projection, false, false );

		HideWhenClose( contact_pos );

		return contact_pos;
	}
};