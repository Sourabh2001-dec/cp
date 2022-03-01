// 18.
// Convert a Sentence into its equivalent mobile numeric keypad
// sequence.
// [Follow here: https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/ ]

#include <bits/stdc++.h>
using namespace std;

string keypadSeq(string input)
{
  unordered_map<char, string> seq;
  char num = '2', count = 1;
  for (char i = 'A'; i <= 'O'; i++)
  {
    seq[i] = string(count % 3 == 0 ? 3 : count % 3, num);
    if (count % 3 == 0)
      num++;
    count++;
  }

  num = '7', count = 1;
  for (char i = 'P'; i <= 'Z'; i++)
  {
    seq[i] = string(count % 4 == 0 ? 4 : count % 4, num);
    if (count % 4 == 0)
      num++;
    count++;
  }

  string result = "";
  for (char c : input)
  {
    result.append(seq[c]);
  }

  return result;
}

int main(int argc, char const *argv[])
{
  string input = "GEEKSFORGEEKS";
  cout << keypadSeq(input) << endl;
  return 0;
}
