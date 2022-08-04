#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = head;
        while (p->next != NULL) {
            if (p->next->val == p->val) {
                p->next = p->next->next;
            }
            else {
                p = p->next;
            }
        }

        return head;
    }
};

int main() {
    Solution A;
    vector<int> vec{1, 1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 5, 5, 6, 6, 6};
    ListNode* p = MakeListNode(vec);
    show(p);
    p = A.deleteDuplicates(p);
    show(p);

    return 0;
}
