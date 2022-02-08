//   10.Given an array with all distinct elements, find the largest three
// elements. Expected time complexity is O(n) and extra space is O(1).
// Input: arr[] = {10, 4, 3, 50, 23, 90}
// Output: 90, 50, 23

#include <bits/stdc++.h>
using namespace std;

void largest3(vector<int> &arr)
{
  int max1 = INT_MIN;
  int max2 = INT_MIN;
  int max3 = INT_MIN;

  for (int i : arr)
  {
    if (i > max1)
    {
      max3 = max2;
      max2 = max1;
      max1 = i;
    }
    else if (i > max2)
    {
      max3 = max2;
      max2 = i;
    }
    else if (i > max3)
    {
      max3 = i;
    }
  }

  cout << max1 << " " << max2 << " " << max3;
}

int main(int argc, char const *argv[])
{
  vector<int> arr = {10, 4, 3, 50, 23, 90};
  largest3(arr);
  return 0;
}
