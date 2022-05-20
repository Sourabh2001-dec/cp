#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int len;
  cin >> len;

  int loops = len;

  while (loops--)
  {
    string input;
    cin >> input;
    if (input.length() > 10)
    {
      cout << input[0];
      cout << input.length() - 2;
      cout << input[input.length() - 1];
    }
    else
    {
      cout << input;
    }
    cout << "\n";
  }

  return 0;
}
