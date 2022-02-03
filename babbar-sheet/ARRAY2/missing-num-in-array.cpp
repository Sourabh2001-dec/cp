// 3. You are given a list of n-1 integers and these integers are in the range
// of 1 to n. There are no duplicates in the list. One of the integers is
// missing in the list. Write an efficient code to find the missing integer.
// [Practice here: https://practice.geeksforgeeks.org/problems/missing-number-in-array/0 ]
// ======================================================================================

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
  int MissingNumber(vector<int> &array, int n)
  {
    // Your code goes here
    int expectTotal = (n * (n + 1)) / 2;
    int sum = 0;
    for (int i : array)
    {
      sum += i;
    }

    return expectTotal - sum;
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

    vector<int> array(n - 1);
    for (int i = 0; i < n - 1; ++i)
      cin >> array[i];
    Solution obj;
    cout << obj.MissingNumber(array, n) << "\n";
  }
  return 0;
} // } Driver Code Ends