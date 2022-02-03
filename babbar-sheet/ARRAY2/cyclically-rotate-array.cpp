// Write a program to cyclically rotate an array by one.
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n);

int main()
{
  int n = 5;
  int a[5] = {1, 2, 3, 4, 5};
  rotate(a, n);
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}
// } Driver Code Ends

void rotate(int arr[], int n)
{
  for (int i = n - 1; i > 0; i--)
  {
    swap(arr[i], arr[i - 1]);
  }
}