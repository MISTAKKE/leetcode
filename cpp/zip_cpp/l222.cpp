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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
class Solution1 {
  public:
    int countNodes(TreeNode* root) {
        int h = 0;
        TreeNode* t = root;
        while (t != nullptr) {
            t = t->left;
            ++h;
        }
        int left = 1;                   //最小不在其中的
        int right = pow(2, h - 1) - 1;  //最大不在其中的
        // h = 4时 最下面一层是 8-15
        //             1
        //       2            3
        //    4    5      6      7
        //  8 [9 10 11  12 13  14 15]
        //将最下面一层都减去8，则为 0-7
        while (left <= right) {
            int mid = (left + right) / 2;
            if (exist(root, h, mid)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return pow(2, h - 1) + left - 1;
    }
    bool exist(TreeNode* root, int h, int val) {
        while (--h != 0) {
            if ((val & (1 << (h - 1))) == 0) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return root != nullptr;
    }
};

int main() {
    Solution A;
    TreeNode* root{nullptr};
    cout << A.countNodes(root) << endl;

    return 0;
}
