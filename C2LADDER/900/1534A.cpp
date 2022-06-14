#include <bits/stdc++.h>
#define int long long int
using namespace std;

// i bet "a" dollar
// ronnie bet b
// excitement gcd(a,b)

// ops +1 both or -1 both if a,b > 0
// max excitement and min moves

void solve()
{
  int a, b;
  cin >> a >> b;
  int exc = abs(a - b);
  int moves = 0;

  if (exc)
  {
    int maxNum = max(a, b);
    int q = maxNum / exc;
    int r = maxNum % exc;

    int sm = maxNum - exc * q;
    int lg = exc * (q + 1) - maxNum;

    moves = min(sm, lg);
  }

  cout << exc << " " << moves << "\n";
}

signed main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}