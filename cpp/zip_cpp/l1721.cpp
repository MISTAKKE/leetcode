#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head->next == NULL) {
            return head;
        }
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* p = prehead;
        ListNode *p1, *p2;
        // the p1 and p2, which are the node before of the k'th and -k'th
        while (--k) {
            p = p->next;
        }
        p1 = p;
        p2 = prehead;
        while (p->next->next != NULL) {
            p = p->next;
            p2 = p2->next;
        }

        int tmp = p1->next->val;
        p1->next->val = p2->next->val;
        p2->next->val = tmp;

        head = prehead->next;
        delete prehead;
        return head;
    }
};

int main() {
    Solution A;
    // p1或者p2相连
    ListNode* p = MakeListNode({7, 9, 6, 6, 7, 8, 3, 0, 9, 5});
    show(p);
    p = A.swapNodes(p, 5);
    show(p);

    return 0;
}