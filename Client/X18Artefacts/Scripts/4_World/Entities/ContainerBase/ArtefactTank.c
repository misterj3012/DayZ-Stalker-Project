class X18_ArtefactTank : WorldContainer_Base
{
	void X18_ArtefactTank()
	{
		SetAllowDamage(false);
	}
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		if (item.IsKindOf("X18_Artefact_Base"))
			return super.CanReceiveItemIntoCargo(item);
		return false;
	}
	override bool CanSwapItemInCargo(EntityAI child_entity, EntityAI new_entity)
	{
		if (child_entity.IsKindOf("X18_Artefact_Base") && new_entity.IsKindOf("X18_Artefact_Base"))
			return super.CanSwapItemInCargo(child_entity, new_entity);
		return false;
	}
}