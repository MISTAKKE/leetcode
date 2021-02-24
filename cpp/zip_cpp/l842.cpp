#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    vector<int> splitIntoFibonacci(string S)
    {
        vector<int> ret;
        if (backtrack(S, 0, ret))
            return ret;
        return {};
    }
    bool backtrack(const string &s, int start, vector<int> &vec)
    {
        if (vec.size() >= 3 && vec[vec.size() - 1] - vec[vec.size() - 2] != vec[vec.size() - 3])//加法可能溢出，用减法
        {
            return false;
        }
        if (s.size() == start)
        {
            if(vec.size()>=3)
                return true;
            return false;
        }
        for (int size = 1; size + start <= s.size(); ++size)
        {
            long tmp = strtolong(s, start, size);
            if (tmp == -1)
            {
                continue;
            }
            vec.push_back(tmp);
            if (backtrack(s, start + size, vec))
            {
                return true;
            }
            vec.pop_back();
        }
        return false;
    }
    long strtolong(const string &s, int start, int size)
    {
        long tmp = 0;
        if (s[start] == '0' && size >= 2)
            return -1;
        for (int i = 0; i < size; ++i)
        {
            tmp = tmp * 10 + (s[start + i] - '0');
            if (tmp > __INT_MAX__)
                return -1;
        }
        return tmp;
    }
};
int main()
{
    Solution A;
    string str = "214748364721474836422147483641";
    show(A.splitIntoFibonacci(str));
    return 0;
}