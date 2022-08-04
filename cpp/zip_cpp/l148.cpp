#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* q2 = slow->next;  // to end  （n+1)/2
        ListNode* q1 = head;
        slow->next = NULL;  // n/2
        q1 = sortList(q1);
        q2 = sortList(q2);

        ListNode *prehead, *temp, *last;
        if (q1->val > q2->val)  // make sure q1 is less as head
        {
            temp = q2;
            q2 = q1;
            q1 = temp;
        }
        last = q1;

        while (q2 != NULL)  // merge q2 to q1
        {
            if (last->next == NULL || q2->val < last->next->val) {
                temp = q2;
                q2 = q2->next;
                temp->next = last->next;
                last->next = temp;
                last = temp;
            }
            else {
                last = last->next;
            }
        }

        return q1;
    }
};

int main() {
    Solution A;
    ListNode* p = MakeRandomListNode(39, 1, 190);
    show(p);
    p = A.sortList(p);
    show(p);

    delete p;
    return 0;
}
