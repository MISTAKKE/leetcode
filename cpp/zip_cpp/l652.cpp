#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        map<string, int> record;
        dfs(root, res, record);
        return res;
    }
    string dfs(TreeNode* root, vector<TreeNode*>& res, map<string, int>& record) {
        // cout << "dress:" << &root << endl;
        if (root == nullptr) {
            return "N";
        }
        string result =
            "L" + dfs(root->left, res, record) + "#" + to_string(root->val) + "#R" + dfs(root->right, res, record);
        if (record[result] == 1) {
            show(result);
            res.push_back(root);
        }
        record[result] += 1;
        return result;
    }
};

int main() {
    Solution A;
    TreeNode* t = new TreeNode(0);
    TreeNode* t1 = new TreeNode(0);
    TreeNode* t2 = new TreeNode(0);
    TreeNode* t3 = new TreeNode(0);
    TreeNode* t4 = new TreeNode(0);
    TreeNode* t5 = new TreeNode(0);
    t->left = t1;
    t->right = t2;
    t1->left = t3;
    t2->right = t4;
    t4->right = t5;
    A.findDuplicateSubtrees(t);

    return 0;
}
