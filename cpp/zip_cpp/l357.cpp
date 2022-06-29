#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(9, 0);
        dp[1] = 11;
        dp[2] = 91;
        for (int i = 3; i <= 8; ++i) {
            int res = 9;
            for (int j = 9; j > 9 - i + 1; --j) {
                res = res * j;
            }
            dp[i] = dp[i - 1] + res;
        }
        show(dp);
        return dp[n];
    }
};

int main() {
    Solution A;
    cout << A.countNumbersWithUniqueDigits(8) << endl;

    return 0;
}
