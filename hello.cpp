#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left_ptr = 0;
        int right_ptr = 0;
        int maxLen = 0;
        unordered_set<char> letters;
        while (right_ptr < s.size())
        {
            if (letters.find(s[right_ptr]) != letters.end())
            {
                letters.insert(s[right_ptr]);
                right_ptr++;
                int setSize = letters.size();
                maxLen = max(maxLen, setSize);
            }
            else
            {
                letters.erase(s[left_ptr]);
                left_ptr++;
            }
        }

        return maxLen;
    };
};

int main(int argc, char const *argv[])
{
    cout << Solution().lengthOfLongestSubstring("abcabcbb");
    return 0;
}
