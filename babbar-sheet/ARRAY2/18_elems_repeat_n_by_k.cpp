// 18. Given an array of size n and a number k, fin all elements that appear
// more than n/k times.
// [Practice here: https://practice.geeksforgeeks.org/problems/count-element-occurences/1 ]
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  void repeatingElem(int arr[], int n, int k)
  {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
      freq[arr[i]]++;
    }

    int repeat = n / k;
    int elems = 0;

    for (auto i = freq.begin(); i != freq.end(); i++)
    {
      if (i->second == repeat)
      {
        cout << i->first << " ";
      }
    }
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
    int k;
    cin >> k;
    int i, a[n];
    for (i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    Solution ob;
    ob.repeatingElem(a, n, k);
  }
  return 0;
} // } Driver Code Ends