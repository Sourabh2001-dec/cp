#include <bits/stdc++.h>
using namespace std;

void getReverseSent(string str)
{
    // word variable to store word
    string word;

    // making a string stream
    stringstream iss(str);

    // Read and print each word.
    while (iss >> word)
    {
        reverse(word.begin(), word.end());
        cout << word << " ";
    }
}

int main(int argc, char const *argv[])
{
    string str = "this is a word";
    getReverseSent(str);
    return 0;
}
