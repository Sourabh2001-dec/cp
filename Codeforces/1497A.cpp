#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  map<int, int> freq;
  cin >> t;
  while (t--)
  {
    int len;
    cin >> len;
    while (len--)
    {
      int num;
      cin >> num;
      freq[num]++;
    }
    string repeat;
    for (auto i = freq.begin(); i != freq.end(); i++)
    {
      cout << i->first << " ";
      if (i->second > 1)
      {
        int times = i->second - 1;
        string rep;
        while (times--)
        {
          rep.append(to_string(i->first));
          rep += ' ';
        }
        repeat.append(rep);
      }
    }
    cout << repeat;
    cout << "\n";
    freq.clear();
  }
  return 0;
}