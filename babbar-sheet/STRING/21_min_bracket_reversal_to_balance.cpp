// 21. Minimum	number	of	bracket	reversals	needed	to	make	an
// expression	balanced.
// [Practice	here:	https://practice.geeksforgeeks.org/problems/count-the-reversals/0 ]

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int countRev(string s);
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    cout << countRev(s) << '\n';
  }
}

// Contributed By: Pranay Bansal// } Driver Code Ends

int countRev(string s)
{
  // if odd then pairs not possible
  if (s.length() % 2)
  {
    return -1;
  }

  stack<char> pairs;
  // eliminate correct pairs
  for (char bracket : s)
  {
    if (bracket == '}')
    {
      if (!pairs.empty() && pairs.top() == '{')
      {
        pairs.pop();
      }
      else
      {
        pairs.push(bracket);
      }
    }
    else
    {
      pairs.push(bracket);
    }
  }

  // from the remaining brackets calculate required reversals
  int red_len = pairs.size();

  int n = 0;             // opening brackets count
  while (!pairs.empty()) // counting open brackets
  {
    if (pairs.top() == '{')
    {
      n++;
    }
    pairs.pop();
  }

  return (red_len / 2) + (n % 2);
}