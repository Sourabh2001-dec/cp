#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++)
  {
    int sunnyCount = 0;
    int rainyCount = 0;
    for (int i = 0; i < 7; i++)
    {
      int day;
      cin >> day;
      if (day == 1)
      {
        sunnyCount++;
      }
      else
      {
        rainyCount++;
      }
    }

    if (sunnyCount > rainyCount)
    {
      cout << "YES";
    }
    else
    {
      cout << "NO";
    }

    cout << "\n";
  }

  return 0;
}
