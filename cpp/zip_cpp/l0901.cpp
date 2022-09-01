#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

笔试题目		
1. 实现单向链表归并排序
#include <iostream> 
using namespace std;  
struct node { 	
int data; 	
struct node* next; 	
node(int x):data(x),next(NULL){} }

2. 给定一个无序数组，求数组中的中位数

3. 给定一个整数数组，i<j, 求a[i]+a[j]+j-i的最大值



*/

// ListNode* mergesort(ListNode* head){
//     if(head == nullptr || head->next == nullptr){
//         return head;
//     }
//     ListNode *fast = head->next, *slow = head;
//     while(fast!=nullptr && fast->next !=nullptr){
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     //split as head and newhead
//     ListNode* newhead = slow->next;
//     slow->next = nullptr;
//     //sort two list
//     head = mergesort(head);
//     newhead = mergesort(newhead);
//     if(newhead == nullptr){
//         return head;
//     }
//     //swap to make head is smaller
//     if(head->val > newhead->val){
//         ListNode *tmp = newhead;
//         newhead = head;
//         head = tmpl
//     }
//     //merge two list
//     ListNode *last = head;
//     while(newhead!=nullptr){
//         if(last->next->val >= newhead->val){
//             ListNode *tmp = newhead;
//             newhead = newhead->next;
//             tmp->next = last->next;
//             last->next = tmp;
//         }
//         last = last->next;
//     }
//     return head;
// }


// // 2. 给定一个无序数组，求数组中的中位数
// double findmid(const vector<int> &vec){
//     if(vec.empty()){
//         return 0;
//     }
//     if(vec.size() == 1){
//         return vec[0];
//     }
//     int size = vec.size()/2 + 1;
//     priority_queue<int, vector<int>> q;
//     for(int i = 0; i<vec.size(); ++i){
//         q.push(vec[i]);
//         if(q.size() == size){
//             q.pop();
//         }
//     }
//     double ret_val{0};
//     //vec.size is odd  return the mid one
//     if(vec.size() % 2 == 1){
//         while(q.size() != 1){
//             q.pop();
//         }
//         ret_val = q.top();
//         return ret_val;
//     }
//     //vec.size is even  return the avg of mid
//     while(q.size() != 2){
//         q.pop();
//     }
//     ret_val = q.top();
//     q.pop();
//     ret_val = (ret_val + q.top()) / 2.0;
//     return val;
// }


// // 3. 给定一个整数数组，i<j, 求a[i]-i + a[j]+j的最大值
// /*
// 1. o(n^2) 的时间复杂度 两次遍历
// 2. 计算出 vec+idx 和 vec-idx 两个数组，求两个数组的maxval之和
//     1）vec1 和 vec2 的idx不相同
//     2) vec1 不用保存，存两个数即可
// */
// // Class Solution

// int getvectorval(const vector<int> &vec){
//     if(vec.size() < 2){
//         return 0;//error
//     }
//     //idx
//     int idx11 = 0, idx12 = 1; // vec1 = vec - idx   //   vec[idx11] >= vec[idx12]
//     int idx21 = 0, idx22 = 1; // vec2 = vec + idx
//     if(vec[1] - 1> vec[0]){
//         idx11 = 1;
//         idx12 = 0;
//     }
//     if(vec[1] + 1> vec[0]){
//         idx21 = 1;
//         idx22 = 0;
//     }
//     //cal vec-nm
//     for(int i = 2; i<vec.size(); ++i){
//         //val
//         int sub = vec[i] - i;
//         int add = vec[i] + i;
//         //idx
//         if(sub >= vec[idx11]){
//             idx12 = idx11;
//             idx11 = i;
//         }
//         if(add >= vec[idx21]){
//             idx22 = idx21;
//             idx21 = i;
//         }
//     }
//     if(idx11 != idx21){
//         return vec[idx11] + vec[idx21] - idx11 + idx21;
//     }
//     return max(vec[idx11] + vec[idx22] - idx11 + idx22, vec[idx12] + vec[idx21] - idx12 + idx21);
// }
#include <iostream>
#include <vector>
bool issubset(const vector<int> &s1, const vector<int> &s2){
    //return true is s2 si subset of s1
    if(s2.empty()){
        return true;
    }
    if(s1.empty()){
        return false;
    }
    int idx1 = 0, idx2 = 0;
    while(idx1!=s1.size() && idx2!=s2.size()){
        if(s1[idx1] == s2[idx2]){
            ++idx2;
        }
        ++idx1;
    }
    return idx2 == s2.size();
}
int main() {
    vector<int> s1 { 0,1,2,3,4,5,9};
    vector<int> s2 { 1,2,32,5};
    if(issubset(s1, s2))
    {
        cout<<"ddd"<<endl;
    }
    return 0;
}

