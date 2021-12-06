#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int size, negIter, iter;
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size - 1; i++)
    {
        scanf("%d ", &arr[i]);
    }
    scanf("%d", &arr[size - 1]);

    negIter = 0;
    iter = 1;

    while (iter < size)
    {
        if (arr[iter] < 0)
        {
            if (arr[negIter] < 0)
                negIter++;

            int temp = arr[iter];
            arr[iter] = arr[negIter];
            arr[negIter] = temp;

            negIter++;
        }

        iter++;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}