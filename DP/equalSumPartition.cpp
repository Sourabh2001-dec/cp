// Find if equal sum partition exists

#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> nums, int sum, int size)
{
  vector<vector<int>> dp(size + 1, vector<int>(sum + 1, false));
  int rows = size + 1;
  int cols = sum + 1;
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
        if (nums[i - 1] <= sum)
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
  return dp[rows - 1][cols - 1];
}

bool equalSumPartition(vector<int> nums, int sum, int size)
{
  if (sum % 2 != 0)
  {
    return false;
  }
  else
  {
    return subsetSum(nums, sum / 2, size);
  }
}

int main(int argc, char const *argv[])
{
  /* code */
  vector<int> nos = {1, 5, 5, 4, 5};
  int sum = 0;
  for (int x : nos)
  {
    sum += x;
  }
  if (equalSumPartition(nos, sum, nos.size()))
  {
    cout << "Equal Subset";
  }
  else
  {
    cout << "NO equal subsets";
  }
  return 0;
}
