#include "../tool/helper.cpp"
using namespace std;

/*
description:

树中节点数目在范围 [0, 2000] 内
-100 <= Node.val <= 100
*/

// Class Solution
class Solution  // 层次遍历，插入数据时将其reverse
{
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        bool reverse = false;
        while (!q.empty()) {
            int cnt = q.size();
            res.push_back(vector<int>{});
            while (--cnt > -1) {
                TreeNode* root = q.front();
                q.pop();
                res.back().push_back(root->val);
                if (root->left != nullptr) {
                    q.push(root->left);
                }
                if (root->right != nullptr) {
                    q.push(root->right);
                }
            }
            if (reverse) {
                std::reverse(res.back().begin(), res.back().end());
            }
            reverse = !reverse;
        }
        return res;
    }
};
class Solution1  // no recursion   bfs   queue->stack
{
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode*> st;
        stack<TreeNode*> st2;
        bool reverse = false;
        if (root != NULL) {
            st.push(root);
        }
        while (!st.empty()) {
            int cnt = st.size();
            res.push_back(vector<int>());
            while (cnt-- > 0) {
                TreeNode* p = st.top();
                st.pop();
                res.back().push_back(p->val);
                if (reverse) {
                    if (p->right != NULL)
                        st2.push(p->right);
                    if (p->left != NULL)
                        st2.push(p->left);
                }
                else {
                    if (p->left != NULL)
                        st2.push(p->left);
                    if (p->right != NULL)
                        st2.push(p->right);
                }
            }
            reverse = !reverse;
            st = st2;
            while (!st2.empty()) {
                TreeNode* p = st2.top();
                st2.pop();
            }
        }
        return res;
    }
};

class Solution2  // no recursion   bfs   queue->vector
{
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        vector<TreeNode*> vec{root};
        int cnt = 1;
        bool reverse = false;
        while (cnt != 0) {
            res.push_back(vector<int>());
            for (int i = 0; i < cnt; ++i) {
                res.back().push_back(vec[i + reverse * (cnt - 1 - 2 * i)]->val);
                TreeNode* p = vec[i];
                if (p->left != NULL)
                    vec.push_back(p->left);
                if (p->right != NULL)
                    vec.push_back(p->right);
            }
            reverse = !reverse;
            vec.erase(vec.begin(), vec.begin() + cnt);
            cnt = vec.size();
        }
        return res;
    }
};
int main() {
    Solution A;
    TreeNode p(1);
    TreeNode l(2, NULL, NULL);
    TreeNode r(3, NULL, NULL);
    p.left = &l;
    p.right = &r;

    TreeNode r1(31, NULL, NULL);
    TreeNode r2(32, NULL, NULL);
    r.left = &r1;
    r.right = &r2;

    TreeNode l1(21, NULL, NULL);
    TreeNode l2(22, NULL, NULL);
    l.left = &l1;
    l.right = &l2;

    show(A.zigzagLevelOrder(&p));
    return 0;
}
