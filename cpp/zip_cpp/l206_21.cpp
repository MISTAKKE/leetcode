#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
链表，奇数位置按序增长，偶数位置按序递减，如何能实现链表从小到大？（2020.10 字节跳动-后端）[2]
奇偶生序倒序链表的重新排序组合，例如：18365472（2020.08 字节跳动-后端）[3]
1->4->3->2->5 给定一个链表奇数部分递增，偶数部分递减，要求在O(n)时间复杂度内将链表变成递增，5分钟左右（2020.07 字节跳动-测试开发）[4]
奇数位升序偶数位降序的链表要求时间O(n)空间O(1)的排序？(2020.07 字节跳动-后端)[5]
可见，无论是后端还是测试开发，都曾被考察过这道题，而且这道题并非力扣上的题目，大家一定要注意！！

题目描述

给定一个奇数位升序，偶数位降序的链表，将其重新排序。

输入: 1->8->3->6->5->4->7->2->NULL
输出: 1->2->3->4->5->6->7->8->NULL


*/

// Class Solution
//22.10
class Solution {
public:
    ListNode* SortList(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *up, *down;
        up = head, uplast = head;
        down = head->next, downlast = head->next;
        bool direction = true;
        head = head->next;
        while(head->next!=nullptr){
            if(direction){
                uplast->next = head->next;
                uplast = uplast->next;
            }
            else{
                downlast->next = head->next;
                downlast = downlast->next;
            }
            head = head->next;
            direction = !direction;
        }
        uplast->next = nullptr;
        downlast->next = nullptr;

        if(up->val < down->val){
            head = up;
            up = up->next;
        }
        else{
            head = down;
            down = down->next;
        }
        ListNode *headlast = head;
        while(up!=nullptr && down!= nullptr){
            if(up->val < down->val){
                headlast->next = up;
                up = up->next;
            }
            else{
                headlast->next = down;
                down = down->next;
            }
            headlast = headlast->next;
        }
        if(up!=nullptr){
            headlast->next = up;
        }
        if(down!=nullptr){
            headlast->next = down;
        }

        return head;
    }
};

int main() {
    Solution A;

    return 0;
}
