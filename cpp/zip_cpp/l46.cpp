#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/
class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int start) {
        // end
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        // try
        backtrack(res, nums, start + 1);
        for (int i = start + 1; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            backtrack(res, nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
};

// Class Solution
class Solution2 {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int left) {
        if (left == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = left; i < nums.size(); ++i) {
            swap(nums[left], nums[i]);
            backtrack(res, nums, left + 1);
            swap(nums[left], nums[i]);
        }
    }
};

int main() {
    Solution A;
    vector<int> vec{1, 2, 3};
    vector<vector<int>> res = A.permute(vec);
    for (auto c : res) {
        show(c);
    }

    return 0;
}
