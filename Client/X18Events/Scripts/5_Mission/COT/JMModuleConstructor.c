#ifdef JM_COT
modded class JMModuleConstructor
{
	override void RegisterModules(out TTypenameArray modules)
	{
		super.RegisterModules(modules);
		if (IsModLoaded("EventManager"))
			modules.Insert(JMEventManagerModule);
	}
}
#endif