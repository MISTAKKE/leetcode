#include "/root/leetcode/tool/helper.cpp"
#include "stdio.h"
#include <string.h>
#include <iostream>
using namespace std;

/*
description:

1. 实现字符串替换功能, 例如src = "abcabc", 把"ab" 替换成"cd", 最终结果 "cdccdc"

2. 对一个链表进行排序

3. 判断一棵树是否是平衡二叉树
*/

class StrReplace {
public:
    void Replace(string &source, const string &target, const string &replace){
        int pos =0;
        int len1 = target.size();
        int len2 = replace.size();
        while((pos=source.find(target,pos)) != string::npos){
            source.replace(pos, len1, replace);
            pos += len2;
        }
    }
};

class InsertionSort {
public:
    ListNode* Sort(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        //cur为待排序的第一个节点  pre最后一个阶段
        ListNode* last = head;
        ListNode* cur = head->next;
        while(cur != NULL){
            ListNode* tmp = newhead;
            if(last->val >= cur->val){
                while(tmp->next->val < cur->val)
                    tmp = tmp->next;
                last->next = cur->next;
                cur->next = tmp->next;
                tmp->next = cur;
                cur = last->next;
            }
            else{
                last = last->next;
                cur = cur->next;
            }
        }
        head = newhead->next;
        delete newhead;
        return head;
    }
};


class BalancedTree {
public:
    bool isBalanced(TreeNode* root) {
        if(height(root) >= 0){
            return true;
        }
        return false;
    }
    int height(TreeNode* root)
    {
        if(!root){
            return 0;
        };
        int l = height(root->left);
        int r = height(root->right);
        if(l<0 || r<0 || (l-r>1)||(r-l>1)){
            return -1;
        }
        return max(l, r)+1;
    }
};

int main() {
    InsertionSort A;
    ListNode *newhead = MakeListNode({11,4,8,2,3,5,3});
    show(newhead);
    ListNode *head = A.Sort(newhead);
    show(head);


    StrReplace B;
    string str = "ababddfsdab";
    string target = "ab";
    string replace = "gh";
    B.Replace(str, target, replace);
    cout<<str<<endl;

    return 0;
}
