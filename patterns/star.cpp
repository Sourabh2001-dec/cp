//     *
//   * * *
// * * * * *
// * * * * *
//   * * *
//     *

// n = 3

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        // spaces = n - i
        // stars = 2i - 1
        for (int k = n - i; k >= 1; k--)
        {
            cout << "  ";
        }
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = n; i >= 1; i--)
    {
        for (int k = n - i; k >= 1; k--)
        {
            cout << "  ";
        }
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
