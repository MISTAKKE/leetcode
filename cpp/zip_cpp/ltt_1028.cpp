#include "/root/leetcode/tool/helper.cpp"
using namespace std;

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> f(const vector<int>& vec) {
    vector<int> res(vec.size(), 0);
    stack<int> sk;
    for (int i = 0; i < vec.size(); ++i) {
        while (!sk.empty() && vec[sk.top()] < vec[i]) {
            int idx = sk.top();
            sk.pop();
            res[idx] = i;
        }
        sk.push(i);
    }
    while (!sk.empty()) {
        int idx = sk.top();
        sk.pop();
        res[idx] = -1;
    }
    return res;
}
int main() {
    // int a;
    vector<int> vec{1, 5, 3, 6};
    vector<int> res = f(vec);
    for (auto c : res)
        cout << c << endl;
}

// 题目：给定一个整型数组，数组元素随机无序的，要求打印出所有元素右边第一个大于该元素的位置。
// 如数组A=[1,5,3,6] 输出[1, 3, 3, -1]
// 1. 二叉树 节点是val-index 按照val排序，从右到左遍历 O(N*lgN)
// 2. 用map记录val-index，排序后找到一个val后面一个值 O(N*lgN)
// 3. 单调栈

// 1 5 3 6
// 1 3 5 6

// [1]  (x, x, x, x)
// [5]  (1, x, x, x)
// [5, 3] (1, x, x, x)
// [5] (1, x, 3, x)
// [idx] (1, 3, 3, x)