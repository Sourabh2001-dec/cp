#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long int
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
const ll MAX_SIZE = 10e6 + 1;
//=======================

vi g[N];
int a[N];

ll getCombo(ll targetSum, ll currentSum, ll faces, unordered_map<ll, ll> &dp)
{
  if (currentSum > targetSum)
    return 0;
  if (currentSum == targetSum)
    return 1;

  if (dp.find(currentSum) != dp.end())
  {
    return dp[currentSum];
  }

  ll combos = 0;
  for (ll i = 1; i <= faces; i++)
  {
    combos = (combos % mod + getCombo(targetSum, currentSum + i, faces, dp) % mod) % mod;
  }
  return dp[currentSum] = combos;
}

ll getcomboIter(ll targetSum, ll faces)
{
  vector<ll> dp(targetSum + 1, 0);
  dp[1] = 1;
  if (targetSum == 0 || targetSum == 1)
    return dp[targetSum];
  for (ll i = 2; i <= targetSum; i++)
  {
    ll res = 0;
    for (ll j = 1; j <= faces; j++)
    {
      if (i >= j)
      {
        res = (res % mod + dp[i - j] % mod) % mod;
      }
    }

    if (i <= faces)
    {
      res = (res % mod + 1 % mod) % mod;
    }

    dp[i] = res;
  }
  return dp[targetSum];
}

void solve()
{
  ll S, m;
  // unordered_map<ll, ll> dp;
  cin >> S >> m;
  cout << getcomboIter(S, m) << "\n";
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());

  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}

int mpow(int base, int exp)
{
  base %= mod;
  int result = 1;
  while (exp > 0)
  {
    if (exp & 1)
      result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m)
{
  int i, u, v;
  while (m--)
  {
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
}

void dfs(int u, int par)
{
  for (int v : g[u])
  {
    if (v == par)
      continue;
    dfs(v, u);
  }
}
