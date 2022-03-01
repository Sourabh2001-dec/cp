// 12.
// Find the longest common subsequence between two strings.
// [Practice here: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0 ]

// { Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
  // Function to find the length of longest common subsequence in two strings.
  int lcs(int x, int y, string s1, string s2)
  {
    int rows = x + 1;
    int cols = y + 1;
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int i = 1; i < rows; i++)
    {
      for (int j = 1; j < cols; j++)
      {
        if (s1[i - 1] == s2[j - 1])
        {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }

    return dp[rows - 1][cols - 1];
  }
};

// { Driver Code Starts.
int main()
{
  int t, n, k, x, y;
  cin >> t;
  while (t--)
  {
    cin >> x >> y; // Take size of both the strings as input
    string s1, s2;
    cin >> s1 >> s2; // Take both the string as input
    Solution ob;
    cout << ob.lcs(x, y, s1, s2) << endl;
  }
  return 0;
}
// } Driver Code Ends