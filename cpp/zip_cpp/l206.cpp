#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution1 // loop
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *last = head;
        ListNode *tmp;
        while (last->next != NULL)
        {
            tmp = last->next;
            last->next = tmp->next;
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};

class Solution // loop
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(head == NULL || head->next==NULL)
            return head;
        ListNode *p = reverseList(head->next); // a(head) [b c d e] -> a(head) (e)p d c b     a->b
        head->next->next = head;
        head->next = NULL;
        return p;
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
    // l1.next = &l2;
    // l2.next = &l3;
    // l3.next = &l4;
    // l4.next = &l5;
    show(A.reverseList(&l1));
    return 0;
}
