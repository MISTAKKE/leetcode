#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p = head;
        int len = 0;
        bool ready = false;
        while(1){
            if(ready){
                if(--len == k - 1){
                    return p;
                }
            }
            else{
                ++len;
            }
            if(p->next == nullptr){
                p = head;
                ready = true;
                cout<<len<<endl;
            }
            else{
                p = p->next;
            }
        }
        return nullptr;
    }
};
int main() {
    Solution A;
    ListNode *head = MakeListNode({1,2,3,4,5});
    show(A.getKthFromEnd(head, 5));

    return 0;
}
