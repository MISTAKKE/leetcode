#include "../tool/helper.cpp"
using namespace std;

/*
description:
*/

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

class Solution//why it doesn't work
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL || root->left == NULL)
            return root;

        Node *pre = root; //当前层第一个节点
        Node *cur;        //当前层每一个遍历点
        Node TheNode(1);
        while (pre != NULL)
        {
            cur = pre;
            TheNode.next = NULL;
            Node *tail = &TheNode; //下一层的最后一个
            Node *head = &TheNode; //辅助用，帮助找到pre

            while (cur != NULL)
            {
                if (cur->left != NULL)
                {
                    tail->next = cur->left;
                    tail = tail->next;
                }
                if (cur->right != NULL)
                {
                    tail->next = cur->right;
                    tail = tail->next;
                }
                cur = cur->next;
            }

            //pre是下层的第一个
            pre = head->next;
        }
        return root;
    }
};

int main()
{
    Solution A;

    return 0;
}
