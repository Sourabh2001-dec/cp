#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++)
  {
    int N;
    cin >> N;
    if ((N / 2) % 2 != 0)
    {
      cout << "NO\n";
    }
    else
    {
      cout << "YES\n";
      int sub = 3;
      int start = N;
      int count = N / 2;
      while (count > 0)
      {
        cout << start << " ";
        start -= sub;
        if (sub == 3)
        {
          sub = 1;
        }
        else
        {
          sub = 3;
        }
        count--;
      }
      cout << "\n";
      sub = 1;
      start = 2;
      count = N / 2;
      while (count > 0)
      {
        cout << start << " ";
        start += sub;
        if (sub == 3)
        {
          sub = 1;
        }
        else
        {
          sub = 3;
        }
        count--;
      }
      cout << "\n";
    }
  }

  return 0;
}
