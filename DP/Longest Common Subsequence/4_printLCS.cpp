#include <bits/stdc++.h>
using namespace std;

// we choose max of diagonal bcoz we get rid of one of the values

string printLCS(vector<string> str1, vector<string> str2, int len1, int len2)
{
  int rows = len1 + 1;
  int cols = len2 + 1;
  vector<vector<int>> dp(rows, vector<int>(cols, 0));

  for (int i = 1; i < rows; i++)
  {
    for (int j = 1; j < cols; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
      }
    }
  }

  string result = "";

  int i = rows - 1;
  int j = cols - 1;

  while (dp[i][j] != 0)
  {
    if (str1[i - 1] == str2[j - 1])
    {
      result = str1[i - 1] + result;
      i--;
      j--;
    }
    else
    {
      if (dp[i - 1][j] >= dp[i][j - 1])
      {
        i--;
      }
      else
      {
        j--;
      }
    }
  }

  return result;
}

int main(int argc, char const *argv[])
{
  vector<string> str1 = {"a", "b", "c", "d", "e"};
  vector<string> str2 = {"a", "d", "c", "e"};
  cout << printLCS(str1, str2, str1.size(), str2.size());
  return 0;
}
