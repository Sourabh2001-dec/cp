#include <bits/stdc++.h>
using namespace std;

int LCS(vector<string> seq1, vector<string> seq2, int size1, int size2)
{
  int rows = size1 + 1;
  int cols = size2 + 1;

  vector<vector<int>> dp(rows, vector<int>(cols, 0));

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
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[rows - 1][cols - 1];
}

int main(int argc, char const *argv[])
{
  // pattern to match
  vector<string> seq1 = {"a", "b", "e"};

  vector<string> seq2 = {"a", "b", "c", "e", "f"};

  cout << ((LCS(seq1, seq2, seq1.size(), seq2.size()) - seq1.size() == 0) ? "Pattern match" : "Pattern does not match");
  return 0;
}
