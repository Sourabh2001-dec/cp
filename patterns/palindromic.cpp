//         1
//       2 1 2
//     3 2 1 2 3
//   4 3 2 1 2 3 4
// 5 4 3 2 1 2 3 4 5

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    // n is row
    // spaces = n - row
    // n - row to 2 and 1 to row no.

    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << "  ";
        }
        for (int k = i; k >= 2; k--)
        {
            cout << k << " ";
        }
        for (int l = 1; l <= i; l++)
        {
            cout << l << " ";
        }
        cout << endl;
    }

    return 0;
}
