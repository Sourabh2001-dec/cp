// 9. Rearrange characters in a string such that no two adjacent are same
// [Practice here: https://practice.geeksforgeeks.org/problems/rearrange-characters/0  ]

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
public:
  string rearrangeString(string str)
  {
    int n = str.length();
    vector<int> count(26, 0);
    for (auto ch : str)
    {
      count[ch - 'a']++;
    }

    int maxCount = 0;
    char ch_max;
    for (int i = 0; i < 26; i++)
    {
      if (count[i] > maxCount)
      {
        maxCount = count[i];
        ch_max = 'a' + i;
      }
    }

    if (maxCount > ((n + 1) / 2))
    {
      return "-1";
    }

    string res(n, ' ');

    int ind = 0;
    while (maxCount)
    {
      res[ind] = ch_max;
      ind = ind + 2;
      maxCount--;
    }

    count[ch_max - 'a'] = 0;

    for (int i = 0; i < 26; i++)
    {
      while (count[i] > 0)
      {
        ind = (ind >= n) ? 1 : ind;
        res[ind] = 'a' + i;
        ind += 2;
        count[i]--;
      }
    }

    return res;
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string str;
    cin >> str;
    Solution ob;
    string str1 = ob.rearrangeString(str);
    // cout << str1 << endl;
    int flag = 1;
    int c[26] = {0};
    for (int i = 0; i < str.length(); i++)
      c[str[i] - 'a'] += 1;
    int f = 0;
    int x = (str.length() + 1) / 2;
    for (int i = 0; i < 26; i++)
    {
      if (c[i] > x)
        f = 1;
    }
    if (f)
    {
      if (str1 == "-1")
        cout << 0 << endl;
      else
        cout << 1 << endl;
    }
    else
    {
      int a[26] = {0};
      int b[26] = {0};
      for (int i = 0; i < str.length(); i++)
        a[str[i] - 'a'] += 1;
      for (int i = 0; i < str1.length(); i++)
        b[str1[i] - 'a'] += 1;

      for (int i = 0; i < 26; i++)
        if (a[i] != b[i])
          flag = 0;

      for (int i = 0; i < str1.length(); i++)
      {
        if (i > 0)
          if (str1[i - 1] == str1[i])
            flag = 0;
      }
      if (flag == 1)
        cout << "1\n";
      else
        cout << "0\n";
    }
  }
  return 0;
} // } Driver Code Ends
