#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//Class Solution
class Solution
{
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *h;
    ListNode *old;
    Solution(ListNode *head)
    {
        h = head;
        old = head;
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int ret = 0;
        int cnt = 0;
        while (h != NULL)
        {
            cnt++;
            if ((rand() % cnt == 0))
            {
                ret = h->val;
            }
            h = h->next;
        }
        h = old;
        return ret;
    }
};

int main()
{
    Solution A;

    return 0;
}
