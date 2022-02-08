#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
  ll t;
  cin >> t;
  ll N = 0;
  string str;
  ll goodness;
  ll len;
  while (N++ != t)
  {
    cin >> len;
    cin >> goodness;
    cin >> str;
    ll left = 0;
    ll right = len - 1;
    ll score = 0;
    while (left < right)
    {
      if (str[left++] != str[right--])
      {
        score++;
      }
    }
    cout << "Case #" << N << ": " << abs(goodness - score) << "\n";
  }
  return 0;
}