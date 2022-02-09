// 27. Find the median in a row wise sorted matrix.
// [Practice here: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix/0 ]

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
  int median(vector<vector<int>> &matrix, int r, int c)
  {
    // code here
    int min_ = INT_MAX, max_ = INT_MIN;
    for (int i = 0; i < r; i++)
    {
      min_ = min(matrix[i][0], min_);
      max_ = max(matrix[i][c - 1], max_);
    }

    // index of the median
    int desired = (r * c + 1) / 2;
    while (min_ < max_)
    {
      // middle element
      int mid = min_ + (max_ - min_) / 2;

      int count = 0;
      for (int i = 0; i < r; i++)
      {
        count += (upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());
      }

      if (count < desired)
      {
        min_ = mid + 1;
      }
      else
      {
        max_ = mid;
      }
    }

    return min_;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        cin >> matrix[i][j];
    Solution obj;
    cout << obj.median(matrix, r, c) << endl;
  }
  return 0;
} // } Driver Code Ends