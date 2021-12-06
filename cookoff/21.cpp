#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll A, B, P, Q;
    cin >> A >> B >> P >> Q;

    if (P < A || Q < B)
    {
      cout << "NO\n";
      continue;
    }

    ll diff1 = (P / A) - (Q / B);

    if (diff1 == 1 || diff1 == -1 || diff1 == 0)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }
  return 0;
}