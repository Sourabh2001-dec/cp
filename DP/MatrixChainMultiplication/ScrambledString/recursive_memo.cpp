#include <bits/stdc++.h>
using namespace std;

map<pair<string, string>, bool> memo;

bool solve(string a, string b)
{
  if (a.compare(b) == 0)
  {
    return true;
  }

  if (a.length() <= 1 || b.length() <= 1)
  {
    return false;
  }

  if (memo.find(make_pair(a, b)) != memo.end())
  {
    // cout << "hit : " << a << " " << b << endl;
    auto val = memo.find(make_pair(a, b));
    return val->second;
  }

  int n = a.length();
  bool flag = false;

  for (int i = 1; i < n; i++)
  {
    bool cond1 = solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i));
    bool cond2 = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i));
    if (cond1 || cond2)
    {
      flag = true;
      break;
    }
  }

  // cout << "miss : " << a << " " << b << endl;
  return memo[make_pair(a, b)] = flag;
}

int main(int argc, char const *argv[])
{
  string a = "great";
  string b = "aetgr";
  if (solve(a, b))
  {
    cout << "Scrambled String";
  }
  else
  {
    cout << "Not Scrambled";
  }
  return 0;
}
