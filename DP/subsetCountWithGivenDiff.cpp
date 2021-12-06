#include <bits/stdc++.h>
using namespace std;

int subsetCountWithGivenDiff(vector<int> nums, int size, int diff)
{
  int rows = size + 1;
  int sum = 0;
  for (auto &&i : nums)
  {
    sum += i;
  }
  int cols = (diff + sum) / 2;
  vector<vector<int>> dp(rows, vector<int>(cols, 0));

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (j == 0)
      {
        dp[i][j] = 1;
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
          dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
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

int main(int argc, char const *argv[])
{
  vector<int> nos = {1, 1, 3, 2};
  int diff = 1;
  cout << subsetCountWithGivenDiff(nos, nos.size(), diff);
  return 0;
}
