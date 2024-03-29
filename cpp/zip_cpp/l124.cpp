#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    int res;
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        res = root->val;
        help(root);
        return res;
    }
    //已当前节点开始， 任意节点结束， 最大的pathval
    int help(TreeNode* root) {
        //返回当前节点加上左或者右最大的值，计算时可以更新res
        if (root == NULL)
            return 0;
        int left = 0;
        int right = 0;
        if (root->left != NULL)
            left = max(help(root->left), 0);//0保证了非叶子节点为最终节点
        if (root->right != NULL)
            right = max(help(root->right), 0);
        res = max(left + right + root->val, res);
        return max(left, right) + root->val;
    }
};

int main() {
    Solution A;

    return 0;
}
