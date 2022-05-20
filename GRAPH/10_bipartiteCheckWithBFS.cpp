#include <bits/stdc++.h>
using namespace std;

// we do bfs traversal and color the nodes adjacent nodes with opposite color and if we find a node among them having the same color then it is not a bipartite graph

bool checkBipartiteBFS(int node, vector<int> &color, vector<int> adj[])
{
  queue<int> q;
  q.push(node);
  // initial color is 0
  color[node] = 0;

  while (!q.empty())
  {
    int n = q.front();
    q.pop();

    for (auto &i : adj[n])
    {
      if (color[i] == -1)
      {
        // setting opposite color
        color[i] = 1 - color[n];
        q.push(i);
      }
      else if (color[i] == color[n])
        return false;
    }
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
      if (!checkBipartiteBFS(i, color, adj))
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
