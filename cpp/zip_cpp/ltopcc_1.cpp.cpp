#include "../tool/helper.cpp"
using namespace std;

/*
description:

[3,1,6,4,5,2]，对于任意子序列可以计算一个X值，X=sum(subArray) * min(subArray)，求最大X
val <= 100
*/

//Class Solution

class Solution1 //二分法
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

class Solution2 //单调栈
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
            sumval[i] = sumval[i - 1] + vec[i]; //sumval记录了截止到idx的和，sumval[i] - sumval[j] = val[j+1] + .. + val[i]
        }
        stack<int> s;
        int res = 0;
        int n = vec.size();
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && vec[i] <= vec[s.top()]) //保证栈内是严格递增的
            {
                int peak = vec[s.top()]; //一溜出栈，栈顶是最小值
                s.pop();
                int l = s.empty() ? -1 : s.top();
                int r = i;
                //l和r是边界，因此区间是[l+1,r-1]
                int dist = sumval[r - 1] - (l == -1 ? 0 : sumval[l]);
                res = max(res, peak * dist);
            }
            s.push(i);
        }
        while (!s.empty())
        {
            int peak = vec[s.top()];
            s.pop();
            int l = s.empty() ? -1 : s.top();
            int r = vec.size();
            int dist = sumval[r - 1] - (l == -1 ? 0 : sumval[l]);
            res = max(res, peak * dist);
        }
        return res;
    }
};

class Solution3 //逐个左右延伸
{
public:
    int findrange(vector<int> &vec)
    {
        if (vec.size() == 0)
        {
            return 0;
        }
        int res = 0;
        vector<int> sumval(vec.size(), 0);
        sumval[0] = vec[0];
        for (int i = 1; i < vec.size(); ++i)
        {
            sumval[i] = sumval[i - 1] + vec[i];
        }
        for (int i = 0; i < vec.size(); ++i)
        {
            int left = i;
            while (left > 0 && vec[left - 1] >= vec[i])
            {
                left -= 1;
            }
            int right = i;
            while (right < vec.size() - 1 && vec[right + 1] >= vec[i])
            {
                right += 1;
            }
            res = max(res, (sumval[right] - sumval[left] + vec[left]) * vec[i]);
        }
        return res;
    }
};

class Solution //逐个左右延伸
{
public:
    int findrange(vector<int> &vec)
    {
        if (vec.size() == 0)
        {
            return 0;
        }
        int res = 0;
        stack<int> s;
        vector<int> sumval(vec.size(), 0);
        sumval[0] = vec[0];
        for (int i = 1; i < vec.size(); ++i)
        {
            sumval[i] = sumval[i - 1] + vec[i];
        }
        for (int i = 0; i < vec.size(); ++i)
        {
            while (!s.empty() && vec[s.top()] >= vec[i])
            {
                int idx = s.top();
                s.pop();
                int l = s.empty() ? -1 : s.top();
                int r = i; // val[l+1] to val[t-1]
                res = max(res, vec[idx] * (sumval[r - 1] - (l == -1 ? 0 : sumval[l])));
            }
            //val 1 3 5 7 2 3
            //idx 0 1 2 3 4 5
            //s   0       4 5
            s.push(i);
        }
        while (!s.empty())
        {
            int idx = s.top();
            s.pop();
            int l = s.empty() ? -1 : s.top();
            int r = vec.size() - 1;
            res = max(res, vec[idx] * (sumval[r] - (l == -1 ? 0 : sumval[l])));
        }
        return res;
    }
};

int main()
{
    Solution A;
    vector<int> vec{3, 1, 6, 4, 5, 2};
    cout << A.findrange(vec) << endl;
    return 0;
}
