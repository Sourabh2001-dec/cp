#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> memo;

int minTrials(int e, int f)
{
  if (e == 1 || f == 0 || f == 1)
  {
    return f;
  }

  if (memo.find(make_pair(e, f)) != memo.end())
  {
    auto val = memo.find(make_pair(e, f));
    return val->second;
  }

  int minAns = INT_MAX;

  for (int i = 1; i <= f; i++)
  {
    // egg is thrown from ith floor so +1 trial and then we choose max of the trials required when the egg breaks or does not break because we want the highest floor
    int trialsOnBreak, trialsOnUnbroken;

    if (memo.find(make_pair(e - 1, f - i)) != memo.end())
    {
      auto val = memo.find(make_pair(e - 1, f - i));
      trialsOnBreak = val->second;
    }
    else
    {
      trialsOnBreak = minTrials(e - 1, f - i);
    }

    if (memo.find(make_pair(e, i - 1)) != memo.end())
    {
      auto val = memo.find(make_pair(e, i - 1));
      trialsOnUnbroken = val->second;
    }
    else
    {
      trialsOnUnbroken = minTrials(e, i - 1);
    }

    int temp = 1 + max(
                       // egg breaks
                       trialsOnBreak,
                       // egg does not break
                       trialsOnUnbroken);

    minAns = min(temp, minAns);
  }

  return memo[make_pair(e, f)] = minAns;
}

int main(int argc, char const *argv[])
{
  int e, f;
  cin >> e >> f;
  cout << minTrials(e, f);
  return 0;
}
