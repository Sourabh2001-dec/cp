// 15. EDIT Distance [Very Imp]
// [Practice here: https://practice.geeksforgeeks.org/problems/edit-distance/0 ]
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  int helper(int i, int j, string s, string t, vector<vector<int>> &dp)
  {
    if (i == s.size())
      return (t.size() - j);
    if (j == t.size())
      return (s.size() - i);

    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }

    if (s[i] == t[j])
    {
      return dp[i][j] = helper(i + 1, j + 1, s, t, dp);
    }
    else
    {
      // insert
      int left = 1 + helper(i, j + 1, s, t, dp);
      // remove
      int mid = 1 + helper(i + 1, j, s, t, dp);
      // update
      int right = 1 + helper(i + 1, j + 1, s, t, dp);

      return dp[i][j] = min(left, min(mid, right));
    }
  }

  int editDistance(string s, string t)
  {
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));

    return helper(0, 0, s, t, dp);
  }
};

// { Driver Code Starts.
int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    string s, t;
    cin >> s >> t;
    Solution ob;
    int ans = ob.editDistance(s, t);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends