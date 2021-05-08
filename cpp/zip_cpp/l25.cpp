#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Solution
{
public:
    ListNode *reverseKGroup2(ListNode *head, int k)
    {
        if (head == NULL || k == 1)
            return head;
        ListNode *h = new ListNode(0);
        h->next = head;
        ListNode *p = head;
        ListNode *tail = h;
        int cnt = 1;
        while (1)
        {
            while (cnt % k != 0 && p->next != NULL) // h(tail)-> a(p) b [c] d   k=3
            {
                cnt += 1;
                p = p->next;
            }                 //p is this [k]th
            p = p->next;
            if (cnt % k == 0) // h(tail)-> a b [c](p) d   k=3
            {
                ListNode *first = tail->next;
                while (first->next != p)
                {
                    ListNode *tmp = first->next;
                    first->next = tmp->next;
                    tmp->next = tail->next;
                    tail->next = tmp;
                }
                tail = first;
                
                if(p == NULL)
                {
                    break;
                }
                else
                {
                    cnt = 1;
                }
            }
            else
            {
                break;
            }
        }

        head = h->next;
        delete h;
        return head;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if(head==NULL || k==1)
            return head;
        ListNode *h = new ListNode(0);
        h->next = head;
        ListNode *last = h, *tmp, *p;

        // h ->  [k] [k] [k-last] head, p ...
        while(1)
        {
            int cnt = k;
            p = head->next;
            while(p!=NULL && cnt != 1)
            {
                p = p->next;
                cnt-=1;
            }
            if(cnt != 1)
            {
                last->next = head;
                break;
            }
            //head is the first of k, p is the nexthead of k
            //to insert as head to last behind
            while(head->next != p)
            {
                tmp = head->next;
                head->next = head->next->next;
                tmp->next = last->next;
                last->next = tmp;
            }
            //head is the last of k, p is the nexthead of k
            last = head;
            head = p;
            if(head==NULL)
            {
                break;
            }
        }

        head = h->next;
        delete h;
        return head;
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
    show(A.reverseKGroup(&l1, 2));
    return 0;
}
