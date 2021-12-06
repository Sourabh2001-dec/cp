#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll n, k;
    cin >> n >> k;

    if (n - k == 0)
    {
      for (ll i = 1; i <= n; i++)
      {
        cout << i << " ";
      }
    }
    else if (n - k == 1)
    {
      cout << -1;
    }
    else
    {
      for (ll i = 1; i <= k; i++)
      {
        cout << i << " ";
      }
      cout << n << " ";
      for (ll i = k + 1; i < n; i++)
      {
        cout << i << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}