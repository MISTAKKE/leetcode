#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Solution
{
public:
    vector<int>dp;
    Solution()
    {
        dp.resize(1000);
        dp[0]=1;
        dp[1]=1;
    }
    int f(int n )
    {
        if(dp[n] !=0)
            return dp[n];
        dp[n] = f(n-1) + f(n-2);
        return dp[n];
    }
};


int main()
{
    Solution A;
    for(int i = 0; i<100; ++i)
    {
        A.f(i);
    }

    return 0;
}
