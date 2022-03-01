// 2. Write a program to remove Duplicate characters from the String.
// [Follow here: https://www.geeksforgeeks.org/remove-duplicates-from-a-given-string/ ]
#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
  unordered_set<char> chars;
  string result = "";
  for (char i : s)
  {
    chars.insert(i);
  }

  for (auto i = chars.begin(); i != chars.end(); i++)
  {
    result += *(i);
  }

  return result;
}

int main(int argc, char const *argv[])
{
  string s = "aasdfoewohasdufbaweriubaosd";
  cout << removeDuplicates(s);
  return 0;
}
