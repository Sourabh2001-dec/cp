// articulation point is a node in  graph which when removed disconnects the graph components

//? Similar to bridge cuts problem
//? here when we found the bridge cut we mark the node in isAritculate array
//? and the root is articulation if it has more than one child

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &tin, vector<int> &low, vector<int> &vis, vector<int> adj[], vector<int> &isArticulation)
{
  vis[node] = 1;
  tin[node] = low[node] = timer++;
  int child = 0;
  for (auto &&it : adj[node])
  {
    if (it == parent)
      continue;
    if (!vis[it])
    {
      dfs(it, node, timer, tin, low, vis, adj, isArticulation);
      child++;
      low[node] = min(low[node], low[it]);
      if (tin[node] <= low[it] && parent != -1)
      {
        // bridge found
        isArticulation[node] = 1;
      }
    }
    else
    {
      low[node] = min(low[node], tin[it]);
    }
  }
  if (parent == -1 && child > 1)
  {
    isArticulation[node] = 1;
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  n = n + 1;
  vector<int> adj[n];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> tin(n, -1);
  vector<int> low(n, -1);
  vector<int> vis(n, 0);
  vector<int> isArticulation(n, 0);

  int timer = 0;
  for (int i = 1; i < n; i++)
  {
    if (!vis[i])
    {
      dfs(i, -1, timer, tin, low, vis, adj, isArticulation);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (isArticulation[i] == 1)
      cout << i << "\n";
  }

  return 0;
}