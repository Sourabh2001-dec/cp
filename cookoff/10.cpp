#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll M, N, K;
    cin >> M >> N >> K;
    if ((N * K - M) >= 0)
    {
      cout << "NO\n";
    }
    else
    {
      cout << "YES\n";
    }
  }
  return 0;
}