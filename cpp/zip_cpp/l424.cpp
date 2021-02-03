#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0;
        map<char, int> mp;
        for (int i = 0; i < 26; ++i)
        {
            mp[i + 'A'] = 0;
        }
        if (s.size() == 0)
            return 0;
        int maxlength = k;

        for (int right = 0; right < s.size(); ++right)
        {
            char &c = s[right];
            mp[c] += 1;
            char maxchar;
            int maxval = 0;
            int otherval = 0;
            for (auto k : mp)
            {
                if (k.second > maxval)
                {
                    maxchar = k.first;
                    maxval = k.second;
                }
                otherval += k.second;
            }
            otherval -= maxval;
            if (k < otherval)
            {
                mp[s[left]] -= 1;
                left++;
                while (s[left] == s[left - 1] && s[left] == maxchar)
                {
                    mp[s[left]] -= 1;
                    left++;
                }
            }
            else
            {
                maxlength = max(maxlength, right - left + 1);
            }
        }
        return maxlength;
    }
};

int main()
{
    Solution A;
    string s = "AAABAACAAAA";
    //cout<<A.characterReplacement(s, 1);
    return 0;
}
