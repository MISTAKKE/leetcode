#include "../tool/helper.cpp"
using namespace std;

/*
description:
vec[]  [,,,a,,,b,,,]
res = max(sum(a, b) * min(a, b));

way:
    1 找到当前的min，左右均分求值
    2 挨个遍历，左右找到最远的idx
    3 单调栈，栈内严格递增
tips:
    sum(a to b) 可由 sumvec 求得
*/

//Class Solution
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        if (heights.size() == 0)
        {
            return 0;
        }
        vector<int> sumval(heights.size(), 0);
        sumval[0] = heights[0];
        for (int i = 1; i < heights.size(); ++i)
        {
            sumval[i] = sumval[i - 1] + heights[i];
        }
        // show(sumval);
        int res = 0;
        stack<int> s;
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                int h = s.top();
                s.pop();
                int l = s.empty() ? -1 : s.top(); //l+1 is ok
                int r = i;                        //l-1 is ok
                // cout << "l:" << l << " r:" << r << " h:" << h << endl;
                res = max(res, heights[h] * (sumval[r-1] - (l == -1 ? 0 : sumval[l])));
            }
            s.push(i);
        }
        while (!s.empty())
        {
            int h = s.top();
            s.pop();
            int l = s.empty() ? -1 : s.top();
            int r = heights.size() - 1;
            // cout << "l:" << l << " r:" << r << " h:" << h << endl;
            res = max(res, heights[h] * (sumval[r-1] - (l == -1 ? 0 : sumval[l])));
        }
        return res;
    }
};

int main()
{
    Solution A;
    vector<int> vec{3, 1, 6, 4, 5, 2};
    cout << A.largestRectangleArea(vec) << endl;
    return 0;
}
