#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
  ll N;
  ll a, b, c, d;
  cin >> N;
  while (N--)
  {
    cin >> a >> b >> c >> d;
    bool ans = (a * a * d * d * d) == (b * b * c * c * c);
    if (ans)
    {
      cout << "Yes\n";
    }
    else
    {
      cout << "No\n";
    }
  }

  return 0;
}
