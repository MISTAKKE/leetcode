#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

class Solution
{
public:
    int shortestSubarray(vector<int> &A, int K)
    {
        int n = A.size();
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + A[i - 1];
        deque<int> q;
        int minval = n + 1;
        for (int i = 0; i <= n; i++)
        {
            while (!q.empty() && sum[q.back()] >= sum[i]) //保证队列里面的sum的递增的；【队列里面的数字是记录起始点idx，相同的值只需要起始点大的idx】
                q.pop_back();
            while (!q.empty() && sum[i] - sum[q.front()] >= K)//现在来的值sum[i]很给力，已经达到要求，来计算长度，将长的不要
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

class Solution2
{
public:
    int shortestSubarray(vector<int> &A, int K)
    {
        int n = A.size();
        vector<int> pre(n + 1, 0);
        vector<int> q(n + 1, 0);
        for (int i = 1; i < pre.size(); i++)
            pre[i] = pre[i - 1] + A[i - 1];
        int ans = 0x7fffffff, l = 0, r = -1;
        for (int i = 0; i < pre.size(); i++)
        {
            while (l <= r && pre[i] <= pre[q[r]])
                r--;
            while (l <= r && pre[i] - pre[q[l]] >= K)
            {
                ans = min(ans, i - q[l]);
                l += 1;
            }
            r++;
            q[r] = i;
        }
        return ans == 0x7fffffff ? -1 : ans;
    }
};

int main()
{
    Solution A;
    vector<int> vec{2, -1, 2};
    cout << A.shortestSubarray(vec, 3) << endl;

    return 0;
}
