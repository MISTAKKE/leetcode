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
    int maxPathSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        res = root->val;
        res = max(help(root->left) + help(root->right) + root->val, res);
        return res;
    }
    int help(TreeNode *root)
    {
        //返回当前节点加上左或者右最大的值，计算时可以更新res
        if (root == NULL)
            return 0;
        int left = 

        return 0;
    }
};

int main()
{
    Solution A;

    return 0;
}
