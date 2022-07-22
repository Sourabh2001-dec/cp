#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
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

typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#ifndef ONLINE_JUDGE
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
  cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
  cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
  cerr << "[ ";
  for (auto i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

void solve()
{
  ll n;
  cin >> n;

  vl a(n);
  fo(i, n)
  {
    cin >> a[i];
  }

  vl a1(all(a));
  vl a2(all(a));

  ll b1 = 0, b2 = 0;

  ll cool = 0;

  Fo(i, 1, n - 1)
  {
    if (i % 2)
    {
      if (a1[i - 1] >= a1[i] || a1[i + 1] >= a1[i])
      {
        ll bricks = abs(max(a1[i - 1], a1[i + 1]) + 1 - a1[i]);
        a1[i] += bricks;
        b1 += bricks;
      }
    }
  }

  Fo(i, 2, n - 1)
  {
    if (i % 2 == 0)
    {
      if (a2[i - 1] >= a2[i] || a2[i + 1] >= a2[i])
      {
        ll bricks = abs(max(a2[i - 1], a2[i + 1]) + 1 - a2[i]);
        a2[i] += bricks;
        b2 += bricks;
      }
    }
  }

  ll coolA = 0, coolB = 0;

  Fo(i, 1, n - 1)
  {
    if (a[i - 1] < a[i] && a[i + 1] < a[i])
    {
      cool++;
    }
    if (a1[i - 1] < a1[i] && a1[i + 1] < a1[i])
    {
      coolA++;
    }
    if (a2[i - 1] < a2[i] && a2[i + 1] < a2[i])
    {
      coolB++;
    }
  }

  // deb2(cool, coolA);
  // deb2(cool, coolB);

  if (max(coolA, coolB) <= cool)
  {
    cout << 0 << "\n";
    return;
  }

  cout << (coolA > coolB ? b1 : b2) << "\n";
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
