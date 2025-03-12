class ControllerConfig
{
	float ShockDamage = 55;
	int DamageRadius = 50;
	bool OnlyTarget = false;
	string MutantClassname = "ZmbM_PatrolNormal_Summer";
	string PsiSuitHelmet = "NBCHoodGray";
	ref TStringArray PsiSuits = { "NBCGlovesGray",  "NBCJacketGray", "NBCPantsGray", "NBCBootsGray" };
}
modded class ZombieBase
{
	private ref ControllerConfig contr_config;
	protected static const string CONF_FILE = ProfilePath + "Controller.json";
	bool ClDwn = false;
	int Cooldown_int = 8;
	override bool ModCommandHandlerAfter(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		private float		damage_player;
		private bool 		isHelmet = false;
		private bool 		is_Monolith = false;
		private int			SUIT_attIdx;
		private int			SUIT_attCount;
		private EntityAI 	SUIT_attachment;
		private ItemBase	SUIT_item;
		private string		SUIT_className;
		private	int			SUIT_ind;
		contr_config = new ControllerConfig();
		string fileName;
		FileAttr fileAttr;
		if (!ClDwn)
		{
			FindFileHandle confFile = FindFile(CONF_FILE, fileName, fileAttr, 0);
			if (!confFile)
				JsonFileLoader<ControllerConfig>.JsonSaveFile(CONF_FILE, contr_config);
			else
				JsonFileLoader<ControllerConfig>.JsonLoadFile(CONF_FILE, contr_config);
			if (GetType() == contr_config.MutantClassname)
			{
				if (contr_config.OnlyTarget)
				{
					DayZInfectedInputController pInputController = GetInputController();
					switch (m_MindState)
					{
					case DayZInfectedConstants.MINDSTATE_DISTURBED:
					{
						m_ActualTarget = pInputController.GetTargetEntity();
						if (m_ActualTarget)
						{
							PlayerBase pb = PlayerBase.Cast(m_ActualTarget);
							if (pb && vector.Distance(pb.GetPosition(), GetPosition()) < contr_config.DamageRadius)
							{
								SUIT_attCount = pb.GetInventory().AttachmentCount();
								for (SUIT_attIdx = 0; SUIT_attIdx < SUIT_attCount; SUIT_attIdx++)
								{
									SUIT_attachment = pb.GetInventory().GetAttachmentFromIndex(SUIT_attIdx);
									if (SUIT_attachment.IsItemBase())
									{
										SUIT_item = ItemBase.Cast(SUIT_attachment);
										SUIT_className = SUIT_item.GetType();
										if (SUIT_className == contr_config.PsiSuitHelmet) isHelmet = true;
										SUIT_ind = contr_config.PsiSuits.Find(SUIT_className);
										if (SUIT_ind >= 0)
										{
											is_Monolith = true;
										}
									}
								}
								if (!is_Monolith)
								{
									damage_player = pb.GetHealth("", "Shock");
									if (!isHelmet)
									{
										GetGame().RPCSingleParam(pb, CONTR_PSI_HIT, NULL, true, pb.GetIdentity());
										pb.SetHealth("", "Shock", damage_player - contr_config.ShockDamage);
										pb.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
									}
									else
									{
										GetGame().RPCSingleParam(pb, CONTR_PSI_HIT_HELMET, NULL, true, pb.GetIdentity());
									}
								}
								ClDwn = true;
								GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.Cooldown, Cooldown_int * 1000, false);
							}
						}
					}
					break;
					case DayZInfectedConstants.MINDSTATE_CHASE:
					{
						m_ActualTarget = pInputController.GetTargetEntity();
						if (m_ActualTarget)
						{
							pb = PlayerBase.Cast(m_ActualTarget);
							if (pb && vector.Distance(pb.GetPosition(), GetPosition()) < contr_config.DamageRadius)
							{
								SUIT_attCount = pb.GetInventory().AttachmentCount();
								for (SUIT_attIdx = 0; SUIT_attIdx < SUIT_attCount; SUIT_attIdx++)
								{
									SUIT_attachment = pb.GetInventory().GetAttachmentFromIndex(SUIT_attIdx);
									if (SUIT_attachment.IsItemBase())
									{
										SUIT_item = ItemBase.Cast(SUIT_attachment);
										SUIT_className = SUIT_item.GetType();
										if (SUIT_className == contr_config.PsiSuitHelmet) isHelmet = true;
										SUIT_ind = contr_config.PsiSuits.Find(SUIT_className);
										if (SUIT_ind >= 0)
										{
											is_Monolith = true;
										}
									}
								}
								if (!is_Monolith)
								{
									damage_player = pb.GetHealth("", "Shock");
									if (!isHelmet)
									{
										GetGame().RPCSingleParam(pb, CONTR_PSI_HIT, NULL, true, pb.GetIdentity());
										pb.SetHealth("", "Shock", damage_player - contr_config.ShockDamage);
										pb.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
									}
									else
									{
										GetGame().RPCSingleParam(pb, CONTR_PSI_HIT_HELMET, NULL, true, pb.GetIdentity());
									}
								}
								ClDwn = true;
								GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.Cooldown, Cooldown_int * 1000, false);
							}
						}
					}
					break;
					}
				}
				else
				{
					private array<Man> players_man = new array<Man>;
					GetGame().GetPlayers(players_man);
					for (private int i = 0; i < players_man.Count(); i++)
					{
						private bool 		isHelmet1 = false;
						private bool 		is_Monolith1 = false;
						pb = PlayerBase.Cast(players_man.Get(i));
						if (pb && vector.Distance(pb.GetPosition(), GetPosition()) < contr_config.DamageRadius)
						{
							SUIT_attCount = pb.GetInventory().AttachmentCount();
							for (SUIT_attIdx = 0; SUIT_attIdx < SUIT_attCount; SUIT_attIdx++)
							{
								SUIT_attachment = pb.GetInventory().GetAttachmentFromIndex(SUIT_attIdx);
								if (SUIT_attachment.IsItemBase())
								{
									SUIT_item = ItemBase.Cast(SUIT_attachment);
									SUIT_className = SUIT_item.GetType();
									if (SUIT_className == contr_config.PsiSuitHelmet) isHelmet1 = true;
									SUIT_ind = contr_config.PsiSuits.Find(SUIT_className);
									if (SUIT_ind >= 0)
									{
										is_Monolith1 = true;
									}
								}
							}
							if (!is_Monolith1)
							{
								damage_player = pb.GetHealth("", "Shock");
								if (!isHelmet1)
								{
									GetGame().RPCSingleParam(pb, CONTR_PSI_HIT, NULL, true, pb.GetIdentity());
									pb.SetHealth("", "Shock", damage_player - contr_config.ShockDamage);
									pb.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
								}
								else
								{
									GetGame().RPCSingleParam(pb, CONTR_PSI_HIT_HELMET, NULL, true, pb.GetIdentity());
								}
							}
							ClDwn = true;
							GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.Cooldown, Cooldown_int * 1000, false);
						}
					}
				}
			}
		}
		return false;
	}
	void Cooldown()
	{
		ClDwn = false;
	}
}