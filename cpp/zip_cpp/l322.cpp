#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
322. 零钱兑换
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。



示例 1：
输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1

示例 2：
输入：coins = [2], amount = 3
输出：-1

示例 3：
输入：coins = [1], amount = 0
输出：0


提示：
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4

*/

// Class Solution

//非递归
class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] <= amount) {
                dp[coins[i]] = 1;
            }
        }

        for (int i = 1; i <= amount; ++i) {
            for (int k = coins[0]; k < i - coins[0]; ++k) {
                if (dp[k] != -1 && dp[i - k] != -1) {
                    if (dp[i] != -1) {
                        dp[i] = min(dp[i], dp[k] + dp[i - k]);
                    }
                    else {
                        dp[i] = dp[k] + dp[i - k];
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution A;
    vector<int> coins{1, 2, 5};
    cout << A.coinChange(coins, 11) << endl;
    return 0;
}
