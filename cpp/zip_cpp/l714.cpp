#include "../tool/helper.cpp"
using namespace std;

/*
description:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

*/

// Class Solution
class Solution {
  public:
    int maxProfit1(vector<int>& prices, int fee) {
        vector<int> dp1(prices.size(), 0);  // hold
        vector<int> dp2(prices.size(), 0);  // not hold
        dp1[0] -= prices[0] + fee;
        for (int i = 1; i < prices.size(); ++i) {
            dp1[i] = max(dp1[i - 1], dp2[i - 1] - (prices[i] + fee));  // hold
            dp2[i] = max(dp2[i - 1], dp1[i - 1] + prices[i]);          // not hold
        }

        return dp2.back();
    }
    int maxProfit2(vector<int>& prices, int fee) {
        int lastday_hold = -1 * (prices[0] + fee);

        int nothold = 0;
        int today_hold = 0;
        for (int i = 1; i < prices.size(); ++i) {
            today_hold = max(lastday_hold, nothold - (prices[i] + fee));
            nothold = max(nothold, lastday_hold + prices[i]);
            lastday_hold = today_hold;
        }

        return nothold;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -1 * (prices[0] + fee);
        int nothold = 0;
        for (int i = 1; i < prices.size(); ++i) {
            hold = max(hold, nothold - (prices[i] + fee));
            nothold = max(nothold, hold + prices[i]);
        }  //因为在一天之内不会同时买卖，所以在计算nothold时，昨天的hold一定等于今天的hold

        return nothold;
    }
};

int main() {
    Solution A;
    vector<int> prices{1, 3, 2, 8, 4, 9};
    cout << A.maxProfit(prices, 2) << endl;
    return 0;
}
