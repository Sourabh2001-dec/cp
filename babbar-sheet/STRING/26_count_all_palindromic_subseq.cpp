// 26.
// Count All Palindromic Subsequence in a given String.
// [Practice here: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1 ]
// https://youtu.be/YHSjvswCXC8

// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // void helper(int i, string str, long long int &count, string temp)
  // {
  //   if (i == str.length())
  //   {
  //     if (temp.length() == 0)
  //       return;
  //     string rev = temp;
  //     reverse(rev.begin(), rev.end());
  //     if (temp == rev)
  //     {
  //       count++;
  //     }
  //     return;
  //   }

  //   temp.push_back(str[i]);
  //   helper(i + 1, str, count, temp);
  //   temp.pop_back();
  //   helper(i + 1, str, count, temp);
  // }

  const long long int mod = 1000000007;
  long long int add(long long int x, long long int y)
  {
    return ((x % mod) + (y % mod)) % mod;
  }
  long long int sub(long long int x, long long int y)
  {
    return ((x % mod) - (y % mod) + mod) % mod;
  }

  long long int countPS(string str)
  {
    int n = str.length();
    vector<vector<long unsigned int>> dp(n, vector<long unsigned int>(n, 0));
    for (int g = 0; g < n; g++)
    {
      for (int i = 0, j = g; j < n; i++, j++)
      {

        if (g == 0)
        {
          dp[i][j] = 1;
        }
        else if (g == 1)
        {
          dp[i][j] = (str[i] == str[j]) ? 3 : 2;
        }
        else
        {
          if (str[i] == str[j])
          {
            dp[i][j] = add(add(dp[i][j - 1], dp[i + 1][j]), 1);
          }
          else
          {
            dp[i][j] = sub(add(dp[i][j - 1], dp[i + 1][j]), dp[i + 1][j - 1]);
          }
        }
        /* code */
      }
    }

    return dp[0][n - 1];
  }
};

// { Driver Code Starts.
// Driver program
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string str;
    cin >> str;
    Solution ob;
    long long int ans = ob.countPS(str);
    cout << ans << endl;
  }
} // } Driver Code Ends