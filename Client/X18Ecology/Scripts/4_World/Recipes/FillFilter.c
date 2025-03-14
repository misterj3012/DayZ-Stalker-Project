class FillFilter : RecipeBase
{
	override void Init()
	{
		m_Name = "RefillFilter(1tablet)";
		m_IsInstaRecipe = false;
		m_AnimationLength = 0.15;
		m_Specialty = 0.02;
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = -1;
		m_MinQuantityIngredient[0] = 0;
		m_MaxQuantityIngredient[0] = 44;
		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = -1;
		m_MinQuantityIngredient[1] = 1;
		m_MaxQuantityIngredient[1] = 60;
		InsertIngredient(0, "X18_Tools_GP5GasMask_Filter");
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = false;
		m_IngredientUseSoftSkills[0] = false;
		InsertIngredient(1, "CharcoalTablets");
		m_IngredientAddHealth[1] = 0;
		m_IngredientSetHealth[1] = -1;
		m_IngredientAddQuantity[1] = -1;
		m_IngredientDestroy[1] = false;
		m_IngredientUseSoftSkills[1] = false;
		m_ResultSetFullQuantity[0] = false;
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = -2;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -2;
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = -1;
	}
	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		return true;
	}
	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		ingredients[0].SetQuantity(ingredients[0].GetQuantity() + 1);
	}
};
