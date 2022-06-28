#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }
        sort(nums.begin(), nums.end());
        int maxval = nums[0];
        int maxcnt = 1;
        vector<int> dp(nums.size(), 1);
        //通过 N^2 找到哪个数字最大
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        //确定最大的次数 以及他的值
        for (int i = 0; i < nums.size(); ++i) {
            if (dp[i] > maxcnt) {
                maxcnt = dp[i];
                maxval = nums[i];
            }
        }
        //找到对应的子集
        vector<int> res{};
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (dp[i] == maxcnt && maxval % nums[i] == 0) {
                // cout << "maxcnt:" << maxcnt << " nums[i]:" << nums[i] << endl;
                maxcnt -= 1;
                //注意此处需要将最大值替换为当前值 避免k1 k2 k3  k2与k3不整除
                maxval = nums[i];
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution A;
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 16, 17, 18};
    show(A.largestDivisibleSubset(nums));
    return 0;
}
