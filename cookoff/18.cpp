#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
  ll t;
  cin >> t;
  ll N;
  ll num;

  while (t--)
  {
    ll min = -1;

    cin >> N;

    while (N--)
    {
      bool isOdd = 0;
      ll count = 0;
      cin >> num;
      if (num % 2 == 0 && num != 2)
      {

        while (!isOdd || num >= 0)
        {
          num = num / 2;
          count++;
          if (num % 2 != 0)
          {
            isOdd = 1;
            if (count < min || min == -1)
            {
              min = count;
            }
            break;
          }
        }
      }
    }

    min == -1 ? cout << 0 << "\n" : cout << min << "\n";
  }
  return 0;
}