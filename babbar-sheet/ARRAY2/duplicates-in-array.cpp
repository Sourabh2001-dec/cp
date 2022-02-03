// 5. F ind duplicates in an array.
// [Practice here : https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1 ]
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  vector<int> duplicates(int arr[], int n)
  {
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
      int index = abs(arr[i]) - 1;
      if (arr[index] < 0)
        result.push_back(index + 1);
      arr[index] = -arr[index];
    }
    return result;
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t-- > 0)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution obj;
    vector<int> ans = obj.duplicates(a, n);
    for (int i : ans)
      cout << i << ' ';
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends