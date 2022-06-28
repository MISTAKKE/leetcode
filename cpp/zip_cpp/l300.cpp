#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res{nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > res.back()) {
                res.push_back(nums[i]);
            }
            else {
                int idx = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
                res[idx] = nums[i];
            }
        }
        return res.size();
    }
};

int main() {
    Solution A;
    vector<int> nums{1, 3, 15, 2, 4, 5};
    cout << A.lengthOfLIS(nums) << endl;

    return 0;
}
