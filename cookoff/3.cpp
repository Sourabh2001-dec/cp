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
        bool printOdd = 1;
        bool isEven = N % 2 == 0;
        int Odd = isEven ? N - 1 : N;
        int Even = isEven ? N : N - 1;

        for (int i = 0; i < N; i++)
        {
            if (printOdd)
            {
                cout << " " << Odd;
                Odd -= 2;
                printOdd = 0;
            }
            else
            {
                cout << " " << Even;
                Even -= 2;
                printOdd = 1;
            }
        }

        cout << "\n";
    }

    return 0;
}
