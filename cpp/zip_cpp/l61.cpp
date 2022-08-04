#include "../tool/helper.cpp"
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
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
 */
class Solution {
  public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        // 1 求长度cnt  k=k%cnt;
        int cnt = 1;
        ListNode* p = head;
        while (p->next != NULL)  // p成为最尾节点
        {
            p = p->next;
            cnt += 1;
        }
        k = k % cnt;  //第cnt个节点开始，移动到头部
        if (k == 0) {
            return head;
        }

        ListNode* q = head;
        cnt = cnt - k - 1;  // q从head移动cnt后，成为首部的最尾节点
        while (cnt != 0) {
            q = q->next;
            cnt -= 1;
        }

        p->next = head;
        p = q->next;
        q->next = NULL;
        return p;
    }
};

int main() {
    Solution A;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    show(A.rotateRight(&l1, 12));
    return 0;
}
