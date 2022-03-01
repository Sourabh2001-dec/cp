// 3. Write a Program to check whether a string is a valid shuffle of two
// strings or not.
// [Follow here: https://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings/ ]

#include <bits/stdc++.h>
using namespace std;

bool isInterleaved(int i, int j, string s1, string s2, string s3, map<pair<int, int>, bool> &cache)
{
  // i -> pointer to char in s1
  // j -> pointer to char in s2
  if (i == s1.length() && j == s2.length())
  {
    return true;
  }

  if (cache.find(make_pair(i, j)) != cache.end())
  {
    return cache[make_pair(i, j)];
  }

  if (i < s1.length() && s1[i] == s3[i + j] && isInterleaved(i + 1, j, s1, s2, s3, cache))
  {
    return true;
  }
  
  if (j < s2.length() && s2[j] == s3[i + j] && isInterleaved(i, j + 1, s1, s2, s3, cache))
  {
    return true;
  }

  return cache[make_pair(i, j)] = false;
}

int main(int argc, char const *argv[])
{
  string s1 = "AB";
  string s2 = "GC";
  string s3 = "AGFB";
  map<pair<int, int>, bool> cache;
  cout << isInterleaved(0, 0, s1, s2, s3, cache);
  return 0;
}
