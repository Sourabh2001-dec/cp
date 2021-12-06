#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll X,Y,Z;
        cin >> X >> Y >> Z;
        if(X+(2*Z) >= Y){
          cout << "YES\n";
        }
        else{
          cout << "NO\n";
        }

    }
    return 0;
}