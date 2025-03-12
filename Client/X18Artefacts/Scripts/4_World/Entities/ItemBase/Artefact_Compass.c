class X18_Artefact_Compass_Base : X18_Artefact_Base
{
	protected int m_LocationID = 0;
	protected string m_LocationName = "Cordon";
	void X18_Artefact_Compass_Base()
	{
		RegisterNetSyncVariableInt("m_LocationID");
	}
	override void ActivateEffects()
	{
		m_ParticleEfx = Particle.PlayOnObject(ParticleList.COMPASS, this);
		m_Light = ArtefactLight.Cast(ScriptedLightBase.CreateLight(ArtefactLight, "0 0 0"));
		m_Light.AttachOnObject(this, "0 0.3 0", "0 0 0");
		m_Light.SetColorToWhite();
	}
	override string GetDisplayName()
	{
		return super.GetDisplayName() + ": " + GetLocationNameByIndex(m_LocationID);
	}
	void SetNextLocation()
	{
		m_LocationID++;
		if (m_LocationID >= 13)
			m_LocationID = 0;
		SetSynchDirty();
	}
	string GetLocationNameByIndex(int locationIndex)
	{
		switch (locationIndex)
		{
		case 0:
		{
			m_LocationName = "Great Swamps";
			break;
		}
		case 1:
		{
			m_LocationName = "Predbannik";
			break;
		}
		case 2:
		{
			m_LocationName = "Darkscape";
			break;
		}
		case 3:
		{
			m_LocationName = "Garbage";
			break;
		}
		case 4:
		{
			m_LocationName = "Agroprom";
			break;
		}
		case 5:
		{
			m_LocationName = "Wild Territory";
			break;
		}
		case 6:
		{
			m_LocationName = "Dark Valley";
			break;
		}
		case 7:
		{
			m_LocationName = "Yantar";
			break;
		}
		case 8:
		{
			m_LocationName = "Army Warehouses";
			break;
		}
		case 9:
		{
			m_LocationName = "Junkyard";
			break;
		}
		case 10:
		{
			m_LocationName = "Dead City";
			break;
		}
		case 11:
		{
			m_LocationName = "Red Forest";
			break;
		}
		case 12:
		{
			m_LocationName = "Limansk";
			break;
		}
		/*case 13:
			{
				m_LocationName = "Northern Swamps";
				break;
			}*/
		}

		return m_LocationName;
	}
	int GetLocationIndex()
	{
		return m_LocationID;
	}
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		ctx.Write(GetLocationIndex());
	}
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;
		int m_LocationID;
		if (!ctx.Read(m_LocationID))
			m_LocationID = 0;
		return true;
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionChangeLocation);
		AddAction(ActionCreateSpaceAnomaly);
	};
}
class X18_Artefact_Compass_Spawn : X18_Artefact_Spawn_Base
{
	override int GetTier()
	{
		return 4;
	}
	override string GetArtefact()
	{
		return "X18_Artefact_Compass";
	}
}