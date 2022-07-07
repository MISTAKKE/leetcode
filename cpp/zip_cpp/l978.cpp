#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    // dp
    /*
    1. 连续子数组 和 非连续子数组
        连续数组 当前节点是最后一个节点时 结果是在每轮过程中
        非连续数组 当前节点是最大的值 结果是输出max(sub, add)
    2. sub和add
        add 是当前节点为最后一个节点时，最后一个节点比上一个节点大
        sub 是当前节点为最后一个节点时，最后一个节点比上一个节点小
    */
    int maxTurbulenceSize2(vector<int>& arr) {
        int add = 1, sub = 1;  //当前节点结束的值
        int maxval = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1]) {
                add = sub + 1;
                sub = 1;
                maxval = max(maxval, add);
            }
            else if (arr[i] < arr[i - 1]) {
                sub = add + 1;
                add = 1;
                maxval = max(maxval, sub);
            }
            else {
                add = 1;
                sub = 1;
            }
        }
        return maxval;
    }
    //双指针
    int maxTurbulenceSize(vector<int>& arr) {
        int begin = 0, end = 1, maxval = 1;
        while (end < arr.size() - 1) {
            cout << "begin:" << begin << " end:" << end << endl;
            if (begin == end) {
                if (arr[begin] == arr[begin + 1]) {
                    begin += 1;
                }
                end += 1;
            }
            else {
                if (arr[end - 1] < arr[end] && arr[end] > arr[end + 1]) {
                    end += 1;
                }
                else if (arr[end - 1] > arr[end] && arr[end] < arr[end + 1]) {
                    end += 1;
                }
                else {
                    begin = end;
                }
            }
            maxval = max(maxval, end - begin + 1);
        }
        return maxval;
    }
};

int main() {
    Solution A;
    vector<int> nums{9, 4, 2, 10, 7, 8, 8, 1, 9};  // 5
    // vector<int> nums{9, 9, 9};  // 2
    cout << A.maxTurbulenceSize(nums) << endl;

    return 0;
}
