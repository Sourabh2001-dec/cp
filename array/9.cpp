#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int size, min, max;
    bool init = 1;
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size - 1; i++)
    {
        scanf("%d ", &arr[i]);
    }
    scanf("%d", &arr[size - 1]);

    for (int i = 0; i < size; i++)
    {
        int ele = arr[i];

        if (init)
        {
            min = ele;
            max = ele;
            init = 0;
        }
        else
        {
            if (ele < min)
            {
                min = ele;
            }

            if (ele > max)
            {
                max = ele;
            }
        }
    }

    cout << "Range : " << max - min << endl;

    return 0;
}
