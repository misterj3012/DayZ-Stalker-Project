modded class VicinityItemManager
{
	override bool ExcludeFromContainer_Phase1(Object actor_in_radius)
	{
		if (super.ExcludeFromContainer_Phase1(actor_in_radius))
			return true;
		PersonalChest chest;
		if (Class.CastTo(chest, actor_in_radius))
		{
			if (!chest.IsMyPersonalChest())
				return true;
		}
		return false;
	}
	override bool ExcludeFromContainer_Phase2(Object object_in_radius)
	{
		if (super.ExcludeFromContainer_Phase2(object_in_radius))
			return true;
		PersonalChest chest;
		if (Class.CastTo(chest, object_in_radius))
		{
			if (!chest.IsMyPersonalChest())
				return true;
		}
		return false;
	}
	override bool ExcludeFromContainer_Phase3(Object object_in_cone)
	{
		if (super.ExcludeFromContainer_Phase3(object_in_cone))
			return true;
		PersonalChest chest;
		if (Class.CastTo(chest, object_in_cone))
		{
			if (!chest.IsMyPersonalChest())
				return true;
		}
		return false;
	}
}