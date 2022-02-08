#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
  ll t;
  cin >> t;
  ll N = 0;
  ll width;
  ll height;
  while (N++ != t)
  {
    cin >> height;
    cin >> width;
    vector<vector<int>> grid(height, vector<int>(width));
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        cin >> grid[i][j];
      }
    }

    ll count = 0;
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        if (grid[i][j] == 1)
        {
          int left, right, up, down;
          left = right = up = down = 1;

          int row = i;
          int col = j;
          // left count
          while ((--col) > -1 && grid[row][col] == 1)
          {
            left++;
          }

          row = i;
          col = j;
          // right count
          while ((++col) < width && grid[row][col] == 1)
          {
            right++;
          }

          row = i;
          col = j;
          // top count
          while ((--row) > -1 && grid[row][col] == 1)
          {
            up++;
          }

          row = i;
          col = j;
          // down count
          while ((++row) < height && grid[row][col] == 1)
          {
            down++;
          }

          vector<vector<int>> counts = {{right, up}, {right, down}, {left, up}, {left, down}, {up, right}, {down, right}, {up, left}, {down, left}};

          // cout << i << "," << j << " l: " << left << " r: " << right << " u: " << up << " d: " << down << endl;
          for (vector<int> &dirs : counts)
          {

            int smallest = dirs[0];
            int largest = dirs[1];
            if (smallest >= 2 && largest >= 4)
            {
              // cout << smallest << " " << largest << endl;

              while (2 * (smallest) > largest)
              {
                smallest--;
              }
              // cout << smallest - 1 << endl;
              count += (smallest - 1);
            }
          }
        }
      }
    }

    cout << "Case #" << N << ": " << count << "\n";
  }
  return 0;
}