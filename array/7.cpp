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

    int occurrences = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == k)
            occurrences++;
    }

    cout << occurrences;

    return 0;
}
