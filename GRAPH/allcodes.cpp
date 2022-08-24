//========================================================================================
/*                                                                                      *
 *              PRINT SHORTEST PATH BETWEEN GIVEN NODES IN UNDIRECTED GRAPH             *
 *                                                                                      */
//========================================================================================

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    vector<int> adj[n];
    for (auto p : edges)
    {
        adj[p.first - 1].push_back(p.second - 1);
        adj[p.second - 1].push_back(p.first - 1);
    }
    vector<int> dist(n, INT_MAX);
    vector<int> par(n);
    dist[s - 1] = 0;
    vector<int> path;

    queue<int> q;
    q.push(s - 1);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto &i : adj[node])
        {
            if (dist[i] > dist[node] + 1)
            {
                par[i] = node;
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }

    int i = t - 1;
    while (i != s - 1)
    {
        path.push_back(i + 1);
        i = par[i];
    }
    path.push_back(i + 1);
    reverse(path.begin(), path.end());

    return path;
}

//========================================================================================
/*                                                                                      *
 *                                   M COLORING GRAPH                                   *
 *                                                                                      */
//========================================================================================

bool isSafe(int node, vector<vector<int>> &mat, vector<int> &color, int i)
{
    int cols = mat[0].size();

    for (int col = 0; col < cols; col++)
    {
        if (mat[node][col] == 1 and color[col] == i)
            return false;
    }

    return true;
}

bool check(vector<vector<int>> &mat, vector<int> &color, int node, int m)
{
    if (node == mat.size())
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, mat, color, i))
        {
            color[node] = i;
            if (check(mat, color, node + 1, m))
                return true;
            color[node] = 0;
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{
    vector<int> color(mat.size(), 0);
    if (check(mat, color, 0, m))
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

//========================================================================================
/*                                                                                      *
 *                                     KRUSKALS ALGO                                    *
 *                                                                                      */
//========================================================================================

//  O(E log E) or O(E log V)

struct DSU
{
    vector<int> dsu, szx;

    DSU(int n) : dsu(n), szx(n, 1)
    {
        for (int i = 0; i < n; i++)
        {
            dsu[i] = i;
        }
    }

    int parent(int node)
    {
        if (node == dsu[node])
            return node;
        return dsu[node] = parent(dsu[node]);
    }

    void unify(int a, int b)
    {
        a = parent(a);
        b = parent(b);
        if (szx[a] < szx[b])
            swap(a, b);
        if (a != b)
            dsu[b] = a, szx[a] += szx[b];
    }

    int operator[](int &n)
    {
        return parent(n);
    }
};

int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    sort(graph.begin(), graph.end(), [](vector<int> &l, vector<int> &r)
         { return l[2] < r[2]; });

    DSU dsu(n + 1);
    int wt = 0;
    for (auto &edge : graph)
    {
        if (dsu[edge[0]] != dsu[edge[1]])
        {
            dsu.unify(edge[0], edge[1]);
            wt += edge[2];
        }
    }

    return wt;
}