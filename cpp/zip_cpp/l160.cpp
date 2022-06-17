#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) {
            pa = pa != nullptr ? pa->next : headB;
            pb = pb != nullptr ? pb->next : headA;
        }
        return pa;
    }

    ListNode* getIntersectionNode1(ListNode* headA, ListNode* headB) {
        ListNode *pa = headA, *pb = headB;
        while (pa != pb && pa != nullptr) {
            pa = pa->next;
            pb = pb->next;
            if (pa == nullptr && pb != nullptr) {
                pa = headB;
            }
            if (pb == nullptr && pa != nullptr) {
                pb = headA;
            }
        }
        return pa;
    }
};

int main() {
    Solution A;
    ListNode* p1 = MakeListNode({1, 2, 3, 4, 6});
    ListNode* p2 = MakeListNode({5, 6, 7, 8});
    ListNode* p3 = MakeListNode({7, 8});
    // p1->next->next->next->next->next = p3;
    // p2->next->next->next->next = p3;
    show(A.getIntersectionNode(p1, p2));

    return 0;
}
