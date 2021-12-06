#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++)
  {
    int len;
    cin >> len;
    int last = 3;

    if ((3 * len) % 9 == 0)
    {
      last = 9;
    }

    for (int j = 0; j < len - 1; j++)
    {
      cout << 3;
    }
    cout << last;

    cout << "\n";
  }

  return 0;
}
