// 13. Find Largest sum contiguous Subarray.[Very Important]
// [Practice here: https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0 ]

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &arr)
{
  int maxSum = INT_MIN;
  int currSum = 0;
  for (auto &&i : arr)
  {
    currSum += i;
    maxSum = max(currSum, maxSum);

    if (currSum < 0)
    {
      currSum = 0;
    }
  }

  return maxSum;
}

int main(int argc, char const *argv[])
{
  vector<int> arr = {5, -4, -2, 6, -1};
  cout << kadane(arr);
  return 0;
}
