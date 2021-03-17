#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    vector<vector<int>> memo;
    int getsum(int total = 100)
    {
        for (int i = 0; i <= 100; ++i)
        {
            memo.push_back(vector<int>());
            for (int j = 0; j <= 10; ++j)
                memo[i].push_back(0);
        }
        return helper(total, 1);
    }

    int helper(int total, int now) //return cnt
    {
        if (memo[total][now] != 0)
            return memo[total][now];
        if (now == 10 || (total + now == 11)) //9 10 2 over   8 10 3   1 10 over
        {
            return 1;
        }
        int maxsize = total - 10 + now; //100 -10 + 1 = 91
        int cnt = 0;
        for (int i = 1; i <= maxsize; ++i)
        {
            cnt += helper(total - i, now + 1);
        }
        memo[total][now] = cnt;
        return memo[total][now];
    }
};

int main()
{
    Solution A;
    cout << getsum() << endl;

    return 0;
}
