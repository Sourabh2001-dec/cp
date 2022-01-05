#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> exp, int i, int j, bool isTrue)
{
  if (i > j)
  {
    return 0;
  }

  if (i == j)
  {
    if (isTrue)
    {
      if (exp[i] == "T")
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      if (exp[i] == "F")
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
  }

  int ans = 0;
  for (int k = i; k <= j; k++)
  {
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

  return ans;
}

int main(int argc, char const *argv[])
{
  vector<string> exp = {"T", "or", "T", "and", "F", "xor", "T"};
  cout << solve(exp, 0, exp.size() - 1, true);
  return 0;
}
