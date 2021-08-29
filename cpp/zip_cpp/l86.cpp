#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *prehead = new ListNode(99);
        prehead->next=head;
        ListNode *last = prehead, *scanner_before;
        while(last->next!=NULL && last->next->val<x)
        {
            last=last->next;
        }
        cout<<"show last ";
        show(last);
        scanner_before = last->next;
        while(scanner_before!=NULL && scanner_before->next!=NULL)
        {
            if(scanner_before->next->val < x)
            {
                ListNode *tmp = scanner_before->next;
                scanner_before ->next = tmp->next;

                tmp->next = last->next;
                last->next = tmp;
                last=last->next;
            }
            else
                scanner_before = scanner_before->next;
        }

        head = prehead->next;
        delete prehead;
        return head;
    }
};




int main()
{
    Solution A;
    ListNode *pa = new ListNode(10);
    ListNode *pb = new ListNode(1);
    ListNode *pc = new ListNode(4);
    ListNode *pd = new ListNode(3);
    ListNode *pe = new ListNode(9);
    pa->next = pb;
    pb->next = pc;
    pc->next = pd;
    pd->next = pe;
    show(pa);
    pa=A.partition(pa, 4);
    show(pa);
    return 0;
}
