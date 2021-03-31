#include "../tool/helper.cpp"
using namespace std;

/*
description:
    0 <= amount (总金额) <= 5000
    1 <= coin (硬币面额) <= 5000
    硬币种类不超过 500 种
    结果符合 32 位符号整数
*/

//Class Solution
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto &&coin : coins)
        {
            for (int i = 0; i + coin <= amount; i++)
            {
                dp[i + coin] += dp[i];
            }
        }
        return dp[amount];
    }
};

int main()
{
    Solution A;

    return 0;
}
