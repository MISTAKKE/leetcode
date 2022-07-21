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
        int h = 0;
        TreeNode* t = root;
        while (t != nullptr) {
            t = t->left;
            ++h;
        }
        int left = 0;
        int right = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (exist(root, h, mid)) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
    bool exist(TreeNode* root, int h, int val) {}
};

int main() {
    Solution A;

    return 0;
}
