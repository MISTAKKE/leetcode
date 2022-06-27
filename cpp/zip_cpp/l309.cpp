#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
/*
dp[0] 最后一次操作为买入
dp[1] 最后一次操作为卖出
dp[2] 最后一次操作为冻结
*/
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(3, -50000);
        dp[2] = 0;
        for (auto c : prices) {
            int t0, t1, t2;
            t0 = max(dp[0], dp[2] - c);
            t1 = max(dp[1], dp[0] + c);
            t2 = max(dp[2], dp[1]);
            dp[0] = t0;
            dp[1] = t1;
            dp[2] = t2;
        }
        return max(dp[1], dp[2]);
    }
};
/*
dp[0] 当前操作为买入
dp[1] 当前操作为卖出
dp[2] 当前无操作-未持有股票
dp[3] 当前无操作-已持有股票
*/
class Solution1 {
  public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(4, -50000);
        dp[2] = 0;
        for (auto c : prices) {
            int t0, t1, t2, t3;
            t0 = dp[2] - c;
            t1 = max(dp[0], dp[3]) + c;
            t2 = max(dp[1], dp[2]);
            t3 = max(dp[0], dp[3]);
            dp[0] = t0;
            dp[1] = t1;
            dp[2] = t2;
            dp[3] = t3;
        }
        return max(dp[1], dp[2]);
    }
};

int main() {
    Solution A;
    vector<int> prices{1, 2, 3, 0, 2};
    cout << A.maxProfit(prices) << endl;

    return 0;
}
