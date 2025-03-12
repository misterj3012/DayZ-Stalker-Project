class FloatingStone_Base : Floating_Base
{
	void FloatingStone_Base()
	{
		if (!GetGame().IsDedicatedServer())
		{
			hoverSpeed = Math.RandomFloatInclusive(0.005, 0.002);;
			hoverMinHeight = 3.5;
			hoverHeight = 5.0;
			hoverDistance = 300;
			hoverRotMin = 0.025;
			hoverRotMax = 0.075;
		}
	}
}

class X18_Floating_Stone1 : FloatingStone_Base {}
class X18_Floating_Stone2 : FloatingStone_Base {}
class X18_Floating_Stone3 : FloatingStone_Base {}
class X18_Floating_Stone4 : FloatingStone_Base {}
class X18_Floating_Stone5 : FloatingStone_Base {}
class X18_Floating_Stone6 : FloatingStone_Base {}
class X18_Floating_Stone7 : FloatingStone_Base {}