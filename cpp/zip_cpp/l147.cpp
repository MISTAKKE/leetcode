#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* tail = head;
        while(tail->next != NULL)
        {
            ListNode *now = tail->next;
            tail->next = tail->next->next;
            ListNode *thetail = newhead;
            while((thetail!=tail)&& (now->val > thetail->next->val))
            {
                thetail = thetail->next;
            }
            now ->next = thetail->next;
            thetail->next = now;
            if(thetail == tail)
            {
                tail = tail->next;
            }
        }
        head = newhead->next;
          delete newhead;
        return head;
    }
};

int main()
{
    Solution A;
    ListNode* r1 = new ListNode(0);
    ListNode* r2 = new ListNode(11);
    ListNode* r3 = new ListNode(2);
    r1->next=r2;
    r2->next=r3;
    show(r1);
    ListNode* r4 = A.insertionSortList(r1);
    show(r4);
    return 0;
}
