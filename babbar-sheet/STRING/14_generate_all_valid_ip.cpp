// 14.
// Program to generate all possible valid IP addresses from given
// string.
// [Follow here: https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/ ]

#include <iostream>
#include <vector>
using namespace std;

bool isvalid(string s)
{
  if (s[0] == '0')
  {
    return false;
  }

  return stoi(s) < 256;
}

void solve(string s, int i, int par, string ans, vector<string> &res)
{

  if (par == 4 || i == s.length())
  {
    if (par == 4 && s.length() == i)
    {
      // removing extra '.' at the end of the answer
      ans.pop_back();
      // storing the valid answer
      res.push_back(ans);
    }
    return;
  }

  // partitioning at first char and appending to answer
  solve(s, i + 1, par + 1, ans + s[i] + '.', res);

  // partitioning using 2 nums
  if ((i + 2) <= s.length() && isvalid(s.substr(i, 2)))
  {
    solve(s, i + 2, par + 1, ans + s.substr(i, 2) + '.', res);
  }

  // partitioning using 3 nums
  if ((i + 3) <= s.length() && isvalid(s.substr(i, 3)))
  {
    solve(s, i + 3, par + 1, ans + s.substr(i, 3) + '.', res);
  }
}

int main()
{
  string s = "25525511135";
  int n = s.length();

  vector<string> ans;

  solve(s, 0, 0, "", ans);

  for (string s : ans)
    cout << s << endl;

  return 0;
}
