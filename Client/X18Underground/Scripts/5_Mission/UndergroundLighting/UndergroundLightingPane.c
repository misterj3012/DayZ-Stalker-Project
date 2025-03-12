class UndergroundLightingPane
{
	ref array<ref Triangle> panes = new ref array<ref Triangle>();
	float transitionArea = 5.0;
	ScriptedLightBase daylight;
	vector centerPos = vector.Zero;
	float range = 0;
	float lowestHeight = 0;
	float minAccom = UndergroundLightManager.MIN_ACCON_VALUE;
	void ~UndergroundLightingPane()
	{
		if (daylight)
			GetGame().ObjectDelete(daylight);
	}
	void Calc()
	{
		array<vector> positions = new array<vector>();
		foreach(Triangle tri : panes)
		{
			if (!IsInArray(positions, tri.pos1))
				positions.Insert(tri.pos1);
			if (!IsInArray(positions, tri.pos2))
				positions.Insert(tri.pos2);
			if (!IsInArray(positions, tri.pos3))
				positions.Insert(tri.pos3);
		}
		int c = positions.Count();
		if (c > 0)
		{
			vector all = vector.Zero;
			foreach(vector pos : positions)
			{
				all = all + pos;
			}
			centerPos = Vector(all[0] / c, all[1] / c, all[2] / c);
			foreach(vector pos2 : positions)
			{
				float dist = vector.Distance(pos2, centerPos);
				if (range < dist)
					range = dist;
			}
			if (MissionGameplay.UNDERGROUND_DEBUG)
				Debug.DrawCylinder(centerPos, range, 0.01, ARGB(255, 255, 255, 0), ShapeFlags.TRANSP | ShapeFlags.WIREFRAME);
		}
		lowestHeight = GetLowestHeight();
	}
	float GetLowestHeight()
	{
		float smallest = 0;
		bool found = false;
		foreach(Triangle triangle : panes)
		{
			vector min = triangle.min;
			if (!found || min[1] < smallest)
				smallest = min[1];
			found = true;
		}
		return smallest;
	}
	bool IsInArray(array<vector> arr, vector checkPos, float distance = 1.0)
	{
		foreach(vector pos : arr)
		{
			if (vector.Distance(pos, checkPos) < distance)
				return true;
		}
		return false;
	}
	bool CheckUnderground(vector pos)
	{
		if (vector.Distance(Vector(centerPos[0], 0, centerPos[2]), Vector(pos[0], 0, pos[2])) > range + 1)
			return false;
		foreach(Triangle triangle : panes)
		{
			vector min = triangle.min;
			vector max = triangle.max;
			if (IsUnderBox(min, max, pos))
				return true;
		}
		return false;
	}
	void SetAsDayLight(bool addLightsource = false, vector pos = vector.Zero)
	{
		if (addLightsource)
			daylight = ScriptedLightBase.CreateLight(DaylightLight, pos, 0.08);
	}
	float GetEyeAccom(vector pos)
	{
		if (!CheckUnderground(pos))
			return 1.0;
		float height = pos[1] - lowestHeight;
		float accom = Math.Min(1.0, Math.Max(0.0, (height / transitionArea) + 1.0));
		foreach(Triangle tri2 : panes)
		{
			if (!tri2.whole)
				continue;
			if (tri2.PointInTriangle2D(pos))
				return 1.0;
		}
		if (accom <= 0)
			return minAccom;
		float min = 99999;
		foreach(Triangle tri : panes)
		{
			if (tri.whole)
				continue;
			bool onPlane;
			float dist = tri.DistanceFromPoint(pos, onPlane);
			if (onPlane)
			{
				if (dist != -1 && min > dist)
					min = dist;
			}
		}
		accom = Math.Min(1.0, Math.Max(0.0, (min / transitionArea) + 1.0));
		return Math.Max(minAccom, accom);
	}
	bool IsUnderBox(vector min, vector max, vector pos)
	{
		return (min[0] < pos[0] && max[0] > pos[0] && max[1] > pos[1] && min[2] < pos[2] && max[2] > pos[2]);
	}
	void AddTriangle(vector t1, vector t2, vector t3, bool whole = false, bool daylight = false)
	{
		int color = -1;
		if (whole)
			color = ARGB(255, 255, 0, 0);
		if (daylight)
			color = ARGB(255, 0, 255, 0);
		Triangle tri = new Triangle(t1, t2, t3, whole, daylight);
		if (MissionGameplay.UNDERGROUND_DEBUG)
		{
			Debug.DrawLine(t1, t2, color);
			Debug.DrawLine(t2, t3, color);
			Debug.DrawLine(t3, t1, color);
			Debug.DrawBox(tri.min, tri.max, ARGB(255, 255, 0, 255));
			Debug.DrawLine(tri.center, tri.center + (tri.normal * 4), ARGB(255, 0, 255, 255));
		}
		panes.Insert(tri);
	}
}
class Triangle
{
	vector pos1, pos2, pos3, normal, min, max, center;
	bool whole = false;
	bool daylight = false;
	void Triangle(vector pos1, vector pos2, vector pos3, bool whole = false, bool daylight = false)
	{
		this.pos1 = pos1;
		this.pos2 = pos2;
		this.pos3 = pos3;
		this.whole = whole;
		this.daylight = daylight;
		this.normal = ComputeTriangleNormal();
		if (normal[1] > 0)
			normal = normal * -1;
		this.min = ComputeBoxMin();
		this.max = ComputeBoxMax();
		this.center = (pos1 + pos2 + pos3);
		this.center = Vector(center[0] / 3, center[1] / 3, center[2] / 3);
	}
	float DistanceFromPoint(vector pos, out bool onplane)
	{
		vector pq = pos1 - pos;
		vector distVec = normal * pq;
		float distPane = vector.Dot(pq, normal);
		vector posOnPlane = pos + (normal * distPane);
		onplane = PointInTriangle2D(posOnPlane);
		return distPane;
	}
	float sign(vector p1, vector p2, vector p3)
	{
		return (p1[0] - p3[0]) * (p2[1] - p3[1]) - (p2[0] - p3[0]) * (p1[1] - p3[1]);
	}
	bool PointInTriangle(vector pt)
	{
		float d1, d2, d3;
		bool has_neg, has_pos;
		d1 = sign(pt, pos1, pos2);
		d2 = sign(pt, pos2, pos3);
		d3 = sign(pt, pos3, pos1);
		float toll = -0.15;
		has_neg = (d1 - toll < 0) || (d2 - toll < 0) || (d3 - toll < 0);
		has_pos = (d1 + toll > 0) || (d2 + toll > 0) || (d3 + toll > 0);
		return !(has_neg && has_pos);
	}
	bool PointInTriangle2D(vector pt)
	{
		vector up = vector.Up;
		if (vector.Dot(normal, up) == 0)
			return false;
		float t = (vector.Dot(normal, pos1) - vector.Dot(normal, pt)) / vector.Dot(normal, up);
		return PointInTriangle(pt + (up * t));
	}
	vector ComputeTriangleNormal()
	{
		vector v1 = pos2 - pos1;
		vector v2 = pos3 - pos1;
		vector norm = Vector(v1[1] * v2[2] - v1[2] * v2[1], v1[2] * v2[0] - v1[0] * v2[2], v1[0] * v2[1] - v1[1] * v2[0]);
		return norm.Normalized();
	}
	vector ComputeBoxMin()
	{
		float x = Math.Min(pos1[0], Math.Min(pos2[0], pos3[0]));
		float y = Math.Min(pos1[1], Math.Min(pos2[1], pos3[1]));
		float z = Math.Min(pos1[2], Math.Min(pos2[2], pos3[2]));
		return Vector(x, y, z);
	}
	vector ComputeBoxMax()
	{
		float x = Math.Max(pos1[0], Math.Max(pos2[0], pos3[0]));
		float y = Math.Max(pos1[1], Math.Max(pos2[1], pos3[1]));
		float z = Math.Max(pos1[2], Math.Max(pos2[2], pos3[2]));
		return Vector(x, y, z);
	}
}