#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == null) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};


int main()
{
    Solution A;

    return 0;
}
