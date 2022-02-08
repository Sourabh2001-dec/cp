// Find common elements in three sorted arrays
// [Practice here: https://practice.geeksforgeeks.org/problems/common-elements/0 ]

#include <bits/stdc++.h>
using namespace std;

vector<int> commonEle(vector<int> &v1, vector<int> &v2, vector<int> &v3)
{
  int i = 0;
  int j = 0;
  int k = 0;
  vector<int> res;
  int e1 = v1[0];
  int e2 = v2[0];
  int e3 = v3[0];
  while (i < v1.size() && j < v2.size() && k < v3.size())
  {

    while ((i + 1) < v1.size() && v1[i] == v1[i + 1])
    {
      i++;
    }
    while ((j + 1) < v2.size() && v2[j] == v2[j + 1])
    {
      j++;
    }
    while ((k + 1) < v3.size() && v3[k] == v3[k + 1])
    {
      k++;
    }

    e1 = v1[i];
    e2 = v2[j];
    e3 = v3[k];

    if (e1 == e2 && e2 == e3 && e1 == e3)
    {
      res.push_back(e1);
      i++;
      j++;
      k++;
      continue;
    }

    if (e1 >= e2 && e1 >= e3)
    {
      while (v2[j] < e1)
      {
        j++;
      }
      while (v3[k] < e1)
      {
        k++;
      }
      continue;
    }

    if (e2 >= e1 && e2 >= e3)
    {
      while (v3[k] < e2)
      {
        k++;
      }
      while (v1[i] < e2)
      {
        i++;
      }
      continue;
    }

    if (e3 >= e2 && e3 >= e1)
    {
      while (v2[j] < e3)
      {
        j++;
      }
      while (v1[i] < e3)
      {
        i++;
      }
      continue;
    }
  }

  return res;
}

int main(int argc, char const *argv[])
{
  vector<int> v1 = {1, 1, 2, 4, 4, 5, 6, 9};
  vector<int> v2 = {1, 2, 2, 3, 4, 5, 5, 6, 9};
  vector<int> v3 = {1, 1, 2, 3, 4, 4, 5, 6, 6, 8, 9, 10};
  vector<int> result = commonEle(v1, v2, v3);
  for (int i : result)
  {
    cout << i << " ";
  }
  return 0;
}
