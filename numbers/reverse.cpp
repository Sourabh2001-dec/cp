// reverse the given number

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int reversed = 0;
    while (n > 0)
    {
        reversed = reversed * 10 + (n % 10);
        n = n / 10;
    }

    cout << reversed;

    return 0;
}
