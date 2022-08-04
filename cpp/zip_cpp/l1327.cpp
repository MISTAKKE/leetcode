#include "../tool/helper.cpp"
using namespace std;

/*
给你一棵以 root 为根的二叉树，二叉树中的交错路径定义如下：

选择二叉树中 任意 节点和一个方向（左或者右）。
如果前进方向为右，那么移动到当前节点的的右子节点，否则移动到它的左子节点。
改变前进方向：左变右或者右变左。
重复第二步和第三步，直到你在树中无法继续移动。
交错路径的长度定义为：访问过的节点数目 - 1（单个节点的路径长度为 0 ）。

请你返回给定树中最长 交错路径 的长度。
*/

class Solution {
  public:
    int maxdepth;
    int longestZigZag(TreeNode* root) {
        maxdepth = 0;
        if (root->left != NULL) {
            get(root->left, true, 0);
        }
        if (root->right != NULL) {
            get(root->right, false, 0);
        }
        return maxdepth;
    }
    void get(TreeNode* root, bool direction, int depth) {
        maxdepth = depth + 1 > maxdepth ? depth + 1 : maxdepth;
        if (root->left != NULL) {
            if (direction)
                get(root->left, direction, 0);
            else
                get(root->left, !direction, depth + 1);
        }

        if (root->right != NULL) {
            if (direction)
                get(root->right, !direction, depth + 1);
            else
                get(root->right, direction, 0);
        }
    }
};

int main() {
    Solution A;

    return 0;
}
