// shortest path in undirected graph with unit weights

#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
  void printShortDist(int N, vector<int> adj[])
  {
    vector<int> dist(N, INT_MAX);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty())
    {
      int elem = q.front();
      q.pop();

      for (auto it : adj[elem])
      {
        if (dist[it] > (dist[elem] + 1))
        {
          dist[it] = dist[elem] + 1;
          q.push(it);
        }
      }
    }

    for (int i = 0; i < N; i++)
    {
      cout << i << " " << dist[i] << "\n";
    }
  }
};

void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main()
{

  int V = 9;

  vector<int> adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 5);
  addEdge(adj, 5, 6);
  addEdge(adj, 2, 6);
  addEdge(adj, 6, 7);
  addEdge(adj, 6, 8);
  addEdge(adj, 7, 8);

  Solution obj;
  obj.printShortDist(V, adj);

  return 0;
}