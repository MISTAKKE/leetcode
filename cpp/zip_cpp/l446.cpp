#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int c(int n, int m) {
        long long int res = 1;
        for (int i = n; i >= m; --i) {
            res *= i;
        }
        for (int i = 1; i <= m; ++i) {
            res /= i;
        }
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<map<int, int>> mp(nums.size(), map<int, int>{});
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int d = nums[i] - nums[j];
                mp[i][d] = mp[j][d] + 1;
            }
        }
        int res = 0;
        for (auto c : mp[nums.size() - 1]) {
            int gap = c.second;
            cout << "c:" << c << " gap:" << gap << endl;
        }
        for (auto c : mp[nums.size() - 1]) {
            int gap = c.second;
            if (gap >= 2) {
                res += (gap * (gap - 1) * (gap - 2) / 6);
            }
        }
        return res;
    }
};
int main() {
    Solution A;
    vector<int> nums{7, 7, 7, 7, 7};
    cout << A.numberOfArithmeticSlices(nums) << endl;

    return 0;
}
