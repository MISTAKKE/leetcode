#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::map<int, int> father;
        int val = 0;
        for(int i =0; i<nums.size(); ++i)
        {
            if(father.find(nums[i]+1) != father.end())
            {
                father[nums[i]] = father[nums[i]+1]+1;
            }
            else
            {
                father[nums[i]] = nums[i];
            }
            val = max(val, father[nums[i]]);
            if(father.find(nums[i]-1) != father.end())
            {
                father[nums[i]-1] += father[nums[i]];
                val = max(val, father[nums[i]]-1);
            }
        }
    }
};





int main()
{
    Solution A;

    return 0;
}
