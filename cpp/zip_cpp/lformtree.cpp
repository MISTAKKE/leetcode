#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

class Solution
{
public:
    TreeNode *formtree(vector<int> &vec)
    {
        if (vec.size() == 0)
            return NULL;
        int cnt = 1;
        cout << "formtree:" << endl;
        TreeNode r(1);
        TreeNode *root = &r;
        queue<TreeNode *> q;
        root->left = NULL;
        root->right = NULL;
        q.push(root);
        return root;

        while (vec.size() > cnt)
        {
            int count = q.size();
            cout << count << endl;
            while (count-- > 0)
            {
                TreeNode *now = q.front();
                q.pop();
                if (now != NULL && now->val != -1)
                {
                    TreeNode left(vec[cnt++]);
                    now->left = &left;
                    if (now->left->val != -1)
                    {
                        q.push(now->left);
                    }

                    TreeNode right(vec[cnt++]);
                    now->right = &right;
                    if (now->right->val != -1)
                    {
                        q.push(now->right);
                    }
                }
            }
        }
        return root;
    }

    vector<vector<int>> res;
    void dfs(TreeNode *p, int level)
    {
        if (res.size() == level)
        {
            res.push_back(vector<int>());
        }
        res[level].push_back(p->val);
        if (p->left != NULL)
            dfs(p->left, level + 1);
        if (p->right != NULL)
            dfs(p->right, level + 1);
    }
    void show(TreeNode *root)
    {
        if (root != NULL)
        {
            dfs(root, 0);
        }
    }
};
int main()
{
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

    vector<int> vec{3, 9, 20, -1, -1, 15, 7};
    Solution A;
    TreeNode *root = A.formtree(vec);
    A.show(root);
    return 0;
}
