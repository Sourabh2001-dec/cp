// 4. Write a program to find the longest Palindrome in a string.[ Lonest
// palindromic Substring]
// [Practice here: https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0 ]

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  string longestPalin(string S)
  {
    string result = "";
    for (int i = 0; i < S.length(); i++)
    {
      string temp;
      int left = i;
      int right = i;

      while (left - 1 >= 0 && S[left - 1] == S[left])
      {
        left--;
      }

      while (right + 1 < S.length() && S[right + 1] == S[right])
      {
        right++;
      }

      while (left >= 0 && right < S.length() && S[left] == S[right])
      {
        left--;
        right++;
      }

      left++;
      right--;

      temp = S.substr(left, right - left + 1);
      if (temp.length() > result.length())
      {
        result = temp;
      }
    }

    return result;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string S;
    cin >> S;

    Solution ob;
    cout << ob.longestPalin(S) << endl;
  }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends