#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> vec(k, NULL);
        int cnt = 0;
        ListNode *p=head;
        while(p!=NULL)
        {
            cnt+=1;
            p=p->next;
        }
        int each = cnt / k; //17 / 5 = 3;  //每个都有3个
        int mod = cnt % k;  //17 % 5 = 2;  //前面2个多1一个
        for(int i = 0;i<k;++i)
        {
            int val = each;
            if(i<mod){
                val+=1;
            }
            //put val node to vec[i]
            
            if(val==0)
                continue;
            vec[i] = head;
            head=head->next;
            ListNode *last = vec[i];
            last->next=NULL;
            while(--val)
            {
                last->next = head;
                head = head->next;
                last = last->next;
                last->next = NULL;
            }
        }
        return vec;
    }
};




int main()
{
    Solution A;
    ListNode *p = MakeRandomListNode(20, 1, 10);
    show(p);
    vector<ListNode*> vec = A.splitListToParts(p, 30);
    for(ListNode*pp : vec)
    {
        show(pp);
    }

    return 0;
}
