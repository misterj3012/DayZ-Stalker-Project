modded class MissionGameplay
{
    ref UndergroundLightManager m_UndergroundLightManager;
    static bool UNDERGROUND_DEBUG = false;
    ref array<ref vector> positions = new array<ref vector>();
    ref array<int> wholes = new array<int>();
    ref array<int> daylights = new array<int>();
    void MissionGameplay()
    {        
        m_UndergroundLightManager = new UndergroundLightManager();
    }
    void ~MissionGameplay()
    {
        if (m_UndergroundLightManager)
            delete m_UndergroundLightManager;
    }
    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
        if (m_UndergroundLightManager)
            m_UndergroundLightManager.Update();
        if (!UNDERGROUND_DEBUG)
            return;
        if (GetUApi().GetInputByName("UALBMUndergroundAdd").LocalPress()) {
            Print("UALBMUndergroundAdd " + positions.Count() + " " + positions.ToString());
            vector lookingAt = GetPointLookingAt();
            Print("Adding: " + lookingAt);
            AddPosition(lookingAt);
        }
        if (GetUApi().GetInputByName("UALBMUndergroundRemove").LocalPress()) {
            Print("UALBMUndergroundRemove");
            RemoveLastPosition();
        }
        if (GetUApi().GetInputByName("UALBMUndergroundAddWhole").LocalPress()) {
            Print("UALBMUndergroundAddWhole");
            lookingAt = GetPointLookingAt();
            Print("Adding: " + lookingAt);
            AddWhole(lookingAt);
        }
        if (GetUApi().GetInputByName("UALBMUndergroundAddDaylight").LocalPress()) {
            Print("UALBMUndergroundAddDaylight");
            lookingAt = GetPointLookingAt();
            Print("Adding: " + lookingAt);
            AddDaylight(lookingAt);
        }
        if (GetUApi().GetInputByName("UALBMUndergroundExport").LocalPress()) {
            Print("UALBMUndergroundExport");
            ExportPositions();
        }
        if (GetUApi().GetInputByName("UALBMUndergroundClear").LocalPress()) {
            Print("UALBMUndergroundClear");
            ClearPositions();
        }
        if (GetUApi().GetInputByName("UALBMUndergroundHere").LocalPress()) {
            Print("UALBMUndergroundHere");
            AddPosition(GetGame().GetCurrentCameraPosition());
        }
    }
    void RemoveLastPosition()
    {
        if (positions.Count() > 0)
            positions.Remove(positions.Count() - 1);
        int index = wholes.Find(positions.Count());
        if (index >= 0)
            wholes.Remove(index);
        daylights.Find(positions.Count());
        if (index >= 0)
            daylights.Remove(index);
        UpdateShapes();
    }
    void AddPosition(vector pos)
    {
        positions.Insert(pos + "0 0.1 0");
        UpdateShapes();
    }
    void AddWhole(vector pos)
    {
        positions.Insert(pos + "0 0.1 0");
        wholes.Insert(positions.Count() - 1);
        UpdateShapes();
    }
    void AddDaylight(vector pos)
    {
        positions.Insert(pos + "0 0.1 0");
        daylights.Insert(positions.Count() - 1);
        UpdateShapes();
    }
    void UpdateShapes()
    {
        Debug.DestroyAllShapes();
        AddShapes();
    }
    void ClearPositions()
    {
        positions.Clear();
        wholes.Clear();
        daylights.Clear();
        UpdateShapes();
    }
    void ExportPositions()
    {
        FileHandle handle = OpenFile("$profile:export.txt", FileMode.WRITE);
        Print("Exporting...");
        if (!handle)
            return;
        int index = 0;
        Print("Exporting to file");
        /*foreach (vector pos2 : positions)
        {
            if (wholes.Find(index) != -1) {
                Print("Whole: " + pos2.ToString());
                FPrintln(handle, "Whole: " + pos2.ToString());
            }
            else if (daylights.Find(index) != -1) {
                Print("Light: " + pos2.ToString());
                FPrintln(handle, "Light: " + pos2.ToString());
            }
            else {
                Print("Point: " + pos2.ToString());
                FPrintln(handle, "Point: " + pos2.ToString());
            }
            index++;
        }
        CloseFile(handle);*/
        Print("\t\t\tpane = new UndergroundLightingPane();");
        array<float> data = new array<float>();
        array<float> dataWholes = new array<float>();
        array<float> dataDaylight = new array<float>();
        index = 0;
        foreach (vector pos : positions)
        {
            if (wholes.Find(index) != -1) {
                dataWholes.Insert(pos[0]);
                dataWholes.Insert(pos[1]);
                dataWholes.Insert(pos[2]);
            }
            else if (daylights.Find(index) != -1) {
                dataDaylight.Insert(pos[0]);
                dataDaylight.Insert(pos[1]);
                dataDaylight.Insert(pos[2]);
            }
            else {
                data.Insert(pos[0]);
                data.Insert(pos[1]);
                data.Insert(pos[2]);
            }
            index++;
        }
        PrintData(data, false, false);
        PrintData(dataWholes, true, false);
        PrintData(dataDaylight, false, true);
        Print("\t\t\tunderground.Insert(pane);");
        return;
    }
    void AddShapes()
    {
        array<float> data = new array<float>();
        array<float> dataWholes = new array<float>();
        array<float> dataDaylight = new array<float>();
        int index = 0;
        foreach (vector pos : positions)
        {
            if (wholes.Find(index) != -1) {
                dataWholes.Insert(pos[0]);
                dataWholes.Insert(pos[1]);
                dataWholes.Insert(pos[2]);
            }
            else if (daylights.Find(index) != -1) {
                dataDaylight.Insert(pos[0]);
                dataDaylight.Insert(pos[1]);
                dataDaylight.Insert(pos[2]);
            }
            else {
                data.Insert(pos[0]);
                data.Insert(pos[1]);
                data.Insert(pos[2]);
            }
            index++;
        }
        DrawData(data);
        DrawData(dataWholes, ARGB(255, 255, 0, 0));
        DrawData(dataDaylight, ARGB(255, 0, 255, 0));
    }
    void PrintData(array<float> data, bool whole, bool daylight)
    {
        array<int> outarr = Earcut.earcut(data, new array<int>(), 3);
        for (int i = 0; i < outarr.Count() / 3; i++) {
            float x1 = data[outarr[i * 3] * 3];
            float y1 = data[outarr[i * 3] * 3 + 1];
            float z1 = data[outarr[i * 3] * 3 + 2];
            float x2 = data[outarr[i * 3 + 1] * 3];
            float y2 = data[outarr[i * 3 + 1] * 3 + 1];
            float z2 = data[outarr[i * 3 + 1] * 3 + 2];
            float x3 = data[outarr[i * 3 + 2] * 3];
            float y3 = data[outarr[i * 3 + 2] * 3 + 1];
            float z3 = data[outarr[i * 3 + 2] * 3 + 2];
            vector vector1 = Vector(x1, y1, z1);
            vector vector2 = Vector(x2, y2, z2);
            vector vector3 = Vector(x3, y3, z3);
            Print("\t\t\tpane.AddTriangle(\"" + vector1.ToString(false) + "\", \"" + vector2.ToString(false) + "\", \"" + vector3.ToString(false) + "\", " + whole + ", " + daylight + ");");
        }
    }
    void DrawData(array<float> data, int color = -1)
    {
        array<int> outarr = Earcut.earcut(data, new array<int>(), 3);
        Print("Data Count: " + data.Count() + "Earcut got: " + outarr + " Color: " + color);
        float y = 30;
        for (int i = 0; i < outarr.Count() / 3; i++) {
            float x1 = data[outarr[i * 3] * 3];
            float y1 = data[outarr[i * 3] * 3 + 1];
            float z1 = data[outarr[i * 3] * 3 + 2];
            float x2 = data[outarr[i * 3 + 1] * 3];
            float y2 = data[outarr[i * 3 + 1] * 3 + 1];
            float z2 = data[outarr[i * 3 + 1] * 3 + 2];
            float x3 = data[outarr[i * 3 + 2] * 3];
            float y3 = data[outarr[i * 3 + 2] * 3 + 1];
            float z3 = data[outarr[i * 3 + 2] * 3 + 2];
            vector vector1 = Vector(x1, y1, z1);
            vector vector2 = Vector(x2, y2, z2);
            vector vector3 = Vector(x3, y3, z3);
            Debug.DrawLine(vector1, vector2, color);
            Debug.DrawLine(vector2, vector3, color);
            Debug.DrawLine(vector3, vector1, color);
        }
    }
    vector GetPointLookingAt()
    {
        vector camPos = GetGame().GetCurrentCameraPosition();
        vector camDir = GetGame().GetCurrentCameraDirection();
        vector end = camPos + (camDir * 1000);
        vector contact;
        vector contactDir;
        int comp;
        DayZPhysics.RaycastRV(camPos, end, contact, contactDir, comp);
        return contact;
    }
}