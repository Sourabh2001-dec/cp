#include <bits/stdc++.h>
#define int long long int
#define debug cout << "K"
#define mod 1000000007

using namespace std;

vector<int> a(300001);
vector<int> adj[300001];
bool visited[300001];
vector<int> subtree(300001, 0);
int ans = 0;

void dfs(int node)
{
  visited[node] = true;
  for (int next : adj[node])
  {
    if (!visited[next])
    {
      dfs(next);
      subtree[node] = __gcd(subtree[node], subtree[next]);
    }
  }
}

void nfs(int node, int above)
{
  visited[node] = true;
  int sum = 0;
  for (int next : adj[node])
  {
    if (!visited[next])
      sum += subtree[next];
  }
  ans = max(ans, above + sum);
  for (int next : adj[node])
  {
    if (!visited[next])
    {
      nfs(next, above + sum - subtree[next]);
    }
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t > 0)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      subtree[i + 1] = a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
      visited[i] = false;
    nfs(1, 0);
    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
    {
      adj[i].clear();
      visited[i] = false;
      subtree[i] = 0;
      a[i] = 0;
    }
    ans = 0;
    t--;
  }
  return 0;
}