//1. Find the Union and Intersection of the two sorted arrays.

#include <bits/stdc++.h>
using namespace std;

vector<int> union2(vector<int> &a, vector<int> &b)
{
  vector<int> ans;
  int i = 0;
  int j = 0;

  while (i < (a.size() - 1) && a[i] == a[i + 1])
    i++;
  while (j < (b.size() - 1) && b[j] == b[j + 1])
    j++;

  while (i < a.size() && j < b.size())
  {
    if (a[i] == b[j])
    {
      ans.push_back(a[i]);
      i++;
      j++;
    }
    else if (a[i] < b[j])
    {
      ans.push_back(a[i]);
      i++;
    }
    else
    {
      ans.push_back(b[j]);
      j++;
    }

    while (i < (a.size() - 1) && a[i] == a[i + 1])
      i++;
    while (j < (b.size() - 1) && b[j] == b[j + 1])
      j++;
  }

  if (i != a.size())
  {
    for (int k = i; k < a.size(); k++)
    {

      while (k < (a.size() - 1) && a[k] == a[k + 1])
        k++;
      ans.push_back(a[k]);
    }
  }

  if (j != b.size())
  {
    for (int k = j; k < b.size(); k++)
    {

      while (k < (b.size() - 1) && b[k] == b[k + 1])
        k++;
      ans.push_back(b[k]);
    }
  }

  return ans;
}

vector<int> doUnion(vector<int> &a, vector<int> &b)
{
  vector<int> ans;
  int i = 0;
  int j = 0;
  while (i < a.size() && j < b.size())
  {
    if (a[i] == b[j])
    {
      ans.push_back(a[i]);
      i++;
      j++;
    }
    else if (a[i] < b[j])
    {
      ans.push_back(a[i]);
      i++;
    }
    else
    {
      ans.push_back(b[j]);
      j++;
    }
  }

  for (int k = i; k < a.size(); k++)
  {
    ans.push_back(a[k]);
  }

  for (int k = j; k < b.size(); k++)
  {
    ans.push_back(b[k]);
  }

  return ans;
}

vector<int> doIntersection(vector<int> &a, vector<int> &b)
{
  vector<int> ans;
  int i = 0;
  int j = 0;
  while (i < a.size() && j < b.size())
  {
    if (a[i] == b[j])
    {
      ans.push_back(a[i]);
      i++;
      j++;
    }
    else if (a[i] < b[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }

  return ans;
}

int main(int argc, char const *argv[])
{
  vector<int> a = {2, 3, 4, 5, 6, 9};
  vector<int> b = {1, 3, 6, 7, 8, 9, 10, 12};
  vector<int> uresult = doUnion(a, b);
  vector<int> iresult = doIntersection(a, b);
  for (int i : uresult)
  {
    cout << i << " ";
  }
  cout << "\n";
  for (int i : iresult)
  {
    cout << i << " ";
  }
  return 0;
}
