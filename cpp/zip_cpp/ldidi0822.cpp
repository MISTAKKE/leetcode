#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
反转链表：
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

*/

// Class Solution
ListNode* localreverse(ListNode *head, int m, int n){
    if(head == nullptr){
        return head;
    }
    ListNode *newhead = new ListNode(0);
    newhead->next = head;
    ListNode *last = newhead;
    // newhead(0)  1 2 3 4 5 
    //process head
    while(--m>0){
        last->next = head;
        last = head;
        head = head ->next;
        --n;
    }
    //reverse from head->next
    while(--n>0){
        ListNode *tmp = head->next;
        head->next = head->next->next;
        tmp->next = last->next;
        last -> next = tmp;
    }

    head = newhead->next;
    delete newhead;
    return head;
}
int main() {
    ListNode* head = new ListNode(1);
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(3);
    ListNode* l3 = new ListNode(4);
    ListNode* l4 = new ListNode(5);
    head->next= l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    show(head);
    ListNode *newnode = localreverse(head, 6, 5);
    show(newnode);
    return 0;
}
