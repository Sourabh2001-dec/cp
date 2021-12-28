// two sequences are given then form a sequence with min length which contains both the sequences

#include <bits/stdc++.h>
#define vectStr vector<string>
#define vectInt vector<int>
using namespace std;

int shortestCommonSubseqLen(vectStr seq1, vectStr seq2, int len1, int len2)
{
  int rows = len1 + 1;
  int cols = len2 + 1;
  vector<vectInt> dp(rows, vectInt(cols, 0));

  for (int i = 1; i < rows; i++)
  {
    for (int j = 1; j < cols; j++)
    {
      if (seq1[i - 1] == seq2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // since the lcs is present in both the strings we exclude one of them from the length
  return len1 + len2 - dp[rows - 1][cols - 1];
}

int main(int argc, char const *argv[])
{
  vectStr seq1 = {"A", "G", "G", "T", "A", "B"};
  vectStr seq2 = {"G", "X", "T", "X", "A", "Y", "B"};
  cout << shortestCommonSubseqLen(seq1, seq2, seq1.size(), seq2.size());
  return 0;
}
