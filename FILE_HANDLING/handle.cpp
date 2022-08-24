#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    fstream myfile;

    // Write
    myfile.open("sourabh.txt", ios::out);
    if (myfile.is_open())
    {
        myfile << "Hello\n";
        myfile << "This is second\n";
        myfile.close();
    }

    // Append
    myfile.open("sourabh.txt", ios::app);
    if (myfile.is_open())
    {
        myfile << "Hello\n";
        myfile << "This is second\n";
        myfile.close();
    }

    // Read
    myfile.open("sourabh.txt", ios::in);
    if (myfile.is_open())
    {
        string line;
        while (getline(myfile, line))
        {
            cout << line << "\n";
        }
    }

    return 0;
}
