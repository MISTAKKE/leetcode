#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Solution
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
