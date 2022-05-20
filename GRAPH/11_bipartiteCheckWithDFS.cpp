#include <bits/stdc++.h>
using namespace std;

// we do dfs traversal and color the nodes adjacent nodes with opposite color and if we find a node among them having the same color then it is not a bipartite graph

bool checkBipartiteDFS(int node, vector<int> &color, vector<int> adj[])
{
  if (color[node] == -1)
    color[node] = 1;

  for (auto it : adj[node])
  {
    if (color[it] == -1)
    {
      color[it] = 1 - color[node];
      if (!checkBipartiteDFS(it, color, adj))
      {
        return false;
      }
    }
    else if (color[it] == color[node])
      return false;
  }
  return true;
}

bool checkBipartite(vector<int> adj[], int V)
{
  vector<int> color(V, -1);
  for (int i = 0; i < V; i++)
  {
    if (color[i] == -1)
    {
      if (!checkBipartiteDFS(i, color, adj))
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (checkBipartite(adj, n))
  {
    cout << "yes";
  }
  else
  {
    cout << "No";
  }
  return 0;
}

/*
8 7
0 1
1 2
2 3
3 4
4 6
6 7
1 7
4 5

// bipartite graph example
*/

/*
7 7
0 1
1 2
2 3
3 4
4 6
6 1
4 5
// not bipartite example
*/
