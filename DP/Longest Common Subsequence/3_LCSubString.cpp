#include <bits/stdc++.h>
using namespace std;

int LCS(vector<string> seq1, vector<string> seq2, int size1, int size2)
{
  int rows = size1 + 1;
  int cols = size2 + 1;

  vector<vector<int>> dp(rows, vector<int>(cols, 0));

  int max = -1;

  for (int i = 1; i < rows; i++)
  {
    for (int j = 1; j < cols; j++)
    {
      if (seq1[i - 1] == seq2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = 0;
      }

      if (dp[i][j] > max)
      {
        max = dp[i][j];
      }
    }
  }

  return max;
}

int main(int argc, char const *argv[])
{
  vector<string> seq1 = {"a", "b", "c", "e", "g"};
  vector<string> seq2 = {"a", "b", "d", "e", "f"};
  cout << LCS(seq1, seq2, seq1.size(), seq2.size());
  return 0;
}
