class Earcut
{
    static array<int> earcut(array<float> data)
    {
        return earcut(data, new array<int>(), 2);
    }
    static array<int> earcut(array<float> data, array<int> holeIndices, int dim)
    {
        bool hasHoles = holeIndices && holeIndices.Count() > 0;
        int outerLen;
        if (hasHoles)
            outerLen = holeIndices[0] * dim;
        else
            outerLen = data.Count();
        Node outerNode = linkedList(data, 0, outerLen, dim, true);
        array<int> triangles = new array<int>();
        if (outerNode == null)
            return triangles;
        float minX = 0;
        float minY = 0;
        float maxX = 0;
        float maxY = 0;
        float size = -88888888.8;
        if (hasHoles)
            outerNode = eliminateHoles(data, holeIndices, outerNode, dim);
        if (data.Count() > 80 * dim) {
            minX = data[0];
            maxX = data[0];
            minY = data[1];
            maxY = data[1];
            for (int i = dim; i < outerLen; ) {
                float x = data[i];
                float y = data[i + 1];
                if (x < minX)
                    minX = x;
                if (y < minY)
                    minY = y;
                if (x > maxX)
                    maxX = x;
                if (y > maxY)
                    maxY = y;
                i += dim;
            }
            size = Math.Max(maxX - minX, maxY - minY);
        }
        earcutLinked(outerNode, triangles, dim, minX, minY, size, -88888887);
        Node.allNodes.Clear();
        return triangles;
    }
    private static void earcutLinked(Node ear, array<int> triangles, int dim, float minX, float minY, float size, int pass)
    {
        if (ear == null)
            return;
        if (pass == -88888887 && size != -88888888.8)
            indexCurve(ear, minX, minY, size);
        Node stop = ear;
        while (ear.prev != ear.next) {
            Node prev = ear.prev;
            Node next = ear.next;
            bool b;
            if (size != -88888888.8)
                b = isEarHashed(ear, minX, minY, size);
            else
                b = isEar(ear);
            if (b)
            {
                triangles.Insert(prev.i / dim);
                triangles.Insert(ear.i / dim);
                triangles.Insert(next.i / dim);
                removeNode(ear);
                ear = next.next;
                stop = next.next;
                continue;
            }
            ear = next;
            if (ear == stop) {
                if (pass == -88888887)
                    earcutLinked(filterPoints(ear, null), triangles, dim, minX, minY, size, 1);
                else if (pass == 1)
                {
                    ear = cureLocalIntersections(ear, triangles, dim);
                    earcutLinked(ear, triangles, dim, minX, minY, size, 2);
                }
                else if (pass == 2)
                    splitEarcut(ear, triangles, dim, minX, minY, size);
                break;
            }
        }
    }
    private static void splitEarcut(Node start, array<int> triangles, int dim, float minX, float minY, float size)
    {
        Node a = start;
        Node b = a.next.next;
        while (b != a.prev) {
            if (a.i != b.i && isValidDiagonal(a, b))
            {
                Node c = splitPolygon(a, b);
                a = filterPoints(a, a.next);
                c = filterPoints(c, c.next);
                earcutLinked(a, triangles, dim, minX, minY, size, -88888887);
                earcutLinked(c, triangles, dim, minX, minY, size, -88888887);
                return;
            }
            b = b.next;
        }
        a = a.next;
        while (a != start) {
            b = a.next.next;
            while (b != a.prev) {
                if (a.i != b.i && isValidDiagonal(a, b))
                {
                    c = splitPolygon(a, b);
                    a = filterPoints(a, a.next);
                    c = filterPoints(c, c.next);
                    earcutLinked(a, triangles, dim, minX, minY, size, -88888887);
                    earcutLinked(c, triangles, dim, minX, minY, size, -88888887);
                    return;
                }
                b = b.next;
            }
            a = a.next;
        }
    }
    private static bool isValidDiagonal(Node a, Node b)
    {
        return a.next.i != b.i && a.prev.i != b.i && !intersectsPolygon(a, b) && locallyInside(a, b) && locallyInside(b, a) && middleInside(a, b);
    }
    private static bool middleInside(Node a, Node b)
    {
        Node p = a;
        bool inside = false;
        float px = (a.x + b.x) / 2;
        float py = (a.y + b.y) / 2;
        if (((p.y > py) != (p.next.y > py)) && (px < (p.next.x - p.x) * (py - p.y) / (p.next.y - p.y) + p.x))
            inside = !inside;
        p = p.next;
        while (p != a) {
            if (((p.y > py) != (p.next.y > py)) && (px < (p.next.x - p.x) * (py - p.y) / (p.next.y - p.y) + p.x))
                inside = !inside;
            p = p.next;
        };
        return inside;
    }
    private static bool intersectsPolygon(Node a, Node b)
    {
        Node p = a;
        if (p.i != a.i && p.next.i != a.i && p.i != b.i && p.next.i != b.i && intersects(p, p.next, a, b))
            return true;
        p = p.next;
        while (p != a) {
            if (p.i != a.i && p.next.i != a.i && p.i != b.i && p.next.i != b.i && intersects(p, p.next, a, b))
                return true;
            p = p.next;
        };
        return false;
    }
    private static bool intersects(Node p1, Node q1, Node p2, Node q2)
    {
        if ((equals(p1, q1) && equals(p2, q2)) || (equals(p1, q2) && equals(p2, q1)))
            return true;
        return area(p1, q1, p2) > 0 != area(p1, q1, q2) > 0 && area(p2, q2, p1) > 0 != area(p2, q2, q1) > 0;
    }
    private static Node cureLocalIntersections(Node start, array<int> triangles, int dim)
    {
        Node p = start;
        Node a = p.prev, b = p.next.next;
        if (!equals(a, b) && intersects(a, p, p.next, b) && locallyInside(a, b) && locallyInside(b, a)) {
            triangles.Insert(a.i / dim);
            triangles.Insert(p.i / dim);
            triangles.Insert(b.i / dim);
            removeNode(p);
            removeNode(p.next);
            p = b;
            start = b;
        }
        p = p.next;
        while (p != start) {
            a = p.prev;
            b = p.next.next;
            if (!equals(a, b) && intersects(a, p, p.next, b) && locallyInside(a, b) && locallyInside(b, a)) {
                triangles.Insert(a.i / dim);
                triangles.Insert(p.i / dim);
                triangles.Insert(b.i / dim);
                removeNode(p);
                removeNode(p.next);
                p = b;
                start = b;
            }
            p = p.next;
        }
        return p;
    }
    private static bool isEar(Node ear)
    {
        Node a = ear.prev, b = ear, c = ear.next;
        if (area(a, b, c) >= 0)
            return false;
        Node p = ear.next.next;
        while (p != ear.prev) {
            if (pointInTriangle(a.x, a.y, b.x, b.y, c.x, c.y, p.x, p.y) && area(p.prev, p, p.next) >= 0)
                return false;
            p = p.next;
        }
        return true;
    }
    private static bool isEarHashed(Node ear, float minX, float minY, float size)
    {
        Node a = ear.prev;
        Node b = ear;
        Node c = ear.next;
        if (area(a, b, c) >= 0)
            return false;
        float minTx, minTY, maxTX, maxTY;
        if (a.x < b.x) {
            if (a.x < c.x)
                minTx = a.x;
            else
                minTx = c.x;
        }
        else {
            if (b.x < c.x)
                minTx = b.x;
            else
                minTx = c.x;
        }
        if (a.y < b.y) {
            if (a.y < c.y)
                minTY = a.y;
            else
                minTY = c.y;
        }
        else {
            if (b.y < c.y)
                minTY = b.y;
            else
                minTY = c.y;
        }
        if (a.x > b.x) {
            if (a.x > c.x)
                maxTX = a.x;
            else
                maxTX = c.x;
        }
        else {
            if (b.x > c.x)
                maxTX = b.x;
            else
                maxTX = c.x;
        }
        if (a.y > b.y) {
            if (a.y > c.y)
                maxTY = a.y;
            else
                maxTY = c.y;
        }
        else {
            if (b.y > c.y)
                maxTY = b.y;
            else
                maxTY = c.y;
        }
        float minZ = zOrder(minTx, minTY, minX, minY, size);
        float maxZ = zOrder(maxTX, maxTY, minX, minY, size);
        Node p = ear.nextZ;
        while (p && p.z <= maxZ) {
            if (p != ear.prev && p != ear.next && pointInTriangle(a.x, a.y, b.x, b.y, c.x, c.y, p.x, p.y) && area(p.prev, p, p.next) >= 0)
                return false;
            p = p.nextZ;
        }
        p = ear.prevZ;
        while (p && p.z >= minZ) {
            if (p != ear.prev && p != ear.next && pointInTriangle(a.x, a.y, b.x, b.y, c.x, c.y, p.x, p.y) && area(p.prev, p, p.next) >= 0)
                return false;
            p = p.prevZ;
        }
        return true;
    }
    private static float zOrder(float x, float y, float minX, float minY, float size)
    {
        int lx = (int) (32767.0 * (x - minX) / size);
        int ly = (int) (32767.0 * (y - minY) / size);
        lx = (lx | (lx << 8)) & 0x00FF00FF;
        lx = (lx | (lx << 4)) & 0x0F0F0F0F;
        lx = (lx | (lx << 2)) & 0x33333333;
        lx = (lx | (lx << 1)) & 0x55555555;
        ly = (ly | (ly << 8)) & 0x00FF00FF;
        ly = (ly | (ly << 4)) & 0x0F0F0F0F;
        ly = (ly | (ly << 2)) & 0x33333333;
        ly = (ly | (ly << 1)) & 0x55555555;
        int ret = lx | (ly << 1);
        return ret;
    }
    private static void indexCurve(Node start, float minX, float minY, float size)
    {
        Node p = start;
        if (p.z == -88888888.8)
            p.z = zOrder(p.x, p.y, minX, minY, size);
        p.prevZ = p.prev;
        p.nextZ = p.next;
        p = p.next;
        while (p != start) {
            if (p.z == 0)
                p.z = zOrder(p.x, p.y, minX, minY, size);
            p.prevZ = p.prev;
            p.nextZ = p.next;
            p = p.next;
        };
        p.prevZ.nextZ = null;
        p.prevZ = null;
        sortLinked(p);
    }
    private static Node sortLinked(Node list)
    {
        int inSize = 1;
        int numMerges;
        Node p = list;
        list = null;
        Node tail = null;
        numMerges = 0;
        while (p) {
            numMerges++;
            Node q = p;
            int pSize = 0;
            for (int i = 0; i < inSize; i++) {
                pSize++;
                q = q.nextZ;
                if (q == null)
                    break;
            }
            int qSize = inSize;
            while (pSize > 0 || (qSize > 0 && q)) {
                Node e;
                if (pSize == 0) {
                    e = q;
                    q = q.nextZ;
                    qSize--;
                }
                else if (qSize == 0 || q == null) {
                    e = p;
                    p = p.nextZ;
                    pSize--;
                }
                else if (p.z <= q.z) {
                    e = p;
                    p = p.nextZ;
                    pSize--;
                }
                else {
                    e = q;
                    q = q.nextZ;
                    qSize--;
                }
                if (tail)
                    tail.nextZ = e;
                else
                    list = e;
                e.prevZ = tail;
                tail = e;
            }
            p = q;
        }
        tail.nextZ = null;
        inSize *= 2;
        while (numMerges > 1) {
            p = list;
            list = null;
            tail = null;
            numMerges = 0;
            while (p) {
                numMerges++;
                q = p;
                pSize = 0;
                for (i = 0; i < inSize; i++) {
                    pSize++;
                    q = q.nextZ;
                    if (q == null)
                        break;
                }
                qSize = inSize;
                while (pSize > 0 || (qSize > 0 && q)) {
                    if (pSize == 0) {
                        e = q;
                        q = q.nextZ;
                        qSize--;
                    }
                    else if (qSize == 0 || q == null) {
                        e = p;
                        p = p.nextZ;
                        pSize--;
                    }
                    else if (p.z <= q.z) {
                        e = p;
                        p = p.nextZ;
                        pSize--;
                    }
                    else {
                        e = q;
                        q = q.nextZ;
                        qSize--;
                    }
                    if (tail)
                        tail.nextZ = e;
                    else
                        list = e;
                    e.prevZ = tail;
                    tail = e;
                }
                p = q;
            }
            tail.nextZ = null;
            inSize *= 2;
        }
        return list;
    }
    private static Node eliminateHoles(array<float> data, array<int> holeIndices, Node outerNode, int dim)
    {
        array<Node> queue = new array<Node>();
        int len = holeIndices.Count();
        for (int i = 0; i < len; i++) {
            int start = holeIndices[i] * dim;
            int end;
            if (i < len - 1)
                end = holeIndices[i + 1] * dim;
            else
                end = data.Count();
            Node list = linkedList(data, start, end, dim, false);
            if (list == list.next)
                list.steiner = true;
            queue.Insert(getLeftmost(list));
        }
        foreach (Node node : queue)
        {
            eliminateHole(node, outerNode);
            outerNode = filterPoints(outerNode, outerNode.next);
        }
        return outerNode;
    }
    private static void sort(array<Node> toSort)
    {
        bool sorted = false;
        Node temp;
        while (!sorted) {
            sorted = true;
            for (int i = 0; i < toSort.Count() - 1; i++) {
                if (toSort[i].x > toSort[i + 1].x) {
                    temp = toSort[i];
                    toSort[i] = toSort[i + 1];
                    toSort[i + 1] = temp;
                    sorted = false;
                }
            }
        }
    }
    private static Node filterPoints(Node start, Node end)
    {
        if (start == null)
            return start;
        if (end == null)
            end = start;
        Node p = start;
        bool again = false;
        if (!p.steiner && equals(p, p.next) || area(p.prev, p, p.next) == 0) {
            removeNode(p);
            p = p.prev;
            end = p;
            if (p == p.next)
                return null;
            again = true;
        }
        else {
            p = p.next;
        }
        while (again || p != end) {
            again = false;
            if (!p.steiner && equals(p, p.next) || area(p.prev, p, p.next) == 0) {
                removeNode(p);
                p = p.prev;
                end = p;
                if (p == p.next)
                    return null;
                again = true;
            }
            else {
                p = p.next;
            }
        }
        return end;
    }
    private static bool equals(Node p1, Node p2)
    {
        return p1.x == p2.x && p1.y == p2.y;
    }
    private static float area(Node p, Node q, Node r)
    {
        return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    }
    private static void eliminateHole(Node hole, Node outerNode)
    {
        outerNode = findHoleBridge(hole, outerNode);
        if (outerNode) {
            Node b = splitPolygon(outerNode, hole);
            filterPoints(b, b.next);
        }
    }
    private static Node splitPolygon(Node a, Node b)
    {
        Node a2 = new Node(a.i, a.x, a.y);
        Node b2 = new Node(b.i, b.x, b.y);
        Node an = a.next;
        Node bp = b.prev;
        a.next = b;
        b.prev = a;
        a2.next = an;
        an.prev = a2;
        b2.next = a2;
        a2.prev = b2;
        bp.next = b2;
        b2.prev = bp;
        return b2;
    }
    private static Node findHoleBridge(Node hole, Node outerNode)
    {
        Node p = outerNode;
        float hx = hole.x;
        float hy = hole.y;
        float qx = -999999.9;
        Node m = null;
        if (hy <= p.y && hy >= p.next.y) {
            float x = p.x + (hy - p.y) * (p.next.x - p.x) / (p.next.y - p.y);
            if (x <= hx && x > qx) {
                qx = x;
                if (x == hx) {
                    if (hy == p.y)
                        return p;
                    if (hy == p.next.y)
                        return p.next;
                }
                if (p.x < p.next.x)
                    m = p;
                else
                    m = p.next;
            }
        }
        p = p.next;
        while (p != outerNode) {
            if (hy <= p.y && hy >= p.next.y) {
                x = p.x + (hy - p.y) * (p.next.x - p.x) / (p.next.y - p.y);
                if (x <= hx && x > qx) {
                    qx = x;
                    if (x == hx) {
                        if (hy == p.y)
                            return p;
                        if (hy == p.next.y)
                            return p.next;
                    }
                    if (p.x < p.next.x)
                        m = p;
                    else
                        m = p.next;
                }
            }
            p = p.next;
        }
        if (m == null)
            return null;
        if (hx == qx)
            return m.prev;
        Node stop = m;
        float mx = m.x;
        float my = m.y;
        float tanMin = 999999.9;
        float tan;
        p = m.next;
        while (p != stop) {
            float p1;
            if (hy < my) {
                p1 = hx;
            }
            else {
                p1 = qx;
            }
            float p2;
            if (hy < my) {
                p2 = qx;
            }
            else {
                p2 = hx;
            }
            if (hx >= p.x && p.x >= mx && pointInTriangle(p1, hy, mx, my, p2, hy, p.x, p.y)) {
                tan = Math.AbsFloat(hy - p.y) / (hx - p.x);
                if ((tan < tanMin || (tan == tanMin && p.x > m.x)) && locallyInside(p, hole)) {
                    m = p;
                    tanMin = tan;
                }
            }
            p = p.next;
        }
        return m;
    }
    private static bool locallyInside(Node a, Node b)
    {
        if (area(a.prev, a, a.next) < 0) {
            return area(a, b, a.next) >= 0 && area(a, a.prev, b) >= 0;
        }
        return  area(a, b, a.prev) < 0 || area(a, a.next, b) < 0;
    }
    private static bool pointInTriangle(float ax, float ay, float bx, float by, float cx, float cy, float px, float py)
    {
        return (cx - px) * (ay - py) - (ax - px) * (cy - py) >= 0 && (ax - px) * (by - py) - (bx - px) * (ay - py) >= 0 && (bx - px) * (cy - py) - (cx - px) * (by - py) >= 0;
    }
    private static Node getLeftmost(Node start)
    {
        Node p = start;
        Node leftmost = start;
        if (p.x < leftmost.x)
            leftmost = p;
        p = p.next;
        while (p != start) {
            if (p.x < leftmost.x)
                leftmost = p;
            p = p.next;
        }
        return leftmost;
    }
    private static Node linkedList(array<float> data, int start, int end, int dim, bool clockwise)
    {
        Node last = null;
        if (clockwise == (signedArea(data, start, end, dim) > 0)) {
            for (int i = start; i < end; ) {
                last = insertNode(i, data[i], data[i + 1], last);
                i += dim;
            }
        }
        else {
            for (i = (end - dim); i >= start;) {
                last = insertNode(i, data[i], data[i + 1], last);
                i -= dim;
            }
        }
        if (last && equals(last, last.next)) {
            removeNode(last);
            last = last.next;
        }
        return last;
    }
    private static void removeNode(Node p)
    {
        p.next.prev = p.prev;
        p.prev.next = p.next;
        if (p.prevZ) {
            p.prevZ.nextZ = p.nextZ;
        }
        if (p.nextZ) {
            p.nextZ.prevZ = p.prevZ;
        }
    }
    private static Node insertNode(int i, float x, float y, Node last)
    {
        Node p = new Node(i, x, y);
        if (last == null) {
            p.prev = p;
            p.next = p;
        }
        else {
            p.next = last.next;
            p.prev = last;
            last.next.prev = p;
            last.next = p;
        }
        return p;
    }
    private static float signedArea(array<float> data, int start, int end, int dim)
    {
        float sum = 0;
        int j = end - dim;
        for (int i = start; i < end; ) {
            sum += (data[j] - data[i]) * (data[i + 1] + data[j + 1]);
            j = i;
            i += dim;
        }
        return sum;
    }
}
class Node
{
    static ref array<ref Node> allNodes = new array<ref Node>();
    int i;
    float x = 0;
    float y = 0;
    float z = 0;
    bool steiner;
    Node prev;
    Node next;
    Node prevZ;
    Node nextZ;
    void Node(int i, float x, float y)
    {
        allNodes.Insert(this);
        this.i = i;
        this.x = x;
        this.y = y;
        this.prev = null;
        this.next = null;
        this.z = -88888888.8;
        this.prevZ = null;
        this.nextZ = null;
        this.steiner = false;
    }
}