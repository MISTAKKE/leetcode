#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    vector<vector<int>> res;
    int target;
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        target = targetSum;
        vector<int> tmp;
        dfs(root, tmp, 0);
        return res;
    }

    void dfs(TreeNode *p, vector<int> &vec, int val)
    {
        vec.push_back(p->val);
        val += p->val;
        if (p->left == NULL && p->right == NULL && val == target)
            res.push_back(vec);
        if (p->left != NULL)
            dfs(p->left, vec, val);
        if (p->right != NULL)
            dfs(p->right, vec, val);
        vec.erase(vec.end() - 1);
        val -= p->val;
    }
};

int main()
{
    Solution A;

    return 0;
}
