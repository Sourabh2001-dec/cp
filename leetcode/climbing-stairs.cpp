#include <bits/stdc++.h>
using namespace std;

class Solution
{
  int maxWays(int stepsCount, vector<int> steps)
  {
    int cols = stepsCount + 1;
    int rows = steps.size() + 1;
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (j == 0)
        {
          dp[i][j] = 1;
        }
        else if (i != 0)
        {

          if (j >= steps[i - 1])
          {
            // choose
            dp[i][j] = dp[i - 1][j] + dp[i][j - steps[i - 1]];
            if (i > 2 && dp[i][j - steps[i - 1]] > 1)
            {
              dp[i][j]++;
            }
          }
          else
          {
            dp[i][j] = dp[i - 1][j];
          }
        }
      }
    }

    return dp[rows - 1][cols - 1];
  }

public:
  int climbStairs(int n)
  {
    vector<int> steps;
    for (int i = 0; i < n; i++)
    {
      steps.push_back(i + 1);
    }

    return this->maxWays(n, steps);
  }
};

int main(int argc, char const *argv[])
{
  Solution *sol = new Solution();
  cout << sol->climbStairs(7);
  return 0;
}
