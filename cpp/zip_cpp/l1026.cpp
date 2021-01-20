#include "../tool/helper.cpp"
using namespace std;


class Solution {
    public:
    int maxval;
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }

        maxval = 0;

        if(root->left!=NULL)
        {
            find(root->left, root->val, root->val);
        }
        
        if(root->right!=NULL)
        {
            find(root->right, root->val, root->val);
        }

        return maxval;
    }

    void find(TreeNode* root, int maxv, int minv)
    {
        //1 update maxval
        maxval = maxval > maxv - root->val ? maxval : maxv - root->val;  
        maxval = maxval > root->val - minv ? maxval : root->val - minv; 

        //2 update parentval
        maxv = root->val > maxv ? root->val : maxv;
        minv = root->val < minv ? root->val : minv;
        if(root->left!=NULL)
        {
            find(root->left, maxv, minv);
        }
        if(root->right!=NULL)
        {
            find(root->right, maxv, minv);
        }
    }
};

int main()
{
    Solution A;

    return 0;
}
