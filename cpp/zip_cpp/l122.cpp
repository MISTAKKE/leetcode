#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1){
            return 0;
        }
        int hold = 0 - prices[0];
        int not = 0;
        for(int i = 1; i<prices.size(); ++i){
            hold = max(not - prices[i], hold);
            not = max(prices[i] + hold, not);
        }
        return not;
    }
};

class Solution2 {
  public:
    int maxProfit(vector<int>& prices) {
        int hold = -1 * prices[0];
        int nothold = 0;
        for (int i = 1; i < prices.size(); ++i) {
            hold = max(hold, nothold - (prices[i]));
            nothold = max(nothold, hold + prices[i]);
        }  //因为在一天之内不会同时买卖，所以在计算nothold时，昨天的hold一定等于今天的hold

        return nothold;
    }
};

int main() {
    Solution A;
    vector<int> nums{7,1,5,3,6,4};
    cout<<A.maxProfit(nums)<<endl;
    return 0;
}
