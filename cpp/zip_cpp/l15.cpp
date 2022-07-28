#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 3; ++i) {
            // nums[i]是目标值 去除已处理过的
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end && start <= nums.size() - 2 && end >= i + 2) {
                if (nums[start] + nums[end] + nums[i] == 0) {
                    res.push_back({nums[start], nums[end], nums[i]});
                    start += 1;
                    end -= 1;
                    while (start <= nums.size() - 3 && nums[start - 1] == nums[start])
                        start += 1;
                    while (end >= i + 3 && nums[end + 1] == nums[end])
                        end -= 1;
                }
                else if (nums[start] + nums[end] + nums[i] > 0) {
                    end -= 1;
                }
                else {
                    start += 1;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution A;
    vector<int> vec{0, 0, 0};
    show(A.threeSum(vec));
    return 0;
}
