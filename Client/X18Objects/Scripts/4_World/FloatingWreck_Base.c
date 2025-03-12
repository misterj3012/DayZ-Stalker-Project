class FloatingWreck_Base : Floating_Base
{
	void FloatingWreck_Base()
	{
		if (!GetGame().IsDedicatedServer())
		{
			hoverSpeed = 0.002;
			hoverMinHeight = 4.5;
			hoverHeight = 6.0;
			hoverDistance = 450;
			hoverRotMin = 0.050;
			hoverRotMax = 0.075;
		}
	}
}

class X18_Floating_Wreck_BMP : FloatingWreck_Base {}
class X18_Floating_Wagon : FloatingWreck_Base {}
class X18_Floating_Cordon_Wagon : FloatingWreck_Base {}
class X18_Floating_Lada_Green : FloatingWreck_Base {}
class X18_Floating_Lada_Red : FloatingWreck_Base {}