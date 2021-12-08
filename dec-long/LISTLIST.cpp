#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
  ll N;
  cin >> N;
  while (N--)
  {
    ll len;
    cin >> len;
    map<ll, ll> nums;
    for (ll i = 0; i < len; i++)
    {
      ll num;
      cin >> num;
      nums[num]++;
    }

    ll min = 0;
    map<ll, ll>::iterator itr;
    for (itr = nums.begin();
         itr != nums.end();
         ++itr)
    {
      if (itr->second > min)
      {
        min = itr->second;
      }
    }
    if (len == 1 || min == len)
    {
      cout << 0 << endl;
      continue;
    }
    if (min == 1)
    {
      cout << -1 << endl;
      continue;
    }
    cout << len - min + 1 << endl;
  }

  return 0;
}
