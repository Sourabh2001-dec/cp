// kahn's algorithm

#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
  void printTopoSort(int N, vector<int> adj[])
  {
    vector<int> indeg(N, 0);
    for (int i = 0; i < N; i++)
    {
      for (auto i : adj[i])
      {
        indeg[i]++;
      }
    }

    queue<int> q;

    vector<int> topo;

    for (int i = 0; i < N; i++)
    {
      if (indeg[i] == 0)
        q.push(i);
    }

    while (!q.empty())
    {
      int top = q.front();
      q.pop();
      topo.push_back(top);

      for (auto i : adj[top])
      {
        indeg[i]--;
        if (indeg[i] == 0)
          q.push(i);
      }
    }

    for (auto i : topo)
    {
      cout << i << " ";
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
  addEdge(adj, 5, 2);

  Solution obj;
  obj.printTopoSort(V, adj);

  return 0;
}