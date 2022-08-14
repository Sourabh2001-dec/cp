#include <bits/stdc++.h>
using namespace std;

// __vptr is created in class which contains virtual functions
// Its child will inherit the same __vptr
// static array vtable is created which is pointed by vptr
// array contains pointer to functions
// tables are created for each classes even without any object
// virtual functions are mapped accordingly in the respective tables

class A
{
public:
    virtual void f1() { cout << "class A\n"; };
    virtual void f2() { cout << "Class A f2\n"; };
};

class B : public A
{
public:
    void f1() { cout << "Class B\n"; };
};

int main(int argc, char const *argv[])
{
    A *p1, o1;
    B o2;
    p1 = &o2;
    o2.f1();
    p1->f1();
    p1->f2();
    return 0;
}
