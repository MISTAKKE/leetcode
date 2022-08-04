#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution1  // 4 param
{
  public:
    int rob(vector<int>& nums) {
        int do1 = 0, do2 = 0;
        int no1 = 0, no2 = 0;
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];

        do1 = nums[0];
        for (int i = 1; i < nums.size() - 1; ++i)  //抢第一个不抢最后一个
        {
            do2 = no1 + nums[i];
            no2 = max(do1, no1);
            do1 = do2;
            no1 = no2;
        }
        int res1 = max(do1, no1);  //抢第一个不抢最后一个

        do1 = nums[1];
        no1 = 0;
        for (int i = 2; i < nums.size(); ++i) {
            do2 = no1 + nums[i];
            no2 = max(do1, no1);
            do1 = do2;
            no1 = no2;
        }
        int res2 = max(do1, no1);  //第一个不抢，抢最后一个
        return max(res1, res2);
    }
};

int main() {
    Solution A;

    return 0;
}
