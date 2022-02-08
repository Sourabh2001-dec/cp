// 8. Find the first repeating element in an array of integers.
// [Practice here: https://practice.geeksforgeeks.org/problems/first-repeating-element/0 ]
#include <bits/stdc++.h>
using namespace std;

int firstRepeating(vector<int> &arr)
{
  unordered_map<int, int> count;
  for (int i = 0; i < arr.size(); i++)
  {
    count[arr[i]]++;
  }

  for (int i = 0; i < arr.size(); i++)
  {
    if (count[arr[i]] > 1)
      return i + 1;
  }

  return -1;
}

int main(int argc, char const *argv[])
{
  vector<int> arr = {1, 5, 3, 4, 3, 5, 6};
  cout << firstRepeating(arr);
  return 0;
}
