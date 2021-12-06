#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    string Doors;
    cin >> Doors;
    char searchFor = '0';
    ll wands = 0;

    for (ll i = 0; i < Doors.size(); i++)
    {
      if (Doors[i] == searchFor)
      {
        wands++;
        if (searchFor == '0')
        {
          searchFor = '1';
        }
        else
        {
          searchFor = '0';
        }
      }
    }
    cout << wands << "\n";
  }
  return 0;
}