// algo is used to find the strongly connected components in a directed graph
// we first do topo sort and then transpose of the graph (i.e revers direction of node)
// then we print the dfs of the components

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
  vis[node] = 1;
  for (auto &&i : adj[node])
  {
    if (!vis[i])
    {
      dfs(i, vis, adj, st);
    }
  }
  st.push(node);
}

void revDfs(int node, vector<int> adj[], vector<int> &vis )
{
  vis[node] = 1;
  cout << node << " ";
  for (auto &&i : adj[node])
  {
    if (!vis[i])
    {
      revDfs(i, adj, vis);
    }
  }
}

int main()
{
  int n = 6, m = 7;
  vector<int> adj[n + 1];
  adj[1].push_back(3);
  adj[2].push_back(1);
  adj[3].push_back(2);
  adj[3].push_back(5);
  adj[4].push_back(6);
  adj[5].push_back(4);
  adj[6].push_back(5);

  stack<int> st;
  vector<int> vis(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
      dfs(i, vis, adj, st);
  }

  vector<int> transpose[n + 1];
  for (int i = 1; i <= n; i++)
  {
    vis[i] = 0;
    for (auto &&it : adj[i])
    {
      transpose[it].push_back(i);
    }
  }

  while (!st.empty())
  {
    int top = st.top();
    st.pop();
    if (!vis[top])
    {
      cout << "SCC ";
      revDfs(top, transpose, vis);
      cout << "\n";
    }
  }

  return 0;
}