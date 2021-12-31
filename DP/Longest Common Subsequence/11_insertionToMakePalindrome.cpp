// same as deletions to make palindrome or the longest palindrom prblem
#include <bits/stdc++.h>
using namespace std;

// the second string will be the recverse of the first string

int Insertions(vector<string> seq1, vector<string> seq2, int size1, int size2)
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

  return size1 - dp[rows - 1][cols - 1];
}

int main(int argc, char const *argv[])
{
  vector<string> seq1 = {"a", "b", "d", "c", "b", "g"};
  vector<string> seq2 = seq1;
  reverse(seq2.begin(), seq2.end());
  cout << Insertions(seq1, seq2, seq1.size(), seq2.size());
  return 0;
}
