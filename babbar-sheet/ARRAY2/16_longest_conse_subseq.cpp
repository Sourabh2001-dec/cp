// 16. Find longest consecutive subsequence.
// [Practice here: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0 ]

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // arr[] : the input array
  // N : size of the array arr[]

  // Function to return length of longest subsequence of consecutive integers.
  int findLongestConseqSubseq(int arr[], int N)
  {
    // Your code here
    set<int> nums;
    for (int i = 0; i < N; i++)
    {
      nums.insert(arr[i]);
    }

    int maxLen = 1;
    int currLen = 1;
    auto start = nums.begin();
    start++;
    for (auto i = start; i != nums.end(); i++)
    {
      int prev = *(--i);
      i++;
      if (*i - prev == 1)
      {
        currLen++;
      }
      else
      {
        currLen = 1;
      }

      maxLen = max(currLen, maxLen);
    }

    return maxLen;
  }
};

// { Driver Code Starts.

// Driver program
int main()
{
  int t, n, i, a[100001];
  cin >> t;
  while (t--)
  {
    cin >> n;
    for (i = 0; i < n; i++)
      cin >> a[i];
    Solution obj;
    cout << obj.findLongestConseqSubseq(a, n) << endl;
  }

  return 0;
} // } Driver Code Ends