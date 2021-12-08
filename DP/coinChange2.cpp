#include <bits/stdc++.h>
using namespace std;

// Coin change problem 2 : Find min number of coins required to get the sum

int coinChangeMin(vector<int> coins, int size, int sum)
{
  int rows = size + 1;
  int cols = sum + 1;
  vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX - 1));

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (j == 0)
      {
        dp[i][j] = 0;
      }
      else if (i == 1)
      {
        dp[i][j] = j % coins[i - 1] == 0 ? j / coins[i - 1] : INT_MAX - 1;
      }
      else if (i != 0)
      {
        if (coins[i - 1] <= j)
        {
          // choose
          dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
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
  vector<int> coins = {1, 2, 3, 4};
  int sum = 5;
  cout << coinChangeMin(coins, coins.size(), sum);
  return 0;
}
