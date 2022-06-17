#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// reverse
class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int add = 0;
        ListNode* head = new ListNode(0);
        ListNode* last = head;
        while (l1 != nullptr || l2 != nullptr || add != 0) {
            int sum = add;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            add = sum / 10;
            last->next = new ListNode(sum % 10);
            last = last->next;
        }
        return reverse(head->next);
    }
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // head  [0..n]  now  t  k2  k3
        ListNode* now;
        now = head->next;

        while (now->next != nullptr) {
            ListNode* t = now->next;
            now->next = t->next;
            t->next = head->next;
            head->next = t;
        }

        now->next = head;
        head = head->next;
        now->next->next = nullptr;

        return head;
    }
};

int main() {
    Solution A;
    ListNode* p1 = MakeListNode({});
    ListNode* p2 = MakeListNode({1, 2});
    show(A.addTwoNumbers(p1, p2));

    return 0;
}
