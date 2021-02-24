#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
#define forp(i, s, n) for (int i = (s); i < (n); i++)
class Solution
{
public:
    string reorganizeString(string S)
    {
        string ret;
        vector<pair<char, int>> vec(26, make_pair('a', 0));
        forp(i, 0, 26)
        {
            vec[i].first = 'a' + i;
        }
        for (auto c : S)
        {
            vec[c - 'a'].second += 1;
        }

        return ret;
    }
};

int main()
{
    Solution A;

    return 0;
}
