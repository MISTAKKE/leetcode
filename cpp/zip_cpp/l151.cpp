#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        string ret = "";
        string res = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                ret += s[i];
            }
            else
            {
                if (!ret.empty())
                {
                    ret += ' ';
                    res += ret;
                    ret = "";
                }
            }
        }
        if (!ret.empty())
        {
            ret += ' ';
            res += ret;
        }
        return res;
    }
    string strreverse(string s, int i, int j)
    {
        string str = "";
        for (int k = j; j >= i; --k)
        {
            str += s[k];
        }
        return str;
    }
};

int main()
{
    Solution A;

    return 0;
}
