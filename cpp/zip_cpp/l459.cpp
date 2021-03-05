#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string sdouble = s.substr(1, s.size() - 1) + s.substr(0, s.size() - 1);
        return sdouble.find(s) != string::npos;
    }
};
// 非质数
// 每个字母最少2次

int main()
{
    Solution A;
    cout<<A.repeatedSubstringPattern("a")<<endl;

    return 0;
}
