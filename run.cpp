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

ll solve(vector<ll> a, vector<ll> b)
{
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll x = 0, y = 0;
  vector<ll> o1, e1, o2, e2;
  // o1 => store odds from a
  // e1 => store evens from a
  // o2 => store odds form b
  // e2 => store evens from b


  // only odd can be converted to add by -2 or +2
  // and same goes for even

  ll n = a.size(), c = 0, d = 0;
  for (ll i = 0; i < n; i++)
  {
    if (a[i] % 2 == 1)
    {
      o1.push_back(a[i]);
      c++;
    }
    else
    {
      e1.push_back(a[i]);
    }
    if (b[i] % 2 == 1)
    {
      o2.push_back(b[i]);
      d++;
    }
    else
    {
      e2.push_back(b[i]);
    }
  }

  // if counts of odds from a != b
  if (c != d)
  {
    return -1;
  }

  // count +2s required and -2s required
  // for converting odd to odd and even to even
  
  for (ll i = 0; i < c; i++)
  {
    if (o1[i] > o2[i])
    {
      x += o1[i] - o2[i];
    }
    else if (o1[i] < o2[i])
    {
      y += o2[i] - o1[i];
    }
  }

  for (ll i = 0; i < n - c; i++)
  {
    if (e1[i] > e2[i])
    {
      x += e1[i] - e2[i];
    }
    else if (e1[i] < e2[i])
    {
      y += e2[i] - e1[i];
    }
  }

  // if not in same quantity
  if (x != y)
  {
    return -1;
  }

  // we have added all 2s so to get count /2
  return x / 2;
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());

  int t = 1;
  // cin >> t;
  while (t--)
  {
    vector<ll> a = {4, 9, 4};
    vector<ll> b = {11, 2, 4};

    cout << solve(a, b);
  }

  return 0;
}
