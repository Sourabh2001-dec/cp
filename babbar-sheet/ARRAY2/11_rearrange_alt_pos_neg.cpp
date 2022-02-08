// 11.Rearrange the array in alternating positive and negative items with
// O(1) extra space. [follow link : https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/ ]

#include <bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &arr)
{
  // N^2 apprach :(

  // bool checkPos = arr[0] > -1;
  // for (int i = 0; i < arr.size(); i++)
  // {
  //   checkPos = !checkPos;
  //   if (!checkPos && arr[i] > -1)
  //     continue;
  //   if (checkPos && arr[i] < 0)
  //     continue;

  //   for (int j = i + 1; j < arr.size(); j++)
  //   {
  //     if ((!checkPos && arr[j] > -1) || (checkPos && arr[j] < 0))
  //     {
  //       swap(arr[j], arr[i]);
  //       break;
  //     }
  //   }
  // }

  int i = 0;
  int j = arr.size() - 1;
  while (i < j)
  {
    if (arr[i] < 0 && arr[j] > -1)
    {
      swap(arr[i], arr[j]);
    }

    while (arr[i] > -1)
      i++;
    while (arr[j] < 0)
      j--;
  }

  i = 1;
  j++;

  while (arr[i] > -1)
  {
    swap(arr[i], arr[j]);
    i += 2;
    j++;
  }

  cout << i << " " << j << endl;
}

int main(int argc, char const *argv[])
{
  vector<int> arr = {10, 4, -3, -50, 23, -90};
  rearrange(arr);
  for (auto &&i : arr)
  {
    cout << i << " ";
  }

  return 0;
}
