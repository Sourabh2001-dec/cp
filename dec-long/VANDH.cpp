#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
  ll N;
  cin >> N;
  while (N--)
  {
    ll hills, valleys;
    cin >> hills >> valleys;
    ll len = 0;
    // valley start from 1
    // hill start from 0
    if (valleys > hills)
    {
      string str = "1";
      for (ll i = 0; i < hills + 1; i++)
      {
        str += "01";
      }
      for (int i = 0; i < valleys - hills - 1; i++)
      {
        str += "101";
      }
      cout << str.length() << endl;
      cout << str << endl;
    }
    else if (valleys < hills)
    {
      string str = "0";
      for (ll i = 0; i < valleys + 1; i++)
      {
        str += "10";
      }
      for (int i = 0; i < hills - valleys - 1; i++)
      {
        str += "010";
      }
      cout << str.length() << endl;
      cout << str << endl;
    }
    else
    {
      string str = "";
      for (ll i = 0; i < (hills + valleys + 2) / 2; i++)
      {
        str += "01";
      }
      cout << str.length() << endl;
      cout << str << endl;
    }
  }

  return 0;
}
