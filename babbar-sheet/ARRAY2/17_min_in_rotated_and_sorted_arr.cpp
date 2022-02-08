// Find the minimum element in a rotated and sorted array.
// [Practice here: https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array/0 ]

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  int findMin(int arr[], int n)
  {
    // complete the function here
    for (int i = 1; i < n; i++)
    {
      if (arr[i] < arr[i - 1])
      {
        return arr[i];
      }
    }

    return arr[0];
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int i, a[n];
    for (i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    Solution ob;
    cout << ob.findMin(a, n) << endl;
  }
  return 0;
} // } Driver Code Ends