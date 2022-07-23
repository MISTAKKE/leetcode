#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == key) {
            // case1 root->val == key
            if (root->right == nullptr) {
                return root->left;
            }
            TreeNode* rightleft = root->right;
            while (rightleft->left != nullptr) {
                rightleft = rightleft->left;
            }
            rightleft->left = root->left;
            return root->right;
        }
        // find key as p, which father is f
        TreeNode* f = findkeyfather(root, key);
        cout << "findkeyfather:" << f->val << endl;
        if (f == nullptr) {
            // case2 key not in tree
            return root;
        }
        if (f->left->val == key) {
            // case3 f->left->val == key
            if (f->left->left == nullptr) {
                f->left = f->left->right;
                return root;
            }
            TreeNode* leftright = f->left->left;
            while (leftright->right != nullptr) {
                leftright = leftright->right;
            }
            leftright->right = f->left->right;
            f->left = f->left->left;
            cout << "f->left:" << f->left->val << endl;
        }
        else {
            // case4 f->right->val == key
            if (f->right->right == nullptr) {
                f->right = f->right->left;
                return root;
            }
            TreeNode* rightleft = f->right->right;
            while (rightleft->left != nullptr) {
                rightleft = rightleft->left;
            }
            rightleft->left = f->right->left;
            f->right = f->right->right;
        }
        return root;
    }
    TreeNode* findkeyfather(TreeNode* root, int key) {
        if (root->val > key) {
            if (root->left != nullptr) {
                if (root->left->val == key) {
                    return root;
                }
                return findkeyfather(root->left, key);
            }
        }
        else {
            if (root->right != nullptr) {
                if (root->right->val == key) {
                    return root;
                }
                return findkeyfather(root->right, key);
            }
        }
        return nullptr;
    }
};

int main() {
    Solution A;
    TreeNode* root = new TreeNode(5);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t6 = new TreeNode(6);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t7 = new TreeNode(7);
    root->left = t3;
    root->right = t6;
    t3->left = t2;
    t3->right = t4;
    t6->right = t7;

    A.deleteNode(root, 3);
    return 0;
}
