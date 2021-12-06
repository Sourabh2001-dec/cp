#include <bits/stdc++.h>
using namespace std;

void getReverseSent(string str)
{
    // erase removes the chars in the given range
    // remove function returns an iterator where the given elements are present after this
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    cout << str;
}

int main(int argc, char const *argv[])
{
    string str = " asdf asdf asdf asd f";
    getReverseSent(str);
    return 0;
}
