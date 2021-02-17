#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution1 //no recursion   bfs   queue->stack
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        stack<TreeNode *> st;
        stack<TreeNode *> st2;
        bool reverse = false;
        if (root != NULL)
        {
            st.push(root);
        }
        while (!st.empty())
        {
            int cnt = st.size();
            res.push_back(vector<int>());
            while (cnt-- > 0)
            {
                TreeNode *p = st.top();
                st.pop();
                res.back().push_back(p->val);
                if (reverse)
                {
                    if (p->right != NULL)
                        st2.push(p->right);
                    if (p->left != NULL)
                        st2.push(p->left);
                }
                else
                {
                    if (p->left != NULL)
                        st2.push(p->left);
                    if (p->right != NULL)
                        st2.push(p->right);
                }
            }
            reverse = !reverse;
            st = st2;
            while (!st2.empty())
            {
                TreeNode *p = st2.top();
                st2.pop();
            }
        }
        return res;
    }
};

class Solution //no recursion   bfs   queue->vector
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
        {
            return res;
        }
        vector<TreeNode *> vec{root};
        int cnt = 1;
        bool reverse = false;
        while (cnt != 0)
        {
            res.push_back(vector<int>());
            for (int i = 0; i < cnt; ++i)
            {
                res.back().push_back(vec[i + reverse * (cnt - 1 - 2 * i)]->val);
                TreeNode *p = vec[i];
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
int main()
{
    Solution A;

    TreeNode l(2, NULL, NULL);
    TreeNode r(23, NULL, NULL);

    TreeNode l2(76, NULL, NULL);
    TreeNode r1(761, NULL, NULL);

    TreeNode l22(13, NULL, NULL);
    TreeNode r12(134, NULL, NULL);
    l.right = &l2;
    r.left = &r1;
    l2.right = &l22;
    r1.right = &r12;

    TreeNode p(1);
    p.left = &l;
    p.right = &r;
    show(A.zigzagLevelOrder(&p));
    return 0;
}
