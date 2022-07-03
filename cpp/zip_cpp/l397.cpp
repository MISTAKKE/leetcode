#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int integerReplacement(int n) {
        map<int, int> dp;
        return dfs(dp, n, n);
    }
    int dfs(vector<int>& dp, int n, int i) {
        if (i == 1) {
            return 0;
        }
        if (dp[i] != 0) {
            return dp[i];
        }
        if (i % 2 == 0) {
            dp[i] = dfs(dp, n, i / 2) + 1;
            cout << "i:" << i << " dp[i]:" << dp[i] << endl;
        }
        else {
            dp[i] = min(dfs(dp, n, (i - 1)), dfs(dp, n, (i + 1))) + 1;
            if (i == 7) {
                cout << "---- dp[i]: " << dp[i] << endl;
            }
        }
        return dp[i];
    }
};

int main() {
    Solution A;
    for (int i = 7; i < 9; ++i) {
        cout << "i:" << i << " val:" << A.integerReplacement(i) << endl;
    }
    return 0;
}
