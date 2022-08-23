#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int minNum = INT_MAX;
    int num;

    while (n--)
    {
        cin >> num;
        minNum = min(minNum, num);
    }

    cout << minNum << "\n";

    return 0;
}
