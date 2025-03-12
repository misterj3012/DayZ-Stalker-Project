class TogglePDAActionInput : DefaultActionInput
{
	ref ActionTarget target_new;

	void TogglePDAActionInput(PlayerBase player)
	{
		SetInput("UATogglePDA");
		m_InputType = ActionInputType.AIT_SINGLE;
	}
};