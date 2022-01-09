#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
  ll N;
  ll nums, riffles;
  vector<ll> digits;
  cin >> N;
  while (N--)
  {
    cin >> nums >> riffles;
    digits.clear();
    ll repeatAfter = (nums - 2);
    ll numOfRiffles = (repeatAfter > 1 && riffles > repeatAfter) ? (riffles % repeatAfter) : riffles;
    for (ll i = 1; i <= nums; i++)
    {
      // cout << "i " << i << endl;
      digits.push_back(i);
    }

    for (ll i = 0; i < numOfRiffles; i++)
    {
      for (ll j = 1; j <= nums / 2; j++)
      {
        digits.push_back(digits[j]);
        auto ite = digits.begin() + j;
        digits.erase(ite);
      }

      // cout << "riffle " << i;
      // for (auto it = digits.begin(); it != digits.end(); ++it)
      //   cout << ' ' << *it;
      // cout << endl;
    }
    auto it = digits.begin();
    cout << *it;
    for (it = it + 1; it != digits.end(); ++it)
      cout << ' ' << *it;

    cout << endl;
  }

  return 0;
}
