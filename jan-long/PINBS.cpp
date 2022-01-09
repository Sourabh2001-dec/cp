#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool solve(string binary)
{
  if (binary.length() == 1 || (binary.length() == 2 && binary[0] != '1'))
  {
    return false;
  }
  for (int i = 0; i < binary.length() - 1; i++)
  {
    if (binary.substr(i, 1) == "1")
    {
      return true;
    }
  }
  return false;
}

int main(int argc, char const *argv[])
{
  ll N;
  string binaryString;
  cin >> N;
  while (N--)
  {
    cin >> binaryString;

    if (solve(binaryString))
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }

  return 0;
}
