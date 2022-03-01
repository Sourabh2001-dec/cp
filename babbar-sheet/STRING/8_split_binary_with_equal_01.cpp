// 8. Split the Binary string into two substring with equal 0’s and 1’s.
// [Follow here: https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/ ]

#include <bits/stdc++.h>
using namespace std;

int maxCount(string s)
{
  int count0 = 0;
  int count1 = 0;
  int result = 0;

  for (char i : s)
  {
    if (i == '0')
    {
      count0++;
    }
    else
    {
      count1++;
    }

    if (count0 == count1)
    {
      result++;
    }
  }

  if (!result)
    return -1;

  return result;
}

int main(int argc, char const *argv[])
{
  string input = "0111100010";
  cout << maxCount(input);
  return 0;
}
