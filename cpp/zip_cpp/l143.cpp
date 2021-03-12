#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
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
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        //偶数节点：
        // 1 2 [3] 4 [5] 6
        // 1 6 2 5 3 4
        // 1 2 3   +   6 5 4
        //奇数节点：
        // 1 2 3 [4] 5 6 [7]
        // 1 7 2 6 3 5 4
        // 1 2 3 4  +  7 6 5
        //步骤：
        //1 快慢表找中点
        //2 将后面的reverse
        //3 将两者交替插入，返回
        if (head == NULL || head->next == NULL)
            return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }                         //slow为快表最后一个
        ListNode *p = slow->next; //p为后半部分第一个
        slow->next = NULL;
        ListNode *h = new ListNode(0); //   h -> p -> p1 -> p2 -> p3 -> NULL
        h->next = p;
        while (p->next != NULL) //2. reverse 后半部分
        {
            ListNode *tmp = p->next;
            p->next = p->next->next;
            tmp->next = h->next;
            h->next = tmp;
        }
        //3. merge head and  h->next(p);
        ListNode *q = head;
        while (h->next != NULL)
        {
            p = h->next;
            h->next = h->next->next;
            p->next = q->next;
            q->next = p;
            q = p->next;
        }
        delete h;
    }
};

int main()
{
    Solution A;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    // l2.next = &l3;
    // l3.next = &l4;
    // l4.next = &l5;
    A.reorderList(&l1);
    show(&l1);

    return 0;
}
