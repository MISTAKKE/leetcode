#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

1 <= nums.length <= 1000
-2^31 <= nums[i] <= 2^31 - 1
对于所有有效的 i 都有 nums[i] != nums[i + 1]

*/

// Class Solution
class Solution {
  public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[mid+1]){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return right;
    }
};

class Solution2 {
  public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1){
            return 0;
        }
        int left = 0, right = nums.size() - 1;
        while (1) {
            int mid = (left + right) / 2;
            if(mid != left){
                if(nums[mid] > nums[mid-1]){
                    left = mid;
                }
                else{
                    right = mid;
                }
            }
            else if (mid == left){
                //等于则说明还有1个或2个
                return nums[left] > nums[right] ? left : right;
            }
        }
        return 0; //never catch
    }
};
int main() {
    Solution A;
    vector<int> nums{1,2,3,4,5,6,78};
    cout<<A.findPeakElement(nums)<<endl;

    return 0;
}
