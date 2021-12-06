// anagram => words formed by rearranging chars of the parent word
#include <bits/stdc++.h>
using namespace std;

void isAnagram(string parent, string word)
{
    int parLen = parent.length();
    int wordLen = word.length();

    if (parLen != wordLen)
    {
        cout << "FALSE";
        return;
    }

    vector<bool> checked(parLen, 0);

    for (int i = 0; i < wordLen; i++)
    {
        char ch = word[i];

        bool found = 0;
        for (int j = 0; j < parLen; j++)
        {
            if (parent[j] == ch && !checked[j])
            {
                found = 1;
                checked[j] = 1;
                break;
            }
        }

        if (!found)
        {
            cout << "FALSE";
            return;
        }
    }
    cout << "TRUE";
}

int main(int argc, char const *argv[])
{
    string parent = "stressed";
    string word = "desserts";
    isAnagram(parent, word);
    return 0;
}
