#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll N, P, X, Y;
    cin >> N >> P >> X >> Y;
    int time = 0;
    for (int i = 0; i < N; i++)
    {
      int pers;
      cin >> pers;
      if (i < P)
      {
        if (pers)
        {
          time += Y;
        }
        else
        {
          time += X;
        }
      }
    }
    cout << time << "\n";
  }
  return 0;
}