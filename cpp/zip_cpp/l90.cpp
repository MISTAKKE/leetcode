#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
1 <= nums.length <= 10
-10 <= nums[i] <= 10

*/

// Class Solution
class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 3:   000 ->  111=2^3-1
        for (int i = 0; i < (1 << nums.size()); ++i) {
            bool flag = true;
            vector<int> val;
            for (int j = 0; j < nums.size(); ++j) {
                //j在其中
                if ((i & (1 << j)) != 0) {
                    //j-1 未选择 但值相等
                    if (j > 0 && ((i & (1 << (j - 1))) == 0) && nums[j - 1] == nums[j]) {
                        flag = false;
                        break;
                    }
                    val.push_back(nums[j]);
                }
            }
            if (flag) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
int main() {
    Solution A;
    vector<int> nums{1, 1, 2};
    show(A.subsetsWithDup(nums));
    return 0;
}
