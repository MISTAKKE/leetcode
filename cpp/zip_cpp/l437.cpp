#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int retval{0};
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, {}, targetSum);
        return retval;
    }
    void dfs(TreeNode* root, vector<int64_t> res, int targetSum) {
        if (root == nullptr) {
            return;
        }
        for (int i = 0; i < res.size(); ++i) {
            res[i] = 0L + res[i] + root->val;
            if (res[i] == targetSum) {
                retval += 1;
            }
        }
        res.push_back(root->val);
        if (root->val == targetSum) {
            retval += 1;
        }

        dfs(root->left, res, targetSum);

        dfs(root->right, res, targetSum);
    }
};

int main() {
    Solution A;

    return 0;
}
