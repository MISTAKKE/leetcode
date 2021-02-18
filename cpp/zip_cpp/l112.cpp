#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution1 //dfs recursion
{
public:
    bool hasPathSum(TreeNode *root, int targetSum, int val = 0)
    {
        //root is null
        if (root == NULL)
            return false;

        //root is leef
        if (root->left == NULL && root->right == NULL)
        {
            if (root->val + val == targetSum)
                return true;
            else
                return false;
        }

        //check left
        if (hasPathSum(root->left, targetSum, val + root->val))
            return true;

        //check right
        return hasPathSum(root->right, targetSum, val + root->val);
    }
};

class Solution //dfs backtrace
{
public:
    int val;
    int target;
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;
        val = 0;
        target = targetSum;
        return dfs(root);
    }
    bool dfs(TreeNode *p)
    {
        val += p->val;
        if (p->left == NULL && p->right == NULL && val == target)
            return true;
        if (p->left != NULL)
            if (dfs(p->left))
                return true;
        if (p->right != NULL)
            if (dfs(p->right))
                return true;
        val -= p->val;
        return false;
    }
};

int main()
{
    Solution A;

    return 0;
}
