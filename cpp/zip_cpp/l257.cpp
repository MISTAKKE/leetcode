#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    vector<string> res{""};
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int idx = 1;
        while (1) {}
        // for (int i = 0; i < res.size(); ++i) {
        //     res[i] += std::to_string(root->val);
        //     if (root->left != nullptr) {
        //         binaryTreePaths(root->left);
        //     }
        //     if (root->right != nullptr) {
        //         binaryTreePaths(root->right);
        //     }
        // }
        return res;
    }
};

int main() {
    Solution A;

    return 0;
}
