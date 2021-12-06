#include <bits/stdc++.h>
using namespace std;

int minSubsetDiff(vector<int> nums, int n)
{
  int range = 0;
  for (auto &&i : nums)
  {
    range += i;
  }

  int rows = n + 1;
  int cols = range + 1;
  vector<vector<bool>> dp(rows, vector<bool>(cols, false));

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (j == 0)
      {
        dp[i][j] = true;
        continue;
      }
      else if (i == 0)
      {
        continue;
      }
      else
      {
        if (nums[i - 1] <= j)
        {
          // choose
          dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
        }
        else
        {
          // reject
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
  }

  int minDiff = INT_MAX;
  for (int j = 0; j <= cols / 2; j++)
  {
    if (dp[rows - 1][j])
    {
      minDiff = min(minDiff, abs(range - 2 * j));
    }
  }

  return minDiff;
}

int main(int argc, char const *argv[])
{
  vector<int> nums = {9, 20, 6, 12};
  cout << minSubsetDiff(nums, nums.size());
  return 0;
}