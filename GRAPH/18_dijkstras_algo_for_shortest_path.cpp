#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n = 5, m = 6, source = 1;
  vector<pair<int, int>> g[n + 1]; // assuming 1 based indexing of graph
  // Constructing the graph
  g[1].push_back({2, 2});
  g[1].push_back({4, 1});
  g[2].push_back({1, 2});
  g[2].push_back({5, 5});
  g[2].push_back({3, 4});
  g[3].push_back({2, 4});
  g[3].push_back({4, 3});
  g[3].push_back({5, 1});
  g[4].push_back({1, 1});
  g[4].push_back({3, 3});
  g[5].push_back({2, 5});
  g[5].push_back({3, 1});
  // Dijkstra's algorithm begins from here
  vector<int> dist(n + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[source] = 0;
  pq.push({0, source});
  while (!pq.empty())
  {
    auto elem = pq.top();
    int dis = elem.first;
    int node = elem.second;
    pq.pop();


    // if we have inserted the node with updated distance lesser then current element which may be already processed we can ignore current
    if (dist[node] >= dis)
    {
      for (auto &i : g[node])
      {
        if (dist[i.first] > (i.second + dis))
        {
          dist[i.first] = i.second + dis;
          pq.push({dist[i.first], i.first});
        }
      }
    }
  }
  for (int i = 1; i <= n; i++)
    cout << dist[i] << " ";
  return 0;
}