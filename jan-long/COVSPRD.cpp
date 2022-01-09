#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll a, ll b)
{
  return (ll)(pow((double)a, (double)b) + 1e-9);
}

int main(int argc, char const *argv[])
{
  ll N;
  ll population, days;
  cin >> N;
  while (N--)
  {
    cin >> population >> days;
    ll infected;

    if (days <= 10)
    {
      infected = power(2, days);
    }
    else
    {
      // greater than 10
      ll daysAfter10 = days - 10;
      infected = power(2, 10);

      while (daysAfter10 && infected <= population)
      {
        infected *= 3;
        daysAfter10--;
      }
    }

    if (infected > population)
    {
      infected = population;
    }

    cout << infected << "\n";
  }

  return 0;
}
