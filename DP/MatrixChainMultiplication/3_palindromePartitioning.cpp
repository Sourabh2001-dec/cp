#include <bits/stdc++.h>
using namespace std;

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

  if (isPalindrome(str, i, j))
    return 0;

  int ans = INT_MAX;
  for (int k = i; k < j; k++)
  {
    int temp = 1 + palindromPartitions(str, i, k) + palindromPartitions(str, k + 1, j);
    ans = min(ans, temp);
  }
  cout << "i : " << i << " j : " << j << " ans : " << ans << endl;
  return ans;
}

int main(int argc, char const *argv[])
{
  vector<string> str = {"a", "k", "t", "i", "n"};
  cout << palindromPartitions(str, 0, str.size() - 1);
  return 0;
}
