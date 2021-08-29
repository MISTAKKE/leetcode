#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

*/

//Class Solution

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL ||head->next==NULL)
            return head;
        ListNode *prehead = new ListNode(99);
        prehead->next = head;
        ListNode *p=head;
        ListNode *pp=head->next;
        ListNode *last=prehead;
        while(01)
        {
            p->next = pp->next;
            last->next = pp;
            pp->next = p;
            last = p;
            if(last->next !=NULL && last->next->next!=NULL)
            {
                p = last->next;
                pp = p->next;
            }
            else
            {
                break;
            }
        }
        head = prehead->next;
        free(prehead);
        return head;
    }
};

int main()
{
    Solution A;
    ListNode *pa = new ListNode(0);
    ListNode *pb = new ListNode(1);
    ListNode *pc = new ListNode(2);
    ListNode *pd = new ListNode(3);
    ListNode *pe = new ListNode(4);
    pa->next = pb;
    pb->next = pc;
    pc->next = pd;
    // pd->next = pe;
    show(pa);
    pa=A.swapPairs(pa);
    show(pa);
    return 0;
}
