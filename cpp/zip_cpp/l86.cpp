#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* prehead = new ListNode(99);
        prehead->next = head;
        ListNode *last = prehead, *scanner_before;
        while (last->next != NULL && last->next->val < x) {
            last = last->next;
        }
        cout << "show last ";
        show(last);
        scanner_before = last->next;
        while (scanner_before != NULL && scanner_before->next != NULL) {
            if (scanner_before->next->val < x) {
                ListNode* tmp = scanner_before->next;
                scanner_before->next = tmp->next;

                tmp->next = last->next;
                last->next = tmp;
                last = last->next;
            }
            else
                scanner_before = scanner_before->next;
        }

        head = prehead->next;
        delete prehead;
        return head;
    }
};

int main() {
    Solution A;
    ListNode* pa = MakeRandomListNode(10, 1, 8);
    show(pa);
    pa = A.partition(pa, 4);
    show(pa);
    delete pa;
    return 0;
}
