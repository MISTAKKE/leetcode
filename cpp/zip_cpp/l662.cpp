#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    // int widthOfBinaryTree(TreeNode* root) {
    // 贪心:每次都选最左侧或者右侧的path，当最长的不在最左或者最右则gg
    //     TreeNode* p = root;
    //     TreeNode* q = root;
    //     int64_t maxval = 0;
    //     int64_t leftval = 1;
    //     int64_t rightval = 1;
    //     while (1) {
    //         if (p->left != nullptr) {
    //             p = p->left;
    //             leftval = 2 * leftval;
    //         }
    //         else if (p->right != nullptr) {
    //             p = p->right;
    //             leftval = 2 * leftval + 1;
    //         }
    //         else {
    //             break;
    //         }

    //         if (q->right != nullptr) {
    //             q = q->right;
    //             rightval = 2 * rightval + 1;
    //         }
    //         else if (q->left != nullptr) {
    //             q = q->left;
    //             rightval = 2 * rightval;
    //         }
    //         else {
    //             break;
    //         }
    //         maxval = max(maxval, rightval - leftval);
    //     }
    //     return maxval;
    // }
};

int main() {
    Solution A;

    return 0;
}