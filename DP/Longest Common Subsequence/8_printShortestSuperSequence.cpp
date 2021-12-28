#include <bits/stdc++.h>
using namespace std;

void printShortestSuperseq(vector<string> seq1, vector<string> seq2, int size1, int size2)
{
  int rows = size2 + 1;
  int cols = size1 + 1;
  vector<vector<int>> dp(rows, vector<int>(cols, 0));

  for (int i = 1; i < rows; i++)
  {
    for (int j = 1; j < cols; j++)
    {
      if (seq2[i - 1] == seq1[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }

  int i = rows - 1;
  int j = cols - 1;
  string result = "";
  while (i >= 0 && j >= 0)
  {
    if (seq2[i - 1] == seq1[j - 1])
    {
      result = seq2[i - 1] + result;
      i--;
      j--;
    }
    else
    {
      if (dp[i - 1][j] >= dp[i][j - 1])
      {
        result = seq2[i - 1] + result;
        i--;
      }
      else
      {
        result = seq1[j - 1] + result;
        j--;
      }
    }
  }
  cout << result;
}

int main(int argc, char const *argv[])
{
  vector<string> str1 = {"a", "c", "b", "c", "f"};
  vector<string> str2 = {"a", "b", "c", "d", "a", "f"};
  printShortestSuperseq(str1, str2, str1.size(), str2.size());
  return 0;
}
