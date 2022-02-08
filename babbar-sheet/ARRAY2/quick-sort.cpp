// 6. Sort an Array using Quicksort algorithm.
// [ Follow link: https://www.geeksforgeeks.org/quick-sort/ ]

#include <bits/stdc++.h>
using namespace std;

int partitionArr(vector<int> &arr, int low, int high)
{
  int pivot = arr[high]; // pivot
  int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

  for (int j = low; j <= high - 1; j++)
  {
    // If current element is smaller than the pivot
    if (arr[j] < pivot)
    {
      i++; // increment index of smaller element
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quicksort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pivot = partitionArr(arr, low, high);

    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
  }
}

int main(int argc, char const *argv[])
{
  vector<int> arr = {1, 7, 2, 7, 3, 5, 323, 536, 12, 123, 45};
  quicksort(arr, 0, arr.size() - 1);
  for (int num : arr)
  {
    cout << num << " ";
  }
  return 0;
}
