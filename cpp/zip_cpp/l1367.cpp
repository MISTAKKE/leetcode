#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution_outoftime
{
public:
    ListNode *orignal;
    int cnt;
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        orignal = head;
        if (head == NULL)
            return true;
        return check(head, root);
    }
    bool check(ListNode *head, TreeNode *root)
    {
        if (root == NULL)
            return false;
        bool left = false, right = false;
        if (root->val == head->val)
        {
            left = (head->next == NULL) ? true : check(head->next, root->left);
            right = (head->next == NULL) ? true : check(head->next, root->right);
        }
        if(left || right)
            return true;
        if(head == orignal)
        {
            left = check(head, root->left);
            right = check(head, root->right);
        }
        else
        {
            head = orignal;
            left = check(head, root);
        }
        return left || right;
    }
};
class Solution_ok
{
public:
    ListNode *orignal;
    vector<int> res;
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if(head==NULL) return true;
        while(head!=NULL)
        {
            res.push_back(head->val);
            head=head->next;
        }
        if(root==NULL) return false;
        vector<int>tmp;
        return dfs(root, tmp);
    }
    bool dfs(TreeNode *r, vector<int> &tmp)
    {
        if(r == NULL)
            return false;
        tmp.push_back(r->val);
        if(tmp.size() >= res.size())
        {
            bool result = true;
            for(int i = 0; i<res.size(); ++i)
            {
                if(tmp[tmp.size()-1-i] != res[res.size()-1-i])
                {
                    result = false;
                    break;
                }
            }
            if(result) return true;
        }
        if(dfs(r->left, tmp))
        {
            return true;
        }
        if(dfs(r->right, tmp))
        {
            return true;
        }
        tmp.pop_back();
        return false;
    }
};

class Solution {
    bool dfs(TreeNode* rt, ListNode* head) {
        // 链表已经全部匹配完，匹配成功
        if (head == NULL) return true;
        // 二叉树访问到了空节点，匹配失败
        if (rt == NULL) return false;
        // 当前匹配的二叉树上节点的值与链表节点的值不相等，匹配失败
        if (rt->val != head->val) return false;
        return dfs(rt->left, head->next) || dfs(rt->right, head->next);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL) return false;
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

// [2,2,1]
// [2,null,2,null,2,null,1]
//      2 
//    n   2
//       n  2  
//         n  1
int main()
{
    Solution A;
    ListNode *l = new ListNode(2);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(1);
    l->next = l2;
    l2->next = l3;

    TreeNode *t = new TreeNode(2);
    TreeNode *tr = new TreeNode(2);
    TreeNode *trr = new TreeNode(3);
    TreeNode *trrr = new TreeNode(1);
    t->left = tr;
    tr->left = trr;
    trr->left = trrr;
    cout<<A.isSubPath(l,t)<<endl;
    return 0;
}
