#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int now = 0;
        int add = 0;
        bool tail_node_is_l1 = true;
        ListNode *tail, *p1 = l1, *p2 = l2;
        while (l1 != NULL || l2 != NULL) {
            int l1val = (l1 == NULL) ? 0 : l1->val;
            int l2val = (l2 == NULL) ? 0 : l2->val;
            now = add + l1val + l2val;
            add = now / 10;
            now = now % 10;
            if (l1 != NULL) {
                tail = l1;
                l1->val = now;
                l1 = l1->next;
                tail_node_is_l1 = true;
            }
            if (l2 != NULL) {
                tail = l2;
                l2->val = now;
                l2 = l2->next;
                tail_node_is_l1 = false;
            }
        }
        if (add != 0) {
            ListNode* more;
            more = tail_node_is_l1 ? p2 : p1;
            more->val = add;
            more->next = NULL;
            tail->next = more;
        }
        return tail_node_is_l1 ? p1 : p2;
    }
};

int main() {
    Solution A;
    ListNode* l1 = MakeRandomListNode(1, 5, 6);
    ListNode* l2 = MakeRandomListNode(1, 5, 6);
    show(l1);
    show(l2);
    ListNode* l3 = A.addTwoNumbers(l1, l2);
    show(l3);
    return 0;
}
