#include "../tool/helper.cpp"
using namespace std;

/*
description:

            1
        2       3
    1    4     5 
121 + 124 + 135 
*/

//Class Solution
class Solution
{
public:
    int res;
    int getsum(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        res = 0;
        helper(root, 0);
        return res;
    }
    void helper(TreeNode *root ,int val)
    {
        val = val * 10 + root->val;
        if(root->left != NULL && root->right == NULL)
        {
            helper(root->left, val);
        }
        else if(root->right!= NULL && root->left== NULL)
        {
            helper(root->right, val);
        }
        else if(root->right == NULL && root->left == NULL)
        {
            res += val;
        }
        else
        {
            helper(root->right, val);
            helper(root->left, val);
        }
    }
};

int main()
{
    Solution A;
    /*
            1
        2       3
    1    4     5 
    */
    TreeNode root(1);
    TreeNode l1(2);
    TreeNode r1(3);
    TreeNode l11(1);
    TreeNode l12(4);
    TreeNode r11(5);
    root.left = &l1;
    root.right = &r1;
    l1.left = &l11;
    l1.right = &l12;
    r1.left = &r11;
    cout<<A.getsum(&root)<<endl;
    return 0;
}
