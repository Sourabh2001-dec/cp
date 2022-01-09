#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
  ll N;
  ll n, diff;
  cin >> N;
  while (N--)
  {
    cin >> n >> diff;
    for (int i = 1; i <= n - 1; i++)
    {
      cout << i << " ";
    }
    cout << (((n) * (n - 1)) / 2) + diff << endl;
  }

  return 0;
}
