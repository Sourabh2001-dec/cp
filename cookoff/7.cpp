#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++)
  {
    int N, F, V, Fi;
    cin >> N;
    cin >> F;
    cin >> V;
    cin >> Fi;
    if (V >= N && (Fi + F) >= N)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }

  return 0;
}
