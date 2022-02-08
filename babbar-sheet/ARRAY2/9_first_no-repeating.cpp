// Find the first non-repeating element in a given array of integers.
// [Solution: https://www.geeksforgeeks.org/non-repeating-element/ ]

#include <bits/stdc++.h>
using namespace std;

int firstNonRepeat(vector<int> &arr)
{
  unordered_map<int, int> elems;
  for (int i = 0; i < arr.size(); i++)
  {
    elems[arr[i]]++;
  }

  for (int i : arr)
  {
    if (elems[i] > 1)
      return i;
  }

  return -1;
}

int main(int argc, char const *argv[])
{
  vector<int> arr = {1, 5, 3, 4, 3, 5, 6};
  cout << firstNonRepeat(arr);
  return 0;
}
