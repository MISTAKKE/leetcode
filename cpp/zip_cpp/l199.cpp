#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != slow && fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == slow)
            return true;
        return false;
    }
};
int main()
{
    Solution A;
    ListNode l11(0);
    ListNode l12(3);
    ListNode l13(6);
    l11.next = &l12;
    l12.next = &l13;

    return 0;
}
