#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp(nums1.size(), 0);
        dp[0] = (nums1[0] == nums2[0]);
        for (int i = 1; i < nums1.size(); ++i) {
            dp[i] = dp[i - 1] || (nums1[i] == nums2[0]);
        }
        // show(dp);
        for (int k = 1; k < nums2.size(); ++k) {
            int lastval = dp[0];
            dp[0] = dp[0] || (nums1[0] == nums2[k]);
            for (int i = 1; i < nums1.size(); ++i) {
                int nowval = dp[i];
                dp[i] = (nums1[i] == nums2[k]) ? lastval + 1 : max(dp[i - 1], dp[i]);
                lastval = nowval;
            }
            // show(dp);
        }
        return dp.back();
    }
};

int main() {
    Solution A;
    vector<int> nums1{2, 5, 1, 2, 5};
    vector<int> nums2{10, 5, 2, 1, 5, 2};
    cout << A.maxUncrossedLines(nums1, nums2) << endl;

    return 0;
}
