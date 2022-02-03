#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
  ll N;
  ll total, infected;
  cin >> N;
  while (N--)
  {
    cin >> total >> infected;

    if (total == 0 || infected == 0)
    {
      cout << total;
    }
    else if (infected == total)
    {
      cout << (infected * 2) - 1;
    }
    else
    {
      cout << ((infected * 2) + (total - infected));
    }
    cout << "\n";
  }

  return 0;
}
