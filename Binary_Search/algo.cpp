#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int lower_bound(vi &arr, int ele)
{
  int lo = 0, hi = arr.size() - 1;

  while (lo < hi)
  {
    int mid = (lo + hi)/2;

    if (arr[mid] < ele)
    {
      lo = mid + 1;
    }
    else
    {
      hi = mid;
    }
  }

  return arr[hi];
}

int upper_bound(vi &arr, int ele)
{
  int lo = 0, hi = arr.size() - 1;

  while (lo < hi)
  {
    int mid = (lo + hi)/2;

    if (arr[mid] <= ele)
    {
      lo = mid + 1;
    }
    else
    {
      hi = mid;
    }
  }

  return arr[hi];
}

int main()
{
  vi arr = {3, 5, 6, 7, 8, 8, 9, 10};
  cout << upper_bound(arr, 7) << "\n";
  cout << "hi";
  return 0;
}