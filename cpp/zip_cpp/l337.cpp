#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }

    vector<int> dfs(TreeNode *root)
    {
        vector<int> res{0, 0};
        if(root==NULL)
            return res;
        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);
        res[0] = max(l[0], l[1]) + max(r[0], r[1]);
        res[1] = root->val + l[0] + r[0];
        return res;
    }
};

int main()
{
    Solution A;

    return 0;
}
