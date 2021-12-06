#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll P, a, b, c, x, y;
    cin >> P >> a >> b >> c >> x >> y;
    ll max = 0;

    ll anarCost = b + (a * x);
    ll chakriCost = c + (a * y);
    bool run = 1;
    while (P >= 0)
    {
      ll noOfAnars = P / anarCost;
      ll noOfChakris = P / chakriCost;
      if (noOfChakris > noOfAnars && noOfChakris > 0)
      {
        if (P - (noOfChakris * chakriCost) >= 0)
        {
          P -= (noOfChakris * chakriCost);
          max += noOfChakris;
        }
        else
        {
          break;
        }
      }
      else
      {
        if (P - (noOfAnars * anarCost) >= 0 && noOfAnars > 0)
        {
          P -= (noOfAnars * anarCost);
          max += noOfAnars;
        }
        else
        {
          break;
        }
      }
    }

    cout << max << "\n";
  }
  return 0;
}