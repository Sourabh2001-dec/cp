// n = 5
// 1 2 3 4 5
// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
