#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        ListNode *last = NULL;
        ListNode *now = NULL;
        ListNode *freelist = NULL;
        int left = 0;
        while (l1 != NULL || l2 != NULL)
        {
            now = NULL;
            int val = left;
            if (l1 != NULL)
            {
                val += l1->val;
                if (head == NULL)
                {
                    head = l1;
                    now = l1;
                }
                else
                {
                    now = l1;
                }
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                val += l2->val;
                if (now == NULL)
                {
                    now = l2;
                }
                else if (freelist == NULL)
                {
                    freelist = l2;
                }
                l2 = l2->next;
            }
            left = val / 10;
            val = val % 10;
            now->val = val;
            if(last==NULL)
            {
                last = now;
            }
            else
            {
                last->next = now;
                last = last->next;
            }
        }
        if (left != 0)
        {
            freelist->val = left;
            freelist->next = NULL;
            last->next = freelist;
        }
        return head;
    }
};

int main()
{
    Solution A;
    ListNode a(9);
    ListNode b(9);
    ListNode c(9);
    b.next = &c;
    ListNode *p = A.addTwoNumbers(&a, &b);
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
