#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int k;
    cin >> k;
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size - 1; i++)
    {
        scanf("%d ", &arr[i]);
    }
    scanf("%d", &arr[size - 1]);

    // bubble sort
    for (int i = size; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "largest : " << arr[size - k] << endl;
    cout << "smallest : " << arr[k - 1] << endl;

    return 0;
}
