#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
  int N;
  cin >> N;
  while (N--)
  {
    ll Z;
    ll Y;
    ll A;
    ll B;
    ll C;
    cin >> Z >> Y >> A >> B >> C;
    if (((Z - Y) % (A + B + C)) == (Z - Y))
    {
      cout << "NO" << endl;
    }
    else
    {
      cout << "YES" << endl;
    }
  }

  return 0;
}
