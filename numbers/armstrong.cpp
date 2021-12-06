//  check if a number is a armstrong number

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int sum = 0;
    int originaln = n;

    while (n > 0)
    {
        int lastDigit = n % 10;
        int cube = ceil(pow(lastDigit, 3));
        sum += cube;
        n = n / 10;
    }

    if (sum == originaln)
    {
        cout << "Armstrong number";
    }
    else
    {
        cout << "Not armstrong number";
    }
    return 0;
}
