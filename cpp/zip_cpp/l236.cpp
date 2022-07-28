#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    //返回非空 ->  p和q的最近公共节点 (或 返回其中某一个点)
    //返回null -> root=null (或 p和q没有公共节点[实际不存在，我单独加的语义])
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }
        // 1 有一个为根 -> 返回根
        if (root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 2 都在左或右 -> 返回左或右
        // 3 分开两侧 -> 返回root
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        if (right != nullptr && left != nullptr) {
            return root;
        }
        return nullptr;
    }
};

int main() {
    Solution A;

    return 0;
}
