#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll power(ll num, ll pow)
{
  ll times = pow;
  ll result = num;
  while (times > 0)
  {
    result = result * result;
    times--;
  }
  return result;
}

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll a, b;
    cin >> a >> b;
    ll lastRemainder;
    ll y = 1;
    bool run = 1;
    bool isTrue = 0;
    ll currRemainder;
    while (run)
    {
      if (b >= a)
      {
        currRemainder = power(b, y) % a;
      }
      else
      {
        currRemainder = (a * y) % b;
      }

      if (currRemainder >= lastRemainder)
      {
        cout << "NO\n";
        break;
      }

      if (currRemainder == 0)
      {
        cout << "YES\n";
        break;
      }
      else
      {
        lastRemainder = currRemainder;
        y++;
      }
    }
  }
  return 0;
}