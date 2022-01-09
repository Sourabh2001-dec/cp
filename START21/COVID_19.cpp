#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
  int N;
  cin >> N;
  while (N--)
  {
    ll rows;
    ll seats;
    ll finalRows;
    ll finalSeats;

    cin >> rows >> seats;

    if (rows % 2 == 0)
    {
      finalRows = rows / 2;
    }
    else
    {
      finalRows = (rows + 1) / 2;
    }

    if (seats % 2 == 0)
    {
      finalSeats = seats / 2;
    }
    else
    {
      finalSeats = (seats + 1) / 2;
    }

    cout << finalRows * finalSeats << "\n";
  }

  return 0;
}
