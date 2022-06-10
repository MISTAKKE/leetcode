#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ret(s.substr(0, 1));
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (j == i - 1) {
                    dp[j][i] = (s[i] == s[j]);
                }
                else {
                    dp[j][i] = dp[j + 1][i - 1] && (s[i] == s[j]);
                }
                if (dp[j][i] && (i - j + 1 > ret.size())) {
                    ret = s.substr(j, i - j + 1);
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution A;
    string str = "abacccc";
    cout << A.longestPalindrome(str) << endl;

    return 0;
}
