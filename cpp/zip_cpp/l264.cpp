#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0x7fffffff);
        dp[1] = 1;
        vector<int> idx{1, 1, 1};
        vector<int> primes{2, 3, 5};
        for (int i = 2; i <= n; ++i) {
            for (int k = 0; k <= 2; ++k) {
                dp[i] = min(dp[i], dp[idx[k]] * primes[k]);
            }
            for (int k = 0; k <= 2; ++k) {
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
    cout << A.nthUglyNumber(10) << endl;

    return 0;
}
