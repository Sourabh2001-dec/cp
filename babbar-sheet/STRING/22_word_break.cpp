// 22. Word	break	Problem[	Very	Imp]
// [Practice	here:	https://practice.geeksforgeeks.org/problems/word-break/0 ]

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
  // does not work bcoz it can be tricked by the dictionary to choose first available option and leave it in a state where the other words are not available
  // int wordBreak(string A, vector<string> &B)
  // {
  //   int i = 0, j = 0;
  //   while (i < A.length() || j < A.length())
  //   {
  //     bool currPoss = false;
  //     while (j < A.length())
  //     {
  //       if (find(B.begin(), B.end(), A.substr(i, j - i + 1)) != B.end())
  //       {
  //         currPoss = true;
  //         i = ++j;
  //         break;
  //       }
  //       j++;
  //     }

  //     if (!currPoss)
  //     {
  //       return 0;
  //     }
  //   }

  //   return 1;
  // }

  int helper(string str, vector<string> &dict, unordered_map<string, bool> &dp)
  {
    int size = str.size();

    // Base case
    if (size == 0)
      return true;

    // Try all prefixes of lengths from 1 to size
    for (int i = 1; i <= size; i++)
    {
      // The parameter for dictionaryContains is
      // str.substr(0, i) which is prefix (of input
      // string) of length 'i'. We first check whether
      // current prefix is in  dictionary. Then we
      // recursively check for remaining string
      // str.substr(i, size-i) which is suffix of
      // length size-i
      if ((find(dict.begin(), dict.end(), str.substr(0, i)) != dict.end()) &&
          helper(str.substr(i, size - i), dict, dp))
        return dp[str.substr(0, i)] = true;
      else
      {
        dp[str.substr(0, i)] = false;
      }
    }

    // If we have tried all prefixes and
    // none of them worked
    return false;
  }

  int wordBreak(string str, vector<string> &B)
  {
    unordered_map<string, bool> dp;
    return helper(str, B, dp);
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<string> dict;
    for (int i = 0; i < n; i++)
    {
      string S;
      cin >> S;
      dict.push_back(S);
    }
    string line;
    cin >> line;
    Solution ob;
    cout << ob.wordBreak(line, dict) << "\n";
  }
}
// } Driver Code Ends