modded class ZombieBase
{
    EntityAI z_birds;
    vector z_pos;
    int z_delay = 30000; // 5000 = 5 secs
    autoptr array<string> birdsArray = {};

    void SpawnBirds()
    {
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
        GetGame().GetObjectsAtPosition3D(z_pos, 30, NearByObjs, null);
        string z_typeName;
        for (int i = 0; i < NearByObjs.Count(); i++)
        {
            z_typeName = NearByObjs[i].GetType();

            Print("[Flying_Birds] -- Object Found =<" + z_typeName + "> In NearByObjs Array");
            if (z_typeName.Contains("flyingbirds")) //Contains(string sample)
            {
                BirdsNearBy.Insert(NearByObjs[i]);
                Print("[Flying_Birds] -- Adding Item =<" + NearByObjs[i] + "> to BirdsNearBy Array");
            }
        }

        //Print("[Flying_Birds] -- Current BirdsNearBy Array before Check-to-Spawn:");					
        //BirdsNearBy.Debug();

        if (BirdsNearBy.Count() < 3)
        {
            string z_rndBirds;
            if (this.IsSoundInsideBuilding())
            {
                Print("[Flying_Birds] -- Victom is inside a building, Not spawning Birds");
            }
            else
            {
                Print("[Flying_Birds] -- Victom is NOT inside a building, spawning Birds");
                if (birdsArray.Count() > 0)
                {
                    z_rndBirds = birdsArray.GetRandomElement();
                    z_birds = EntityAI.Cast(GetGame().CreateObject(z_rndBirds, z_pos, false));
                    birdsArray.RemoveItem(z_rndBirds);
                    Print("[Flying_Birds] -- birdsArray > 0 | RandomBirds =<" + z_rndBirds + ">");
                    //birdsArray.Debug();
                }
                else
                {
                    z_rndBirds = birdsArray.GetRandomElement();
                    z_birds = EntityAI.Cast(GetGame().CreateObject(z_rndBirds, z_pos, false));
                    birdsArray.RemoveItem(z_rndBirds);
                    Print("[Flying_Birds] -- birdsArray = 0 | RandomBirds =<" + z_rndBirds + ">");
                    //birdsArray.Debug();
                }
            }
        }
    }

    override void EEKilled(Object killer)
    {
        super.EEKilled(killer);
        z_pos = this.GetPosition();
        if (!z_birds)
        {
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.SpawnBirds, z_delay, false);
            Print("[Flying_Birds] -- ZombieBase EEKilled SpawnBirds--");
        }
    }
    override void EEDelete(EntityAI parent)
    {
        super.EEDelete(parent);
        if (z_birds)
        {
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, z_delay * 3, false, z_birds);
            Print("[Flying_Birds] -- ZombieBase EEDelete RemoveBirds--");
        }
    }
}