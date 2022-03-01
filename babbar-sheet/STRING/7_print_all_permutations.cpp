// 7. Print all the permutations of the given string
// [Practice here: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0 ]

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  void permutations(string &s, string &temp, vector<string> &result, vector<bool> &used)
  {
    if (temp.length() == s.length())
    {
      result.push_back(temp);
      return;
    }

    for (int j = 0; j < s.length(); j++)
    {
      if (used[j] == true)
        continue;
      temp.push_back(s[j]);
      used[j] = true;
      permutations(s, temp, result, used);
      temp.pop_back();
      used[j] = false;
    }
  }

  vector<string> find_permutation(string S)
  {
    vector<string> result;
    string temp;
    vector<bool> used(S.length(), false);
    sort(S.begin(), S.end());
    permutations(S, temp, result, used);
    return result;
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string S;
    cin >> S;
    Solution ob;
    vector<string> ans = ob.find_permutation(S);
    for (auto i : ans)
    {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends