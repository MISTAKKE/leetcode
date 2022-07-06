#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

1 <= nums.length <= 2 * 10^4
1 <= nums[i] <= 10^4

*/

// Class Solution

class Solution {
  public:
    // dp1
    int deleteAndEarn2(vector<int>& nums) {
        vector<int> cnt(10001, 0);
        int maxval = 0;
        for (auto c : nums) {
            cnt[c] += 1;
            maxval = max(maxval, c);
        }
        vector<vector<int>> dp(maxval + 1, vector<int>{0, 0});
        for (int i = 1; i <= maxval; ++i) {
            dp[i][1] = dp[i - 1][0] + i * cnt[i];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        return max(dp[maxval][0], dp[maxval][1]);
    }
    // not dp as math
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        bool theswitch = true;
        int d1 = nums[0], d2 = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i] - 1 || nums[i - 1] == nums[i]) {
                cout << "i" << i - 1 << " nums[i-1]:" << nums[i - 1] << " nums[i]:" << nums[i] << endl;
                theswitch = (nums[i - 1] == nums[i]) * theswitch;
                d1 += nums[i] * theswitch;
                d2 += nums[i] * !theswitch;
            }
            else {
                res += max(d1, d2);
                d1 = nums[i - 1];
                d2 = 0;
                theswitch = true;
            }
        }
        // res += max(d1, d2);
        return res;
    }
};

int main() {
    Solution A;
    vector<int> nums{2, 2, 2, 3, 3, 3, 4};
    cout << A.deleteAndEarn(nums) << endl;

    return 0;
}
