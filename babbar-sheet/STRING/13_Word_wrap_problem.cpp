// 13.Word Wrap Problem [VERY IMP].
// [Practice here: https://practice.geeksforgeeks.org/problems/word-wrap/0 ]
// Not solved

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  int solveWordWrap(vector<int> nums, int k)
  {
    int n = nums.size();
    int i, j;
    int currlen;
    int cost;
    vector<int> dp(n, 0);
    vector<int> ans(n, 0);
    dp[n - 1] = 0;
    ans[n - 1] = n - 1;
    for (i = n - 2; i >= 0; i--)
    {
      currlen = -1;
      dp[i] = INT_MAX;
      for (j = i; j < n; j++)
      {
        currlen += (nums[j] + 1);
        if (currlen > k)
          break;
        if (j == n - 1)
          cost = 0;
        else
          cost = (k - currlen) * (k - currlen) + dp[j + 1];
        if (cost < dp[i])
        {
          dp[i] = cost;
          ans[i] = j;
        }
      }
    }
    int res = 0;
    i = 0;
    while (i < n)
    {
      int pos = 0;
      for (int j = i; j < ans[i] + 1; j++)
      {
        pos += nums[j];
      }
      int x = ans[i] - i;
      if (ans[i] + 1 != nums.size())
        res += (k - x - pos) * (k - x - pos);
      i = ans[i] + 1;
    }
    return res;
  }
};

// { Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    cin >> k;
    Solution obj;
    cout << obj.solveWordWrap(nums, k) << endl;
  }
  return 0;
} // } Driver Code Ends