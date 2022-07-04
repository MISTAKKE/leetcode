#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        int samecnt = 1;
        int interval = 2001;

        for (int i = 1; i < nums.size(); ++i) {
            int nowgap = nums[i] - nums[i - 1];
            if (nowgap == interval) {
                samecnt += 1;
            }
            else {
                samecnt = 1;
                interval = nowgap;
            }
            res += (samecnt - 1);
        }
        return res;
    }
};

int main() {
    Solution A;
    vector<int> nums{1, 2, 3, 4, 5};
    cout << A.numberOfArithmeticSlices(nums) << endl;

    return 0;
}
