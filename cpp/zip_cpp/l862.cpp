#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

class Solution1 {
  public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + A[i - 1];
        deque<int> q;
        int minval = n + 1;
        for (int i = 0; i <= n; i++) {
            //保证队列里面的sum的递增的；
            //【队列里面的数字是记录起始点idx，相同的值需要起始点大的idx，这样 i-idx才会更小，得到更短的长度
            while (!q.empty() && sum[q.back()] >= sum[i])
                q.pop_back();
            while (!q.empty() &&
                   sum[i] - sum[q.front()] >= K)  //现在来的值sum[i]很给力，已经达到要求，来计算长度，将长的不要
            {
                minval = min(minval, i - q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        if (minval == n + 1)
            return -1;
        return minval;
    }
};

class Solution3 {
  public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> pre(n + 1, 0);
        vector<int> q(n + 1, 0);
        for (int i = 1; i < pre.size(); i++)
            pre[i] = pre[i - 1] + A[i - 1];
        int ans = 0x7fffffff, l = 0, r = -1;
        for (int i = 0; i < pre.size(); i++) {
            while (l <= r && pre[i] <= pre[q[r]])
                r--;
            while (l <= r && pre[i] - pre[q[l]] >= K) {
                ans = min(ans, i - q[l]);
                l += 1;
            }
            r++;
            q[r] = i;
        }
        return ans == 0x7fffffff ? -1 : ans;
    }
};

class Solution2 {
  public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> sumval(A.size() + 1, 0);
        for (int i = 1; i <= A.size(); ++i)
            sumval[i] = sumval[i - 1] + A[i - 1];
        int val = A.size() + 1;
        deque<int> q;
        for (int i = 0; i <= A.size(); ++i) {
            while (!q.empty() && sumval[q.back()] >= sumval[i])  // 1  3  -1  2    // 0 1 3
            {
                q.pop_back();
            }
            while (!q.empty() && (sumval[i] - sumval[q.front()] >= K))  // 2 -1 2      //0 2    i=3
            {
                val = min(val, i - q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        if (val == A.size() + 1)
            return -1;
        return val;
    }
};

class Solution {
  public:
    int shortestSubarray(vector<int>& A, int K) {
        deque<int> q;
        int ret = A.size() + 1;
        if (A.size() == 0)
            return -1;
        vector<int> sum(A.size() + 1, 0);  // sum[idx] is the sum from [0, i)  idx [0, A.size()]
        for (int i = 0; i < A.size(); ++i) {
            sum[i + 1] = sum[i] + A[i];
        }
        for (int i = 0; i <= A.size(); ++i) {
            while (!q.empty() && sum[i] <= sum[q.back()]) {
                q.pop_back();
            }
            while (!q.empty() && sum[i] - sum[q.front()] >= K) {
                ret = min(ret, i - q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        return ret == A.size() + 1 ? -1 : ret;
        // [1, 2, 5, -3, 3, 2]
    }
};

/*
one pass:
    如果数组内都是大于0的，那么end++则sum增加，start++则sum减少；
    上面说明需要有一个单调性，但是因为数组里面有负数，所以单调性不存在
    单调性有什么用？
        单调性可以达到one pass；减少时间复杂度；
    如何构造单调性？
        queue 里面的每个值，都是idx，sum[idx]<sum[idx+1]
        我们可以断言，最小的size肯定是在单调性的stack里面，不可能增加一个值后让sum减少了，这时还满足条件
*/
int main() {
    Solution A;
    vector<int> vec{2, -1, 2};
    cout << A.shortestSubarray(vec, 4) << endl;  // 2 1 3

    return 0;
}
