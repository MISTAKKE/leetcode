#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int64_t d1 = 0l + p->val - root->val;
        int64_t d2 = 0l + q->val - root->val;
        if (d1 == 0 || d2 == 0) {
            return root;
        }
        if (d1 < 0) {
            if (d2 < 0) {
                return lowestCommonAncestor(root->left, p, q);
            }
            return root;
        }
        if (d2 < 0) {
            return root;
        }
        return lowestCommonAncestor(root->right, p, q);
    }
};

int main() {
    Solution A;

    return 0;
}
