#include <bits/stdc++.h>
using namespace std;

int minTrials(int e, int f)
{
  if (e == 1 || f == 0 || f == 1)
  {
    return f;
  }

  int minAns = INT_MAX;

  for (int i = 1; i <= f; i++)
  {
    // egg is thrown from ith floor so +1 trial and then we choose max of the trials required when the egg breaks or does not break because we want the highest floor
    int temp = 1 + max(
                       // egg breaks
                       minTrials(e - 1, f - i),
                       // egg does not break
                       minTrials(e, i - 1));

    minAns = min(temp, minAns);
  }

  return minAns;
}

int main(int argc, char const *argv[])
{
  int e, f;
  cin >> e >> f;
  cout << minTrials(e, f);
  return 0;
}
