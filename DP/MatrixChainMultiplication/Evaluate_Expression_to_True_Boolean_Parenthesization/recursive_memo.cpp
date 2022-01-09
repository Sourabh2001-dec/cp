#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int value = -1;
};

map<tuple<int, int, bool>, Node> memo;

int solve(vector<string> exp, int i, int j, bool isTrue)
{
  if (i > j)
  {
    return 0;
  }
  // cout << "memo " << memo[make_tuple(i, j, isTrue)].value << endl;
  if (memo[make_tuple(i, j, isTrue)].value != -1)
  {
    // cout << "hit : " << i << " " << j << " " << isTrue << endl;
    return memo[make_tuple(i, j, isTrue)].value;
  }

  if (i == j)
  {
    if (isTrue)
    {
      if (exp[i] == "T")
      {
        // cout << "miss1 : " << i << " " << j << " " << isTrue << endl;
        return memo[make_tuple(i, j, isTrue)].value = 1;
      }
      else
      {
        // cout << "miss2 : " << i << " " << j << " " << isTrue << endl;
        return memo[make_tuple(i, j, isTrue)].value = 0;
      }
    }
    else
    {
      if (exp[i] == "F")
      {
        // cout << "miss3 : " << i << " " << j << " " << isTrue << endl;
        return memo[make_tuple(i, j, isTrue)].value = 1;
      }
      else
      {
        // cout << "miss4 : " << i << " " << j << " " << isTrue << endl;
        return memo[make_tuple(i, j, isTrue)].value = 0;
      }
    }
  }

  int ans = 0;
  for (int k = i; k <= j; k++)
  {
    // int lT = memo[make_tuple(i, k - 1, true)].value != -1 ? memo[make_tuple(i, k - 1, true)].value : solve(exp, i, k - 1, true);
    // int lF = memo[make_tuple(i, k - 1, false)].value != -1 ? memo[make_tuple(i, k - 1, false)].value : solve(exp, i, k - 1, false);
    // int rT = memo[make_tuple(k + 1, j, true)].value != -1 ? memo[make_tuple(k + 1, j, true)].value : solve(exp, k + 1, j, true);
    // int rF = memo[make_tuple(k + 1, j, false)].value != -1 ? memo[make_tuple(k + 1, j, false)].value : solve(exp, k + 1, j, false);

    int lT = solve(exp, i, k - 1, true);
    int lF = solve(exp, i, k - 1, false);
    int rT = solve(exp, k + 1, j, true);
    int rF = solve(exp, k + 1, j, false);

    string op = exp[k];
    if (op == "or")
    {
      if (isTrue)
      {

        ans = ans + lT * rF + lF * rT + lT * rT;
      }
      else
      {
        ans = ans + lF * rF;
      }
    }
    else if (op == "and")
    {
      if (isTrue)
      {
        ans = ans + lT * rT;
      }
      else
      {
        ans = ans + lT * rF + rT * lF + lF * rF;
      }
    }
    else if (op == "xor")
    {
      if (isTrue)
      {

        ans = ans + lT * rF + lF * rT;
      }
      else
      {
        ans = ans + lT * rT + lF * rF;
      }
    }
  }

  return memo[make_tuple(i, j, isTrue)].value = ans;
}

int main(int argc, char const *argv[])
{
  vector<string> exp = {"T", "or", "T", "and", "F", "xor", "T"};
  cout << solve(exp, 0, exp.size() - 1, true);
  return 0;
}
