#include <bits/stdc++.h>
using namespace std;

// generalize function or class as far as data type is concerned

//========================================================================================
/*                                                                                      *
 *                                   Function Template                                  *
 *                                                                                      */
//========================================================================================

template <class X> // mutliple <class X, class Y>
X big(X a, X b)
{
    if (a > b)
        return a;
    else
        return b;
}

// overloading
// double big(double a, double b)
// {
//     if (a > b)
//         return a;
//     else
//         return b;
// }

//========================================================================================
/*                                                                                      *
 *                                    Class Template                                    *
 *                                                                                      */
//========================================================================================

template <class X>
class Hello
{
private:
    X a;

public:
    Hello(X b)
    {
        a = b;
    }

    void print()
    {
        cout << a << "\n";
    }
};

int main(int argc, char const *argv[])
{
    cout << big<int>(2, 3) << "\n";
    cout << big(2.56, 3.67) << "\n";

    Hello<float> a(5.5);
    a.print();

    return 0;
}
