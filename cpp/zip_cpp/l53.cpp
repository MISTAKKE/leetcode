#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23
 

提示：

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

*/
class Solution2 {
  public:
    int maxSubArray(vector<int>& nums) {
        int nowval = nums[0];
        int maxval = nowval;
        for (int i = 1; i < nums.size(); ++i) {
            if (nowval < 0) {
                nowval = 0;
            }
            nowval += nums[i];
            maxval = max(maxval, nowval);
        }
        return maxval;
    }
};
// Class Solution
class Solution2 {
  public:
    int maxSubArray(vector<int>& nums) {
        int nowval = nums[0];
        int maxval = nowval;
        for (int i = 1; i < nums.size(); ++i) {
            if (nowval < 0) {
                nowval = 0;
            }
            nowval += nums[i];
            maxval = max(maxval, nowval);
        }
        return maxval;
    }
};
int main() {
    Solution A;
    vector<int> num{-2,1,-3,4,-1,2,1,-5,4};
    cout<<A.maxSubArray(num)<<endl;

    return 0;
}
