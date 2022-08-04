#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p = list1;
        b = b - a + 2;
        while (--a) {
            p = p->next;
        }
        ListNode* l2start = p;
        while (--b) {
            p = p->next;
        }
        ListNode* l2end = p->next;
        l2start->next = list2;
        while (list2->next != NULL) {
            list2 = list2->next;
        }
        list2->next = l2end;
        return list1;
    }
};

int main() {
    Solution A;
    ListNode* l1 = MakeRandomListNode(10, 1, 5);
    ListNode* l2 = MakeRandomListNode(3, 99, 105);
    show(l1);
    show(l2);
    show(A.mergeInBetween(l1, 2, 4, l2));

    return 0;
}
