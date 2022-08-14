#include <bits/stdc++.h>
using namespace std;

//========================================================================================
/*                                                                                      *
 *                      ⚠️ Excessive friends harms encapsulation ⚠️                     *
 *                                                                                      */
//========================================================================================


//========================================================================================
/*                                                                                      *
 *                      Class member functions as friend functions                      *
 *                                                                                      */
//========================================================================================

class B;

class A
{
public:
    int Func1(B &b);

private:
    int pvtA = 6;
    int Func2(B &b);
};

class B
{
private:
    int _b = 12;

public:
    // 1️⃣ Only Method as friend
    // A::Func1 is a friend function to class B
    // so A::Func1 has access to all members of B
    //    friend int A::Func1( B& );

    // 2️⃣ All methods as friend
    friend class A;
};

int A::Func1(B &b)
{
    cout << pvtA << "\n";
    return b._b;
} // OK
// int A::Func2( B& b ) { return b._b; }   // C2248

int main(int argc, char const *argv[])
{
    /* code */
    A a;
    B b;

    // When they mean it cannot be called using the object of
    // the class of which it is friend
    // b.Func1(b); ❌

    cout << a.Func1(b);
    return 0;
}
