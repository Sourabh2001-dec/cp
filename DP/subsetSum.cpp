#include <bits/stdc++.h>
using namespace std;

bool hasSubset(vector<int> nums, int sum)
{
  vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));
  int rows = nums.size() + 1;
  int cols = sum + 1;
  for (int n = 0; n < rows; n++)
  {
    for (int s = 0; s < cols; s++)
    {
      if (s == 0)
      {
        dp[n][s] = true;
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
          dp[n][s] = dp[n - 1][s - nums[n - 1]] || dp[n - 1][s];
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
  vector<int> nums = {2, 3, 7, 8, 10};
  int sum = 12;
  if (hasSubset(nums, sum))
  {
    cout << "has Subset";
  }
  else
  {
    cout << "does not have subset";
  };
  return 0;
}
