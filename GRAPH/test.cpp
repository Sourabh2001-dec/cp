#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string intToRoman(int num)
  {
    unordered_map<int, string> cov;
    cov[1] = "I";
    cov[5] = "V";
    cov[10] = "X";
    cov[50] = "L";
    cov[100] = "C";
    cov[500] = "D";
    cov[1000] = "M";
    cov[4] = "IV";
    cov[9] = "IX";
    cov[40] = "XL";
    cov[90] = "XC";
    cov[400] = "CD";
    cov[900] = "CM";

    vector<int> nums = {1, 5, 10, 50, 100, 500, 1000};

    int cpnum = num;
    int place = 1;
    string output = "";
    while (cpnum)
    {
      int last = cpnum % 10;
      cpnum /= 10;
      int cpplace = place;
      while (cpplace--)
      {
        last *= 10;
      }
      if (cov.find(last) == cov.end())
      {
        while (last)
        {
          int closest = NULL;
          for (auto i : nums)
          {
            if (i <= last)
              closest = i;
          }
          last -= closest;
          output.append(cov[closest]);
        }
      }
      place++;
    }

    return output;
  }
};