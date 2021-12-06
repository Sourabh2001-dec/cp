// find count of subsets with given sum
#include <bits/stdc++.h>
using namespace std;

int subsetCount(vector<int> nums, int sum)
{
  vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, 0));
  int rows = nums.size() + 1;
  int cols = sum + 1;
  for (int n = 0; n < rows; n++)
  {
    for (int s = 0; s < cols; s++)
    {
      if (s == 0)
      {
        dp[n][s] = 1;
        continue;
      }
      else if (n == 0)
      {
        continue;
      }
      else
      {
        if (nums[n - 1] <= s)
        {
          // choose
          dp[n][s] = dp[n - 1][s - nums[n - 1]] + dp[n - 1][s];
        }
        else
        {
          // reject
          dp[n][s] = dp[n - 1][s];
        }
      }
    }
  }
  return dp[rows - 1][cols - 1];
}

int main(int argc, char const *argv[])
{
  vector<int> nums = {2, 3, 7, 8, 10, 4};
  int sum = 12;
  cout << subsetCount(nums, sum);
  return 0;
}
