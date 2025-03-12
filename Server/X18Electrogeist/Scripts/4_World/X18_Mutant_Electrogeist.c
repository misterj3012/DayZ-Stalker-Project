modded class X18_Mutant_Electrogeist
{
	protected float 				health = 400;
	protected bool 					IsOnCooldown = false;
	protected float 				search_timer = 10;
	protected bool 					loot_spawned = false;
	protected X18_ElectrogeistDeath_Fx	m_Death;
	protected ref Timer 			m_Timer;
	X18_ElectrogeistHit_Fx 			m_hit;
	ref array<Object> nearest_objects = new array<Object>;
	ref array<CargoBase> proxy_cargos = new array<CargoBase>;
	ref array<Man> players = new array<Man>;
	void X18_Mutant_Electrogeist()
	{
		if (GetGame().IsDedicatedServer())
			m_Timer = new Timer(CALL_CATEGORY_SYSTEM);
	}
	override void EEInit()
	{
		super.EEInit();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetNewHealth, 1000, false);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StartSearch, 2000, false);
	}
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		vector death_position = this.GetPosition();
		GetGame().CreateObject("X18_ElectrogeistDeath_Fx", death_position, false);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Delete, 100, false);
	}
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		if (!m_hit)
			m_hit = X18_ElectrogeistHit_Fx.Cast(GetGame().CreateObject("X18_ElectrogeistHit_Fx", this.GetPosition(), false));
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
	}
	void SetNewHealth()
	{
		this.SetHealth(health);
	}
	void SpawnLoot(int chance, string loot)
	{
		int randomizer = Math.RandomIntInclusive(1, 100);
		if (randomizer <= chance)
			GetGame().CreateObject(loot, this.GetPosition(), false);
	}
	void Delete()
	{
		if (loot_spawned == false)
		{
			SpawnLoot(50, "X18_Artefact_Battery");
			loot_spawned = true;
		}
		GetGame().ObjectDelete(this);
	}
	void StartSearch()
	{
		IsOnCooldown = false;
		m_Timer.Stop();
		m_Timer.Run(search_timer, this, "TargetSearch", NULL, true);
	}
	void TargetSearch()
	{
		nearest_objects.Clear();
		proxy_cargos.Clear();
		players.Clear();
		GetGame().GetObjectsAtPosition3D(this.GetPosition(), 20, nearest_objects, proxy_cargos);
		for (int i = 0; i < nearest_objects.Count(); i++)
		{
			Object nearest_object = nearest_objects.Get(i);
			if (nearest_object.IsInherited(PlayerBase))
			{
				PlayerBase player = PlayerBase.Cast(nearest_object);
				if (player.IsAlive() && (!player.IsAdminActive() && player.GetFaction() != EFactions.Sin))
					players.Insert(player);
			}
		}
		if (players.Count() == 0)
			search_timer = 10;
		else
			search_timer = 4;
		int players_in_radius = players.Count();
		players_in_radius--;
		for (int p = 0; p < players.Count(); p++)
		{
			int random_player_number = Math.RandomIntInclusive(0, players_in_radius);
			PlayerBase random_player = PlayerBase.Cast(players.Get(p));
			if (!IsOnCooldown && random_player.IsAlive())
			{
				vector anomaly_spawn_position = random_player.GetPosition();
				anomaly_spawn_position[1] = anomaly_spawn_position[1] + 1;
				GetGame().CreateObject("X18_Electrogeist", anomaly_spawn_position, false);
				p = players_in_radius + 1;
				SearchCooldown();
			}
		}
	}
	void SearchCooldown()
	{
		m_Timer.Stop();
		m_Timer.Run(1, this, "StartSearch", NULL, false);
		IsOnCooldown = true;
	}
}