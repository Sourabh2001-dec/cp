#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
  int N;
  cin >> N;
  while (N--)
  {
    ll n, i, j;
    cin >> n >> i >> j;

    if ((i + j) % 2 == 0)
    {
      cout << 0 << "\n";
    }
    else
    {
      cout << 1 << "\n";
    }
  }

  return 0;
}
