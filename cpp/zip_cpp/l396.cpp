#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int maxRotateFunction(vector<int>& nums) {
        int sumval = 0;
        int base = 0;
        int maxval = 0;
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            base += i * nums[i];
            total += nums[i];
        }
        // cout << "total: " << total << " base:" << base << endl;
        for (int i = 0; i < nums.size() - 1; ++i) {
            sumval += (total - nums.size() * (nums[(nums.size() - 1 - i) % nums.size()]));
            // cout << "i: " << i << " fi:" << sumval + base << endl;
            maxval = max(maxval, sumval);
        }
        return maxval + base;
    }
};

int main() {
    Solution A;
    vector<int> nums{4, 3, 2, 6};
    cout << A.maxRotateFunction(nums) << endl;

    return 0;
}
