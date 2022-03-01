// 0. Write a program to find the smallest window that contains all
// characters of string itself.
//  [Practice here: https://practice.geeksforgeeks.org/problems/smallest-distant-window/0 ]
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // string findSubString(string str)
  // {
  //   int n = str.length();

  //   int dist_count = 0;
  //   unordered_map<char, int> hash_map;
  //   for (char s : str)
  //   {
  //     hash_map[s]++;
  //   }

  //   dist_count = hash_map.size();
  //   int size = INT_MAX;
  //   string res;

  //   for (int i = 0; i < n; i++)
  //   {
  //     int count = 0;
  //     int visited[256] = {0};
  //     string sub_str = "";
  //     for (int j = i; j < n; j++)
  //     {
  //       if (visited[str[j]] == 0)
  //       {
  //         count++;
  //         visited[str[j]] = 1;
  //       }
  //       sub_str += str[j];
  //       if (count == dist_count)
  //         break;
  //     }
  //     if (sub_str.length() < size && count == dist_count)
  //     {
  //       res = sub_str;
  //       size = res.length();
  //     }
  //   }
  //   return res;
  // }
  string findSubString(string str)
  {
    int n = str.length();
    if (n <= 1)
    {
      return str;
    }

    int dist_count = 0;
    bool visited[256] = {false};

    // count unique chars
    for (int i = 0; i < n; i++)
    {
      if (visited[str[i]] == false)
      {
        visited[str[i]] = true;
        dist_count++;
      }
    }

    int start = 0, start_index = -1, min_len = INT_MAX;

    int count = 0;
    int curr_count[256] = {0};

    for (int j = 0; j < n; j++)
    {
      curr_count[str[j]]++;

      // first occurence found
      if (curr_count[str[j]] == 1)
      {
        count++;
      }

      if (count == dist_count)
      {
        // removing repeated chars from start
        while (curr_count[str[start]] > 1)
        {
          if (curr_count[str[start]] > 1)
          {
            curr_count[str[start]]--;
          }
          start++;
        }
        int len_window = j - start + 1;
        if (min_len > len_window)
        {
          min_len = len_window;
          start_index = start;
        }
      }
    }

    return str.substr(start_index, min_len);
  }
};

// { Driver Code Starts.
// Driver code
int main()
{
  int t;
  cin >> t;
  while (t--)
  {

    string str;
    cin >> str;
    Solution ob;
    cout << ob.findSubString(str) << endl;
    cout << ob.findSubString(str).size() << endl;
  }
  return 0;
} // } Driver Code Ends