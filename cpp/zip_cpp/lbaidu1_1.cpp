#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
    ListNode* reverse(ListNode *root)
    {
        ListNode *h = new ListNode(0);
        ListNode *last = NULL;
        while(root != NULL)
        {
            ListNode *tmp = root;
            root= root->next;

            h->next = tmp;  // h tmp last tmp....
            tmp->next = last;
            last = tmp;
        }
        root = h->next;
        delete h;
        return root;
    }
};

1 工作内容，面向业务是什么 
智慧高速 rcu路测 自动驾驶 智能交通

2 部门规模，是怎么交付的
分队之间的互备


int main()
{
    Solution A;

    return 0;
}
