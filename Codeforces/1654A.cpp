#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    vector<ll> arr;
    ll len;
    cin >> len;
    for (ll i = 0; i < len; i++)
    {
      ll input;
      cin >> input;
      arr.push_back(input);
    }

    ll left = INT_MIN, curr = INT_MIN, right = INT_MIN;

    for (ll i = 0; i < len; i++)
    {
      if (arr[i] >= curr)
      {
        left = curr;
        curr = arr[i];
      }
      else if (arr[i] >= right)
      {
        right = arr[i];
      }
    }

    cout << max(left + curr, curr + right) << "\n";
  }
  return 0;
}