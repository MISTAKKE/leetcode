#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
链表中节点数目在范围[1, 10^5] 内
0 <= Node.val <= 9

23.35 48
*/

// Class Solution
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next==nullptr){
            return true;
        }
        ListNode *slow = head, *fast = head->next;
        while(fast != nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *last = slow->next, *newhead = slow->next;
        while(last ->next != nullptr){
            ListNode *tmp = last->next;
            last->next = last->next->next;
            tmp->next = newhead;
            newhead = tmp;
        }
        while(newhead != nullptr){
            if(head->val != newhead->val){
                return false;
            }
            head = head->next;
            newhead = newhead ->next;
        }
        return true;
    }
};
int main() {
    Solution A;

    return 0;
}
