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

bool cmp(node a, node b)
{
  return a.wt < b.wt;
}

int findPar(int node, vector<int> &parent)
{
  if (node == parent[node])
    return node;

  return parent[node] = findPar(parent[node], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
  int parU = findPar(u, parent);
  int parV = findPar(v, parent);

  if (rank[parU] > rank[parV])
  {
    parent[parV] = parU;
  }
  else if (rank[parV] > rank[parU])
  {
    parent[parU] = parV;
  }
  else
  {
    rank[parU]++;
    parent[parV] = parU;
  }
}

int main()
{
  int N = 5, m = 6;
  vector<node> edges;
  edges.push_back(node(0, 1, 2));
  edges.push_back(node(0, 3, 6));
  edges.push_back(node(1, 0, 2));
  edges.push_back(node(1, 2, 3));
  edges.push_back(node(1, 3, 8));
  edges.push_back(node(1, 4, 5));
  edges.push_back(node(2, 1, 3));
  edges.push_back(node(2, 4, 7));
  edges.push_back(node(3, 0, 6));
  edges.push_back(node(3, 1, 8));
  edges.push_back(node(4, 1, 5));
  edges.push_back(node(4, 2, 7));
  sort(edges.begin(), edges.end(), cmp);

  vector<int> parent(N);
  vector<int> rank(N, 0);

  for (int i = 0; i < N; i++)
  {
    parent[i] = i;
  }

  vector<pair<int, int>> MST;
  int cost = 0;

  for (auto &i : edges)
  {
    if (findPar(i.u, parent) != findPar(i.v, parent))
    {
      MST.push_back({i.u, i.v});
      cost += i.wt;
      unionn(i.u, i.v, parent, rank);
    }
  }

  cout << "COST " << cost << "\n";
  for (auto i : MST)
  {
    cout << i.first << " -> " << i.second << "\n";
  }

  return 0;
}