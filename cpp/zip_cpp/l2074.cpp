#include "/root/leetcode/tool/helper.cpp"
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
 */
/*
重点：
    由于长度>=1，且head一定不变，首先可明确返回值是 head
    其次明确链表是一段段组成的 设计好每一段的开头和结尾节点的变量名 newhead newlast
    明确每段开头节点的前一个节点，用于创造头插法的条件
    使用cnt标记当前区间有几个值，使用val标记是否需要reverse
    reverse时，需知道取节点和头插法的标准范式
    维护好下一次迭代的条件，在不同情况下对last进行赋值
*/
class Solution {
  public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // head | . . . | . . last|  newhead  .  .  .  newlast  | ....
        int cnt = 1;
        ListNode* last = head;
        while (last->next != nullptr) {
            ListNode* newhead = last->next;
            ListNode* newlast = last->next;
            // find newlast
            int val = cnt;
            while (val > 0 && newlast->next != nullptr) {
                newlast = newlast->next;
                val -= 1;
            }
            if ((cnt - val) % 2) {
                // reverse
                ListNode* end = newlast->next;
                while (newhead->next != end) {
                    // get one node
                    ListNode* tmp = newhead->next;
                    newhead->next = tmp->next;
                    // insert after last
                    tmp->next = last->next;
                    last->next = tmp;
                }
                last = newhead;
            }
            else {
                last = newlast;
            }
            cnt += 1;
        }
        return head;
    }
};

//很不错的代码
class Solution1 {
  public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* last = head;
        int cnt = 1;
        while (last->next != nullptr) {
            ListNode* newhead = last->next;
            ListNode* newlast = last->next;
            //计算当前轮次的尾节点
            int val = cnt;
            while (val > 0 && newlast->next != nullptr) {
                newlast = newlast->next;
                val -= 1;
            }
            if ((cnt - val) % 2) {
                // reverse  [last|  newhead  .  .  .  newlast  | .... ]
                ListNode* lastnode = newlast->next;
                while (newhead->next != lastnode) {
                    ListNode* tmp = newhead->next;
                    newhead->next = tmp->next;

                    tmp->next = last->next;
                    last->next = tmp;
                }
                last = newhead;
            }
            else {
                last = newlast;
            }
            cnt += 1;
        }
        return head;
    }
};

int main() {
    Solution A;
    ListNode* p = MakeListNode({1, 2, 3, 4, 5, 6, 7, 8});
    show(A.reverseEvenLengthGroups(p));

    return 0;
}
