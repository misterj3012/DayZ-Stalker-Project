modded class DayZPlayerImplement
{
	array<EntityAI> FindItemInInventory(string itemName)
	{
		ref array<EntityAI> m_ItemsArray = new array<EntityAI>;
		ref array<EntityAI> m_ItemsInInventory = new array<EntityAI>;

		if (GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, m_ItemsInInventory))
		{
			for (int i = 0; i < m_ItemsInInventory.Count(); i++)
			{
				EntityAI m_Item = EntityAI.Cast(m_ItemsInInventory.Get(i));
				if (m_Item.GetType() == itemName)
					m_ItemsArray.Insert(m_Item);
			}
			if (m_ItemsArray.Count() != 0)
				return m_ItemsArray;
			else
				return NULL;
		}
		else
			return NULL;
	}
	array<EntityAI> FindInheritedItemInInventory(typename typeName)
	{
		ref array<EntityAI> m_ItemsArray = new array<EntityAI>;
		ref array<EntityAI> m_ItemsInInventory = new array<EntityAI>;

		if (GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, m_ItemsInInventory))
		{
			for (int i = 0; i < m_ItemsInInventory.Count(); i++)
			{
				EntityAI m_Item = EntityAI.Cast(m_ItemsInInventory.Get(i));
				if (m_Item.IsInherited(typeName))
					m_ItemsArray.Insert(m_Item);
			}
			if (m_ItemsArray.Count() != 0)
				return m_ItemsArray;
			else
				return NULL;
		}
		else
			return NULL;
	}
	bool isAttached(ItemBase item)
	{
		EntityAI parent = item.GetHierarchyParent();

		if (!parent)
			return false;

		if (item.GetInventory().IsAttachment() || item.GetNumberOfItems() > 0)
			return true;

		if (parent.IsWeapon() || parent.IsMagazine() || parent.IsKindOf("Artefact_Container_Base"))
			return true;

		return false;
	}
}