// 27.
// Number of flips to make binary string alternate
// [Practice here: https://practice.geeksforgeeks.org/problems/min-number-of-flips/0 ]

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int minFlips(string s);
int32_t main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;

    cout << minFlips(s) << endl;
  }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int minFlips(string S)
{
  int start0 = 0;
  int start1 = 0;

  bool isZero = true;
  bool isOne = true;

  for (char bin : S)
  {
    if (bin == '0')
    {
      if (!isZero)
      {
        start0++;
      }
      if (isOne)
      {
        start1++;
      }
    }
    else
    {
      if (isZero)
      {
        start0++;
      }
      if (!isOne)
      {
        start1++;
      }
    }
    isZero = !isZero;
    isOne = !isOne;
  }

  return min(start0, start1);
}