#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    int strangePrinter(string s) {
        if (s.size() <= 1)
            return s.size();
        char now = '1';
        string ss = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == now)
                continue;
            ss += s[i];
            now = s[i];
        }
        vector<vector<int>> dp(ss.size(), vector<int>(ss.size(), -1));
        return helper(0, ss.size() - 1, ss, dp);
    }

    int helper(int i, int j, string& ss, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = helper(i + 1, j, ss, dp) + 1;
        for (int k = i + 1; k <= j; ++k) {
            if (ss[k] == ss[i]) {
                dp[i][j] = min(dp[i][j], helper(i, k - 1, ss, dp) + helper(k + 1, j, ss, dp));
            }
        }
        return dp[i][j];
    }
};

int main() {
    Solution A;
    cout << A.strangePrinter("tbgtgb");

    return 0;
}
