#include "../tool/helper.cpp"
using namespace std;

/*
description:
*/

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution1
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL || root->left == NULL)
            return root;

        root->left->next = root->right;
        if (root->next != NULL)
        {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL || root->left == NULL)
            return root;

        Node *pre = root;//指向每一层的第一个节点
        Node *cur;//每层之间循环
        while (pre != NULL)
        {
            cur = pre;
            while (cur != NULL)
            {
                cur->left->next = cur->right;
                if (cur->next != NULL)
                {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            pre = pre->left;

            //已经到了叶子节点，退出
            if (pre->left == NULL)
                break;
        }
        return root;
    }
};
int main()
{
    Solution A;

    return 0;
}
