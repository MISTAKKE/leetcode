#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  private:
    unordered_map<int, int> index;

  public:
    // 中序遍历 inorder = [9,3,15,20,7]
    // 后序遍历 postorder = [9,15,7,20,3]
    /**
     *              3
     *         9        20
     *                15  7
     */
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        for (int i = 0; i < n; ++i)
            index[inorder[i]] = i;
        return helper(inorder, postorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* helper(vector<int>& inorder,
                     vector<int>& postorder,
                     int inorder_left,
                     int inorder_right,
                     int postorder_left,
                     int postorder_right) {
        if (inorder_left > inorder_right) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postorder_right]);
        int inorder_root_idx = index[postorder[postorder_right]];

        // lerft
        int left_subtree_size = inorder_root_idx - inorder_left;
        root->left = helper(inorder, postorder, inorder_left, inorder_left + left_subtree_size - 1, postorder_left,
                            postorder_left + left_subtree_size - 1);

        // right
        root->right = helper(inorder, postorder, inorder_root_idx + 1, inorder_right,
                             postorder_left + left_subtree_size, postorder_right - 1);
        return root;
    }
};

int main() {
    Solution A;

    return 0;
}
