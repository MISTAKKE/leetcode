#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
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
    l4.next = &l5;
    show(A.reverseKGroup(&l1, 3));
    return 0;
}
