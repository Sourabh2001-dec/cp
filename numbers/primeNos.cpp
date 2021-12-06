// check if a numbver is prime

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    bool flag = false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        cout << "Not a Prime Number";
    }
    else
    {
        cout << "Prime number";
    }
    return 0;
}
