#include <bits/stdc++.h>
using namespace std;

void getOccuringChars(string str)
{
    vector<int> count(256, 0);
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        count[str[i]]++;
    }

    char *ch = new char[str.length()];

    for (int i = 0; i < len; i++)
    {
        // copy current char to array
        ch[i] = str[i];
        int find = 0;

        // search for the char in the ch and increment count
        for (int j = 0; j < i; j++)
        {
            if (str[i] == ch[j])
            {
                find++;
            }
        }

        // if an occurrence is not found earlier than print the count
        if (find == 0)
        {
            cout << "Occurrence of " << str[i] << " is: " << count[str[i]] << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    getOccuringChars(str);
    return 0;
}
