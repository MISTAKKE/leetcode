#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (!res.empty() && nums[i] < res.back() && n - i + res.size() > k)
                res.pop_back();
            if(res.size()<k)
                res.push_back(nums[i]);
        }

        return res;
    }
};

int main()
{
    Solution A;
    vector<int> nums{1, 3, 4, 5, 2, 7, 8};
    show(A.mostCompetitive(nums, 3));

    return 0;
}
