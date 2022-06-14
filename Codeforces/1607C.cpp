#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve()
{
  int len;
  cin >> len;
  vector<int> arr;
  for (int i = 0; i < len; i++)
  {
    int num;
    cin >> num;
    arr.push_back(num);
  }

  int currMin = INT_MAX;
  int currMinInd = -1;
  for (int i = 0; i < len; i++)
  {
    if (arr[i] < currMin)
    {
      currMin = arr[i];
      currMinInd = i;
    }
  }

  arr[currMinInd] = INT_MAX;
  int minMax = currMin;

  for (int i = 0; i < len; i++)
  {
    int nextMin = INT_MAX;
    int nextMinInd = -1;
    for (int j = 0; j < len; j++)
    {
      if (arr[j] == INT_MAX)
        continue;
      arr[j] = arr[j] - currMin;
      if (arr[j] < nextMin)
      {
        nextMin = arr[j];
        nextMinInd = j;
      }
    }

    if (nextMinInd > -1)
    {
      currMin = nextMin;
      arr[nextMinInd] = INT_MAX;
    }

    minMax = max(minMax, currMin);
  }

  cout << minMax << "\n";
}

int32_t main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
