// 26. Find the row with maximum number of 1’s.
// [Practice here: https://practice.geeksforgeeks.org/problems/row-with-max-1s/0 ]
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
  int rowWithMax1s(vector<vector<int>> arr, int n, int m)
  {
    // Initialize first row as row with max 1s
    int j, max_row_index = 0;
    j = m - 1;

    for (int i = 0; i < n; i++)
    {
      // Move left until a 0 is found
      bool flag = false; // to check whether a row has more 1's than previous
      while (j >= 0 && arr[i][j] == 1)
      {
        j = j - 1;   // Update the index of leftmost 1
                     // seen so far
        flag = true; // present row has more 1's than previous
      }
      // if the present row has more 1's than previous
      if (flag)
      {
        max_row_index = i; // Update max_row_index
      }
    }
    if (max_row_index == 0 && arr[0][m - 1] == 0)
      return -1;
    return max_row_index;
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> arr[i][j];
      }
    }
    Solution ob;
    auto ans = ob.rowWithMax1s(arr, n, m);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends