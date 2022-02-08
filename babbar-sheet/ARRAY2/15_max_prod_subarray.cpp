// 15. Find Maximum Product Subarray.
// [Practice here: https://practice.geeksforgeeks.org/problems/maximum-product-subarray/0 ]

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
  // Function to find maximum product subarray
  long long maxProduct(vector<int> arr, int n)
  {
    // code here
    long long int ans = INT_MIN;
    long long int cprod = 1; 

    for (int i = 0; i < n; i++)
    {
      cprod *= arr[i];

      ans = max(cprod, ans);
      if (cprod == 0)
      {
        cprod = 1;
      }
    }

    cprod = 1;
    for (int i = n - 1; i > -1; i--)
    {
      cprod *= arr[i];

      ans = max(cprod, ans);
      if (cprod == 0)
      {
        cprod = 1;
      }
    }

    return ans;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, i;
    cin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.maxProduct(arr, n);
    cout << ans << "\n";
  }
  return 0;
} // } Driver Code Ends