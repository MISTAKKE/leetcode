#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
2. 给定一个无序数组，求数组中的中位数

3. 给定一个整数数组，i<j, 求a[i]+a[j]+j-i的最大值



/*
1. 实现单向链表归并排序
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

/*
2. 给定一个无序数组，求数组中的中位数
    1. 使用堆 o(N*lgN) 的时间复杂度 o(N) 的空间复杂度
    2. 快排 o(lgN*lgN)的时间复杂度
*/
// double findmid1(const vector<int> &vec){
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
//     return ret_val;
// }

// //return findidx_th of vec, which vec is not sorted, started from 0
// int findidxthval(vector<int> &vec, int start, int end, int findidx){
//     if(end == start){
//         return vec[start];
//     }
//     //find a place for the first
//     int start_orig = start;
//     int end_orig = end;
//     while(start < end){
//         while(start < end && vec[start] <= vec[start_orig]){
//             ++start;   
//         }
//         while(start < end && vec[end] > vec[start_orig]){
//             --end;
//         }
//         if(start < end){
//             swap(vec[start], vec[end]);
//         }
//     }
//     //start==end 小于等于第一个值的点的个数
//     int lessorequal_to_firstnode_cnt = start - start_orig + (vec[start] <= vec[start_orig]);
//     // 如果相等 则返回第一个
//     if (lessorequal_to_firstnode_cnt == findidx + 1){
//         return vec[start_orig];
//     }
//     else if(lessorequal_to_firstnode_cnt > findidx + 1){
//         // 如果太多，则剔除第一个，保留剩下所有的
//         return findidxthval(vec, start_orig + 1, start - (vec[start] > vec[start_orig]), findidx);
//     }
//     // 如果太少，则使用右侧的
//     return findidxthval(vec, start + (vec[start] <= vec[start_orig]), end_orig, findidx - lessorequal_to_firstnode_cnt);
// }

// double findmid2(vector<int> &vec){
//     if(vec.empty()){
//         return 0;
//     }
//     //偶数个
//     if(vec.size()%2 == 0){
//         double val = findidxthval(vec, 0, vec.size()-1, vec.size()/2 - 1);
//         val += findidxthval(vec, 0, vec.size()-1, vec.size()/2);
//         return val / 2;
//     }
//     //奇数个
//     return findidxthval(vec, 0, vec.size()-1, vec.size()/2);
// }

/*
3. 给定一个整数数组，i<j, 求a[i]-i + a[j]+j的最大值
    1. o(n^2) 的时间复杂度 两次遍历
    2. 计算出 vec+idx 和 vec-idx 两个数组，求两个数组的maxval之和
        1）vec1 和 vec2 的idx不相同
        2) vec1 不用保存，存两个数即可
*/

int getvectorval(const vector<int> &vec){
    if(vec.size() < 2){
        return 0;//error
    }
    //idx
    int idx11 = 0, idx12 = 1; // vec1 = vec - idx   //   vec[idx11] >= vec[idx12]
    int idx21 = 0, idx22 = 1; // vec2 = vec + idx
    if(vec[1] - 1> vec[0]){
        idx11 = 1;
        idx12 = 0;
    }
    if(vec[1] + 1> vec[0]){
        idx21 = 1;
        idx22 = 0;
    }
    //cal vec-nm
    for(int i = 2; i<vec.size(); ++i){
        //val
        int sub = vec[i] - i;
        int add = vec[i] + i;
        //idx
        if(sub >= vec[idx11]){
            idx12 = idx11;
            idx11 = i;
        }
        if(add >= vec[idx21]){
            idx22 = idx21;
            idx21 = i;
        }
    }
    if(idx11 != idx21){
        return vec[idx11] + vec[idx21] - idx11 + idx21;
    }
    return max(vec[idx11] + vec[idx22] - idx11 + idx22, vec[idx12] + vec[idx21] - idx12 + idx21);
}

/*
s1 和 s2是有序的，求s2是否是s1的子序列
1. 两个指针
2. 提前结束条件，s2比s1小，直接返回faslse
*/
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
        if(s1[idx1] > s2[idx2]){
            return false;
        }
        else if(s1[idx1] == s2[idx2]){
            ++idx2;
        }
        else 
        ++idx1;
    }
    return idx2 == s2.size();
}
int main() {
    vector<int> vec{1,4,6,7,3,2,5,8,9,7,7,7,7,7,7};
                 // 1,2,3,4,5,6,7,7,7,7,7,7,7,8,9
                 // 1,4,4,4,77777777777777777,9,9
    for(int i = 0;i < vec.size(); ++i){
        cout<<"i="<<i<<" val="<<findidxthval(vec, 0, vec.size()-1, i)<<endl;
    }
}

