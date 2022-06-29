#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    //打表
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp{1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851};
        return dp[n];
    }
    int countNumbersWithUniqueDigits2(int n) {
        vector<int> dp(9, 1);
        for (int i = 1; i <= 8; ++i) {
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
