// 19. GCD of given index ranges in an array
// [Solut<ion : https://www.geeksforgeeks.org/gcds-of-a-given-index-ranges-in-an-array/ ]
#include <bits/stdc++.h>
using namespace std;

struct query
{
  int start;
  int end;
};

int gcd(int a, int b)
{
  int small = min(a, b);
  int large = max(a, b);

  if (large % small == 0)
  {
    return small;
  }
  else
  {
    int rem = large % small;
    return gcd(small, rem);
  }
}

void printGcd(vector<int> &arr, vector<query> &queries)
{
  for (query q : queries)
  {
    int prevGcd = arr[q.start];
    for (int i = q.start + 1; i <= q.end; i++)
    {
      prevGcd = gcd(prevGcd, arr[i]);
    }

    cout << prevGcd << " ";
  }
}

int main(int argc, char const *argv[])
{
  vector<int> arr = {2, 3, 60, 90, 50};
  vector<query> queries = {{1, 3}, {2, 4}, {0, 2}};
  printGcd(arr, queries);
  return 0;
}
