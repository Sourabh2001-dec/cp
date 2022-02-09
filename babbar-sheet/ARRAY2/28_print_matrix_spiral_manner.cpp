// 28. Print the matrix in a Spiral manner. [Very IMP ]
// [Practice here: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0 ]

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to return a list of integers denoting spiral traversal of matrix.
  vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
  {
    vector<int> result;

    if (r == 1)
    {
      return matrix[0];
    }

    if (c == 1)
    {
      for (auto i : matrix)
      {
        result.push_back(i[0]);
      }

      return result;
    }

    int x, y;
    x = y = 0;
    bool top, right, bottom, left;
    right = true;
    for (int i = 0; i < (r * c); i++)
    {
      result.push_back(matrix[x][y]);
      matrix[x][y] = INT_MIN;

      // top
      if (top)
      {
        x--;
        if (x - 1 < 0 || matrix[x - 1][y] == INT_MIN)
        {
          top = false;
          right = true;
        }
      }
      // right
      else if (right)
      {
        y++;
        if (y + 1 >= c || matrix[x][y + 1] == INT_MIN)
        {
          right = false;
          bottom = true;
        }
      }
      // bottom
      else if (bottom)
      {
        x++;
        if (x + 1 >= r || matrix[x + 1][y] == INT_MIN)
        {
          bottom = false;
          left = true;
        }
      }
      // left
      else
      {
        y--;
        if (y - 1 < 0 || matrix[x][y - 1] == INT_MIN)
        {
          left = false;
          top = true;
        }
      }
    }

    return result;
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
    vector<vector<int>> matrix(r);

    for (int i = 0; i < r; i++)
    {
      matrix[i].assign(c, 0);
      for (int j = 0; j < c; j++)
      {
        cin >> matrix[i][j];
      }
    }

    Solution ob;
    vector<int> result = ob.spirallyTraverse(matrix, r, c);
    for (int i = 0; i < result.size(); ++i)
      cout << result[i] << " ";
    cout << endl;
  }
  return 0;
} // } Driver Code Ends
