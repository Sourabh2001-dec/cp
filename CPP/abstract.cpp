#include <bits/stdc++.h>
using namespace std;

//========================================================================================
/*                                                                                      *
 *                                    ABSTRACT CLASS                                    *
 *                                                                                      */
//========================================================================================

// Even if one pure virtual function class is abstract
class Abstract
{
public:
    // special syntax to tell there is no definition of function
    // 🟩 PURE VIRTUAL FUNCTION - DO NOTHING FUNCTION
    virtual void solve() = 0;
    void solve2(){};
};

class Child : public Abstract
{
public:
    // ⚠️ NECESSARY FOR CHILD TO EITHER OVERRIDE OR DECLARE AS PURE VIRTUAL
    void solve(){};
};

int main(int argc, char const *argv[])
{
    // Abstract a; // ❌ Object cannot be made
    Child b;
    b.solve();
    b.solve2();
    return 0;
}
