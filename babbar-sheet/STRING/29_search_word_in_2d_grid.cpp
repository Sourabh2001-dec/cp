// 29.
// Search a Word in a 2D Grid of characters.
// [Practice here: https://practice.geeksforgeeks.org/problems/find-the-string-in-grid/0 ]

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  bool searchAll(int x, int y, string word, vector<vector<char>> &grid)
  {
    // t r b l tr rb bl tl
    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> rowDirs = {-1, 0, 1, 0, -1, 1, 1, -1};
    vector<int> colDirs = {0, 1, 0, -1, 1, 1, -1, -1};

    for (int i = 0; i < 8; i++)
    {
      int incRow = rowDirs[i];
      int incCol = colDirs[i];
      int X = x;
      int Y = y;
      int needlePtr = 0;
      int matchedLen = 0;
      while (X >= 0 && X < rows && Y >= 0 && Y < cols && needlePtr < word.length())
      {
        if (grid[X][Y] == word[needlePtr])
        {
          matchedLen++;
        }
        else
        {
          break;
        }
        needlePtr++;
        X += incRow;
        Y += incCol;
        if (matchedLen == word.length())
        {
          return true;
        }
      }
    }
    return false;
  }
  vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
  {
    // Code here
    vector<vector<int>> coords;
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (searchAll(i, j, word, grid))
        {
          vector<int> res;
          res.push_back(i);
          res.push_back(j);
          coords.push_back(res);
        }
      }
    }

    return coords;
  }
};

// { Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, 'x'));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        cin >> grid[i][j];
    }
    string word;
    cin >> word;
    Solution obj;
    vector<vector<int>> ans = obj.searchWord(grid, word);
    for (auto i : ans)
    {
      for (auto j : i)
        cout << j << " ";
      cout << "\n";
    }
    if (ans.size() == 0)
    {
      cout << "-1\n";
    }
  }
  return 0;
} // } Driver Code Ends