#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int wheels;
        cin >> wheels;
        if(wheels%4 == 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    
    return 0;
}
