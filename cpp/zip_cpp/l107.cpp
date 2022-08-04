#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution1  // recursion
{
  public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root != NULL)
            dfs(root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(TreeNode* root, int level) {
        if (res.size() == level) {
            res.push_back(vector<int>());
        }
        res[level].push_back(root->val);
        if (root->left != NULL) {
            dfs(root->left, level + 1);
        }
        if (root->right != NULL) {
            dfs(root->right, level + 1);
        }
    }
};

// Class Solution
class Solution  // no recursion
{
  public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root != NULL) {
            q.push(root);
        }
        while (!q.empty()) {
            int cnt = q.size();
            res.push_back(vector<int>());
            while (cnt-- > 0) {
                TreeNode* t = q.front();
                q.pop();
                res.back().push_back(t->val);
                if (t->left != NULL)
                    q.push(t->left);
                if (t->right != NULL)
                    q.push(t->right);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
int main() {
    Solution A;

    TreeNode l(2, NULL, NULL);
    TreeNode r(23, NULL, NULL);

    TreeNode l2(76, NULL, NULL);
    TreeNode r1(761, NULL, NULL);

    TreeNode l22(13, NULL, NULL);
    TreeNode r12(134, NULL, NULL);
    l.right = &l2;
    r.left = &r1;
    l2.right = &l22;
    r1.right = &r12;

    TreeNode p(1);
    p.left = &l;
    p.right = &r;
    show(A.levelOrderBottom(&p));
    return 0;
}
