// 12.  Find if there is any subarray with sum equal to zer
// [Practice here: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0 ]

#include <bits/stdc++.h>
using namespace std;

bool withSum0(vector<int> &arr)
{
  unordered_set<int> sums;
  int sum = 0;
  for (auto &&i : arr)
  {
    sum += i;
    if (sum == 0 || sums.find(sum) != sums.end())
    {
      return true;
    }
    sums.insert(sum);
  }
  return false;
}

int main(int argc, char const *argv[])
{
  vector<int> arr = {1, -4, 3, 4, -3, 5, 6};
  cout << withSum0(arr);
  return 0;
}
