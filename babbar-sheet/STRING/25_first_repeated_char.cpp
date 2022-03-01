// Efficiently check First repeated character
// in C++ program
#include <bits/stdc++.h>
using namespace std;

// Returns -1 if all characters of str are
// unique.
// Assumptions : (1) str contains only characters
//				 from 'a' to 'z'
//			 (2) integers are stored using 32
//				 bits
int FirstRepeated(string str)
{
  // An integer to store presence/absence
  // of 26 characters using its 32 bits.
  int checker = 0;

  for (int i = 0; i < str.length(); i++)
  {
    int asciNum = (str[i] - 'a');
    if ((checker & (1 << asciNum)) > 0)
    {
      return i;
    }

    checker |= (1 << asciNum);
  }

  return -1;
}

// Driver code
int main()
{
  string s = "abcfdeacf";
  int i = FirstRepeated(s);
  if (i != -1)
    cout << "Char = " << s[i] << " and Index = " << i;
  else
    cout << "No repeated Char";
  return 0;
}
