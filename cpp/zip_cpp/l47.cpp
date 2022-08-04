#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int left) {
        if (left == nums.size()) {
            res.push_back(nums);
            return;
        }
        set<int> processed;
        for (int i = left; i < nums.size(); ++i) {
            if (processed.find(nums[i]) == processed.end()) {
                processed.insert(nums[i]);
                swap(nums[left], nums[i]);
                backtrack(res, nums, left + 1);
                swap(nums[left], nums[i]);
            }
        }
    }
};

int main() {
    Solution A;
    vector<int> vec{1, 1, 2};
    vector<vector<int>> res = A.permuteUnique(vec);
    for (auto c : res)
        show(c);
    return 0;
}
