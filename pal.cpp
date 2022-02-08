#include <bits/stdc++.h>
using namespace std;

string largestPal(string s)
{
  map<char, int, greater<char>> freq;
  for (char i : s)
  {
    freq[i]++;
  }

  bool isOddFound = false;
  string result = "";
  string middleEle = "";
  for (auto it = freq.begin(); it != freq.end(); it++)
  {
    char num = it->first;
    int count = it->second;

    // odd handling
    if (count % 2 != 0)
    {
      if (isOddFound)
        return "-1";
      else
      {
        isOddFound = true;
        middleEle = num;
        continue;
      }
    }

    // even handling
    string elems(count / 2, num);
    result.append(elems);
  }

  string half = result;
  reverse(half.begin(), half.end());

  result += middleEle;
  result.append(half);

  return result;
}

int main(int argc, char const *argv[])
{
  string s = "8833009";
  cout << largestPal(s);
  return 0;
}
