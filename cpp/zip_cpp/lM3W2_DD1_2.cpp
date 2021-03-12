#include "../tool/helper.cpp"
using namespace std;

/*
description:
a->b->c->d->e->f
a->f->b->e->c->d

a->b->c->d->e   3 + 2
a->e->b->d->c
*/

class Solution
{
public:
    ListNode *process(ListNode *root)
    {
        if(root==NULL || root->next == NULL || root->next->next ==NULL)//0 1 2 return self
            return root;
        //1. split as 2 parts
        // 1 2 [3]  4 5
        // 1 2 [3] 4 5 6
        ListNode *fast = root;
        ListNode *slow = root;
        while(fast->next != NULL && fast->next->next !=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *p = new ListNode(0);
        p->next = slow->next;//p as the head of slow
        slow->next = NULL;

        //2. reverse the slow
        slow = p->next;
        while(slow->next!=NULL)
        {
            ListNode *tmp = slow->next;
            slow->next = slow->next->next;
            tmp->next = p->next;
            p->next = tmp;
        }

        //3. merge 2 parts; root and p->next
        ListNode *last = root;
        while(p->next != NULL)
        {
            ListNode *tmp = p->next;
            p->next = tmp->next;
            tmp->next = last->next;
            last->next = tmp;
            last = tmp->next;
        }

        return root;
    }

};


int main()
{
    Solution A;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    // l4.next = &l5;
    show(A.process(&l1));
    return 0;
}
