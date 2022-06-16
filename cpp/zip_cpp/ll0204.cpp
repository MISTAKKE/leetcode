#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

链表中节点的数目在范围 [0, 200] 内
-100 <= Node.val <= 100
-200 <= x <= 200

*/

// Class Solution

// math
class Solution {
  public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* more = new ListNode(0);
        ListNode *pl = less, *pm = more;
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
                head = head->next;
                less->next = nullptr;
            }
            else {
                more->next = head;
                more = more->next;
                head = head->next;
                more->next = nullptr;
            }
        }
        less->next = pm->next;
        head = pl->next;
        detele pl;
        detele pm;
        return head;
    }
};
// math
class Solution1 {
  public:
    ListNode* partition(ListNode* head, int x) {
        map<int, int> mp;
        ListNode* p = head;
        while (head != nullptr) {
            mp[head->val] += 1;
            head = head->next;
        }
        head = p;
        for (auto c : mp) {
            while (--mp[c.first] >= 0) {
                head->val = c.first;
                head = head->next;
            }
        }
        return p;
    }
};

int main() {
    Solution A;
    vector<int> vec{-1, -1, -2, -3, -5, 1, 4, 44, 111, 0, 34, 23423, -33};
    ListNode* p = MakeListNode(vec);
    show(A.partition(p, 22));

    return 0;
}
