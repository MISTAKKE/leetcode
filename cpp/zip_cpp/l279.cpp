#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (i * i <= n)
            {
                dp[i * i] = 1;
            }
            if (dp[i] == 1)
                continue;
            int minval = i; //init as multi 1
            for (int k = 1; k*k < i; ++k)
            {
                minval = min(minval, dp[k*k] + dp[i - k*k]);
            }
            dp[i] = minval;
        }
        return dp[n];
    }
};

int main()
{
    Solution A;
    for (int i = 1; i < 20; ++i)
    {
        cout << "i:" << i << " cnt:" << A.numSquares(i) << endl;
    }

    return 0;
}
