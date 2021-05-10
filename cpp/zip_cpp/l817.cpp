#include "../tool/helper.cpp"
using namespace std;

/*
description:

如果 N 是给定链表 head 的长度，1 <= N <= 10000。
链表中每个结点的值所在范围为 [0, N - 1]。
1 <= G.length <= 10000

*/

//Class Solution

class Solution
{
public:
    int numComponents(ListNode *head, vector<int> &nums)
    {
        int cnt = 0;
        map<int, int> mp;
        while (head != NULL)
        {
            mp[head->val] = cnt;
            cnt += 1;
            head = head->next;
        }
        vector<bool> vec(cnt, false);
        for (auto c : nums)
        {
            if(mp.find(c) != mp.end())
            {
                vec[mp[c]] = true;
            }
        }
        int maxlen = 1;// 1 <= G.length <= 10000
        int cntofnow = 0;
        int nowlen= 0;
        vec.push_back(false);
        for(int i = 0;i<cnt;++i)
        {
            if(vec[i])
            {
                nowlen+=1;
            }
            else
            {
                if(nowlen > maxlen)
                {
                    maxlen = nowlen;
                    cntofnow = 1;
                }
                else if(maxlen == nowlen)
                {
                    cntofnow +=1;
                }
                nowlen = 0;
            }
        }
        return cntofnow;
    }
};

int main()
{
    Solution A;

    ListNode *l = new ListNode(2);
    ListNode *l2 = new ListNode(3);
    ListNode *l3 = new ListNode(1);
    l->next = l2;
    l2->next = l3;

    vector<int>vec{2,1,3};
    cout<<A.numComponents(l, vec)<<endl;
    return 0;
}
