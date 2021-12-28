#include <bits/stdc++.h>
using namespace std;

int LCS(vector<string> seq1, vector<string> seq2, int size1, int size2)
{
  if (size1 == 0 || size2 == 0)
  {
    return 0;
  }

  // last elements are same decrement from both
  if (seq1[size1 - 1] == seq2[size2 - 1])
  {
    return 1 + LCS(seq1, seq2, size1 - 1, size2 - 1);
  }
  else
  {
    // return combination of 1 removed and another kept and vice-versa
    return max(LCS(seq1, seq2, size1, size2 - 1), LCS(seq1, seq2, size1 - 1, size2));
  }
}

int main(int argc, char const *argv[])
{
  vector<string> seq1 = {"a", "b", "d", "e", "g"};
  vector<string> seq2 = {"a", "b", "c", "e", "f"};
  cout << LCS(seq1, seq2, seq1.size(), seq2.size());
  return 0;
}
