#include "../tool/helper.cpp"
using namespace std;

/*
description:

[3,1,6,4,5,2]，对于任意子序列可以计算一个X值，X=sum(subArray) * min(subArray)，求最大X
val <= 100
*/

//Class Solution

class Solution1
{
public:
    int findrange(vector<int> &vec)
    {
        if (vec.size() == 0)
        {
            return 0;
        }
        vector<int> sumval(vec.size(), 0); //sumval[2] - sumval[0] = val[1] + val[2]
        sumval[0] = vec[0];
        for (int i = 1; i < vec.size(); ++i)
        {
            sumval[i] = sumval[i - 1] + vec[i]; //sumval记录了截止到idx的合，可以快速算出sum(a,b)
        }
        // show(sumval);
        return help(vec, sumval, 0, vec.size() - 1);
    }
    int help(vector<int> &vec, vector<int> &sumval, int start, int end)
    {
        if (end == start)
            return vec[start] * vec[start];
        int minidx = start;
        for (int i = start + 1; i <= end; ++i)
        {
            if (vec[minidx] > vec[i])
            {
                minidx = i; //找到min花费O(n)
            }
        }
        int maxval = (sumval[end] - sumval[start] + vec[start]) * vec[minidx];
        // cout << "init: start:" << start << " end:" << end << " minidx:" << minidx << " val:" << maxval << endl;
        int left = 0;
        int right = 0;
        if (minidx != start) //不稳定地拆一半出去 O(logn) -> O(n)之间
        {
            left = help(vec, sumval, start, minidx - 1);
            // cout << "left: start:" << start << " end:" << minidx - 1 << " val:" << left << endl;
        }
        if (minidx != end)
        {
            right = help(vec, sumval, minidx + 1, end);
            // cout << "right: start:" << minidx + 1 << " end:" << end << " val:" << right << endl;
        }
        return max(maxval, max(left, right));
    }
};

class Solution
{
public:
    int findrange(vector<int> &vec)
    {
        if (vec.size() == 0)
        {
            return 0;
        }
        vector<int> sumval(vec.size() + 1, 0); //sumval[2] - sumval[0] = val[1] + val[2]
        for (int i = 1; i <= vec.size(); ++i)
        {
            sumval[i] = sumval[i - 1] + vec[i - 1]; //sumval记录了截止到idx的合，sumval[i] - sumval[j] = val[i] + .. + val[j-1]
        }
        stack<int> s;
        int res = 0;
        int n = vec.size();
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && vec[i] <= vec[s.top()])
            {
                int peak = vec[s.top()];
                s.pop();
                int l = s.empty() ? -1 : s.top();
                int r = i;
                //l和r是边界，因此区间是[l+1,r-1]，其区间和sumval[r+1]-sumval[l]
                int dist = sumval[r] - sumval[l + 1];
                res = max(res, peak * dist);
            }
            s.push(i);
        }
        while (!s.empty())
        {
            int peak = vec[s.top()];
            s.pop();
            int l = s.empty() ? -1 : s.top();
            int r = n;

            int dist = sumval[r] - sumval[l + 1];
            res = max(res, peak * dist);
        }
        return res;
    }
};
main()
{
    Solution A;
    vector<int> vec{3, 1, 6, 4, 5, 2};
    cout << A.findrange(vec) << endl;

    return 0;
}
