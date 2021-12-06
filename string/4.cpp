#include <bits/stdc++.h>
using namespace std;

void getReverseSent(string str)
{
    char *ch = new char[str.length()];
    for (int i = 0; i < str.length(); i++)
    {
        ch[i] = str[i];
        int found = 0;
        for (int j = 0; j < i; j++)
        {
            if (str[i] == ch[j])
            {
                found++;
            }
        }
        if (found == 1)
        {
            cout << " " << str[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    string str = "thiissconntaiasdfwernmbsmkmagsoidf";
    getReverseSent(str);
    return 0;
}
