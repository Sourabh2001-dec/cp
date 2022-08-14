#include <bits/stdc++.h>
using namespace std;

struct MyData
{
    int p;
    MyData()
    {
        p = 10;
    }
    MyData(int a)
    {
        p = a;
    }
};

int add() { return 1; };

main(int argc, char const *argv[])
{
    // static array allocation of size 3 and allocated in stack memory
    int statArr[3];
    // statArr acts as pointer to first element of array
    *statArr = 1;
    *(statArr + 1) = 2; // pointer arithmetics used => add offset of 1*sizeof(int)
    *(statArr + 2) = 3;

    cout << statArr[1] << "\n";

    // dynamic array allocation of size 3 and allocated in heap memory
    int *dynArr = new int[3];
    // dynArr is the pointer to first memory block
    *dynArr = 1;
    *(dynArr + 1) = 2;
    *(dynArr + 2) = 3;

    cout << dynArr[1] << "\n";

    // array containing pointers to MyData object
    MyData *ptrArr[3];
    ptrArr[0] = new MyData(4);
    ptrArr[1] = new MyData(5);
    ptrArr[2] = new MyData(7);

    cout << ptrArr[1]->p << "\n";

    // same above with dyanmic allocation
    // two * because pointer to array of pointers is being returned by new operator
    MyData **ptrArr2 = new MyData *[3];
    ptrArr2[0] = new MyData(4);
    ptrArr2[1] = new MyData(5);
    ptrArr2[2] = new MyData(7);

    cout << ptrArr2[1]->p << "\n";

    // pointer to first element of array containing MyData type elements and calling default constructors
    MyData *arr = new MyData[4];

    cout << arr->p << "\n";
    // output : 10

    // 2d arrays
    int a2d[2][2];
    a2d[0][0] = 1;
    cout << a2d[0][0] << "\n";

    // inner * dereferences and refers to pointer of inner array
    // outer * again dereferences and gives value of first element of inner array
    cout << *(*(a2d)) << "\n";

    // dyanmically assign a linear block of memory
    int *ddarr = new int[3 * 4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            *(ddarr + i * 3 + j) = 4;
        }
    }

    // 2d array using array of pointers
    int m = 3, n = 4, c = 0;

    // Declare memory block of size M
    int **a = new int *[m];

    for (int i = 0; i < m; i++)
    {

        // Declare a memory block
        // of size n
        a[i] = new int[n];
    }

    // Traverse the 2D array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            // Assign values to the
            // memory blocks created
            a[i][j] = ++c;
        }
    }

    // pointer to a function with no params and returning int
    int (*p)() = &add;
    cout << (*p)() << "\n";
}
