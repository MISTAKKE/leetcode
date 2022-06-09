#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
313. 超级丑数
超级丑数 是一个正整数，并满足其所有质因数都出现在质数数组 primes 中。
给你一个整数 n 和一个整数数组 primes ，返回第 n 个 超级丑数 。
题目数据保证第 n 个 超级丑数 在 32-bit 带符号整数范围内。



示例 1：
输入：n = 12, primes = [2,7,13,19]
输出：32
解释：给定长度为 4 的质数数组 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。

示例 2：
输入：n = 1, primes = [2,3,5]
输出：1
解释：1 不含质因数，因此它的所有质因数都在质数数组 primes = [2,3,5] 中。

提示：
1 <= n <= 10e6
1 <= primes.length <= 100
2 <= primes[i] <= 1000
题目数据 保证 primes[i] 是一个质数
primes 中的所有值都 互不相同 ，且按 递增顺序 排列

*/

// Class Solution

class Solution {
    /*
    1. 第一个丑数是1
    2. 后续的丑数一定要从前面的某个丑数，乘以 primes中的某个数 而来
    3. 每个primes中的指针，最初都指向第一个丑数，每用一次则向后移动一位
    4. 每次取出最小的 dp[idx] * primes[idx]
    */
  public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> idx(primes.size(), 1);
        vector<int> dp(n + 1, 0x7fffffff);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int k = 0; k < primes.size(); ++k) {
                dp[i] = min(dp[i], dp[idx[k]] * primes[k]);
                // cout << "n:" << n << " i:" << i << " k:" << k << " idx[k]:" << idx[k] << " dp[idx[k]]:" << dp[idx[k]]
                //  << " primes[k]:" << primes[k] << " mul:" << dp[idx[k]] * primes[k] << " dp[n]:" << dp[n] << endl;
            }
            for (int k = 0; k < primes.size(); ++k) {
                if (dp[i] == dp[idx[k]] * primes[k]) {
                    idx[k] += 1;
                }
            }
        }
        return dp[n];
    }
};
int main() {
    Solution A;
    vector<int> primes{2, 3, 5};
    cout << A.nthSuperUglyNumber(10, primes) << endl;

    return 0;
}
