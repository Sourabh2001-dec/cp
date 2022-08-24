//========================================================================================
/*                                                                                      *
 *                            LONGEST INCREASING SUBSEQUENCE                            *
 *                                                                                      */
//========================================================================================

#include <bits/stdc++.h>

int maxLen(int i, int lastChosen, int arr[], int n, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;

    if (dp[i][lastChosen + 1] != -1)
        return dp[i][lastChosen + 1];

    int notpick = maxLen(i + 1, lastChosen, arr, n, dp);

    int pick = 0;
    if (lastChosen == -1 or arr[i] > arr[lastChosen])
    {
        pick = 1 + maxLen(i + 1, i, arr, n, dp);
    }

    return dp[i][lastChosen + 1] = max(pick, notpick);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return maxLen(0, -1, arr, n, dp);
}

//========================================================================================
/*                                                                                      *
 *                                LIS USING BINARY SEARCH                               *
 *                                                                                      */
//========================================================================================
// This method only gives length of LIS
int lengthOfLIS(vector<int> &nums)
{
    vector<int> temp;
    temp.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }

    return temp.size();
}

//========================================================================================
/*                                                                                      *
 *                               LONGEST COMMON SUBSTRING                               *
 *                                                                                      */
//========================================================================================
int lcs(string &s1, string &s2)
{

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                int val = 1 + dp[i - 1][j - 1];
                dp[i][j] = val;
                ans = max(ans, val);
            }
            else
                dp[i][j] = 0;
        }
    }

    return ans;
}

//========================================================================================
/*                                                                                      *
 *                              LONGEST COMMON SUBSEQUENCE                              *
 *                                                                                      */
//========================================================================================

int f(string a, string b, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (a[m - 1] == b[n - 1])
    {
        return dp[m][n] = 1 + f(a, b, m - 1, n - 1, dp);
    }
    else
    {
        return dp[m][n] = max(f(a, b, m - 1, n, dp), f(a, b, m, n - 1, dp));
    }
}

int lcs(string s, string t)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));
    return f(s, t, s.length(), t.length(), dp);
}