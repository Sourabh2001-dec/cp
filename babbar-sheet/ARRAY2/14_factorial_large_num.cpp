// 14. Find the factorial of a large number.
// [Practice here: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0 ]

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
  void multipy(vector<int> &num, int x)
  {
    long long int carry = 0;
    for (int i = 0; i < num.size(); i++)
    {
      // cout << (num[i]) << "*" << x << endl;
      long long int prod = (num[i] * x) + carry;
      num[i] = prod % 10;
      carry = prod / 10;
    }

    while (carry)
    {
      num.push_back(carry % 10);
      carry /= 10;
    }
  }

  vector<int> factorial(int N)
  {
    // code here
    vector<int> num;

    if (N == 0 || N == 1)
    {
      num.push_back(1);
      return num;
    }

    int inputNum = N;
    while (inputNum)
    {
      num.push_back(inputNum % 10);
      inputNum /= 10;
    }

    // for (auto &&i : num)
    // {
    //   cout << i << " ";
    // }
    // cout << endl;

    for (int i = N - 1; i > 1; i--)
    {
      multipy(num, i);
    }

    reverse(num.begin(), num.end());

    return num;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    Solution ob;
    vector<int> result = ob.factorial(N);
    for (int i = 0; i < result.size(); ++i)
    {
      cout << result[i];
    }
    cout << endl;
  }
  return 0;
} // } Driver Code Ends