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
    // dp2
    int deleteAndEarn(vector<int>& nums) {
        vector<int> cnt(10001, 0);
        int maxval = 0;
        for (auto c : nums) {
            cnt[c] += 1;
            maxval = max(maxval, c);
        }
        int giveuped = 0, choosed = 0;
        for (int i = 1; i <= maxval; ++i) {
            int choose = giveuped + cnt[i] * i;
            giveuped = max(giveuped, choosed);
            choosed = choose;
        }
        return max(giveuped, choosed);
    }
};

int main() {
    Solution A;
    // vector<int> nums{2, 2, 3, 3, 3, 4};//9
    // vector<int> nums{1, 3};  // 4
    vector<int> nums{10, 8, 4,  2, 1, 3,  4, 8,  2, 9, 10, 4, 8, 5,  9, 1, 5, 1,  6, 8,  1,  1, 6,  7, 8,
                     9,  1, 7,  6, 8, 4,  5, 4,  1, 5, 9,  8, 6, 10, 6, 4, 3, 8,  4, 10, 8,  8, 10, 6, 4,
                     4,  4, 9,  6, 9, 10, 7, 1,  5, 3, 4,  4, 8, 1,  1, 2, 1, 4,  1, 1,  4,  9, 4,  7, 1,
                     5,  1, 10, 3, 5, 10, 3, 10, 2, 1, 10, 4, 1, 1,  4, 1, 2, 10, 9, 7,  10, 1, 2,  7, 5};
    cout << A.deleteAndEarn(nums) << endl;

    return 0;
}
