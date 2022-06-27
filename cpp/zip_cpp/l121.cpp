#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int buy = 1000000;
        int sell = 0;
        for (auto c : prices) {
            buy = min(buy, c);
            sell = max(sell, c - buy);
        }
        return sell;
    }
};

int main() {
    Solution A;
    // vector<int> prices{7, 6, 5, 4, 3, 2, 1};//0
    vector<int> prices{7, 1, 5, 3, 6, 4};  // 5

    cout << A.maxProfit(prices) << endl;

    return 0;
}
