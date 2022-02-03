#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
  ll N;
  ll X;
  cin >> N;
  while (N--)
  {
    int a, b, c, x;
    cin >> x;
    int y = 0, count = 0;

    while (y < x)
    {
      y += pow(2, count);
      count++;
    }
    count++;
    y = x + (pow(2, count));
    cout << x << " " << 0 << " " << y << "\n";
  }

  return 0;
}
