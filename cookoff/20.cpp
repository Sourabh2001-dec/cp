#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll A;
    cin >> A;
    if (A < 100)
    {
      cout << "Easy\n";
    }
    else if (A < 200)
    {
      cout << "Medium\n";
    }
    else
    {
      cout << "Hard\n";
    }
  }
  return 0;
}