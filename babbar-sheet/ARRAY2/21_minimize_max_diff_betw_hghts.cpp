// 21. Minimize the maximum difference between the heights.
//  [ADOBE spl.]
// [Practice here: https://practice.geeksforgeeks.org/problems/minimize-the-heights/0 ]

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
  int getMinDiff(int arr[], int n, int k)
  {
    sort(arr, arr + n);
    int max_ = arr[n - 1];
    int min_ = arr[0];
    int ans = max_ - min_;

    for (int i = 1; i < n; i++)
    {
      max_ = max(arr[i - 1] + k, arr[n - 1] - k);
      min_ = min(arr[i] - k, arr[0] + k);

      ans = min(ans, max_ - min_);
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
    int n, k;
    cin >> k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.getMinDiff(arr, n, k);
    cout << ans << "\n";
  }
  return 0;
} // } Driver Code Ends