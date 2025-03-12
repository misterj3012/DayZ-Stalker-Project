/*modded class VicinityItemManager
{
	override void RefreshVicinityItems()
	{
		array<Object> objects_in_vicinity = new array<Object>;
		array<CargoBase> proxyCargos = new array<CargoBase>;
		array<Object> filtered_objects = new array<Object>;
		array<Object> allFoundObjects = new array<Object>;
		EntityAI entity_ai;
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (m_VicinityItems)
		{
			m_VicinityItems.Clear();
		}
		if (m_VicinityCargos)
			m_VicinityCargos.Clear();
		GetGame().GetObjectsAtPosition3D(player.GetPosition(), VICINITY_ACTOR_DISTANCE, objects_in_vicinity, proxyCargos);
		for (int ic = 0; ic < proxyCargos.Count(); ic++)
			AddVicinityCargos(proxyCargos[ic]);
		for (int i = 0; i < objects_in_vicinity.Count(); i++)
		{
			Object actor_in_radius = objects_in_vicinity.Get(i);
			if (allFoundObjects.Find(actor_in_radius) == INDEX_NOT_FOUND)
			{
				allFoundObjects.Insert(actor_in_radius);
			}
			if (ExcludeFromContainer_Phase1(actor_in_radius))
				continue;
			if (filtered_objects.Find(actor_in_radius) == INDEX_NOT_FOUND)
			{
				filtered_objects.Insert(actor_in_radius);
			}
		}
		if (objects_in_vicinity)
		{
			objects_in_vicinity.Clear();
		}
		GetGame().GetObjectsAtPosition3D(player.GetPosition(), VICINITY_DISTANCE, objects_in_vicinity, proxyCargos);
		for (int j = 0; j < objects_in_vicinity.Count(); j++)
		{
			Object object_in_radius = objects_in_vicinity.Get(j);
			if (allFoundObjects.Find(object_in_radius) == INDEX_NOT_FOUND)
			{
				allFoundObjects.Insert(object_in_radius);
			}
			if (ExcludeFromContainer_Phase2(object_in_radius))
				continue;
			if (filtered_objects.Find(object_in_radius) == INDEX_NOT_FOUND)
			{
				filtered_objects.Insert(object_in_radius);
			}
		}
		if (objects_in_vicinity)
		{
			objects_in_vicinity.Clear();
		}
		vector headingDirection = MiscGameplayFunctions.GetHeadingVector(player);
		DayZPlayerUtils.GetEntitiesInCone(player.GetPosition(), headingDirection, VICINITY_CONE_ANGLE, VICINITY_CONE_REACH_DISTANCE, CONE_HEIGHT_MIN, CONE_HEIGHT_MAX, objects_in_vicinity);
		for (int k = 0; k < objects_in_vicinity.Count(); k++)
		{
			Object object_in_cone = objects_in_vicinity.Get(k);
			if (allFoundObjects.Find(object_in_cone) == INDEX_NOT_FOUND)
			{
				allFoundObjects.Insert(object_in_cone);
			}
			if (ExcludeFromContainer_Phase3(object_in_cone))
				continue;
			if (filtered_objects.Find(object_in_cone) == INDEX_NOT_FOUND)
			{
				filtered_objects.Insert(object_in_cone);
			}
		}
		BoxCollidingParams params = new BoxCollidingParams();
		vector box = { VICINITY_ACTOR_DISTANCE,VICINITY_ACTOR_DISTANCE,VICINITY_ACTOR_DISTANCE };
		params.SetParams(player.GetPosition(), headingDirection.VectorToAngles(), box * 2, ObjIntersect.View, ObjIntersect.Fire, true);
		array<ref BoxCollidingResult> results = new array<ref BoxCollidingResult>;
		if (GetGame().IsBoxCollidingGeometryProxy(params, { player }, results))
		{
			Object obstruction;
			foreach(BoxCollidingResult bResult : results)
			{
				obstruction = null;
				if (bResult.obj && (bResult.obj.CanObstruct() || bResult.obj.CanProxyObstruct()))
				{
					obstruction = bResult.obj;
					if (allFoundObjects.Find(obstruction) == INDEX_NOT_FOUND)
					{
						allFoundObjects.Insert(obstruction);
					}
				}
				if (bResult.parent && (bResult.parent.CanObstruct() || bResult.parent.CanProxyObstruct()))
				{
					obstruction = bResult.parent;
					if (allFoundObjects.Find(obstruction) == INDEX_NOT_FOUND)
					{
						allFoundObjects.Insert(obstruction);
					}
				}
			}
		}
		array<Object> obstructingObjects = new array<Object>;
		MiscGameplayFunctions.FilterObstructingObjects(allFoundObjects, obstructingObjects);
		if (obstructingObjects.Count() > 0)
		{
			if (filtered_objects.Count() > 10 && false)
			{
				vector rayStart;
				MiscGameplayFunctions.GetHeadBonePos(PlayerBase.Cast(GetGame().GetPlayer()), rayStart);
				array<Object> filteredObjects = new array<Object>;
				MiscGameplayFunctions.FilterObstructedObjectsByGrouping(rayStart, VICINITY_CONE_DISTANCE, 0.3, filtered_objects, obstructingObjects, filteredObjects, true, true, VICINITY_CONE_REACH_DISTANCE);
				for (int n = 0; n < filteredObjects.Count(); ++n)
					AddVicinityItems(filteredObjects[n]);
			}
			else
			{
				for (int l = 0; l < filtered_objects.Count(); l++)
				{
					Object filtered_object = filtered_objects.Get(l);
					bool is_obstructed = false;
					Class.CastTo(entity_ai, filtered_object);
					if (vector.DistanceSq(player.GetPosition(), entity_ai.GetPosition()) > VICINITY_CONE_REACH_DISTANCE * VICINITY_CONE_REACH_DISTANCE)
					{
						if (!CanIgnoreDistanceCheck(entity_ai))
						{
							continue;
						}
					}
					is_obstructed = IsObstructed(filtered_object);
					if (!is_obstructed)
					{
						AddVicinityItems(filtered_object);
					}
				}
			}
		}
		else
		{
			for (int m = 0; m < filtered_objects.Count(); m++)
			{
				AddVicinityItems(filtered_objects[m]);
			}
		}
	}
}*/