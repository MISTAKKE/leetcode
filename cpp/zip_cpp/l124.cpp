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
        res = __INT32_MAX__ * -1;
        help(root);
        return res;
    }
    int help(TreeNode *root) //返回以root为根节点，只取一边的最大值
    {
        if (root == NULL)
            return 0;
        int left = max(0, help(root->left));
        int right = max(0, help(root->right));
        res = max(res, root->val + left + right);
        return max(left, right) + root->val;
    }
};

int main()
{
    Solution A;

    return 0;
}
