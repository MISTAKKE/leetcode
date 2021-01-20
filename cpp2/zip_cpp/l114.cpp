#include "../tool/helper.cpp"
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        TreeNode *tmp = root->left;
        while(tmp->right!=NULL)
            tmp = tmp->right;
        tmp->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};


int main()
{
    Solution A;

    return 0;
}
