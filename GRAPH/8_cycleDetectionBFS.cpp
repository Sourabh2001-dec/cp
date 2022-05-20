// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  bool checkCycle(int s, vector<int> &visited, vector<int> adj[])
  {
    queue<pair<int, int>> q;
    q.push({s, -1});
    visited[s] = 1;

    while (!q.empty())
    {
      int node = q.front().first;
      int par = q.front().second;

      for (int &i : adj[node])
      {
        if (!visited[i])
        {
          visited[i] = 1;
          q.push({i, node});
        }
        // if the node is already visited and not the parent of the current node then we have detected a cycle
        else if (i != par)
          return true;
      }
    }

    return false;
  }
  // Function to detect cycle in an undirected graph.
  bool isCycle(int V, vector<int> adj[])
  {
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        if (checkCycle(i, visited, adj))
          return true;
      }
    }
    return false;
  }
};

// { Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    if (ans)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
} // } Driver Code Ends