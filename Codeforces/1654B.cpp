#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string input;
    cin >> input;
    unordered_map<char, int> freq;
    for (char c : input)
    {
      freq[c]++;
    }

    ll lenToTrim = 0;
    for (char c : input)
    {
      if (freq[c] == 1)
        break;
      lenToTrim++;
      freq[c]--;
    }

    ll len = input.length();
    input.erase(0, lenToTrim);
    cout << input << "\n";
    // cout << input.substr(lenToTrim - 1, len - lenToTrim - 1);
  }
  return 0;
}