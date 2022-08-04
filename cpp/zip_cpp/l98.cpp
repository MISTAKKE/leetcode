#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
/*
    1 没有说限定值，使用long作为max和min的初始值
    2 注意在递归到后续时，应该把历史信息带上，该值定在区间内
*/
class Solution1  // dfs + recursion
{
  public:
    bool isValidBST(TreeNode* root, long minval = __LONG_MAX__ * -1, long maxval = __LONG_MAX__) {
        if (root == NULL) {
            return true;
        }
        if (root->left != NULL) {
            if (root->left->val >= root->val || root->left->val >= maxval || root->left->val <= minval ||
                !isValidBST(root->left, minval, root->val)) {
                return false;
            }
        }
        if (root->right != NULL) {
            if (root->val >= root->right->val || root->right->val >= maxval || root->right->val <= minval ||
                !isValidBST(root->right, root->val, maxval)) {
                return false;
            }
        }
        return true;
    }
};
class Solution2  // no recursion + dfs
{
  public:
    class Node {
      public:
        TreeNode* tree;
        long minval;
        long maxval;
        Node(TreeNode* tree_, long minval_, long maxval_) : tree(tree_), minval(minval_), maxval(maxval_){};
    };
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        stack<Node> st;  // first in last out
        st.push(Node(root, -1 * __LONG_MAX__, __LONG_MAX__));
        while (!st.empty()) {
            Node node = st.top();
            TreeNode* p = node.tree;
            st.pop();
            if (p->left != NULL) {
                if (p->left->val >= p->val || p->left->val >= node.maxval || p->left->val <= node.minval) {
                    return false;
                }
                st.push(Node(p->left, node.minval, p->val));
            }
            if (p->right != NULL) {
                if (p->val >= p->right->val || p->right->val >= node.maxval || p->right->val <= node.minval) {
                    return false;
                }
                st.push(Node(p->right, p->val, node.maxval));
            }
        }

        return true;
    }
};
class Solution  // no recursion + bfs
{
  public:
    class Node {
      public:
        TreeNode* tree;
        long minval;
        long maxval;
        Node(TreeNode* tree_, long minval_, long maxval_) : tree(tree_), minval(minval_), maxval(maxval_){};
    };

    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        queue<Node> q;  // first in first out
        q.push(Node(root, -1 * __LONG_MAX__, __LONG_MAX__));
        while (!q.empty()) {
            Node node = q.front();
            TreeNode* p = node.tree;
            q.pop();
            if (p->left != NULL) {
                if (p->left->val >= p->val || p->left->val >= node.maxval || p->left->val <= node.minval) {
                    return false;
                }
                q.push(Node(p->left, node.minval, p->val));
            }
            if (p->right != NULL) {
                if (p->val >= p->right->val || p->right->val >= node.maxval || p->right->val <= node.minval) {
                    return false;
                }
                q.push(Node(p->right, p->val, node.maxval));
            }
        }

        return true;
    }
};
int main() {
    Solution A;

    TreeNode l(1, NULL, NULL);
    TreeNode r(4, NULL, NULL);
    TreeNode r1(3, NULL, NULL);
    TreeNode r2(6, NULL, NULL);
    r.left = &r1;
    r.right = &r2;
    TreeNode p(5);
    p.left = &l;
    p.right = &r;
    cout << A.isValidBST(&p) << endl;

    return 0;
}