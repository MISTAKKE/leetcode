#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    int maxval{0};
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxval;
    }
    int depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        maxval = max(maxval, left + right);
        return max(left, right) + 1;
    }
};
int main() {
    Solution A;

    return 0;
}
