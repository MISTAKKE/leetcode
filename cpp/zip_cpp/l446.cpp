#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // mp[i][d] = k  以nums[i]结尾，d为公差，的子序列个数为k
        vector<map<long long int, long long int>> mp(nums.size(), map<long long int, long long int>{});
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                long long int d = (long long int)nums[i] - (long long int)nums[j];
                mp[i][d] += (mp[j][d] + 1);
                //在处理完 nums[i] 后，需要将nums[i]结尾公差为d的子序列统计累加
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (auto c : mp[i]) {
                res += c.second;
            }
        }

        res -= ((nums.size() - 1) * (nums.size() - 0) / 2);
        return res;
    }
};
int main() {
    Solution A;
    // vector<int> nums{2, 4, 6, 8, 10};  // 7
    // vector<int> nums{2, 4, 6, 8};  // 3
    // vector<int> nums{1, 2, 3, 4, 5, 6};  // 12
    // vector<int> nums{7, 7, 7, 7, 7};  // 16
    vector<int> nums{7, 7, 7, 7};  // 5
    // vector<int> nums{7, 7, 7};  // 1
    // vector<int> nums{0, 2000000000, -294967296};
    cout << A.numberOfArithmeticSlices(nums) << endl;

    return 0;
}
