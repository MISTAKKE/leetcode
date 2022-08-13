#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  private:
    map<int, int> inorder_mp;

  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_mp[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    // 前序遍历 preorder = [3,9,20,15,7]
    // 中序遍历 inorder = [9,3,15,20,7]
    TreeNode* helper(vector<int>& preorder,
                     vector<int>& inorder,
                     int preorderstart,
                     int preorderend,
                     int inorderstart,
                     int inorderend) {
        if (preorderend < preorderstart || inorderend < inorderstart) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preorderstart]);
        int rootinorderidx = inorder_mp[preorder[preorderstart]];
        int leftsize = rootinorderidx - inorderstart;
        root->left =
            helper(preorder, inorder, preorderstart + 1, preorderstart + leftsize, inorderstart, rootinorderidx - 1);
        root->right =
            helper(preorder, inorder, preorderstart + leftsize + 1, preorderend, rootinorderidx + 1, inorderend);
        return root;
    }
};

class Solution1 {
  private:
    unordered_map<int, int> index;

  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i)
            index[inorder[i]] = i;
        return helper(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    // 前序遍历 preorder = [3,9,20,15,7]
    // 中序遍历 inorder = [9,3,15,20,7]
    TreeNode* helper(vector<int>& preorder,
                     vector<int>& inorder,
                     int preorder_left,
                     int preorder_right,
                     int inorder_left,
                     int inorder_right) {
        if (preorder_left > preorder_right) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preorder_left]);

        // root left
        int inorder_root_idx = index[preorder[preorder_left]];
        int left_subtree_size = inorder_root_idx - inorder_left;
        root->left = helper(preorder, inorder, preorder_left + 1, preorder_left + left_subtree_size, inorder_left,
                            inorder_root_idx - 1);

        // root right
        root->right = helper(preorder, inorder, preorder_left + 1 + left_subtree_size, preorder_right,
                             inorder_root_idx + 1, inorder_right);

        return root;
    }
};

class Solution3 {
  private:
    unordered_map<int, int> index;

  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            index[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        // 前序遍历 preorder = [3,9,20,15,7]
        // 中序遍历 inorder = [9,3,15,20,7]
    }
    TreeNode* helper(vector<int>& preorder,
                     vector<int>& inorder,
                     int preorder_left,
                     int preorder_right,
                     int inorder_left,
                     int inorder_right) {
        if (preorder_left > preorder_right || inorder_left > inorder_right)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preorder_left]);
        int inorder_root = index[preorder[preorder_left]];
        int lefttreesize = inorder_root - inorder_left;
        root->left =
            helper(preorder, inorder, preorder_left + 1, preorder_left + lefttreesize, inorder_left, inorder_root - 1);
        root->right = helper(preorder, inorder, preorder_left + lefttreesize + 1, preorder_right, inorder_root + 1,
                             inorder_right);
        return root;
    }
};
int main() {
    Solution A;

    return 0;
}
