#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
      int D,L,R;
      cin >> D;
      cin >> L;
      cin >> R;
      if(D >= L && D<= R){
        cout << "Take second dose now\n";
      }
      else if(D < L){
        cout << "Too Early\n";
      }
      else{
        cout << "Too Late\n";
      }
    }
    
    return 0;
}
