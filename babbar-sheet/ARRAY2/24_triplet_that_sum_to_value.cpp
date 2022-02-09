// 24.Find a triplet that sum to a given value.
// [Practice here: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0 ]

#include <bits/stdc++.h>
using namespace std;

// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
  sort(A, A + arr_size);

  for (int i = 0; i < arr_size; i++)
  {

    int reqSum = sum - (A[i]);
    int pn1 = i + 1;
    int pn2 = arr_size - 1;
    while (pn1 < pn2)
    {
      int currSum = A[pn1] + A[pn2];
      if (currSum == reqSum)
        return true;
      if (currSum < reqSum)
        pn1++;
      if (currSum > reqSum)
        pn2--;
    }
  }

  // If we reach here, then no triplet was found
  return false;
}

/* Driver code */
int main()
{
  int A[] = {1, 4, 45, 6, 10, 1};
  int sum = 11;
  int arr_size = sizeof(A) / sizeof(A[0]);
  cout << find3Numbers(A, arr_size, sum);
  return 0;
}
