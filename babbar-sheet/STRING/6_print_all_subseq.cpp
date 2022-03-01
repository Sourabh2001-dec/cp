// 6. Print all Subsequences of a string.
// [Follow here: https://www.geeksforgeeks.org/print-subsequences-string/ ]

#include <bits/stdc++.h>
using namespace std;

void allSubsequences(int i, string &s, vector<string> &result, string &temp)
{
  if (i == s.length())
  {
    result.push_back(temp);
    return;
  }

  temp.push_back(s[i]);
  allSubsequences(i + 1, s, result, temp);
  temp.pop_back();
  allSubsequences(i + 1, s, result, temp);
};

int main(int argc, char const *argv[])
{
  string s = "abcd";
  vector<string> result;
  string temp = "";

  allSubsequences(0, s, result, temp);

  for (string i : result)
  {
    cout << i << endl;
  }
  return 0;
}
