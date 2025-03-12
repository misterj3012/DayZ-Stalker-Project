modded class FireplaceBase
{
	typename ATTACHMENT_ZENNOTE = X18_Note;
	void FireplaceBase()
	{
		m_FireConsumableTypes.Insert(ATTACHMENT_ZENNOTE, new FireConsumableType(ATTACHMENT_ZENNOTE, 10, true, "X18_Note"));
	}
};