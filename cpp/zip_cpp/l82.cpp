#include "../tool/helper.cpp"
using namespace std;

/*
description:
*/

// Class Solution
void show(ListNode* head) {
    cout << "Linknode: ";
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
class Solution {
  public:
    ListNode* deleteDuplicates1(ListNode* head) {
        ListNode p(0);
        p.next = head;
        ListNode* root = NULL;
        while (p.next != NULL)  //   pp(p) -> head(2) -> 2 -> 3
        {
            int val = p.next->val;
            bool remove = false;
            while (p.next->next != NULL && p.next->next->val == val) {
                remove = true;
                p.next = p.next->next;
            }
            if (remove) {
                p.next = p.next->next;
            }
            else {
                p = *p.next;
                if (root == NULL) {
                    root = &p;
                }
            }
        }
        return root == NULL ? p.next : root;
    }
    ListNode* deleteDuplicates3(ListNode* head) {
        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;
        ListNode *left,
            *right;  // left 是左边可能重复的  right是右边可能重复的    p(head)  2(left, right)   2   3   3   4   null
        while (p->next) {
            left = p->next;
            right = left;
            while (right->next && right->next->val == left->val)
                right = right->next;
            if (left == right)
                p = p->next;
            else
                p->next = right->next;
        }
        return head->next;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode p(0);  // error
        p.next = head;
        head = &p;  // head指向p
        ListNode *left, *right;
        while (p.next != NULL) {
            left = p.next;
            right = left;
            while (right->next != NULL && left->val == right->next->val) {
                right = right->next;
            }
            if (left == right) {
                p = *(p.next);
            }
            else {
                p.next = right->next;
            }
        }
        show(&p);
        return head->next;
    }

    ListNode* deleteDuplicates5(ListNode* head) {
        ListNode* p = new ListNode(0);  // ok
        p->next = head;
        head = p;  // head指向空间
        ListNode *left, *right;
        while (p->next != NULL) {
            left = p->next;
            right = left;
            while (right->next != NULL && left->val == right->next->val) {
                right = right->next;
            }
            if (left == right) {
                p = p->next;
            }
            else {
                p->next = right->next;
            }
        }
        show(p);
        return head->next;
    }
};

int main() {
    Solution A;
    ListNode l1(0);
    ListNode l2(0);
    ListNode l3(1);
    ListNode l4(1);
    ListNode l5(2);
    ListNode l6(2);
    ListNode l7(3);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    show(&l1);
    show(A.deleteDuplicates(&l1));

    return 0;
}
