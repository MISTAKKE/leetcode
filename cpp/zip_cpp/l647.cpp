#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = 1;
        int ret = dp[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i][i] = 1;
            if (s[i - 1] == s[i])
                dp[i - 1][i] = 1;
            ret = ret + dp[i][i] + dp[i - 1][i];
        }

        for (int i = 2; i < n; ++i) {
            for (int j = n - i; j > 0; j--) {
                // j次 i=0 j=5   0,0 1,1 2,2 3,3 4,4   i=0  j=5,4,3,2,1
                //     i=1 j=4   0,1 1,2 2,3 3,4       i=1  j=4,3,2,1
                //     i=2 j=3   0,2 1,3 2,4           i=2  j=3,2,1
                int x = n - j - i;
                int y = n - j;
                dp[x][y] = (s[x] == s[y]) && dp[x + 1][y - 1];
                ret += dp[x][y];
            }
        }

        show(dp);

        return ret;
    }
};

int main() {
    Solution A;
    string s = "abc";
    print(A.countSubstrings(s));

    return 0;
}
