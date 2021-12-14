#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Solution
{
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return res;
        res.push_back(root->val);
        if (root->left != NULL)
            preorderTraversal(root->left);
        if (root->right != NULL)
            preorderTraversal(root->right);
        return res;
    }
};

class Solution2
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> q;
        if (root != NULL)
            q.push(root);
        vector<int> res;
        while (!q.empty())
        {
            TreeNode *tmp = q.top();
            q.pop();
            if (tmp->right != NULL)
            {
                q.push(tmp->right);
            }
            if (tmp->left != NULL)
            {
                q.push(tmp->left);
            }
            res.push_back(tmp->val);
        }
        return res;
    }
};

int main()
{
    Solution A;

    return 0;
}
