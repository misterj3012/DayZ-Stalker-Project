class UndergroundLightManager
{
	const float MIN_ACCON_VALUE = 0.001;
	const float MAX_CHANGE_RATE = 0.02;
	const int LIGHTING_UPDATE_TIMER = 100;
	float undergroundDarknessFactor = 1.0;
	float targetUndergroundDarknessFactor = 1.0;
	bool init = false;
	ref array<ref UndergroundLightingPane> underground = new array<ref UndergroundLightingPane>();
	void UndergroundLightManager()
	{
		FillPanes();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CalcUndergroundLighting, LIGHTING_UPDATE_TIMER, true);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(UpdateSetUndergroundLighting, LIGHTING_UPDATE_TIMER / 10, true);
	}
	void ~UndergroundLightManager()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(CalcUndergroundLighting);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(UpdateSetUndergroundLighting);
	}
	void FillPanes()
	{
		string worldName = "";
		if (GetGame() && GetGame().GetWorld())
			GetGame().GetWorldName(worldName);
		worldName.ToLower();
		InitPanes(worldName);
		//Print("Init " + underground.Count() + " Panes for World: " + worldName);
	}
	void InitPanes(string worldname)
	{
		//Print("World: " + worldname);
		UndergroundLightingPane pane;
		if (worldname == "exclusionzone")
		{
			// Sidorovich
			pane = new UndergroundLightingPane();
			pane.transitionArea = 2.0;
			pane.AddTriangle("4530.576660 76.261665 1820.120605", "4529.706543 76.261665 1820.257080", "4530.734375 76.261665 1811.719360", false, false);
			pane.AddTriangle("4553.130859 76.261665 1816.762207", "4530.576660 76.261665 1820.120605", "4530.734375 76.261665 1811.719360", false, false);
			pane.AddTriangle("4553.130859 76.261665 1816.762207", "4530.734375 76.261665 1811.719360", "4554.718750 76.261665 1810.756714", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			//Cordon Bunker
			pane = new UndergroundLightingPane();
			pane.transitionArea = 0.5;
			pane.AddTriangle("4624.878418 75.956192 1834.978638", "4624.881348 76.107056 1825.112549", "4613.464844 75.913979 1820.527832", false, false);
			pane.AddTriangle("4613.464844 75.913979 1820.527832", "4613.791504 75.690849 1839.961426", "4620.035645 75.664696 1839.842407", false, false);
			pane.AddTriangle("4620.035645 75.664696 1839.842407", "4624.878418 75.956192 1834.978638", "4613.464844 75.913979 1820.527832", false, false);
			pane.Calc();
			underground.Insert(pane);

			//Cordon Bunker
			pane = new UndergroundLightingPane();
			pane.transitionArea = 0.5;
			pane.AddTriangle("4613.550781 76.014061 1820.290649", "4607.554688 76.115501 1822.595459", "4605.207520 75.914268 1839.864746", false, false);
			pane.AddTriangle("4605.207520 75.914268 1839.864746", "4613.829590 75.611511 1839.923950", "4613.550781 76.014061 1820.290649", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			//Tunnel Cordon
			pane = new UndergroundLightingPane();
			pane.transitionArea = 1.0;
			pane.AddTriangle("4780.667969 94.267052 2239.221191", "4798.631348 97.455444 2211.744873", "4769.848145 97.497208 2155.640625", false, false);
			pane.AddTriangle("4769.848145 97.497208 2155.640625", "4730.518555 97.289680 2156.230225", "4733.277832 97.081726 2187.076904", false, false);
			pane.AddTriangle("4733.277832 97.081726 2187.076904", "4780.667969 94.267052 2239.221191", "4769.848145 97.497208 2155.640625", false, false);
			pane.Calc();
			underground.Insert(pane);

			//PredBannik Bunker
			pane = new UndergroundLightingPane();
			pane.transitionArea = 0.5;
			pane.AddTriangle("6645.322266 66.936493 815.516541", "6660.355469 67.219505 821.942444", "6660.768066 67.350647 827.559814", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			//PredBannik Bunker
			pane = new UndergroundLightingPane();
			pane.transitionArea = 0.5;
			pane.AddTriangle("6565.854980 81.483505 935.047974", "6573.470703 81.577065 937.537231", "6572.927246 81.604591 946.809509", false, false);
			pane.AddTriangle("6572.927246 81.604591 946.809509", "6565.684082 81.486717 949.704346", "6565.854980 81.483505 935.047974", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			//RailRoad Swamps -> Darkscape
			pane = new UndergroundLightingPane();
			pane.transitionArea = 3.0;
			pane.AddTriangle("6744.117676 126.557274 2718.511230", "6748.623047 128.599022 2685.686768", "5376.432617 128.374573 2328.501953", false, false);
			pane.AddTriangle("5357.306152 128.375427 2373.676758", "5482.416504 128.728348 2377.344727", "5516.653809 128.043228 2447.852783", false, false);
			pane.AddTriangle("5772.102051 128.983658 2499.669922", "5770.144043 128.283463 2619.650146", "5788.930176 128.601913 2665.039551", false, false);
			pane.AddTriangle("6044.257324 128.975769 2590.027588", "6123.486816 128.632187 2649.358643", "6289.119141 128.581223 2640.652100", false, false);
			pane.AddTriangle("6289.119141 128.581223 2640.652100", "6267.703125 128.794250 2639.509033", "6299.334473 128.531250 2682.510986", false, false);
			pane.AddTriangle("6299.334473 128.531250 2682.510986", "6425.902344 128.965637 2701.344971", "6455.065430 128.314110 2665.156006", false, false);
			pane.AddTriangle("6744.117676 128.557274 2718.511230", "5376.432617 128.374573 2328.501953", "5357.306152 128.375427 2373.676758", false, false);
			pane.AddTriangle("5772.102051 128.983658 2499.669922", "5788.930176 128.601913 2665.039551", "5844.508789 128.923042 2684.962402", false, false);
			pane.AddTriangle("5961.139160 128.492065 2604.158203", "6044.257324 128.975769 2590.027588", "6289.119141 128.581223 2640.652100", false, false);
			pane.AddTriangle("6289.119141 128.581223 2640.652100", "6299.334473 128.531250 2682.510986", "6455.065430 128.314110 2665.156006", false, false);
			pane.AddTriangle("5772.102051 128.983658 2499.669922", "5844.508789 128.923042 2684.962402", "5943.791504 128.184402 2559.771240", false, false);
			pane.AddTriangle("5961.139160 128.492065 2604.158203", "6289.119141 128.581223 2640.652100", "6455.065430 128.314110 2665.156006", false, false);
			pane.AddTriangle("5516.653809 128.043228 2447.852783", "5772.102051 128.983658 2499.669922", "5943.791504 128.184402 2559.771240", false, false);
			pane.AddTriangle("5516.653809 128.043228 2447.852783", "5943.791504 128.184402 2559.771240", "5961.139160 128.492065 2604.158203", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			pane = new UndergroundLightingPane();
			pane.transitionArea = 3.0;
			pane.AddTriangle("7277.819824 129.620903 2628.981445", "7287.603027 129.701279 2672.674561", "7096.213867 129.111221 2703.905273", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			pane = new UndergroundLightingPane();
			pane.transitionArea = 3.0;
			pane.AddTriangle("8473.806641 127.225388 2426.283691", "8469.617188 127.489159 2378.025635", "8976.917969 127.004906 2381.925293", false, false);
			pane.AddTriangle("8976.917969 127.004906 2381.925293", "8972.005859 127.525658 2340.634766", "8473.806641 127.225388 2426.283691", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			pane = new UndergroundLightingPane();
			pane.transitionArea = 3.0;
			pane.AddTriangle("9300.336914 130.292450 2374.369629", "9299.260742 130.826767 2346.931152", "9370.620117 130.492355 2372.920654", false, false);
			pane.AddTriangle("9370.620117 130.492355 2372.920654", "9372.274414 130.546951 2346.471436", "9300.336914 130.292450 2374.369629", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			pane = new UndergroundLightingPane();
			pane.transitionArea = 3.0;
			pane.AddTriangle("1243.671997 101.608475 2398.591064", "1269.585449 100.007950 2424.206299", "1267.352661 100.666183 2395.575195", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			//Dark Valley Lab
			pane = new UndergroundLightingPane();
			pane.transitionArea = 1.0;
			pane.AddTriangle("8140.125000 115.417381 4414.790527", "8162.100098 115.510193 4407.819336", "8174.023926 115.699104 4310.853516", false, false);
			pane.AddTriangle("8174.023926 115.699104 4310.853516", "8149.939941 115.926956 4305.039063", "8100.062988 115.366806 4319.987793", false, false);
			pane.AddTriangle("8100.062988 115.366806 4319.987793", "8085.025879 115.968735 4349.933105", "8037.173340 113.311157 4353.124023", false, false);
			pane.AddTriangle("8105.111816 115.323036 4394.804688", "8105.200684 115.264343 4409.649414", "8125.140137 115.919930 4414.830078", false, false);
			pane.AddTriangle("8140.125000 115.417381 4414.790527", "8174.023926 115.699104 4310.853516", "8100.062988 115.366806 4319.987793", false, false);
			pane.AddTriangle("8035.223145 115.042747 4394.637695", "8105.111816 115.323036 4394.804688", "8125.140137 115.919930 4414.830078", false, false);
			pane.AddTriangle("8125.140137 115.919930 4414.830078", "8140.125000 115.417381 4414.790527", "8100.062988 115.366806 4319.987793", false, false);
			pane.AddTriangle("8035.223145 115.042747 4394.637695", "8125.140137 115.919930 4414.830078", "8100.062988 115.366806 4319.987793", false, false);
			pane.Calc();
			underground.Insert(pane);

			// Duty Base
			pane = new UndergroundLightingPane();
			pane.transitionArea = 1.0;
			pane.AddTriangle("4935.818359 125.757828 6784.003418", "4940.030762 125.757828 6764.981445", "4974.701660 126.757828 6765.416016", false, false);
			pane.AddTriangle("4974.220703 126.757828 6789.959473", "4945.066406 126.757828 6794.927734", "4935.818359 125.757828 6784.003418", false, false);
			pane.AddTriangle("4935.818359 125.757828 6784.003418", "4974.701660 126.757828 6765.416016", "4974.220703 126.757828 6789.959473", false, false);
			pane.Calc();
			underground.Insert(pane);

			//Bar
			pane = new UndergroundLightingPane();
			pane.transitionArea = 1.0;
			pane.AddTriangle("4875.133789 126.737167 6687.881836", "4884.819824 126.737167 6675.250488", "4879.048340 126.737167 6665.889160", false, false);
			pane.AddTriangle("4879.048340 126.737167 6665.889160", "4869.584961 126.737167 6655.530762", "4840.224609 126.737167 6660.002441", false, false);
			pane.AddTriangle("4840.184570 126.737167 6679.870117", "4850.458984 126.737167 6694.535645", "4860.075684 126.737167 6694.809082", false, false);
			pane.AddTriangle("4860.075684 126.737167 6694.809082", "4860.664551 126.737167 6699.484863", "4865.026855 126.737167 6699.519531", false, false);
			pane.AddTriangle("4869.517578 126.737167 6694.983887", "4875.133789 126.737167 6687.881836", "4879.048340 126.737167 6665.889160", false, false);
			pane.AddTriangle("4860.075684 126.737167 6694.809082", "4865.026855 126.737167 6699.519531", "4869.517578 126.737167 6694.983887", false, false);
			pane.AddTriangle("4869.517578 126.737167 6694.983887", "4879.048340 126.737167 6665.889160", "4840.224609 126.737167 6660.002441", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			//Agroprom Lab
			/*pane = new UndergroundLightingPane();
			pane.transitionArea = 1.0;
			pane.AddTriangle("2169.968262 54.675446 4350.655273", "2122.303467 54.593163 4335.113281", "2060.522461 54.252670 4344.939941", false, false);
			pane.AddTriangle("2060.522461 54.252670 4344.939941", "2032.182983 54.085886 4395.192383", "2032.776855 54.452543 4427.853027", false, false);
			pane.AddTriangle("2059.296387 54.425688 4443.266113", "2129.347900 54.965399 4419.149902", "2180.343750 54.208584 4469.045898", false, false);
			pane.AddTriangle("2180.343750 54.208584 4469.045898", "2191.038330 54.944469 4495.988770", "2204.917480 54.469090 4498.801270", false, false);
			pane.AddTriangle("2243.402832 54.125057 4406.772461", "2214.081299 54.982327 4391.188477", "2179.995850 54.712528 4355.946777", false, false);
			pane.AddTriangle("2180.343750 54.208584 4469.045898", "2204.917480 54.469090 4498.801270", "2274.939209 54.007172 4478.243652", false, false);
			pane.AddTriangle("2282.858154 54.136600 4449.029297", "2243.402832 54.125057 4406.772461", "2179.995850 54.712528 4355.946777", false, false);
			pane.AddTriangle("2282.858154 54.136600 4449.029297", "2179.995850 54.712528 4355.946777", "2169.968262 54.675446 4350.655273", false, false);
			pane.AddTriangle("2282.858154 54.136600 4449.029297", "2169.968262 54.675446 4350.655273", "2060.522461 54.252670 4344.939941", false, false);
			pane.AddTriangle("2060.522461 54.252670 4344.939941", "2032.776855 54.452543 4427.853027", "2059.296387 54.425688 4443.266113", false, false);
			pane.AddTriangle("2180.343750 54.208584 4469.045898", "2274.939209 54.007172 4478.243652", "2060.522461 54.252670 4344.939941", false, false);
			pane.AddTriangle("2180.343750 54.208584 4469.045898", "2060.522461 54.252670 4344.939941", "2059.296387 54.425688 4443.266113", false, false);
			pane.Calc();
			underground.Insert(pane);*/

			//Yantar Lab
			pane = new UndergroundLightingPane();
			pane.transitionArea = 1.0;
			pane.AddTriangle("2320.883789 51.460163 6554.317871", "2491.609131 51.093456 6522.008789", "2493.754395 53.498928 6506.384277", false, false);
			pane.AddTriangle("2493.754395 51.498928 6506.384277", "2394.024658 51.764072 6420.706543", "2327.343018 51.845261 6379.063477", false, false);
			pane.AddTriangle("2327.343018 51.845261 6379.063477", "2256.806152 51.715614 6454.088379", "2202.263672 51.108582 6489.193359", false, false);
			pane.AddTriangle("2202.263672 51.108582 6489.193359", "2191.243652 51.879581 6523.438477", "2275.709961 51.438244 6543.957520", false, false);
			pane.AddTriangle("2327.343018 51.845261 6379.063477", "2202.263672 51.108582 6489.193359", "2275.709961 51.438244 6543.957520", false, false);
			pane.AddTriangle("2493.754395 51.498928 6506.384277", "2327.343018 51.845261 6379.063477", "2275.709961 51.438244 6543.957520", false, false);
			pane.Calc();
			underground.Insert(pane);

			//Dead City Basement
			pane = new UndergroundLightingPane();
			pane.transitionArea = 1.0;
			pane.AddTriangle("2899.411377 121.578781 8150.559082", "2876.879639 121.449562 8153.797363", "2876.011230 121.077576 8183.847656", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			//Tunnel Limansk
			pane = new UndergroundLightingPane();
			pane.transitionArea = 1.0;
			pane.AddTriangle("3111.983887 106.524689 10166.588867", "3091.550537 106.131126 10165.490234", "3107.026367 106.866997 10211.317383", false, false);
			pane.AddTriangle("3107.026367 106.866997 10211.317383", "3147.373291 106.419273 10240.260742", "3131.485840 106.465340 10198.187500", false, false);
			pane.AddTriangle("3131.485840 106.465340 10198.187500", "3111.983887 106.524689 10166.588867", "3107.026367 106.866997 10211.317383", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);

			//Red Forest Mines
			/*pane = new UndergroundLightingPane();
			pane.transitionArea = 1.0;
			pane.AddTriangle("3204.268311 108.506264 10575.931641", "3213.415039 108.125633 10577.157227", "3209.836914 108.651352 10659.737305", false, false);
			pane.AddTriangle("3160.246338 108.528694 10666.886719", "3110.471924 108.090309 10669.451172", "3102.669922 108.877907 10654.958008", false, false);
			pane.AddTriangle("3124.844482 108.258713 10574.568359", "3204.268311 108.506264 10575.931641", "3209.836914 108.651352 10659.737305", false, false);
			pane.AddTriangle("3160.246338 108.528694 10666.886719", "3102.669922 108.877907 10654.958008", "3124.844482 108.258713 10574.568359", false, false);
			pane.AddTriangle("3124.844482 108.258713 10574.568359", "3209.836914 108.651352 10659.737305", "3160.246338 108.528694 10666.886719", false, false);
			pane.Calc();
			underground.Insert(pane);

			pane = new UndergroundLightingPane();
			pane.transitionArea = 1.0;
			pane.AddTriangle("3926.563477 104.314133 10173.152344", "3912.527100 104.916283 10169.983398", "3916.067627 104.628944 10124.813477", false, false);
			pane.AddTriangle("3916.067627 104.628944 10124.813477", "3962.695801 104.574074 10128.588867", "3962.681641 104.757011 10145.504883", false, false);
			pane.AddTriangle("3962.681641 104.757011 10145.504883", "3926.563477 104.314133 10173.152344", "3916.067627 104.628944 10124.813477", false, false);
			pane.Calc();
			underground.Insert(pane);*/

			//Yantar MSL
			pane = new UndergroundLightingPane();
			pane.transitionArea = 0.5;
			pane.AddTriangle("2458.350342 41.823517 6220.109375", "2462.827637 41.959003 6215.740723", "2462.770752 41.372658 6203.610840", false, false);
			pane.AddTriangle("2446.481201 41.879871 6198.842773", "2442.002441 41.018631 6203.195801", "2441.824707 41.899132 6215.365723", false, false);
			pane.AddTriangle("2458.350342 41.823517 6220.109375", "2462.770752 41.372658 6203.610840", "2458.458740 41.167377 6199.093262", false, false);
			pane.AddTriangle("2446.307129 41.994358 6219.915527", "2458.350342 41.823517 6220.109375", "2458.458740 41.167377 6199.093262", false, false);
			pane.Calc();
			//pane.minAccom = 0.03;
			underground.Insert(pane);
		}
	}
	void Update()
	{
		if (undergroundDarknessFactor <= 1.0)
			GetGame().GetWorld().SetEyeAccom(Math.Max(undergroundDarknessFactor, MIN_ACCON_VALUE));
	}
	void ResetUndergroundLighting(bool force = false)
	{
		if (force)
			undergroundDarknessFactor = 1.0;
		targetUndergroundDarknessFactor = 1.0;
	}
	void SetUndergroundLighting(float lightfactor, bool force = false)
	{
		if (lightfactor < 0)
			lightfactor = 0;
		else if (lightfactor > 1)
			lightfactor = 1;
		targetUndergroundDarknessFactor = lightfactor;
		if (force)
			undergroundDarknessFactor = lightfactor;
	}
	void UpdateSetUndergroundLighting()
	{
		float diff = undergroundDarknessFactor - targetUndergroundDarknessFactor;
		float maxRate = MAX_CHANGE_RATE * LIGHTING_UPDATE_TIMER / 100;
		if (diff > maxRate)
			undergroundDarknessFactor -= maxRate;
		else if (diff < -maxRate)
			undergroundDarknessFactor += maxRate;
		else
			undergroundDarknessFactor = targetUndergroundDarknessFactor;
		if (undergroundDarknessFactor < 0)
			undergroundDarknessFactor = 0;
		else if (undergroundDarknessFactor > 1)
			ResetUndergroundLighting();
	}
	void CalcUndergroundLighting()
	{
		if (!GetGame().GetPlayer())
			return;
		vector camPos = GetGame().GetCurrentCameraPosition();
		vector headPos;
		MiscGameplayFunctions.GetHeadBonePos(PlayerBase.Cast(GetGame().GetPlayer()), headPos);
		vector pos = headPos;
		if (vector.Distance(camPos, headPos) > 10 && (!GetGame().GetPlayer().GetCommand_Vehicle() || !GetGame().GetPlayer().GetCommand_Vehicle().GetTransport()))
			pos = camPos;
		float accom = 1.0;
		float dayAdd = 0.0;
		foreach(UndergroundLightingPane pane : underground)
		{
			float paneAccom = pane.GetEyeAccom(pos);
			accom = Math.Min(paneAccom, accom);
		}
		dayAdd = Math.Min(1.0, Math.Max(0.0, dayAdd));
		SetUndergroundLighting(accom + dayAdd * 0.25, !init);
		init = true;
	}
}