#include <bits/stdc++.h>

using namespace std;

// here we maintain two arrays
// vis => to mark the node from where dfs is called
// dfsVis => to mark the nodes int the current dfs call
//          when there are branches this arr will unmark nodes from the prev branch and start marking for the next branch
//          so we can detect if the cycle is there in the current branch only

class Solution
{
private:
  bool checkCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis)
  {
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        if (checkCycle(it, adj, vis, dfsVis))
          return true;
      }
      else if (dfsVis[it])
        return true;
    }

    dfsVis[node] = 0;
    return false;
  }

public:
  bool isCyclic(int N, vector<int> adj[])
  {
    vector<int> visited(N, 0);
    vector<int> dfsVis(N, 0);

    for (int i = 0; i < N; i++)
    {
      if (!visited[i])
      {
        if (checkCycle(i, adj, visited, dfsVis))
          return true;
      }
    }

    return false;
  }
};

void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  // adj[v].push_back(u);
}

int main()
{

  int V = 6;

  vector<int> adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 0);
  addEdge(adj, 4, 1);

  Solution obj;
  if (obj.isCyclic(V, adj))
    cout << "Cycle Detected"
         << "\n";
  else
    cout << "No Cycle Detected";

  return 0;
}