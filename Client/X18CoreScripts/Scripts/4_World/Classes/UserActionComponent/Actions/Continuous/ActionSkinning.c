modded class ActionSkinningCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(GetDefaultTime());
	}
	float GetDefaultTime()
	{
		string item_type = m_ActionData.m_MainItem.GetType();
		switch (item_type)
		{
		case "air_weapon_knife_old":
		case "air_weapon_knife_improve":
			return 30;
			break;
		case "air_weapon_knife_skin":
		case "HuntingKnife":
		case "CombatKnife":
		case "KukriKnife":
			return 25;
			break;
		case "Machete":
		case "air_weapon_knife_geralt":
			return 22.5;
			break;
		case "air_weapon_knife_shark":
		case "air_weapon_knife_tomohawk":
		case "air_weapon_knife_ots":
			return 20;
			break;
		case "air_weapon_knife_m9":
		case "air_weapon_knife_boot":
			return 17.5;
			break;
		case "air_weapon_knife_tactical":
		case "air_weapon_knife_acb90":
		case "air_weapon_knife_hunting":
			return 15;
			break;
		default:
			return 30;
			break;
		}
		Print("ActionSkinningCB | Item detection error, assigning negative time");
		return -1;
	}
};
modded class ActionSkinning
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		Object targetObject = action_data.m_Target.GetObject();
		string item_to_spawn;
		string cfg_skinning_organ_class;
		EntityAI body;
		Class.CastTo(body, targetObject);
		vector body_pos = body.GetPosition();
		body.SetAsSkinned();
		if (body.IsInherited(PlayerBase))
		{
			PlayerBase body_PB = PlayerBase.Cast(body);
			if (body_PB.IsRestrained() && body_PB.GetHumanInventory().GetEntityInHands())
			{
				MiscGameplayFunctions.TransformRestrainItem(body_PB.GetHumanInventory().GetEntityInHands(), null, action_data.m_Player, body_PB);
			}
			if (body_PB.IsWearingSplint())
			{
				EntityAI entity = action_data.m_Player.SpawnEntityOnGroundOnCursorDir("Splint", 0.5);
				EntityAI attachment;
				ItemBase new_item = ItemBase.Cast(entity);
				Class.CastTo(attachment, body_PB.GetItemOnSlot("Splint_Right"));
				if (attachment && attachment.GetType() == "Splint_Applied")
				{
					if (new_item)
					{
						MiscGameplayFunctions.TransferItemProperties(attachment, new_item);
						if (GetGame().IsServer())
						{
							if (new_item.GetHealthLevel() < 4)
							{
								int newDmgLevel = new_item.GetHealthLevel() + 1;
								float max = new_item.GetMaxHealth("", "");
								switch (newDmgLevel)
								{
								case GameConstants.STATE_BADLY_DAMAGED:
									new_item.SetHealth("", "", max * GameConstants.DAMAGE_BADLY_DAMAGED_VALUE);
									break;
								case GameConstants.STATE_DAMAGED:
									new_item.SetHealth("", "", max * GameConstants.DAMAGE_DAMAGED_VALUE);
									break;
								case GameConstants.STATE_WORN:
									new_item.SetHealth("", "", max * GameConstants.DAMAGE_WORN_VALUE);
									break;
								case GameConstants.STATE_RUINED:
									new_item.SetHealth("", "", max * GameConstants.DAMAGE_RUINED_VALUE);
									break;
								default:
									break;
								}
							}
						}
					}
					attachment.Delete();
				}
			}
			int deadBodyLifetime;
			if (GetCEApi())
			{
				deadBodyLifetime = GetCEApi().GetCEGlobalInt("CleanupLifetimeDeadPlayer");
				if (deadBodyLifetime <= 0)
				{
					deadBodyLifetime = 3600;
				}
			}
			array<EntityAI> children = new array<EntityAI>;
			body_PB.GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, children);
			int count = children.Count();
			for (int i = 0; i < count; ++i)
			{
				EntityAI child = children.Get(i);
				if (child)
				{
					body_PB.GetInventory().DropEntity(InventoryMode.SERVER, body_PB, child);
					child.SetLifetime(deadBodyLifetime);
				}
			}
			int draw = Math.RandomIntInclusive(1, 2);
			if (draw == 2)
			{
				ItemBase skull_item;
				vector skull_pos_rnd = body_pos + Vector(Math.RandomFloat01() - 0.5, 0, Math.RandomFloat01() - 0.5);
				Class.CastTo(skull_item, GetGame().CreateObjectEx("HumanSkull", skull_pos_rnd, ECE_PLACE_ON_SURFACE));
				skull_item.PlaceOnSurface();
			}
		}
		GetGame().ObjectDelete(body);
		string cfg_animal_class_path = "cfgVehicles " + body.GetType() + " " + "Skinning ";
		int child_count = g_Game.ConfigGetChildrenCount(cfg_animal_class_path);
		int infChance = Math.RandomIntInclusive(1, 10);
		int smallAnimalMeatAmount = Math.RandomIntInclusive(1, 10);
		if (smallAnimalMeatAmount < 7)
			smallAnimalMeatAmount = 2;
		else
			smallAnimalMeatAmount = 1;
		int normalAnimalMeatAmount = Math.RandomIntInclusive(2, 3);
		int bearMeatAmount = Math.RandomIntInclusive(3, 5);
		int humanMeatAmount = Math.RandomIntInclusive(2, 4);
		float smallAnimalBonesAmount = Math.RandomFloatInclusive(0.1, 0.2);
		float normalAnimalBonesAmount = Math.RandomFloatInclusive(0.2, 0.3);
		float bearBonesAmount = Math.RandomFloatInclusive(0.3, 0.4);
		float humanBonesAmount = Math.RandomFloatInclusive(0.2, 0.4);
		for (int i1 = 0; i1 < child_count; i1++)
		{
			g_Game.ConfigGetChildName(cfg_animal_class_path, i1, cfg_skinning_organ_class);
			cfg_skinning_organ_class = cfg_animal_class_path + cfg_skinning_organ_class + " ";
			g_Game.ConfigGetText(cfg_skinning_organ_class + "item", item_to_spawn);
			if (item_to_spawn != "")
			{
				int item_count;
				switch (item_to_spawn)
				{
				case "ChickenFeather":
				{
					if (Math.RandomIntInclusive(1, 100) < 15)
						item_count = 1;
					else
						item_count = 0;
					break;
				}
				case "RabbitLegMeat":
				{
					item_count = smallAnimalMeatAmount;
					break;
				}
				case "ChickenBreastMeat":
				{
					item_count = smallAnimalMeatAmount;
					break;
				}
				case "HumanSteakMeat":
				{
					item_count = humanMeatAmount;
					break;
				}
				case "GoatSteakMeat":
				{
					item_count = normalAnimalMeatAmount;
					break;
				}
				case "BoarSteakMeat":
				{
					item_count = normalAnimalMeatAmount;
					break;
				}
				case "PigSteakMeat":
				{
					item_count = normalAnimalMeatAmount;
					break;
				}
				case "DeerSteakMeat":
				{
					item_count = normalAnimalMeatAmount;
					break;
				}
				case "WolfSteakMeat":
				{
					item_count = normalAnimalMeatAmount;
					break;
				}
				case "BearSteakMeat":
				{
					item_count = bearMeatAmount;
					break;
				}
				case "CowSteakMeat":
				{
					item_count = bearMeatAmount;
					break;
				}
				case "SheepSteakMeat":
				{
					item_count = normalAnimalMeatAmount;
					break;
				}
				case "InfectedWolfSteakMeat":
				{
					if (infChance <= 3)
						item_to_spawn = "WolfSteakMeat";
					item_count = normalAnimalMeatAmount;
					break;
				}
				case "Lard":
				{
					if (body.GetType() == "Animal_UrsusArctos" || body.GetType() == "Animal_UrsusArctosMiddendorffi")
						item_count = Math.RandomIntInclusive(1, 2);
					else
						item_count = 1;
					break;
				}
				case "InfectedLard":
				{
					if (infChance <= 3)
						item_to_spawn = "Lard";
					item_count = 1;
					break;
				}
				case "SmallGuts":
				{
					item_count = 0;
					break;
				}
				default:
				{
					item_count = 1;
					break;
				}
				}
				for (int i2 = 0; i2 < item_count; i2++)
				{
					ItemBase spawn_result = CreateOrgan(action_data.m_Player, body_pos, item_to_spawn, cfg_skinning_organ_class, action_data.m_MainItem);
					float item_quantity = 0;
					switch (item_to_spawn)
					{
					case "ChickenFeather":
					{
						item_quantity = Math.RandomFloatInclusive(0.05, 0.15);
						break;
					}
					case "SmallGuts":
					{
						item_quantity = 0;
						break;
					}
					case "RabbitLegMeat":
					{
						item_quantity = Math.RandomFloatInclusive(0.4, 0.8);
						break;
					}
					case "Bone":
					{
						item_quantity = normalAnimalBonesAmount;
						if (body.IsInherited(Animal_GallusGallusDomesticus) || body.IsInherited(Animal_GallusGallusDomesticusF))
							item_quantity = smallAnimalBonesAmount;
						if (body.GetType() == "Animal_LepusEuropaeus")
							item_quantity = smallAnimalBonesAmount;
						if (body.GetType() == "Animal_UrsusArctos" || body.GetType() == "Animal_UrsusArctosMiddendorffi")
							item_quantity = bearBonesAmount;
						if (body.IsInherited(PlayerBase))
							item_quantity = humanBonesAmount;
						break;
					}
					default:
					{
						item_quantity = Math.RandomFloatInclusive(0.4, 0.8);
						break;
					}
					}
					spawn_result.SetQuantityNormalized(item_quantity, false);
					if ((item_to_spawn == "Lard") || (item_to_spawn == "Guts"))
					{
						if (body.IsKindOf("SurvivorBase"))
						{
							spawn_result.InsertAgent(eAgents.BRAIN, 1);
						}
					}
				}
			}
		}
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, UADamageApplied.SKINNING);
		PluginLifespan module_lifespan = PluginLifespan.Cast(GetPlugin(PluginLifespan));
		module_lifespan.UpdateBloodyHandsVisibility(action_data.m_Player, true);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
	}
	ItemBase CreateOrgan(PlayerBase player, vector body_pos, string item_to_spawn, string cfg_skinning_organ_class, ItemBase tool)
	{
		ItemBase added_item;
		vector pos_rnd = body_pos + Vector(Math.RandomFloat01() - 0.5, 0, Math.RandomFloat01() - 0.5);
		Class.CastTo(added_item, GetGame().CreateObjectEx(item_to_spawn, pos_rnd, ECE_PLACE_ON_SURFACE));
		if (!added_item)
			return NULL;
		added_item.PlaceOnSurface();
		float item_quantity = 0;
		array<float> quant_min_max = new array<float>;
		array<float> quant_min_max_coef = new array<float>;
		GetGame().ConfigGetFloatArray(cfg_skinning_organ_class + "quantityMinMax", quant_min_max);
		GetGame().ConfigGetFloatArray(cfg_skinning_organ_class + "quantityMinMaxCoef", quant_min_max_coef);
		if (quant_min_max.Count() > 0)
		{
			float soft_skill_manipulated_value = (quant_min_max.Get(0) + quant_min_max.Get(1)) / 2;
			float min_quantity = player.GetSoftSkillsManager().AddSpecialtyBonus(soft_skill_manipulated_value, this.GetSpecialtyWeight());
			item_quantity = Math.RandomFloat(min_quantity, quant_min_max.Get(1));
		}
		if (quant_min_max_coef.Count() > 0)
		{
			float coef = Math.RandomFloat(quant_min_max_coef.Get(0), quant_min_max_coef.Get(1));
			item_quantity = added_item.GetQuantityMax() * coef;
		}
		if (GetGame().ConfigGetFloat(cfg_skinning_organ_class + "quantity") > 0)
			item_quantity = g_Game.ConfigGetFloat(cfg_skinning_organ_class + "quantity");
		if (GetGame().ConfigGetFloat(cfg_skinning_organ_class + "quantityCoef") > 0)
		{
			float coef2 = g_Game.ConfigGetFloat(cfg_skinning_organ_class + "quantityCoef");
			item_quantity = added_item.GetQuantityMax() * coef2;
		}
		if (item_quantity > 0)
		{
			item_quantity = Math.Round(item_quantity);
			added_item.SetQuantity(item_quantity, false);
		}
		float item_apply_tool_damage_coef = GetGame().ConfigGetFloat(cfg_skinning_organ_class + "transferToolDamageCoef");
		if (item_apply_tool_damage_coef > 0)
		{
			float tool_dmg_coef = 1 - tool.GetHealth01();
			float organ_dmg_coef = tool_dmg_coef * item_apply_tool_damage_coef;
			added_item.DecreaseHealthCoef(organ_dmg_coef);
		}
		added_item.InsertAgent(eAgents.SALMONELLA, 1);
		return added_item;
	}
	override void OnFinishProgressClient(ActionData action_data)
	{
		super.OnFinishProgressClient(action_data);
		if (action_data.m_Target)
		{
			Object target_obj = action_data.m_Target.GetObject();
			if (target_obj.IsKindOf("Animal_CapreolusCapreolus") || target_obj.IsKindOf("Animal_CapreolusCapreolusF") || target_obj.IsKindOf("Animal_CervusElaphus") || target_obj.IsKindOf("Animal_CervusElaphusF"))
				GetGame().GetAnalyticsClient().OnActionFinishedGutDeer();
		}
	}
};