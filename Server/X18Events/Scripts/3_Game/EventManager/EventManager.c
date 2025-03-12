modded class EventManager
{
	override typename GetRandomEvent()
	{
		if (m_PossibleEventTypes.Count() == 0) return typename;

		array<typename> possible_types = {};
		foreach(typename type, float freq : m_PossibleEventTypes)
		{
			for (int i = 0; i < freq * 100; i++)
			{
				if (freq > 0)
					possible_types.Insert(type);
			}
		}

		return possible_types.GetRandomElement();
	}
	override void RegisterEvent(typename event_type, float frequency = 1.0)
	{
		m_PossibleEventTypes[event_type] = frequency;
	}
}