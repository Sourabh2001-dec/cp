#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
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

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

ll offset;

bool f(int i, int j, int sum, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp)
{

  int prevSum = sum;

  if (prevSum == -1e9)
    prevSum = 0;

  if (i == 0 && j == 0)
    return ((prevSum + arr[i][j]) == 0);
  if (i < 0 || j < 0)
    return false;

  if (dp[i][j][prevSum + offset] != -1)
    return dp[i][j][prevSum + offset];

  prevSum += arr[i][j];

  bool left = f(i, j - 1, prevSum, arr, dp);
  if (left)
    return dp[i][j][sum + offset] = true;

  bool up = f(i - 1, j, prevSum, arr, dp);
  if (up)
    return dp[i][j][sum + offset] = true;

  return dp[i][j][sum + offset] = false;
}

void solve()
{
  ll n, m, i, j;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m, 0));

  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2 * (m + n - 1) + 1, -1)));

  fo(i, n)
  {
    fo(j, m)
    {
      cin >> arr[i][j];
    }
  }

  offset = m + n - 1;

  // deb(offset);

  if (f(n - 1, m - 1, -1e9, arr, dp))
  {
    cout << "YES\n";
  }
  else
  {
    cout << "NO\n";
  }
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
