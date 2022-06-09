#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

204. 计数质数
给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。



示例 1：
输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

示例 2：
输入：n = 0
输出：0

示例 3：
输入：n = 1
输出：0


提示：
0 <= n <= 5 * 1e6
*/

// Class Solution

class Solution {
    /*
    使用o(n)存储 每个数都乘以每个素数，直接记录下来
    */
  public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<bool> isprime(n, true);  //假设所有数都是
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isprime[i]) {
                ans += 1;
                primes.push_back(i);
            }
            // vector<int> now;
            //遍历每个素数
            for (int j = 0; i * primes[j] < n; ++j) {
                isprime[primes[j] * i] = false;
                // now.push_back(primes[j] * i);
                if (i % primes[j] == 0) {
                    break;
                }
            }
            // cout << "i=" << i << "    ";
            // show(now);
        }
        // show(primes);
        return ans;
    }
};
class Solution2 {
    /*
    使用o(n)存储 每个素数其倍数，直接记录下来
    */
  public:
    int countPrimes(int n) {
        vector<bool> isprime(n, true);  //假设所有数都是
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isprime[i]) {
                ans += 1;
                for (int j = i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }

        return ans;
    }
};

class Solution1 {
    /*
    普通的解法，递归每一个数，不存储
    */
  public:
    bool isprime(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            ans += isprime(i);
        }

        return ans;
    }
};

int main() {
    Solution A;
    cout << A.countPrimes(5e6) << endl;

    return 0;
}
