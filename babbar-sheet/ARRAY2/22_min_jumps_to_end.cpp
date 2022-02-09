// 22. Minimum number of Jumps to reach end.
// [Practice here: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0 ]

#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
  return (x > y) ? x : y;
}

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{
  if (n <= 1)
  {
    return 0;
  }

  if (arr[0] == 0)
  {
    return -1;
  }

  int maxReach = arr[0];
  int step = arr[0];
  int jump = 1;

  for (int i = 1; i < n; i++)
  {
    if (i == n - 1)
    {
      return jump;
    }

    maxReach = max(maxReach, i + arr[i]);
    step--;

    if (step == 0)
    {
      jump++;

      // our maxReach ended just in earlier cell
      if (i >= maxReach)
      {
        return -1;
      }

      // steps of one of the jump we have taken are to be used
      step = maxReach - i;
    }
  }

  return -1;
}

// Driver program to test above function
int main()
{
  int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int size = sizeof(arr) / sizeof(int);

  // Calling the minJumps function
  cout << ("Minimum number of jumps to reach end is %d ",
           minJumps(arr, size));
  return 0;
}