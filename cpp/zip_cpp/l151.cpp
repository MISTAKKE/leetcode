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
        string tmp = "";
        string res = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                tmp += s[i];
            }
            else
            {
                if (!tmp.empty())
                {
                    reverse(tmp.begin(), tmp.end());
                    if (!res.empty())
                        res += " ";
                    res += tmp;
                    tmp = "";
                }
            }
        }
        if (!tmp.empty())
        {
            reverse(tmp.begin(), tmp.end());
            if (!res.empty())
                res += " ";
            res += tmp;
        }
        return res;
    }
};

int main()
{
    Solution A;
    string str = "  abc edf ghijk  lom    ";
    cout << A.reverseWords(str) << endl;

    return 0;
}
