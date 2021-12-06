#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    int size;
    cin >> num;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    bool flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }

    return 0;
}
