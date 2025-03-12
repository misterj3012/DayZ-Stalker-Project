class X18_Artefact_Base : ItemBase
{
	private ref Timer           levitate;
	private bool                isUp;
	private bool                isYaw;
	private bool                isPitch;
	private bool                isRoll;
	private vector              tempPos;
	private vector              tempRot;
	private float               startPos;
	private float               startYaw;
	private float               startPitch;
	private float               startRoll;
	private int                 timeSlice;
	Particle 					m_ParticleEfx;
	ArtefactLight 				m_Light;
	protected float				hoverHeight;
	protected float				hoverMinHeight;
	protected float				hoverSpeed;
	protected float				hoverDistance;
	protected float				hoverRotMin;
	protected float				hoverRotMax;

	void X18_Artefact_Base()
	{
#ifdef EDITOR
#else
		if (!GetGame().IsDedicatedServer())
		{
			ActivateEffects();

			isUp = true;
			isYaw = true;
			isPitch = true;
			isRoll = true;
			timeSlice = 0.001;

			hoverSpeed = Math.RandomFloatInclusive(0.0005, 0.00025);;
			hoverMinHeight = 0.25;
			hoverHeight = 0.50;
			hoverDistance = 50;
			hoverRotMin = 0.025;
			hoverRotMax = 0.075;

			if (!levitate)
				levitate = new Timer(CALL_CATEGORY_SYSTEM);
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(_StartTimer, 200, false);
		}
#endif
	}
	void ~X18_Artefact_Base()
	{
		DeactivateEffects();
		if (!GetGame().IsDedicatedServer())
		{
			if (levitate)
				levitate.Stop();
			levitate = NULL;
		}
	}
	override void OnRemovedFromCargo(EntityAI container)
	{
		super.OnRemovedFromCargo(container);
		if (!GetGame().IsDedicatedServer())
			ActivateEffects();
	}
	override void OnMovedInsideCargo(EntityAI container)
	{
		super.OnMovedInsideCargo(container);
		DeactivateEffects();
	}
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		DeactivateEffects();
	}
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);
		if (!GetGame().IsDedicatedServer())
			ActivateEffects();
	}
	void ActivateEffects() {}
	void DeactivateEffects()
	{
		if (!GetGame().IsDedicatedServer())
		{
			if (m_ParticleEfx)
				m_ParticleEfx.Stop();
			if (m_Light)
				m_Light.FadeOut();

			m_ParticleEfx = NULL;
			m_Light = NULL;
		}
	}
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		DeactivateEffects();
		if (!GetGame().IsDedicatedServer())
		{
			if (levitate)
				levitate.Stop();
			levitate = NULL;
		}
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
		hover(tDelta);
		timeSlice += 0.001;
	}
	void hover(float tDelta)
	{
		if (!GetGame().IsDedicatedServer())
		{
			if (PlayerBase.Cast(GetHierarchyRootPlayer()))
			{
				tempPos = GetPosition();
				return;
			}

			PlayerBase m_Player;
			X18_ArtefactStorage m_ArtefactStorage;

			if (!PlayerBase.CastTo(m_Player, GetGame().GetPlayer()) || (!PlayerBase.CastTo(m_ArtefactStorage, GetHierarchyParent()) && !PlayerBase.CastTo(m_Player, GetGame().GetPlayer())))
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
			if (isUp)
			{
				y += hoverSpeed;
				posVector = Vector(posVector[0], y, posVector[2]);
				if ((posVector[1] - startPos) >= hoverHeight)
					isUp = false;
			}
			else if (!isUp)
			{
				y -= hoverSpeed;
				posVector = Vector(posVector[0], y, posVector[2]);
				if ((posVector[1] - startPos) <= hoverMinHeight)
					isUp = true;
			}
			else
			{
				y += 0.0500;
				posVector = Vector(tempPos[0], y, tempPos[2]);
				isUp = true;
			}

			mat[3] = posVector;
			MoveInTime(mat, tDelta);

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
	}
	override bool CanHaveTemperature()
	{
		return true;
	}
};
class X18_Artefact_Spawn_Base : House
{
	int GetTier()
	{
		return 0;
	}
	string GetArtefact()
	{
		return "";
	}
};