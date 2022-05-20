#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig)
  {
    int ans = 0;
    for (int i = 0; i < artifacts.size(); i++)
    {
      vector<int> artifact = artifacts[i];
      vector<vector<int>> points;

      int count = 0;

      int x1 = artifact[0];
      int y1 = artifact[1];
      int x2 = artifact[2];
      int y2 = artifact[3];

      // top left
      if ((x2 - x1 == 0) && (y2 - y1 == 0))
      {
        vector<int> p2 = {x2, y2};
        points.push_back(p2);
      }
      // right
      else if (y2 - y1 == 0)
      {
        for (int j = x1; j <= x2; j++)
        {
          vector<int> p = {j, y1};
          points.push_back(p);
        }
      }
      // bottom
      else if (x2 - x1 == 0)
      {
        for (int j = y1; j <= y2; j++)
        {
          vector<int> p = {x1, j};
          points.push_back(p);
        }
      }
      // bottom right
      else
      {
        vector<int> p1 = {x1, y1};
        vector<int> p2 = {x1 + 1, y1};
        vector<int> p3 = {x2 - 1, y2};
        vector<int> p4 = {x2, y2};
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
      }

      bool foundAll = true;

      for (auto p : points)
      {
        auto is_eq = [p](vector<int> poi)
        { return (poi[0] == p[0] && poi[1] == p[1]); };
        if (find_if(dig.begin(), dig.end(), is_eq) == dig.end())
        {
          foundAll = false;
          break;
        }
      }

      if (foundAll)
        ans++;
    }

    return ans;
  }
};

int main(int argc, char const *argv[])
{
  int n = 6;
  vector<vector<int>> artifacts = {{0, 2, 0, 5}, {0, 1, 1, 1}, {3, 0, 3, 3}, {4, 4, 4, 4}, {2, 1, 2, 4}};
  vector<vector<int>> dig = {{0, 2}, {0, 3}, {0, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 5}, {3, 0}, {3, 1}, {3, 3}, {3, 4}, {4, 0}, {4, 3}, {4, 5}, {5, 0}, {5, 1}, {5, 2}, {5, 4}, {5, 5}};
  Solution s = Solution();
  cout << s.digArtifacts(n, artifacts, dig);
  return 0;
}
