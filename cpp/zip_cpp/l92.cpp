#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution1 //需要一个空的头
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *h = new ListNode(0);
        h->next = head;
        int cnt = 1;
        ListNode *slow = h; // h(slow)-> a(head) b c d [e 5] f g [h 8] i j k
        while (cnt < left)
        {
            slow = slow->next;
            cnt += 1;
        }
        ListNode *first = slow->next;
        while (cnt != right)
        {
            ListNode *tmp = first->next;
            first->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
            cnt += 1;
        }
        head = h->next;
        delete h;
        return head;
    }
};

class Solution //不需要一个空的头
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // a [b] c [d] e f  l =2 r =4
        if (head == NULL)
            return head;
        ListNode *h = head;
        ListNode *p = NULL;
        int cnt = 1;
        while (cnt != left)
        {
            p = h;
            h = h->next;
            cnt += 1;
        } //h is the first node to reverse    p->next = h if p is not null;
        ListNode *last = h;
        while (cnt != right)
        {
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = h;
            h = tmp;
            cnt += 1;
        }
        if(p!=NULL)
        {
            p->next = h;
            return head;
        }
        return h;
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
    show(A.reverseBetween(&l1, 2, 4));
    return 0;
}
