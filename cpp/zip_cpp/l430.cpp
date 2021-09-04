#include "/root/leetcode/tool/helper.cpp"
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution
{
public:
    Node* flatten(Node* head)
    {
        stack< Node* > sk;
        Node *p = head, *ret = head;
        while (p->next != NULL || p->child != NULL || !sk.empty())
        {
            if (p->child != NULL)
            {
                if (p->next != NULL)
                {
                    sk.push(p->next);
                }
                p->next = p->child;
                p->next->prev = p;
                p->child = NULL;
                p = p->next;
            }
            else if (p->next != NULL)
            {
                p = p->next;
            }
            else if (!sk.empty())
            {
                Node *top = sk.top();
                sk.pop();
                p->next = top;
                p->next->prev = p;
                p = p->next;
            }
        }
        return ret;
    }
};

int main()
{
    Solution A;

    return 0;
}
