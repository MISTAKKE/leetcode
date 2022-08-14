#include "../tool/helper.cpp"
using namespace std;

/*
description:
*/

class Solution {
  public:
    int firstMissingPositive(vector<int>& nums) {
        for (auto val : nums) {
            while (val >= 1 && val <= nums.size() && val != nums[val - 1]) {
                // swap val with nums[val-1]
                int tmp = nums[val - 1];
                nums[val - 1] = val;
                val = tmp;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

// Class Solution
class Solution2 {
  public:
    int firstMissingPositive(vector<int>& nums) {
        for (auto val : nums)  // 4 3 -1 2
        {
            while (val <= nums.size() && val >= 1 && val != nums[val - 1]) {
                int tmp = nums[val - 1];
                nums[val - 1] = val;
                val = tmp;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};

int main() {
    Solution A;
    vector<int> vec{4, -3, 1, 2};
    cout << A.firstMissingPositive(vec) << endl;

    return 0;
}
