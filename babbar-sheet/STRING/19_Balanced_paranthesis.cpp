// Balanced Parenthesis problem.[Imp]
// [Practice here: https://practice.geeksforgeeks.org/problems/parenthesis-checker/0

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to check if brackets are balanced or not.
  char getClosingBracket(char open)
  {
    switch (open)
    {
    case '{':
      return '}';
    case '(':
      return ')';
    case '[':
      return ']';
    default:
      return '1';
    }
  }
  bool ispar(string x)
  {
    stack<char> pairs;

    for (char c : x)
    {
      if (c == '{' || c == '(' || c == '[')
      {
        pairs.push(c);
      }
      else
      {
        if (pairs.empty())
          return false;
        char top = pairs.top();
        pairs.pop();
        if (c != getClosingBracket(top))
        {
          return false;
        }
      }
    }

    if (!pairs.empty())
      return false;

    return true;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  string a;
  cin >> t;
  while (t--)
  {
    cin >> a;
    Solution obj;
    if (obj.ispar(a))
      cout << "balanced" << endl;
    else
      cout << "not balanced" << endl;
  }
} // } Driver Code Ends