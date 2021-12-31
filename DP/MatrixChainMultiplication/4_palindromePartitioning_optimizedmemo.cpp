#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo(5, vector<int>(5, -1));

bool isPalindrome(vector<string> arr, int i, int j)
{
  for (int k = i; k < i + ((j - i) / 2); k++)
  {
    if (arr[k] != arr[j - k - 1])
    {
      return false;
    }
  }
  return true;
}

int palindromPartitions(vector<string> str, int i, int j)
{

  if (i >= j)
    return 0;

  if (memo[i][j] != -1)
  {
    return memo[i][j];
  }

  if (isPalindrome(str, i, j))
    return memo[i][j] = 0;

  int ans = INT_MAX;
  for (int k = i; k < j; k++)
  {
    int left, right;

    if (memo[i][k] != -1)
    {
      left = memo[i][k];
    }
    else
    {
      left = palindromPartitions(str, i, k);
      memo[i][k] = left;
    }

    if (memo[k + 1][j] != -1)
    {
      right = memo[k + 1][j];
    }
    else
    {
      right = palindromPartitions(str, k + 1, j);
      memo[k + 1][j] = right;
    }

    int temp = 1 + left + right;
    ans = min(ans, temp);
  }
  cout << "i : " << i << " j : " << j << " ans : " << ans << endl;
  return memo[i][j] = ans;
}

int main(int argc, char const *argv[])
{
  vector<string> str = {"a", "k", "t", "i", "n"};
  cout << palindromPartitions(str, 0, str.size() - 1);
  return 0;
}
