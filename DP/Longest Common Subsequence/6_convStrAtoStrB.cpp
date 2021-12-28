// find min number of insertion and deletions required to convert string A to string B
#include <bits/stdc++.h>
#define vectInt vector<int>
#define vectStr vector<string>
using namespace std;

void minInsertAndDel(vectStr seq1, vectStr seq2, int len1, int len2)
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

  cout << "Insertions : " << len2 - dp[rows - 1][cols - 1] << endl;
  cout << "Deletions : " << len1 - dp[rows - 1][cols - 1];
}

int main(int argc, char const *argv[])
{
  vectStr seq1 = {"H", "E", "A", "P"};
  vectStr seq2 = {"P", "E", "A"};
  minInsertAndDel(seq1, seq2, seq1.size(), seq2.size());
  return 0;
}
