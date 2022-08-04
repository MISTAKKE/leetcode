#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
        int i = nums.size() - 1;
        int count = 0;
        while (i > 0) {
            int idx = i - 1;
            while (idx >= 0 && nums[i] == nums[idx])  // 0 1 2 idx 3 4 i
            {
                idx -= 1;
            }
            if (i - idx > 2) {
                // 1 no same
                // 2 2 same but idx is not same
                // n n same and idx is not same
                int id = 1;
                nums.erase(nums.begin() + idx + 3, nums.begin() + i + 1);
            }
            i = idx;
        }
        return nums.size();
    }
};

int main() {
    Solution A;
    vector<int> vec{0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 4, 5, 6, 6};
    cout << A.removeDuplicates(vec) << endl;
    show(vec);
    return 0;
}
