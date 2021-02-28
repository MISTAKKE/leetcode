#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        if (nums.size() == 0 || k == 0)
            return res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (!q.empty() && i - q.front() + 1 > k)
            {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1)
            {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};

int main()
{
    Solution A;
    // vector<int> vec{1, 3, -1, -3, 5, 3, 6, 7};
    // show(A.maxSlidingWindow(vec, 3));

    // vector<int> vec{1, -1};
    // show(A.maxSlidingWindow(vec, 1));

    vector<int> vec{7, 2, 4};
    show(A.maxSlidingWindow(vec, 2));

    return 0;
}
