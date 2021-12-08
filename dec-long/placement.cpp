#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int N;
  cin >> N;
  while (N--)
  {
    map<string, int> prefs;
    for (int i = 0; i < 3; i++)
    {
      string company;
      cin >> company;
      prefs[company] = i + 1;
    }
    string offer1, offer2;
    cin >> offer1 >> offer2;
    if (prefs.find(offer1)->second < prefs.find(offer2)->second)
    {
      cout << offer1 << endl;
    }
    else
    {
      cout << offer2 << endl;
    }
  }

  return 0;
}
