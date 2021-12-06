#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int len, k;
        string bin;
        scanf("%d %d\n", &len, &k);
        cin >> bin;

        bool isKEven = k % 2 == 0;
        char start = bin[0];
        char end;

        if (start == '0')
        {
            end = !isKEven ? '1' : '0';
        }
        else if (start == '1')
        {
            end = !isKEven ? '0' : '1';
        }

        int steps = 0;
        int block = 0;
        for (int j = bin.length() - 1; j > 0; j--)
        {
            char current = bin[j];
            if (current == end)
            {
                steps++;
                if (block == 0)
                {
                    block = j + 1;
                }
                end = end == '0' ? '1' : '0';
                if (steps == k)
                {
                    break;
                }
            }
        }

        if (steps == k)
        {
            cout << block << "\n";
        }
        else
        {
            cout << "-1"
                 << "\n";
        }
    }

    return 0;
}
