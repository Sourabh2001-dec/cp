#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
  void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
  {
    vis[node] = 1;

    for (auto &i : adj[node])
    {
      if (!vis[i])
      {
        dfs(i, adj, vis, st);
      }
    }

    st.push(node);
  }

public:
  void printTopoSort(int N, vector<int> adj[])
  {
    vector<int> vis(N, 0);
    stack<int> st;

    for (int i = 0; i < N; i++)
    {
      if (!vis[i])
      {
        dfs(i, adj, vis, st);
      }
    }

    while (!st.empty())
    {
      cout << st.top() << " ";
      st.pop();
    }
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
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 1);
  addEdge(adj, 4, 0);
  addEdge(adj, 4, 1);
  addEdge(adj, 5, 0);

  Solution obj;
  obj.printTopoSort(V, adj);

  return 0;
}