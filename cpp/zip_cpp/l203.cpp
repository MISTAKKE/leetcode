#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* last = p;
        while (last->next != nullptr) {
            if (last->next->val == val) {
                head = last->next;
                last->next = last->next->next;
                delete head;
            }
            else {
                last = last->next;
            }
        }
        head = p->next;
        delete p;
        return head;
    }
};

int main() {
    Solution A;
    ListNode* p = MakeListNode({5, 2, 3, 4, 5, 6, 7, 5, 5});
    show(A.removeElements(p, 5));

    return 0;
}
