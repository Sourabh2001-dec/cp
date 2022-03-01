// 1. Write a Code to check whether one string is a rotation of another
// [Practice here: https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/ ]

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to check if two strings are rotations of each other or not.
  bool areRotations(string s1, string s2)
  {
    if (s1.length() != s2.length())
      return false;

    for (int i = 0; i < s2.size(); i++)
    {
      if (s2[i] == s1[0])
      {
        string part2 = s2.substr(i, s2.size() - i);
        string part1 = s2.substr(0, i);
        string combine = part2.append(part1);
        if (combine == s1)
        {
          return true;
        }
      }
    }

    return false;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s1;
    string s2;
    cin >> s1 >> s2;
    Solution obj;
    cout << obj.areRotations(s1, s2) << endl;
  }
  return 0;
}
// } Driver Code Ends