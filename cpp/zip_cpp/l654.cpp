#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

1 <= nums.length <= 1000
0 <= nums[i] <= 1000
nums 中的所有整数 互不相同
*/

// Class Solution

class Solution {
  public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // nums.size >= 1
        int maxidx = 0;
        int maxval = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > maxval) {
                maxval = nums[i];
                maxidx = i;
            }
        }
    }
};

int main() {
    Solution A;

    return 0;
}
