// n = 5

//     * * * * *
//    * * * * *
//   * * * * *
//  * * * * *
// * * * * *

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= n; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
