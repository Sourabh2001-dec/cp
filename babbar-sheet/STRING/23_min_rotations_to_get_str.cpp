// 23. Minimum	rotations	required	to	get	the	same	string.
// [Follow	here:	https://www.geeksforgeeks.org/minimum-rotations-required-get-string/ ]
#include <bits/stdc++.h>
using namespace std;

int minRotations(string input)
{
  for (int i = 0; i < input.length(); i++)
  {
    if ((input.substr(0, input.length() - 1 - i) + input.substr(0, i + 1)) == input)
    {
      return i + 1;
    }
  }

  return input.length();
}

int main(int argc, char const *argv[])
{
  string input;
  cin >> input;
  cout << minRotations(input);
  return 0;
}
