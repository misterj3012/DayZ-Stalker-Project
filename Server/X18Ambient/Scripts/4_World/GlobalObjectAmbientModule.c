class GlobalObjectAmbientModule : AmbientModuleBase
{
	ref Timer m_SyncAmbientMapTimer;
	void GlobalObjectAmbientModule()
	{
	}
	void ~GlobalObjectAmbientModule()
	{
	}
	override void OnInit()
	{
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_SyncAmbientMapTimer = new Timer();
			m_SyncAmbientMapTimer.Run(180, this, "GlobalAmbientObjectMap", NULL, true);
		}
	}
	private void GlobalAmbientObjectMap()
	{
		SpawnBirds(500);
	}

	void SpawnBirds(int amount = 5)
	{
		for (int n = 0; n < amount; n++)
		{
			vector position = GetRandomPosition();
			position[1] = GetGame().SurfaceY(position[0], position[2]);

			EntityAI z_birds;
			autoptr array<string> birdsArray = {};
			int z_delay = 180000;
			if (birdsArray.Count() == 0)
			{
				birdsArray.Insert("flyingbirds");
				birdsArray.Insert("flyingbirds2");
				birdsArray.Insert("flyingbirds3");
				birdsArray.Insert("flyingbirds4");
				birdsArray.Insert("flyingbirds5");
				birdsArray.Insert("flyingbirds6");
			}

			array<Object> NearByObjs = new array<Object>;
			array<Object> BirdsNearBy = new array<Object>;
			GetGame().GetObjectsAtPosition3D(position, 30, NearByObjs, null);
			string z_typeName;
			for (int i = 0; i < NearByObjs.Count(); i++)
			{
				z_typeName = NearByObjs[i].GetType();

				if (z_typeName.Contains("flyingbirds")) {
					BirdsNearBy.Insert(NearByObjs[i]);
				}
			}


			if (BirdsNearBy.Count() < 3)
			{
				string z_rndBirds;
				if (birdsArray.Count() > 0)
				{
					z_rndBirds = birdsArray.GetRandomElement();
					z_birds = EntityAI.Cast(GetGame().CreateObject(z_rndBirds, position, false));
					birdsArray.RemoveItem(z_rndBirds);
				}
				else
				{
					z_rndBirds = birdsArray.GetRandomElement();
					z_birds = EntityAI.Cast(GetGame().CreateObject(z_rndBirds, position, false));
					birdsArray.RemoveItem(z_rndBirds);
				}
			}

			if (z_birds)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, z_delay, false, z_birds);
			}
		}
	}
}