#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve()
{
  int a;
  cin >> a;

  if (a % 2)
  {
    cout << "YES\n";
    return;
  }

  while (a % 2 == 0)
    a /= 2;

  if (a > 1)
  {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
}

signed main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}