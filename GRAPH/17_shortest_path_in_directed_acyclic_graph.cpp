// shortest path in undirected graph with unit weights

#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
  void dfsTopo(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
  {
    if (vis[node])
      return;

    vis[node] = 1;

    for (auto it : adj[node])
    {
      if (!vis[it.first])
      {
        dfsTopo(it.first, adj, vis, st);
      }
    }

    st.push(node);
  }

  void printShortDist(int N, vector<pair<int, int>> adj[])
  {
    vector<int> vis(N, 0);
    stack<int> st;

    for (int i = 0; i < N; i++)
    {
      if (!vis[i])
      {
        dfsTopo(i, adj, vis, st);
      }
    }

    vector<int> dist(N, INT_MAX);

    dist[0] = 0;

    while (!st.empty())
    {
      int node = st.top();
      st.pop();

      for (auto it : adj[node])
      {
        if (dist[it.first] > (dist[node] + it.second))
        {
          dist[it.first] = dist[node] + it.second;
        }
      }
    }

    for (int i = 0; i < N; i++)
    {
      cout << i << " " << dist[i] << "\n";
    }
  }
};

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
  adj[u].push_back({v, wt});
  // adj[v].push_back(u);
}

int main()
{

  int V = 6;

  vector<pair<int, int>> adj[V];
  addEdge(adj, 0, 1, 2);
  addEdge(adj, 0, 4, 1);
  addEdge(adj, 1, 2, 3);
  addEdge(adj, 2, 3, 6);
  addEdge(adj, 4, 2, 2);
  addEdge(adj, 4, 5, 4);
  addEdge(adj, 5, 3, 1);

  Solution obj;
  obj.printShortDist(V, adj);

  return 0;
}