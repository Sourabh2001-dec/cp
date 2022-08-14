#include <bits/stdc++.h>
using namespace std;

// Friend Function

// ✔️ not a member function of a class to which it is a friend
// ✔️ declared in class with friend keyword
// ✔️ must be defined outside the class to which it is friend
// ✔️ can access any member of the class to which it is a friend
// ✔️ cannot access members directly but by passing objects as parameters
// ✔️ has no caller object
// ✔️ should not be defined with membership label ::

class Complex2;

//========================================================================================
/*                                                                                      *
 *                                     Complex Class                                    *
 *                                                                                      */
//========================================================================================

class Complex
{
public:
    Complex()
    {
        a = 1;
        b = 2;
    }

    void print()
    {
        cout << a << " " << b << "\n";
    }

    // ⚠️ member functions can access private variables of another instance of same class as well
    // 🟩 below code works fine
    Complex operator+(Complex &num)
    {
        Complex temp;
        temp.a = a + num.a;
        temp.b = b + num.b;

        return temp;
    }

    friend void add(Complex &a, Complex &b);

    friend void operator++(Complex &a, int);

    friend Complex2 operator+(Complex2 &a, Complex &num);

    friend ostream &operator<<(ostream &, Complex &);

private:
    int a, b;
};

//========================================================================================
/*                                                                                      *
 *                                    Complex2 Class                                    *
 *                                                                                      */
//========================================================================================

class Complex2
{
public:
    Complex2()
    {
        a = 1;
        b = 2;
    }

    void print()
    {
        cout << a << " " << b << "\n";
    }

    //💀 below code wont work as it tries to access member of instance of another class
    // Complex2 operator+(Complex &num)
    // {
    //     Complex2 temp;
    //     temp.a = a + num.a;
    //     temp.b = b + num.b;

    //     return temp;
    // }

    friend Complex2 operator+(Complex2 &a, Complex &num);

private:
    int a, b;
};

//========================================================================================
/*                                                                                      *
 *                       Overloaded Operators as friend functions                       *
 *                                                                                      */
//========================================================================================

// it returns a ostream reference because the operators are chained and the same ostream should be used in next operation
// ⚠️ we can create our own ostream object but we need to pass a buffer to the constructor. for example we can pass file buffer and the output will be streamed to file
ostream &operator<<(ostream &dout, Complex &obj)
{
    dout << obj.a << " " << obj.b << "\n";
    return dout;
}

//────  ──────────────────────────────────────────────────────────────────────────────────

Complex2 operator+(Complex2 &a, Complex &num)
{
    Complex2 temp;
    temp.a = a.a + num.a;
    temp.b = a.b + num.b;

    return temp;
}

//────  ──────────────────────────────────────────────────────────────────────────────────
// overload post increment operator
void operator++(Complex &a, int)
{
    a.a++;
    a.b++;
    cout << "Post Increment ++\n";
}

//────  ──────────────────────────────────────────────────────────────────────────────────
void add(Complex &a, Complex &b)
{
    a.a += b.a;
    a.b += b.b;
}

//========================================================================================
/*                                                                                      *
 *                                      Driver Code                                     *
 *                                                                                      */
//========================================================================================


int main(int argc, char const *argv[])
{
    Complex a, b, c;
    add(a, b);
    c = a + b;

    c.print();

    // friend function cannot be called by object as
    // a.add(a,b); ❌

    a.print();
    b.print();
    cout << a;

    // using overloaded + operator
    Complex2 a2;
    a++;
    Complex2 b2 = a2 + a;
    b2.print();

    // ⚠️ This is how cin >> abc works!
    // int abc;
    // cin.operator>>(abc);
    return 0;
}
