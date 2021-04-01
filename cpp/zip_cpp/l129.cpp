#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Solution
{
public:
    int res;
    int sumNumbers(TreeNode *root)
    {
        res = 0;
        if (root != NULL)
            helper(root, 0);
        return res;
    }
    void helper(TreeNode *root, int val)
    {
        if (root->left != NULL)
        {
            helper(root->left, val * 10 + root->val);
        }
        if (root->right != NULL)
        {
            helper(root->right, val * 10 + root->val);
        }
        if (root->left == NULL && root->right == NULL)
        {
            res += val * 10 + root->val;
        }
    }
};

int main()
{
    Solution A;

    return 0;
}
