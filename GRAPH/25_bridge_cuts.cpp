#include <bits/stdc++.h>
using namespace std;

//! condition to detect bridge => low[adjacent_node] > tin[node]

//? We do dfs traversal from a node in graph while assigning a time and lowest time to reach to each node
//? If we found a node which can be accessed by a early node with less time we modify current low to that low
//? If we found a node with the above condition we add it to the set of bridges

void dfs(int node, int parent, int &timer, vector<int> &tin, vector<int> &low, vector<int> &vis, vector<int> adj[])
{
  vis[node] = 1;
  tin[node] = low[node] = timer++;

  for (auto &&it : adj[node])
  {
    if (it == parent)
      continue;
    if (!vis[it])
    {
      dfs(it, node, timer, tin, low, vis, adj);
      low[node] = min(low[node], low[it]);
      if (tin[node] < low[it])
      {
        // bridge found
        cout << node << " -> " << it << "\n";
      }
    }
    else
    {
      low[node] = min(low[node], tin[it]);
    }
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

  // time of insertion
  vector<int> tin(n, -1);

  // lowest time of insertion
  vector<int> low(n, -1);

  // visited
  vector<int> vis(m, 0);

  int timer = 0;
  for (int i = 1; i < n; i++)
  {
    if (!vis[i])
    {
      dfs(i, -1, timer, tin, low, vis, adj);
    }
  }

  return 0;
}