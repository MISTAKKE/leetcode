#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int maxval = 0;
        int end = 0;
        int minlen = 0x7fffffff;
        for (int i = 0; i < nums.size(); ++i)
        {
            maxval += nums[i];
            while (maxval >= target)
            {
                minlen = min(minlen, i - end + 1);
                maxval -= nums[end];
                end++;
            }
        }
        if (minlen == 0x7fffffff)
            return 0;
        return minlen;
    }
};

int main()
{
    Solution A;
    vector<int> vec{1,1,1,1,1,1,1,1};
    cout << A.minSubArrayLen(11, vec) << endl;

    return 0;
}
