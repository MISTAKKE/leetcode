#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/
class Solution1  // no recursion   bfs
{
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root != NULL) {
            q.push(root);
        }
        while (!q.empty()) {
            int cnt = q.size();
            res.push_back(vector<int>());
            while (cnt-- > 0) {
                TreeNode* p = q.front();
                q.pop();
                res.back().push_back(p->val);
                if (p->left != NULL)
                    q.push(p->left);
                if (p->right != NULL)
                    q.push(p->right);
            }
        }
        return res;
    }
};

class Solution  // recursion   bfs
{
  public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root != NULL) {
            dfs(root, 0);
        }
        return res;
    }
    void dfs(TreeNode* p, int level) {
        if (res.size() == level) {
            res.push_back(vector<int>());
        }
        res[level].push_back(p->val);
        if (p->left != NULL)
            dfs(p->left, level + 1);
        if (p->right != NULL)
            dfs(p->right, level + 1);
    }
};

int main() {
    Solution A;

    TreeNode l(1, NULL, NULL);
    TreeNode r(4, NULL, NULL);
    TreeNode r1(3, NULL, NULL);
    TreeNode r2(6, NULL, NULL);
    r.left = &r1;
    r.right = &r2;
    TreeNode p(5);
    p.left = &l;
    p.right = &r;
    show(A.levelOrder(&p));

    return 0;
}
