#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int min, max = arr[0];
    bool init = 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    cout << "MAX : " << max << endl;
    cout << "MIN : " << min << endl;

    return 0;
}
