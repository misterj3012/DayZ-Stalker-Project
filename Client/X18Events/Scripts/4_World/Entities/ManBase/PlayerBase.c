modded class PlayerBase
{
	protected ref array<EffectSound> m_AnomalyVoices = {};
	bool m_IsInside;
	protected float m_InsideCheckTimer;
	override void Init()
	{
		super.Init();
		RegisterNetSyncVariableBool("m_IsInside");
	}
	void ~PlayerBase()
	{
		delete m_AnomalyVoices;
	}
	void ShowInsideIcon(bool show)
	{
		if (m_PluginPlayerStatus)
			m_PluginPlayerStatus.ShowInsideIcon(show);
	}
	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);
		if (!GetGame().IsDedicatedServer())
		{
			bool m_Inside = CheckIfInside();
			ShowInsideIcon(m_Inside);
			m_InsideCheckTimer += deltaTime;
			if (m_InsideCheckTimer >= 5.0)
			{
				GetGame().RPCSingleParam(this, X18EventsRPCs.RPC_SETISINSIDE, new Param1<bool>(m_Inside), true);
				m_InsideCheckTimer = 0;
			}
		}
	}
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if ((GetGame().IsDedicatedServer()) || (GetGame().GetPlayer() == this))
		{
			switch (rpc_type) {
			case X18EventsRPCs.RPC_SETISINSIDE:
			{
				Param1<bool> insideData;
				if (!ctx.Read(insideData))
					break;
				SetIsInside(insideData.param1);
				break;
			}
			}
		}
	}
	void SetIsInside(bool inside)
	{
		m_IsInside = inside;
		SetSynchDirty();
	};
	protected int m_InsideSphereCounter, m_InsideCounter;
	protected bool CheckIfInside()
	{
		if (IsSoundInsideBuilding())
			return true;
		float sphereDispersion = 20, directDispersion = 30;
		Object sphereHitObject, directHitObject;
		float sphereHitFraction, directHitFraction;
		PhxInteractionLayers collisionLayerMask = PhxInteractionLayers.BUILDING;
		vector sphereHitPosition, sphereHitNormal, directHitPosition, directHitNormal;
		vector from = this.GetPosition();
		vector sphereTo = from + Vector(sphereDispersion / 2 - Math.RandomFloat(0, sphereDispersion), 0.2, sphereDispersion / 2 - Math.RandomFloat(0, sphereDispersion));
		vector directTo = from + Vector(directDispersion / 2 - Math.RandomFloat(0, directDispersion), 15, directDispersion / 2 - Math.RandomFloat(0, directDispersion));
		bool m_IsInsideSphereCheck = DayZPhysics.SphereCastBullet(from, sphereTo, 3.5, collisionLayerMask, this, sphereHitObject, sphereHitPosition, sphereHitNormal, sphereHitFraction);
		bool m_IsInsideDirectCheck = DayZPhysics.RayCastBullet(from, directTo, collisionLayerMask, this, directHitObject, directHitPosition, directHitNormal, directHitFraction);
		if (m_IsInsideSphereCheck)
			m_InsideSphereCounter++;
		else
			m_InsideSphereCounter = 0;
		if (m_IsInsideDirectCheck)
			m_InsideCounter++;
		else
			m_InsideCounter = 0;
		if ((m_InsideSphereCounter >= 100 && m_InsideCounter >= 75) || (IsSoundInsideBuilding()))
			return true;
		else
			return false;
	};
	void RegisterAnomalyVoice(EffectSound sound)
	{
		m_AnomalyVoices.Insert(sound);
	}
	array<EffectSound> GetAnomalyVoices()
	{
		return m_AnomalyVoices;
	}
};