#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo(5, vector<int>(5, -1));

int minMatrixMultiplicationCost(vector<int> sizes, int i, int j)
{
  if (i >= j)
    return 0;
  if (memo[i][j] != -1)
  {
    return memo[i][j];
  }
  int tempAns = INT_MAX;
  for (int k = i; k <= j - 1; k++)
  {
    int cost = minMatrixMultiplicationCost(sizes, i, k) + minMatrixMultiplicationCost(sizes, k + 1, j) + (sizes[i - 1] * sizes[k] * sizes[j]);
    tempAns = min(cost, tempAns);
  }

  return memo[i][j] = tempAns;
}

int main(int argc, char const *argv[])
{
  vector<int> sizes = {20, 10, 30, 10, 40};
  cout << minMatrixMultiplicationCost(sizes, 1, sizes.size() - 1);
  return 0;
}
