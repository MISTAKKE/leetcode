#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[i][i] = 0;
        }
        for (int i = 1; i <= n; ++i) {     // i = 1 .. n-1
            for (int k = 1; k < i; ++k) {  // k = 1 .. n-1
                int row = i - k;
                int col = i;
                // cout << "row:" << row << " col:" << col << endl;
                if (col - row == 1) {
                    dp[row][col] = row;
                }
                else if (col - row == 2) {
                    dp[row][col] = row + 1;
                }
                else if (col - row == 3) {
                    dp[row][col] = 2 * row + 2;
                }
                else if (col - row == 4) {
                    dp[row][col] = 2 * row + 4;
                }
                else {
                    int minval = col + dp[row][col - 1];
                    for (int idx = 1; idx < col - row; ++idx) {
                        // cout << "idx:" << idx << " dp[row][row + idx - 1]:" << dp[row][row + idx - 1]
                        //      << " row + idx:" << row + idx << " dp[row + idx + 1][col]:" << dp[row + idx + 1][col]
                        //      << endl;
                        minval = min(minval, max(dp[row][row + idx - 1], dp[row + idx + 1][col]) + (row + idx));
                    }
                    dp[row][col] = minval;
                }
            }
        }
        // show(dp);
        return dp[1][n];
    }
};

int main() {
    Solution A;
    cout << A.getMoneyAmount(10) << endl;

    return 0;
}
