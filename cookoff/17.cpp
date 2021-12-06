#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll X,Y;
        cin >> X >> Y;
        if((X+Y)%2 == 0){
          cout << "YES\n";
        }
        else{
          cout << "NO\n";
        }

    }
    return 0;
}