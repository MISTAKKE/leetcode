#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *p = head, *p2 = head;
        bool circle = false;
        while (p->next != NULL && p->next->next != NULL) {
            p2 = p2->next->next;
            p = p->next;
            if (p == p2) {
                circle = true;
                break;
            }
        }
        if (circle) {
            p = head;
            while (p != p2) {
                p = p->next;
                p2 = p2->next;
            }
            return p;
        }
        return NULL;
    }
};

int main() {
    Solution A;

    return 0;
}
