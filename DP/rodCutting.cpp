#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> lengths, vector<int> prices, int size, int N)
{
  int rows = size + 1;
  int cols = N + 1;
  vector<vector<int>> dp(rows, vector<int>(cols, 0));

  for (int i = 1; i < rows; i++)
  {
    for (int j = 1; j < cols; j++)
    {
      if (lengths[i - 1] <= j)
      {
        // choose
        dp[i][j] = max(prices[i - 1] + dp[i][j - lengths[i - 1]], dp[i - 1][j]);
      }
      else
      {
        // reject
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[rows - 1][cols - 1];
}

int main(int argc, char const *argv[])
{
  vector<int> lengths = {1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
  int N = 8;
  cout << maxProfit(lengths, prices, lengths.size(), N);
  return 0;
}
