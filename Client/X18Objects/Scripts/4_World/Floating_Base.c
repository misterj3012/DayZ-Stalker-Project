class Floating_Base : BuildingSuper
{
	private ref Timer           levitate;
	private bool                isUp;
	private bool                isYaw;
	private bool                isPitch;
	private bool                isRoll;
	private bool				hasPhysics;
	private vector              tempPos;
	private vector              tempRot;
	private float               startPos;
	private float               startYaw;
	private float               startPitch;
	private float               startRoll;
	private int                 timeSlice;
	Particle					m_ParticleEfx;
	protected float				hoverHeight;
	protected float				hoverMinHeight;
	protected float				hoverSpeed;
	protected float				hoverDistance;
	protected float				hoverRotMin;
	protected float				hoverRotMax;
	void Floating_Base()
	{
#ifdef EDITOR
#else
		if (!GetGame().IsDedicatedServer())
		{
			isUp = true;
			isYaw = true;
			isPitch = true;
			isRoll = true;
			hasPhysics = false;
			timeSlice = 0.001;
			if (!levitate)
				levitate = new Timer(CALL_CATEGORY_SYSTEM);
			int rnd = Math.RandomIntInclusive(5000, 15000);
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(_StartTimer, rnd, false);
		}
#endif
	}
	override bool IsBuilding()
	{
		return false;
	}
	void _StartTimer()
	{
		thread StartTimer();
	}
	void StartTimer()
	{
		tempPos = GetPosition();
		tempRot = Vector(0.0, 0.0, 0.0);
		levitate.Run(0.001, this, "PrepareAnim", new Param1<float>(timeSlice), true);
	}
	void PrepareAnim(float tDelta)
	{
		Hover(tDelta);
		timeSlice += 0.001;
	}
	void Hover(float tDelta)
	{
		PlayerBase m_Player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!m_Player)
			return;
		float distance = vector.Distance(m_Player.GetPosition(), GetPosition());
		if (distance >= hoverDistance)
			return;
		vector mat[4];
		startPos = tempPos[1];
		startYaw = tempRot[0];
		startPitch = tempRot[1];
		startRoll = tempRot[2];
		float yaw = GetYawPitchRoll()[0];
		float pitch = GetYawPitchRoll()[1];
		float roll = GetYawPitchRoll()[2];
		GetTransform(mat);
		vector posVector = mat[3];
		float y = posVector[1];
		vector lowestPos = GetPosition();
		float distanceOrigPos = vector.Distance(tempPos, lowestPos);
		if (isUp && !hasPhysics)
		{
			y += hoverSpeed;
			posVector = Vector(posVector[0], y, posVector[2]);
			if ((posVector[1] - startPos) >= hoverHeight)
				isUp = false;
			hasPhysics = false;
		}
		else if (!isUp && !hasPhysics)
		{
			y -= hoverSpeed;
			posVector = Vector(posVector[0], y, posVector[2]);
			if ((posVector[1] - startPos) <= hoverMinHeight)
				isUp = true;
			hasPhysics = false;
		}
		else
		{
			y += 0.0500;
			posVector = Vector(tempPos[0], y, tempPos[2]);
			isUp = true;
			hasPhysics = true;
		}
		mat[3] = posVector;
		MoveInTime(mat, tDelta);
		if (hasPhysics)
			return;
		float cyaw, cpitch, croll;
		if (isYaw)
		{
			cyaw += Math.RandomFloatInclusive(hoverRotMin, hoverRotMax);
			if ((yaw - startYaw) >= 180.0)
				isYaw = false;
		}
		else
		{
			cyaw -= Math.RandomFloatInclusive(hoverRotMin, hoverRotMax);
			if ((yaw - startYaw) <= -180.0)
				isYaw = true;
		}
		if (isPitch)
		{
			cpitch += Math.RandomFloatInclusive(hoverRotMin, hoverRotMax);
			if ((pitch - startPitch) >= 90.0)
				isPitch = false;
		}
		else
		{
			cpitch -= Math.RandomFloatInclusive(hoverRotMin, hoverRotMax);
			if ((pitch - startPitch) <= -90.0)
				isPitch = true;
		}
		if (isRoll)
		{
			croll += Math.RandomFloatInclusive(hoverRotMin, hoverRotMax);
			if ((roll - startRoll) >= 180.0)
				isRoll = false;
		}
		else
		{
			croll -= Math.RandomFloatInclusive(hoverRotMin, hoverRotMax);
			if ((roll - startRoll) <= -180.0)
				isRoll = true;
		}
		SetYawPitchRoll(Vector(GetYawPitchRoll()[0] + cyaw, GetYawPitchRoll()[1] + cpitch, GetYawPitchRoll()[2] + croll));
	}
	void EnablePhysics(bool enable)
	{
		hasPhysics = enable;
		if (enable)
		{
			CreateDynamicPhysics(PhxInteractionLayers.DYNAMICITEM);
			SetDynamicPhysicsLifeTime(-1);
			dBodySetMass(this, 100);
		}
		else
		{
			SetDynamicPhysicsLifeTime(0.001);
		}
	}
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		if (m_ParticleEfx && GetGame())
		{
			m_ParticleEfx.Stop();
			if (m_ParticleEfx)
				GetGame().ObjectDelete(m_ParticleEfx);
		}
	}
};