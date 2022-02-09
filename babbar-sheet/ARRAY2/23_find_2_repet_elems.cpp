// 23.Find the two repetitive elements in a given array.
// [Practice here: https://practice.geeksforgeeks.org/problems/two-repeated-elements/0 ]

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
  // Function to find two repeated elements.
  vector<int> twoRepeated(int arr[], int N)
  {
    // Your code here
    vector<int> res;
    for (int i = 0; i < (N + 2); i++)
    {
      // index pointed by current element
      int absIndex = abs(arr[i]) - 1;

      // if element at pointed index is negative that element is repeated
      if (arr[absIndex] < 0)
      {
        res.push_back(absIndex + 1);
      }
      // else make that pointed element at that index negative
      else
      {
        arr[absIndex] = -1 * arr[absIndex];
      }
    }

    return res;
  }
};

// { Driver Code Starts.

int main()
{
  int t, n;
  cin >> t;

  while (t--)
  {
    cin >> n;

    int a[n + 2];

    for (int i = 0; i < n + 2; i++)
      cin >> a[i];

    Solution obj;
    vector<int> res;
    res = obj.twoRepeated(a, n);
    cout << res[0] << " " << res[1] << endl;
  }
  return 0;
}
// } Driver Code Ends