// in this algo we do relaxation of edges for n-1 times
// relaxation means
// for point u,v and weight wt
// if(dist[u] + wt < dist[v]){
//   dist[v] = dist[u] + wt
// }

#include <bits/stdc++.h>
using namespace std;
struct node
{
  int u;
  int v;
  int wt;
  node(int first, int second, int weight)
  {
    u = first;
    v = second;
    wt = weight;
  }
};

int main()
{
  int N = 6, m = 7;
  vector<node> edges;
  edges.push_back(node(0, 1, 5));
  edges.push_back(node(1, 2, -2));
  edges.push_back(node(1, 5, -3));
  edges.push_back(node(2, 4, 3));
  edges.push_back(node(3, 2, 6));
  edges.push_back(node(3, 4, -2));
  edges.push_back(node(5, 3, 1));

  int inf = 10e6;
  vector<int> dist(N, inf);
  dist[0] = 0;

  for (int i = 0; i < N - 1; i++)
  {
    for (auto &&edge : edges)
    {
      if ((dist[edge.u] + edge.wt) < dist[edge.v])
      {
        dist[edge.v] = dist[edge.u] + edge.wt;
      }
    }
  }

  bool negCycle = 0;
  for (auto &&edge : edges)
  {
    if ((dist[edge.u] + edge.wt) < dist[edge.v])
    {
      cout << "negative cycle found\n";
      negCycle = 1;
      break;
    }
  }

  if (!negCycle)
  {
    for (int i = 0; i < N; i++)
    {
      cout << i << " -> " << dist[i] << "\n";
    }
  }
  return 0;
}