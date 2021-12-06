#include <bits/stdc++.h>
using namespace std;

void getReverseSent(string str)
{
    int num = 0;
    stringstream number(str);
    number >> num;
    cout << num;
}

int main(int argc, char const *argv[])
{
    string str = "1045";
    getReverseSent(str);
    return 0;
}
