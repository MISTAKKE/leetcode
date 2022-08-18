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
class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 0x7fffffff);
        dp[0] = 0;
        for (auto&& c : coins) {
            if (c <= amount) {
                dp[c] = 1;
            }
        }
        for (int i = 2; i <= amount; ++i) {
            //如果 i 能凑齐 一定是从某个值 [得到] 一枚硬币而成功
            for (auto&& c : coins) {
                if (i >= c && dp[i - c] != 0x7fffffff) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        return dp[amount] == 0x7fffffff ? -1 : dp[amount];
    }
};

//非递归
class Solution2 {
  public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 1000000);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] <= amount) {
                dp[coins[i]] = 1;
            }
        }
        for (int i = 1; i <= amount; ++i) {
            for (int k = 0; k < coins.size() && coins[k] <= amount; ++k) {
                if (i - coins[k] >= 0) {
                    dp[i] = min(dp[i], dp[coins[k]] + dp[i - coins[k]]);
                }
            }
        }
        return dp[amount] == 1000000 ? -1 : dp[amount];
    }
};

int main() {
    Solution A;
    vector<int> coins{1, 2, 5};
    cout << A.coinChange(coins, 0) << endl;
    return 0;
}
