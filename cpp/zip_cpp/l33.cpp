#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums 中的每个值都 独一无二
题目数据保证 nums 在预先未知的某个下标上进行了旋转
-10^4 <= target <= 10^4

如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
*/

// Class Solution

class Solution {
  public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        if (nums.size() == 1) {
            if (nums[0] != target) {
                return -1;
            }
            return 0;
        }
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 左侧递增
            else if (nums[left] <= nums[mid - 1]) {
                // 在左侧
                if (target >= nums[left] && target <= nums[mid - 1]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            //右侧递增
            else {
                if (target >= nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    cout << "dddddd mid:" << mid << endl;
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution A;
    vector<int> nums{1, 3};
    for (int i = 0; i < nums.size(); ++i)
        if (i != A.search(nums, nums[i])) {
            cout << "error val:" << nums[i] << " idx:" << i << endl;
        }
    cout << A.search(nums, 0) << endl;

    return 0;
}
